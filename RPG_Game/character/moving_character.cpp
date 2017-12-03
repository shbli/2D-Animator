#include "moving_character.h"

moving_character::moving_character() {
    connect(this,SIGNAL(aim_to_char_signal(character_base*)),this,SLOT(aim_to_char_move(character_base*)),Qt::UniqueConnection);
}

void moving_character::aim_to_char_move(character_base *character) {
    check_type_by_distance = false;
    if (character != 0) {
//        aimToAtttackChar->nearest_point_mutex.lock();
        enemy_attacking_point = character->get_nearest_free_point(this);
#ifdef DEBUG_ATTACKING_POINTS
        qDebug() << "Point to return: " << enemy_attacking_point->point;
#endif
//        aimToAtttackChar->nearest_point_mutex.unlock();

    }
    stopAnimation();
    setAnimationType("walking");
    connect(this,SIGNAL(stepChildsAnimation(double)),this,SLOT(move_to_attack(double)),Qt::UniqueConnection);
    runAnimation();
}

void moving_character::ckeckAttackingDistance() {

//    float screenScale = Director::sharedDirector()->winSizeInPixels().width() / origwallw;

    //in this function, the character tries to move closer, and closer to the enemy, after that, starts attacking

    if (aimToAtttackChar != 0) {
        moveToPoint = aimToAtttackChar->pos() + enemy_attacking_point->point;
        //if the character got far enough to attack, let's start attacking, otherwise continue moving close
        if (! (close_to_moving_point() || mainWeapon->canFireFromFarAway) ) {
            aim_to_char(aimToAtttackChar);
        }
    } else {
        startBreathing();
    }


}

bool moving_character::close_to_moving_point() {
    if (check_type_by_distance) {
        float xDist = aimToAtttackChar->pos().x() - pos().x();
        float yDist = aimToAtttackChar->pos().y() - pos().y();

        float dist = (xDist*xDist) + (yDist*yDist);
        dist = sqrt(dist);

        if (dist < 100*character_base::screenScale) {
            return true;
        }
    } else {
        if (abs(pos().x() - moveToPoint.x()) < (attacking_distance*character_base::screenScale) ) {
            if (abs(pos().y() - moveToPoint.y()) < (attacking_distance*character_base::screenScale) ) {
                return true;
            }
        }
    }
    return false;
}


void moving_character::move_to_attack(double delta) {
    if (aimToAtttackChar != 0) {
        //in this function, the character tries to move closer, and closer to the enemy, after that, starts attacking

        moveToPoint = aimToAtttackChar->pos() + enemy_attacking_point->point;


        //    float dist_from_char = (xDist*xDist) + (yDist*yDist);
        //    dist_from_char = sqrt(dist_from_char);


        float xDist = moveToPoint.x() - pos().x();
        float yDist = moveToPoint.y() - pos().y();

        float dist = (xDist*xDist) + (yDist*yDist);
        dist = sqrt(dist);

        //if the character is close enough to attack, let's start attacking, otherwise continue moving close
        if (close_to_moving_point() || mainWeapon->canFireFromFarAway) {
            //        if (aimToAtttackChar->currentAnimationName != "walking") {
            if (enemy_attacking_point->left) {
                setScaleX(1);
            } else {
                setScaleX(-1);
            }
            setAnimationType("attacking");
            connect(this,SIGNAL(one_animation_round_done()),this,SLOT(ckeckAttackingDistance()),Qt::UniqueConnection);
            charaacter_close_to_attack = true;
            emit character_close_to_attack();
            //        }

        } else {

            speedPoint.setX((xDist/dist)*character_speed);
            speedPoint.setY((yDist/dist)*character_speed);

            if (speedPoint.x() < 0) {
                if (scaleX() != -1) {
                    setScaleX(-1);
                }
            } else {
                if (scaleX() != 1) {
                    setScaleX(1);
                }
            }

            QPointF nextPos = pos() + (speedPoint*delta);
            setIneffectivePos(nextPos);
            setZ(startZ - (nextPos.y() * 100));
        }
    } else {
        startBreathing();
    }
}
