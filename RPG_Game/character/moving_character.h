#ifndef MOVING_CHARACTER_H
#define MOVING_CHARACTER_H

#include "character_base.h"
#define attacking_distance (5*character_base::screenScale)

class moving_character : public character_base
{
    Q_OBJECT

public:
    moving_character();

public slots:
    void move_to_attack(double delta);
    void aim_to_char_move(character_base *character);
    void ckeckAttackingDistance();
private:
    bool close_to_moving_point();
};

#endif // MOVING_CHARACTER_H
