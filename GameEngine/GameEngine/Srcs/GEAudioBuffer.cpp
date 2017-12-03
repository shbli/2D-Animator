/**
 * Copyright (c) 2011 Nokia Corporation.
 *
 * Part of the Qt GameEnabler.
 */

#include "GEAudioBuffer.h"

#include <math.h>
#include <QFile>

#include "GEAudioBufferPlayInstance.h"
#include "GEAudioMixer.h"
#include "trace.h"

using namespace GE;


/*!
  Header for wav data
*/
struct SWavHeader {
    char chunkID[4];
    unsigned int chunkSize;
    char format[4];

    unsigned char subchunk1id[4];
    unsigned int subchunk1size;
    unsigned short audioFormat;
    unsigned short nofChannels;
    unsigned int sampleRate;
    unsigned int byteRate;

    unsigned short blockAlign;
    unsigned short bitsPerSample;

    unsigned char subchunk2id[4];
    unsigned int subchunk2size;
};


/*!
 * \class AudioBuffer
 * \brief A class to hold audio information (a buffer).
 */


/*!
  Constructor.
*/
AudioBuffer::AudioBuffer(QObject *parent /* = 0 */)
    : QObject(parent),
      m_sampleFunction(0),
      m_data(0),
      m_dataLength(0),
      m_nofChannels(0),
      m_bitsPerSample(0),
      m_signedData(false),
      m_samplesPerSec(0)
{
}


/*!
  Destructor.
*/
AudioBuffer::~AudioBuffer()
{
    // Deallocate the data.
    reallocate(0);
}


/*!
  (Re)allocates the audio buffer according to \a length.
*/
void AudioBuffer::reallocate(int length)
{
}


/*!
  Loads a .wav file from file with \a fileName. Note that this method can be
  used for loading .wav from Qt resources as well. If \a parent is given, it
  is set as the parent of the constructed buffer.

  Returns a new buffer if successful, NULL otherwise.
*/
AudioBuffer *AudioBuffer::loadWav(QString fileName, QObject *parent /* = 0 */)
{
    return 0;
}


/*!
  Protected method, called from AudioBuffer::loadWav(QString, QObject*).

  Loads a .wav file from a preopened \a wavFile. If \a parent is given, it is
  set as the parent of the constructed buffer.

  Returns a new buffer if successful, NULL otherwise.
*/
AudioBuffer *AudioBuffer::loadWav(QFile &wavFile, QObject *parent /* = 0 */)
{
    return NULL;
}


/*!
  Loads a .wav file from a preopened file handle, \a wavFile. If \a parent is
  given, it is set as the parent of the constructed buffer.

  Returns a new buffer if successful, NULL otherwise.
*/
AudioBuffer *AudioBuffer::loadWav(FILE *wavFile, QObject *parent /* = 0 */)
{
    return 0;
}


// Mix to  mono versions.

AUDIO_SAMPLE_TYPE AudioBuffer::sampleFunction8bitMono(AudioBuffer *buffer,
                                                      int pos,
                                                      int channel)
{
    Q_UNUSED(channel);
    return (AUDIO_SAMPLE_TYPE)(((quint8*)(buffer->m_data))[pos] - 128) << 8;
}


AUDIO_SAMPLE_TYPE AudioBuffer::sampleFunction16bitMono(AudioBuffer *buffer,
                                                        int pos,
                                                        int channel)
{
    Q_UNUSED(channel);
    return (AUDIO_SAMPLE_TYPE)(((quint16*)(buffer->m_data))[pos]);
}


AUDIO_SAMPLE_TYPE AudioBuffer::sampleFunction32bitMono(AudioBuffer *buffer,
                                                        int pos,
                                                        int channel)
{
    Q_UNUSED(channel); // To prevent compiler warnings.
    return (((float*)(buffer->m_data))[pos * buffer->m_nofChannels]) * 65536.0f / 2.0f;
}


// Mix to stereo versions.

AUDIO_SAMPLE_TYPE AudioBuffer::sampleFunction8bitStereo(AudioBuffer *buffer,
                                                         int pos,
                                                         int channel)
{
    return ((AUDIO_SAMPLE_TYPE)
        (((quint8*)(buffer->m_data))[pos * buffer->m_nofChannels + channel]) << 8);
}


AUDIO_SAMPLE_TYPE AudioBuffer::sampleFunction16bitStereo(AudioBuffer *buffer,
                                                          int pos,
                                                          int channel)
{
    return (AUDIO_SAMPLE_TYPE)
        (((quint16*)(buffer->m_data))[pos * buffer->m_nofChannels + channel]);
}


AUDIO_SAMPLE_TYPE AudioBuffer::sampleFunction32bitStereo(AudioBuffer *buffer,
                                                          int pos,
                                                          int channel)
{
    return (((float*)(buffer->m_data))[pos * buffer->m_nofChannels +
            channel]) * 65536.0f / 2.0f;
}


/*!
  Constructs a new play instance and sets it as an audio source for \a mixer.
  Note that the mixer takes ownership of the constructed instance.
  Returns the constructed instance or NULL in case the mixer refused to add
  the instance.
*/
AudioBufferPlayInstance *AudioBuffer::playWithMixer(AudioMixer &mixer)
{
    AudioBufferPlayInstance *instance = new AudioBufferPlayInstance(this);

    if (!mixer.addAudioSource(instance)) {
        DEBUG_INFO("Failed to add the new audio source to mixer!");
        delete instance;
        return NULL;
    }

    return instance;
}


/*!
  Sets an appropriate sample function for \a buffer depending on the number of
  channels and the bit rate.

  Returns true if successful, false otherwise.
*/
bool AudioBuffer::setSampleFunction(AudioBuffer &buffer)
{
    buffer.m_sampleFunction = 0;

    if (buffer.m_nofChannels == 1) {
        if (buffer.m_bitsPerSample == 8)
            buffer.m_sampleFunction = sampleFunction8bitMono;

        if (buffer.m_bitsPerSample == 16)
            buffer.m_sampleFunction = sampleFunction16bitMono;

        if (buffer.m_bitsPerSample == 32)
            buffer.m_sampleFunction = sampleFunction32bitMono;
    } else {
        if (buffer.m_bitsPerSample == 8)
            buffer.m_sampleFunction = sampleFunction8bitStereo;

        if (buffer.m_bitsPerSample == 16)
            buffer.m_sampleFunction = sampleFunction16bitStereo;

        if (buffer.m_bitsPerSample == 32)
            buffer.m_sampleFunction = sampleFunction32bitStereo;
    }

    if (!buffer.m_sampleFunction) {
        // Unknown bit rate!
        DEBUG_INFO("Unknown bit rate:" << buffer.m_bitsPerSample);
        return false;
    }

    return true;
}
