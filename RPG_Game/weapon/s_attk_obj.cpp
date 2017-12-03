#include "s_attk_obj.h"
#include "character_base.h"

s_attk_obj::s_attk_obj(QObject *parent) :
    QObject(parent) {
    number_of_effects = 0;
}

void s_attk_obj::start_effect(character_base* from_character) {
    excuter = from_character;
    //if it's a super attack, let's add all the elements
    if (super_affects_all) {
        for (int i = 0; i < game_controller::sharedGameController()->enemyCharacters.size(); i++) {
            to_be_attacked.append(game_controller::sharedGameController()->enemyCharacters.at(i));
        }
    } else {
        if (weapon_super) {
            if (from_character->super_aimToAtttackChar_weapon != 0) {
                to_be_attacked.append(from_character->super_aimToAtttackChar_weapon);
            }
        } else {
            if (from_character->super_aimToAtttackChar_character != 0) {
                to_be_attacked.append(from_character->super_aimToAtttackChar_character);
            }
        }
    }

    //check if we're going to add hp deduction to the list
    if (super_decreases_hp) {
        number_of_effects++;
        connect(&timer,SIGNAL(timeout()),this,SLOT(decrease_hp()),Qt::UniqueConnection);
    }

    //check if we're going to add slow down to the list
    if (super_slow_down_enemies) {
        number_of_effects++;
        for (int i = 0; i < to_be_attacked.size(); i++) {
            to_be_attacked.at(i)->slow_down_character();
        }
        connect(&timer,SIGNAL(timeout()),this,SLOT(slow_down()),Qt::UniqueConnection);
    }

    //check if we're going to add freeze to the list
    if (super_freezes_enemy) {
        number_of_effects++;
        for (int i = 0; i < to_be_attacked.size(); i++) {
            to_be_attacked.at(i)->freeze_character();
        }
        connect(&timer,SIGNAL(timeout()),this,SLOT(freeze()),Qt::UniqueConnection);
    }

#ifdef debug_super_effect_damage
                    qDebug() << "Checking if Provoke is applicable";
#endif
    //check if this attack is going to provoke or not
    if (super_provoke_enemies) {
#ifdef debug_super_effect_damage
                    qDebug() << "Yes!!, Provoke is applicable";
#endif
        for (int i = 0; i < to_be_attacked.size(); i++) {
            for (int j = 0; j < game_controller::sharedGameController()->playerCharacters.size(); j++) {
                if (game_controller::sharedGameController()->playerCharacters.at(j) == excuter) {
                    float newValue = to_be_attacked.at(i)->hateValues.at(j) + (3 * ((excuter->myLevel/decreaseHealLevelFix) * excuter->mainWeapon->weapon_power));


#ifdef debug_super_effect_damage
                    qDebug() << "Provoke values for player " << j << " before = " << to_be_attacked.at(i)->hateValues.at(j) << " after is " << newValue;
#endif
                    to_be_attacked.at(i)->hateValues.replace(j,newValue);
                    to_be_attacked.at(i)->selectMaxHatedCharacter();
                }
            }
        }
    }

    timer.start(timer_repeat_seconds*1000);
    time_elepsed.start();
    connect(&timer,SIGNAL(timeout()),this,SLOT(end_effect_if_nothing_remaining()),Qt::UniqueConnection);
}

void s_attk_obj::end_effect_if_nothing_remaining() {
    if (number_of_effects <= 0) {
        //stopping the timer, then deleting self by self
        timer.stop();
        deleteLater();
    }
}

void s_attk_obj::decrease_hp() {
    if (time_elepsed.elapsed() / 1000 >= (super_hp_reduction_value_timeout) ) {
        disconnect(&timer,SIGNAL(timeout()),this,SLOT(decrease_hp()));
#ifdef debug_super_effect_damage
        qDebug() << "Stopping HP-- after " << time_elepsed.elapsed();
#endif
        number_of_effects--;
    }
    for (int i = 0; i < to_be_attacked.size(); i++) {
#ifdef debug_super_effect_damage
        qDebug() << "Decreasing HP for char " << i << " by " << super_hp_reduction_value;
#endif
        to_be_attacked.at(i)->decreaseHealthBy((1.0 + (excuter->myLevel/decreaseHealLevelFix)) * super_hp_reduction_value,excuter);
    }
}

void s_attk_obj::slow_down() {
    if (time_elepsed.elapsed() / 1000 >= (super_slow_down_timeout) ) {
#ifdef debug_super_effect_damage
        qDebug() << "Stopping Slow down after " << time_elepsed.elapsed();
#endif
        disconnect(&timer,SIGNAL(timeout()),this,SLOT(slow_down()));
        number_of_effects--;
        for (int i = 0; i < to_be_attacked.size(); i++) {
            to_be_attacked.at(i)->un_slow_down_character();
        }
    }
}

void s_attk_obj::freeze() {
    if (time_elepsed.elapsed() / 1000 >= (super_freeze_timeout) ) {
#ifdef debug_super_effect_damage
        qDebug() << "Stopping Freeze after " << time_elepsed.elapsed();
#endif
        disconnect(&timer,SIGNAL(timeout()),this,SLOT(freeze()));
        number_of_effects--;
        for (int i = 0; i < to_be_attacked.size(); i++) {
            to_be_attacked.at(i)->un_freeze_character();
        }
    }
}
