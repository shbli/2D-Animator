#ifndef UNDER_CHAR_ELIPS_H
#define UNDER_CHAR_ELIPS_H

#include "game_engine.h"
#include <QDomDocument>
#include "global_keys.h"
#include "character_base.h"

/*
  This class, is an abstract layer, that reads from an under_char_elips.xml the specific values, and create from them an elips
*/

class under_char_elips : public Layer
{
    Q_OBJECT

public:
    under_char_elips();
    void attachToChar(character_base* toBeAttachedTo);
public slots:
    void attachedCharPosChanges();
private:
    Elips* belowElips;
    Elips* abovevElips;
    character_base* attachedChar;

};

#endif // UNDER_CHAR_ELIPS_H
