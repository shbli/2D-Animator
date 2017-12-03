#include "startscreen.h"
#include "map.h"

startscreen::startscreen() {
    screenScale = Director::sharedDirector()->winSizeInPixels().width() / origwallw;
    Sprite* background = Sprite::spriteWithSvg("blue_ground.svg",screenScale);
    addChild(background);
    setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);

    Sprite* logo_glow = Sprite::spriteWithSvg("compassgames_logo_glow.svg",screenScale);
    addChild(logo_glow);

    logo_glow->setOpacity(0);

//    logo_glow->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(1,100)),action::FuncCall(this,SLOT(start_screen_after_glow())),action::easeinout(action::fadeTo(1,0)),action::easeinout(action::fadeTo(1,0)),action::easeinout(action::fadeTo(1,100)),action::FuncCall(this,SLOT(hide_screen_after_glow())),action::easeinout(action::fadeTo(1,0)),action::FuncCall(this,SLOT(show_sky())),NULL));
//    logo_glow->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.5,0),action::fadeTo(1,100),action::FuncCall(this,SLOT(start_screen_after_glow())),action::fadeTo(2,0),action::fadeTo(0.5,0),action::fadeTo(1,100),action::FuncCall(this,SLOT(hide_screen_after_glow())),action::fadeTo(2,0),action::FuncCall(this,SLOT(show_sky())),NULL));
    logo_glow->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.5,0),action::fadeTo(1,100),action::FuncCall(this,SLOT(start_screen_after_glow())),action::fadeTo(2,0),action::fadeTo(0.5,0),action::FuncCall(this,SLOT(show_sky())),NULL));
}

Scene *startscreen::scene() {
    Scene* newscene = Scene::node();
    startscreen* newstartscreen = new startscreen();
    newscene->addChild(newstartscreen);
    return newscene;
}

void startscreen::start_screen_after_glow() {
    logo = Sprite::spriteWithSvg("compassgames_logo.svg",screenScale);
    addChild(logo);
}

void startscreen::hide_screen_after_glow() {
    logo->setOpacity(0);
}

void startscreen::show_sky() {
    Sprite* sky_background = Sprite::spriteWithSvg("sky.svg",screenScale);
    sky_background->setOpacity(0);
    addChild(sky_background);
    sky_background->setZ(10);
    sky_background->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(1,100)),NULL));
    setTouchEnabled(true);
}

void startscreen::touchEnd(QGraphicsSceneMouseEvent *event) {
    setTouchEnabled(false);
    Director::sharedDirector()->replaceScene(map::scene("area_1_1.xml"));
}
