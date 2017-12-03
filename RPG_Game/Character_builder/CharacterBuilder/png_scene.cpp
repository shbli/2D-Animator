#include "png_scene.h"

Scene* png_scene::scene() {
    Scene *scene = Scene::node();
    png_scene* layer = new png_scene;
    scene->addChild(layer);
    return scene;
}



void png_scene::onEnterTransitionDidStart() {
    qDebug() << Q_FUNC_INFO;
}

void png_scene::onEnterTransitionDidFinish() {
    qDebug() << Q_FUNC_INFO;
}

void png_scene::onExitTransitionDidStart() {
    qDebug() << Q_FUNC_INFO;
}

void png_scene::onExitTransitionDidFinish() {
    qDebug() << Q_FUNC_INFO;
}

png_scene::~png_scene()
{
}

png_scene::png_scene() {

#ifdef Q_OS_MAC64
    game_controller::sharedGameController()->resetController();
#endif
    //taking screen size, saving it to variable called winSize
    winSize = Director::sharedDirector()->winSizeInPixels();


    //we'll start by adding a sprite that represents the background for the menu
    background = Sprite::spriteWithSvg("ground_1_fight.svg",1);
    background->setPos(winSize.width()/2,winSize.height()/2);
    background->setZ(0);
//    background->setScale(winSize.width()/origwallw);
    addChild(background);

    humanLayer = new human_char_controller;

#ifndef COMPUTER
    loadCharacterFromXML("warrior_tom.xml");
#endif
}

void png_scene::loadCharacterFromXML(QString xml_file_name, skeltal_hbox *root)
{

    enemy_char_controller* enemyController = new enemy_char_controller;


    addChild(humanLayer);
    humanLayer->setZ(1000);


    float total_number_of_characters = 0;
    total_number_of_characters = 2;
    character_base* temp;

    //adding to human controlled characters
    humanLayer->addCharacterFromXML(xml_file_name);
    humanLayer->addCharacterFromXML("ninja_mitsu.xml");

    for (int i = 0; i < total_number_of_characters; i++) {
        temp = enemyController->addCharacterFromXML("warrior_enemy_1.xml");
    }

}

void png_scene::stopAllAnimatedCharacters()
{
}

