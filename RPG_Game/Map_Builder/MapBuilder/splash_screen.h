#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include "game_engine.h"
#include <QTimer>
#include "png_scene.h"

class splash_screen : public Layer
{
    Q_OBJECT

public:
    static Scene* scene();
private:
    splash_screen();
    QRect winSize;
    qreal backGroundHeight;
    Sprite* splashScreen;
public slots:
    void removeSplashScreen1();
    void removeSplashScreen1Free();
    void replaceWithGameLogo();
    void replaceSceneStep2();
    void replaceWithFreeAd();
};

#endif // SPLASH_SCREEN_H
