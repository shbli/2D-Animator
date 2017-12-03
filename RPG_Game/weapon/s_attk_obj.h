#ifndef S_ATTK_OBJ_H
#define S_ATTK_OBJ_H

#include <QObject>
#include <QTime>
#include <QTimer>

#define timer_repeat_seconds 0.5
//#define debug_super_effect_damage

class character_base;
/*
  This is a special super attack object, the effect is going to delete itself after a period of time
*/
class s_attk_obj : public QObject
{
    Q_OBJECT
public:
    explicit s_attk_obj(QObject *parent = 0);

    bool weapon_super;

    bool super_affects_all;
    bool super_decreases_hp;
    bool super_freezes_enemy;
    bool super_slow_down_enemies;
    bool super_provoke_enemies;

    int super_reset_seconds;
    float super_hp_reduction_value;
    int super_hp_reduction_value_timeout;
    int super_freeze_timeout;
    int super_slow_down_timeout;


    QList <character_base*> to_be_attacked;
    character_base* excuter;
    QTimer timer;
    QTime time_elepsed;
    
    int number_of_effects;
signals:
    
public slots:

    void start_effect(character_base* from_character);
    void end_effect_if_nothing_remaining();

    void decrease_hp();
    void slow_down();
    void freeze();
};

#endif // S_ATTK_OBJ_H
