#include "game_controller.h"
#include "moving_character.h"
#include "map.h"

game_controller* game_controller::gameController = 0;
QMutex game_controller::mutex;
map* game_controller::currentMap = 0;

game_controller::game_controller(QObject *parent) :
    QObject(parent)
{
    mainPlayLayer = 0;
    gameSpeed = 1;
    enemySpeed = 1;
    playerSpeed = 1;
}

game_controller *game_controller::sharedGameController() {
    mutex.lock();
    if (!gameController) {
        gameController = new game_controller;
        gameController->current_id = 0;
    }
    mutex.unlock();
    return gameController;
}

void game_controller::addPlayerCharacter(character_base *character) {
    character->computer_player = false;
    playerCharacters.append(character);
}

void game_controller::removePlayerCharacter(character_base *character) {
    playerCharacters.removeOne(character);
}

void game_controller::addEnemyCharacter(character_base *character) {
    character->computer_player = true;
    enemyCharacters.append(character);
}

void game_controller::removeEnemyCharacter(character_base *character) {
    removeAllConnectionToPlayer(character);
    enemyCharacters.removeOne(character);
    //this will cause a crash once main play layer is deleted, because of null pointers
//    QTimer::singleShot(60*1000,character,SLOT(deleteLater()));

    bool characterAdded = false;
    bool found = true;
    while (enemyCharacters.size() < 3 && found) {
        if (currentMap != 0) {
            if (!currentMap->enemies.isEmpty()) {
                characterAdded = true;
                character_base* xml_character = currentMap->enemies.takeFirst();
                addEnemyCharacter(xml_character);
                xml_character->setOpacity(0);
                xml_character->setPos(Director::sharedDirector()->winSizeInPixels().width()*2,Director::sharedDirector()->winSizeInPixels().height()/2);
                QTimer::singleShot(1000,xml_character,SLOT(enterStage()));
            } else {
                found = false;
            }
        }
    }

    if (!characterAdded) {
        //no more enemies
        if (enemyCharacters.isEmpty()) {
            //unlock the map
            if (currentMap != 0) {
                currentMap->humanLayer->setTouchEnabled(false);
                for (int i = 0; i < playerCharacters.size(); i++) {
                    if (!playerCharacters.at(i)->isDead()) {
                        playerCharacters.at(i)->armor->hideArrow(false);
                        playerCharacters.at(i)->armor->removePointedChar();
                        playerCharacters.at(i)->aimToAtttackChar = 0;
                    }
                }
                QTimer::singleShot(1000*3,currentMap,SLOT(unclock_map()));
            }
        }
    }
}

void game_controller::resetController() {
    for (int i = 0 ; i < enemyCharacters.size(); i++) {
        enemyCharacters.at(i)->stopAnimation();
    }
    for (int i = 0 ; i < playerCharacters.size(); i++) {
        playerCharacters.at(i)->stopAnimation();
    }

    if (!enemyCharacters.isEmpty()) {
        enemyCharacters.clear();
    }
    if (!playerCharacters.isEmpty()) {
        playerCharacters.clear();
    }

    mainPlayLayer = 0;
    gameSpeed = 1;
    enemySpeed = 1;
    playerSpeed = 1;
    current_id = 0;
}

void game_controller::removeAllConnectionToPlayer(character_base *character) {
    if (character->computer_player) {
        for (int i = 0; i < playerCharacters.size(); i++) {
            playerCharacters.at(i)->removeConnectionFromPlayer(character);
        }
    } else {
        for (int i = 0; i < enemyCharacters.size(); i++) {
            enemyCharacters.at(i)->removeConnectionFromPlayer(character);
//            qDebug() << "Removing connection from " << character->character_name;
            enemyCharacters.at(i)->selectMaxHatedCharacter();
        }
    }
}

int game_controller::request_new_id() {
    current_id++;
    return current_id;
}
