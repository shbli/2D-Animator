#include "enemy_char_controller.h"

#define mainPlayLayer game_controller::sharedGameController()->mainPlayLayer
#define enemy_characters_list game_controller::sharedGameController()->enemyCharacters

enemy_char_controller::enemy_char_controller(QObject *parent) :
    QObject(parent)
{
}

character_base *enemy_char_controller::addCharacterFromXML(QString xml_file_name) {
    moving_character* xml_character = new moving_character;
    mainPlayLayer->addChild(xml_character);
    game_controller::sharedGameController()->addEnemyCharacter(xml_character);
    xml_character->setOpacity(0);
    xml_character->load_from_xml(xml_file_name);
    xml_character->setOpacity(0);
    xml_character->setPos(Director::sharedDirector()->winSizeInPixels().width()*2,Director::sharedDirector()->winSizeInPixels().height()/2);
    QTimer::singleShot(2000,xml_character,SLOT(enterStage()));
//    xml_character->startEnemeyIntleegince();
    return xml_character;
}
