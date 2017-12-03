#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

/*

  This is a singleton class, that controlls the game, it contains many static instances, for all the objects to contact

*/

#include <QObject>
#include <QMutex>
#include "character_base.h"
#include "game_engine.h"

class map;

class game_controller : public QObject
{
    Q_OBJECT
public:
    Layer* mainPlayLayer;
    float gameSpeed;
    QList <character_base*> playerCharacters;
    QList <character_base*> enemyCharacters;
    static game_controller* sharedGameController();
    void addPlayerCharacter(character_base* character);
    void removePlayerCharacter(character_base* character);
    void addEnemyCharacter(character_base* character);
    void removeEnemyCharacter(character_base* character);
    void resetController();
    void removeAllConnectionToPlayer(character_base* character);
    float enemySpeed;
    float playerSpeed;
    static map* currentMap;
    int request_new_id();

private:
    static QMutex mutex;
    explicit game_controller(QObject *parent = 0);
    static game_controller* gameController;
    int current_id;
signals:
    
public slots:
    
};

#endif // GAME_CONTROLLER_H
