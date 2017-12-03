#include "human_char_controller.h"
#define human_characters_list game_controller::sharedGameController()->playerCharacters
#define enemy_characters_list game_controller::sharedGameController()->enemyCharacters

#define halfCharacterWidth 60
#define halfCharacterhight 100


human_char_controller::human_char_controller() {

    startCharacterSelectedIndex = -1;

    game_controller::sharedGameController()->mainPlayLayer = this;
//    elips = new under_char_elips;
//    addChild(elips);
//    elips->setPos(200,200);
//    elips->setOpacity(0);
//    elips->setScale(0);
//    elips->setZ(1000);

//    arrow = new human_char_arrow;
//    addChild(arrow);
//    arrow->setOpacity(0);
//    arrow->setZ(1000);

    screenScale = Director::sharedDirector()->winSizeInPixels().width()/ origwallw;

    QTimer::singleShot(500,this,SLOT(enable_touch_controls()));
}
#ifdef characterbuilder
character_base* human_char_controller::addCharacterFromXML(QString xml_file_name,skeltal_hbox* root) {
#else
character_base* human_char_controller::addCharacterFromXML(QString xml_file_name) {
#endif
    moving_character* xml_character = new moving_character;
    addChild(xml_character);
    game_controller::sharedGameController()->addPlayerCharacter(xml_character);
    #ifdef characterbuilder
    xml_character->load_from_xml(xml_file_name,root);
#else
    xml_character->load_from_xml(xml_file_name);
#endif
    xml_character->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);
    xml_character->computer_player = false;
    return xml_character;
}

void human_char_controller::touchBegin(QGraphicsSceneMouseEvent *event) {


    arrowAttached = false;
    clickTimer.restart();
    startTouchPos = Director::sharedDirector()->convertTouchPoint(event->scenePos());
    startCharacterSelectedIndex = -1;
    int selectedZLevel = -200000000;
    for (int i = 0; i < human_characters_list.size(); i++) {
        if (startTouchPos.x() > (human_characters_list.at(i)->pos().x() - (halfCharacterWidth * character_base::screenScale)) && startTouchPos.x() < (human_characters_list.at(i)->pos().x() + (halfCharacterWidth * character_base::screenScale)) ) {
            if (startTouchPos.y() > (human_characters_list.at(i)->pos().y() - (halfCharacterhight * character_base::screenScale)) && startTouchPos.y() < (human_characters_list.at(i)->pos().y() + (halfCharacterhight * character_base::screenScale)) ) {
                if (selectedZLevel < human_characters_list.at(i)->z()) {
                    startCharacterSelectedIndex = i;
                    selectedZLevel = human_characters_list.at(i)->z();
                }
//                return;
            }
        }
    }
}

void human_char_controller::touchEnd(QGraphicsSceneMouseEvent *event) {


    //    qDebug() << "Clicked time in Milliseconds = " << clickTimer.elapsed();

    bool movedetected = false;
    if (clickTimer.elapsed() > 70) {
        movedetected = true;
    }
    if (arrowAttached) {
        human_characters_list.at(startCharacterSelectedIndex)->armor->hideArrow(movedetected);
    }
    arrowAttached = false;

    startCharacterSelectedIndex = -1;
}

void human_char_controller::enable_touch_controls() {
    setTouchEnabled(true);
}


void human_char_controller::touchMove(QGraphicsSceneMouseEvent *event) {


    QPointF touchPos = Director::sharedDirector()->convertTouchPoint(event->scenePos());

    if (startCharacterSelectedIndex >= 0 && startCharacterSelectedIndex < human_characters_list.size()) {
        //he's trying to move a character
        if (!arrowAttached) {
            arrowAttached = true;
            human_characters_list.at(startCharacterSelectedIndex)->armor->showArrow();
//            human_characters_list.at(startCharacterSelectedIndex)->armor->attachToChar(human_characters_list.at(startCharacterSelectedIndex));
        }
        //arrow is already attached, if am trying to point to an enemy, attach me to that enemy, else, move to
        if (human_characters_list.at(startCharacterSelectedIndex)->armor->attachedChar != 0) {
            //arrow is already attached to a character
            if (touchPos.x() > (human_characters_list.at(startCharacterSelectedIndex)->armor->attachedChar->pos().x() - (halfCharacterWidth * character_base::screenScale)) && touchPos.x() < (human_characters_list.at(startCharacterSelectedIndex)->armor->attachedChar->pos().x() + (halfCharacterWidth * character_base::screenScale)) ) {
                if (touchPos.y() > (human_characters_list.at(startCharacterSelectedIndex)->armor->attachedChar->pos().y() - (halfCharacterhight * character_base::screenScale)) && touchPos.y() < (human_characters_list.at(startCharacterSelectedIndex)->armor->attachedChar->pos().y() + (halfCharacterhight * character_base::screenScale)) ) {
                    //my move is near the char, stop doing anything else, keep the end pointing to that opponet
                    return;
                }
            }

        }
        for (int i = 0; i < enemy_characters_list.size(); i++) {
            if (!enemy_characters_list.at(i)->isDead()) {
                if (touchPos.x() > (enemy_characters_list.at(i)->pos().x() - (halfCharacterWidth * character_base::screenScale)) && touchPos.x() < (enemy_characters_list.at(i)->pos().x() + (halfCharacterWidth * character_base::screenScale)) ) {
                    if (touchPos.y() > (enemy_characters_list.at(i)->pos().y() - (halfCharacterhight * character_base::screenScale)) && touchPos.y() < (enemy_characters_list.at(i)->pos().y() + (halfCharacterhight * character_base::screenScale)) ) {
                        //am approching an enemy, let's do point to him
                        human_characters_list.at(startCharacterSelectedIndex)->armor->attachToChar(enemy_characters_list.at(i));
                        return;
                    }
                }
            }
        }
        //am not pointing to an enemy, let's remove my armor from him
        human_characters_list.at(startCharacterSelectedIndex)->armor->removePointedChar(true);
//        human_characters_list.at(startCharacterSelectedIndex)->armor->glow_in_white();
        human_characters_list.at(startCharacterSelectedIndex)->armor->setEnd(touchPos.x(),touchPos.y());
    }
}
