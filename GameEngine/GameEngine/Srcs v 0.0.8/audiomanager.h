#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <QObject>
#include <QTimer>

//this is set to exclude some devices (Like android) which still doesn't support QtMultiMediaKit
#ifndef Q_WS_QPA
#define QtMultiMediaKitSupported
#endif

#ifdef Q_OS_MAC
#define QtMultiMediaKitSupported
#endif

#ifdef QtMultiMediaKitSupported
#include "GEAudioMixer.h"
#include "GEAudioBuffer.h"
#include "GEAudioOut.h"
#include "GEAudioBufferPlayInstance.h"
#endif

class audioManager : public QObject
{
    Q_OBJECT
public:
    static void playSound(QString path);
    static void setUpAudioManager();
    static void enableSounds(bool);
private:
    explicit audioManager(QObject *parent = 0);
#ifdef QtMultiMediaKitSupported
    static GE::AudioOut *m_audioOut;
    static GE::AudioMixer m_mixer;
#ifdef Q_OS_SYMBIAN
    static QTimer m_audioPullTimer; // Used to tick the audio engine in symbian devices only
#endif
#ifdef harmattan
    static GE::AudioBuffer* meego_sample;
    static GE::AudioBufferPlayInstance *meego_instance;
#endif
#endif

signals:

public slots:

};

#endif // AUDIOMANAGER_H
