#include "audiomanager.h"
/*
Refer to
https://projects.developer.nokia.com/qtgameenabler/wiki/audio
for more info, please use wav 22050 kHz, 2 channels, signed 16 bit PCM.
*/



#ifdef QtMultiMediaKitSupported
GE::AudioOut * audioManager::m_audioOut;
GE::AudioMixer audioManager::m_mixer;
#ifdef Q_OS_SYMBIAN
QTimer audioManager::m_audioPullTimer;
#endif
#ifdef harmattan
    GE::AudioBuffer* audioManager::meego_sample;
    GE::AudioBufferPlayInstance* audioManager::meego_instance;
#endif
#endif

audioManager::audioManager(QObject *parent) :
    QObject(parent)
{

}

void audioManager::playSound(QString path) {
    if  (path != "") {
#ifdef QtMultiMediaKitSupported
        GE::AudioBuffer* m_someSample = GE::AudioBuffer::loadWav(path);
        GE::AudioBufferPlayInstance *m_instance = new GE::AudioBufferPlayInstance(m_someSample);
        connect(m_instance,SIGNAL(finished()),m_someSample,SLOT(deleteLater()));
        //    connect(m_instance,SIGNAL(finished()),m_instance,SLOT(deleteLater()));
        m_mixer.addAudioSource(m_instance);
#ifdef harmattan
        m_mixer.addAudioSource(meego_instance);
#endif
#endif
    }
}

void audioManager::setUpAudioManager() {
#ifdef QtMultiMediaKitSupported
    m_audioOut = new GE::AudioOut(&m_mixer);
    m_mixer.setGeneralVolume(1.0f);
#ifdef Q_OS_SYMBIAN
    m_mixer.setGeneralVolume(10.0);
    m_mixer.setAbsoluteVolume(10.0);
    m_audioPullTimer.setInterval(5);
    connect(&m_audioPullTimer, SIGNAL(timeout()), m_audioOut, SLOT(tick()));
#endif
#ifdef harmattan
    qWarning() << Q_FUNC_INFO << " Harmattan setup";
    meego_sample = GE::AudioBuffer::loadWav(QString("plain.wav"));
    meego_instance = new GE::AudioBufferPlayInstance(meego_sample);
    meego_instance->setDestroyWhenFinished(false);
#endif
    audioManager::enableSounds(true);
#endif

}

void audioManager::enableSounds(bool enable)
{
#ifdef QtMultiMediaKitSupported
    if (enable) {
#ifdef Q_OS_SYMBIAN
        m_audioPullTimer.start();
#endif
        m_mixer.setGeneralVolume(1.0f);
#ifdef Q_OS_SYMBIAN
        m_mixer.setGeneralVolume(10.0);
        m_mixer.setAbsoluteVolume(10.0);
#endif

    }
    else {
#ifdef Q_OS_SYMBIAN
        m_audioPullTimer.stop();
#endif
        m_mixer.setGeneralVolume(0);
    }
#endif
}
