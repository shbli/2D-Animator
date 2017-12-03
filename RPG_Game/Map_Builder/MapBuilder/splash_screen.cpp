#include "splash_screen.h"
#include "global_keys.h"
#include "png_scene.h"
Scene * splash_screen::scene() {
    Scene *scene = Scene::node();
    splash_screen* layer = new splash_screen;
    scene->addChild(layer);
    return scene;
}


splash_screen::splash_screen() {
    qDebug() << Q_FUNC_INFO;
    //taking screen size, saving it to variable called winSize
    winSize = Director::sharedDirector()->winSizeInPixels();
    backGroundHeight = winSize.width()/origwallw*origwallh;

    //we'll set the position of the layer that we are in so it's in the middle of the screen
    setPos(winSize.width()/2,winSize.height()/2);
    setScale((winSize.width()/origwallw));
    //we'll start by adding a sprite that represents the background for the menu
    splashScreen = Sprite::spriteWithImage("splash_screen.png");
    splashScreen->setPos(0,0);
    addChild(splashScreen);
    splashScreen->setOpacity(0);
    splashScreen->runAction(action::easeinout(action::fadeTo(0.9,100)));
    QTimer::singleShot(3000,this,SLOT(replaceSceneStep2()));

}

void splash_screen::removeSplashScreen1() {
    splashScreen->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.25,0)),action::FuncCall(this,SLOT(replaceWithGameLogo())),NULL));
}

void splash_screen::removeSplashScreen1Free()
{
    splashScreen->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.25,0)),action::FuncCall(this,SLOT(replaceWithFreeAd())),NULL));
}

void splash_screen::replaceWithFreeAd()
{
    qDebug() << Q_FUNC_INFO;
    removeChild(splashScreen);
    splashScreen = Sprite::spriteWithImage("splash_ad.png");
    splashScreen->setPos(0,0);
    addChild(splashScreen);
    splashScreen->setOpacity(0);
    splashScreen->runAction(action::easeinout(action::fadeTo(0.9,100)));
    QTimer::singleShot(6000,this,SLOT(removeSplashScreen1()));
}

void splash_screen::replaceWithGameLogo() {
    qDebug() << Q_FUNC_INFO;
    removeChild(splashScreen);
    //we'll start by adding a sprite that represents the background for the menu
    Sprite* background = Sprite::spriteWithImage("whitewall.png");
    background->setPos(0,0);
    background->setOpacity(0);
    background->runAction(action::easeinout(action::fadeTo(0.25,100)));
    addChild(background);

    //now, we'll add the logo on that screen as another sprite, no need to save that variable
    Sprite* logo = Sprite::spriteWithImage("menu_logo.png");
    logo->setPos(0,0);
    addChild(logo);
    logo->setOpacity(0);
    logo->runAction(action::easeinout(action::fadeTo(0.25,100)));
    QTimer::singleShot(1500,this,SLOT(replaceSceneStep2()));
    //make some problems in Nokia Symbian devices
#ifndef Q_OS_SYMBIAN
    audioManager::playSound("welcome_message.wav");
#endif
}

void splash_screen::replaceSceneStep2() {
    Director::sharedDirector()->replaceScene(transitionScene::FadeTransition(png_scene::scene(),1));
}

