#ifndef ENEMY_CHAR_CONTROLLER_H
#define ENEMY_CHAR_CONTROLLER_H

#include <QObject>
#include "game_controller.h"
#include "moving_character.h"

class enemy_char_controller : public QObject
{
    Q_OBJECT
public:
    explicit enemy_char_controller(QObject *parent = 0);
    //adds a character child, and returns it as a pointer
    character_base* addCharacterFromXML(QString xml_file_name);
    
signals:
    
public slots:
    
};

#endif // ENEMY_CHAR_CONTROLLER_H
