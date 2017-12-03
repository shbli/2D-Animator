#include "human_char_arrow.h"
#include "character_base.h"
#include "map.h"


float character_base::screenScale = 0;

character_base::~character_base() {
    chtimer->deleteLater();

    if (attacking_right_point.occupied_by != 0) {
        attacking_right_point.occupied_by->enemy_attacking_point = 0;
    }
    if (attacking_right_top_point.occupied_by != 0) {
        attacking_right_top_point.occupied_by->enemy_attacking_point = 0;
    }
    if (attacking_right_bottom_point.occupied_by != 0) {
        attacking_right_bottom_point.occupied_by->enemy_attacking_point = 0;
    }

    if (attacking_left_point.occupied_by != 0) {
        attacking_left_point.occupied_by->enemy_attacking_point = 0;
    }
    if (attacking_left_top_point.occupied_by != 0) {
        attacking_left_top_point.occupied_by->enemy_attacking_point = 0;
    }
    if (attacking_left_bottom_point.occupied_by != 0) {
        attacking_left_bottom_point.occupied_by->enemy_attacking_point = 0;
    }
    //    while (!attackingPoints.isEmpty()) {
    //        delete attackingPoints.takeFirst();
    //    }
}

#ifdef characterbuilder
void character_base::load_from_xml(QString xml_file_name, skeltal_hbox* root) {
#else
void character_base::load_from_xml(QString xml_file_name) {
#endif

    player_xml_file = xml_file_name;
    enemy_attacking_point = 0;
    if (screenScale == 0) {
        screenScale = Director::sharedDirector()->winSizeInPixels().width() / origwallw;
    }

    //request an id from the game controller
    char_id = game_controller::sharedGameController()->request_new_id();

    alreadyDead = false;
    animatedWhenAttaqcked = true;
    Super_Attacking = false;
    currentAnimationTime = 0;
    super_character_q = 0;
    super_weapon_q = 0;
    local_speed = 1;
    local_speed = 1;
    number_of_freezes = 0;
    number_of_slow_downs = 0;
    charaacter_close_to_attack = false;
    currentAnimationName = "breathing";
    prevAnimationName = currentAnimationName;
    chtimer = new QTimer;
    chtimer->setInterval((1.0/frameRate)*1000.0);
    aimToAtttackChar = 0;
    animationRunning = false;
    moveToPoint.setX(Director::sharedDirector()->winSizeInPixels().width()/2);
    moveToPoint.setY(Director::sharedDirector()->winSizeInPixels().height()/2);
    tryingtochangeanimation = false;
    QDomDocument xmlDocument;
    QFile openxml(xml_file_name);

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("Error, can't read") + xml_file_name + " Please contact us with a screen shot, or a copy of this error message";
        box.setText(messagetext);
        box.exec();
    } else {

        xmlDocument.setContent(&openxml);

        QDomElement document = xmlDocument.documentElement();

        character_type = document.attribute("type");
        character_name = document.attribute("name");
        below_char_elements_y_offset = document.attribute("circule-y-offset").toFloat() * screenScale;
        character_speed = document.attribute("speed").toFloat() * screenScale;
        maxHealth = document.attribute("health").toFloat();
        if (computer_player) {
            maxHealth /= 5;
        }
        if (!computer_player) {
            myLevel = shared_storage::sharedGameStorage()->getPlayerLevel(player_xml_file);
        }
        maxHealth *= myLevel;

        //load the mainweapon for the character
        mainWeapon = new weapon;
        if (computer_player) {
            weapon_xml = document.attribute("w1-xml");
        } else {
            weapon_xml = shared_storage::sharedGameStorage()->getWeaponForCharacter(xml_file_name);
        }

        //loading character super attack
        QString super_attack_xml = document.attribute("super-attack-xml");
        if (super_attack_xml.contains(".xml")) {
            super_attack_weapon = new weapon;
            game_controller::sharedGameController()->mainPlayLayer->addChild(super_attack_weapon);
            super_attack_weapon->load_from_xml(super_attack_xml,this,this,SLOT(q_char_super()));
        }


        //load the super attack effect
        super_attack_effect_weapon = new weapon;
        addChild(super_attack_effect_weapon);
        super_attack_effect_weapon->load_from_xml("super_energy_weapon.xml",this,0,0);
        connect(super_attack_effect_weapon,SIGNAL(effect_finished()),this,SLOT(start_weapon_super_2()),Qt::UniqueConnection);


        //load the super attack effect
        super_attack_effect_character = new weapon;
        addChild(super_attack_effect_character);
        super_attack_effect_character->load_from_xml("super_energy_character.xml",this,0,0);
        connect(super_attack_effect_character,SIGNAL(effect_finished()),this,SLOT(start_char_super_2()),Qt::UniqueConnection);

        QDomElement eye;

        //use the eye element to load into it the first, or root joint
        eye = document.namedItem("joint").toElement();

        rootJoint = new skeltal_joint;
        rootJoint->characterPointer = this;
        addChild(rootJoint);
#ifdef characterbuilder
        rootJoint->loadFromQDomElement(&eye,root);
#else
        rootJoint->loadFromQDomElement(&eye);
#endif
        openxml.close();
        for (int i = 0; i < rootJoint->animationsList.size(); i++) {
            rootJoint->setMaxAnimationTime(i,rootJoint->animationsList.at(i)->animation_steps.last().end_time);
        }

        myHealthBar = new health_bar(screenScale);
        addChild(myHealthBar);
        myHealthBar->setPos(0,(160 * screenScale));
        myHealthBar->setMaxValue(maxHealth * (1.0 + (myLevel/decreaseHealLevelFix)));

        if (computer_player) {
            myHealthBar->setXPBarHidden();
        }

        myHealthBar->setXPMaxValue(shared_storage::sharedGameStorage()->getMaxXPforPlayer(xml_file_name));
        myHealthBar->setXPLevel(shared_storage::sharedGameStorage()->getPlayerXP(xml_file_name));


        dieEffect = new die_and_join_effect;
        dieEffect->character_parent = this;
        game_controller::sharedGameController()->mainPlayLayer->addChild(dieEffect);
        //this is for testing, this is y offset in character
        //        below_char_elements_y_offset = 200;
        if (!computer_player) {
            armor = new human_char_arrow(below_char_elements_y_offset,pointer_file_name);
            armor->pointToChar(this);
        } else {
            armor = 0;
        }

        //adding the attacking points

        //first, three points on the left
        //left point
        attacking_left_point.left = true;
        attacking_left_point.occupied = false;
        attacking_left_point.point.setX(-attacking_horizontal_distance);
        attacking_left_point.point.setY(0);
        //left top point
        attacking_left_top_point.left = true;
        attacking_left_top_point.occupied = false;
        attacking_left_top_point.point.setX(attacking_horizontal_corner_spacing - attacking_horizontal_distance);
        attacking_left_top_point.point.setY(attacking_vertical_distance);
        //left bottom point
        attacking_left_bottom_point.left = true;
        attacking_left_bottom_point.occupied = false;
        attacking_left_bottom_point.point.setX(attacking_horizontal_corner_spacing - attacking_horizontal_distance);
        attacking_left_bottom_point.point.setY(-attacking_vertical_distance);

        //adding the three points on the right
        //right point
        attacking_right_point.left = false;
        attacking_right_point.occupied = false;
        attacking_right_point.point.setX(attacking_horizontal_distance);
        attacking_right_point.point.setY(0);
        //right top point
        attacking_right_top_point.left = false;
        attacking_right_top_point.occupied = false;
        attacking_right_top_point.point.setX(attacking_horizontal_distance - attacking_horizontal_corner_spacing);
        attacking_right_top_point.point.setY(attacking_vertical_distance);
        //right bottom point
        attacking_right_bottom_point.left = false;
        attacking_right_bottom_point.occupied = false;
        attacking_right_bottom_point.point.setX(attacking_horizontal_distance - attacking_horizontal_corner_spacing);
        attacking_right_bottom_point.point.setY(-attacking_vertical_distance);

        //resetting the occupied by to 0s
        attacking_right_point.occupied_by = 0;
        attacking_right_top_point.occupied_by = 0;
        attacking_right_bottom_point.occupied_by = 0;

        attacking_left_point.occupied_by = 0;
        attacking_left_top_point.occupied_by = 0;
        attacking_left_bottom_point.occupied_by = 0;


    }
}

void character_base::setAnimationType(QString animationType, bool savePre) {

//    qDebug() << "Character name " << character_name << " is computer " << computer_player;
//    qDebug() << "Changing animation from " << currentAnimationName << " to " << animationType;
    disconnect(SIGNAL(stepChildsAnimation(double)));
    disconnect(SIGNAL(one_animation_round_done()));
    bool found = false;
    for (int i = 0; i < rootJoint->animationsList.size()  && !found; i++) {
        if (rootJoint->animationsList.at(i)->animation_name == animationType) {
            currentAnimationIndex = i;
            found = true;
        }
    }
    if (found) {
        if (currentAnimationName == "attacking") {
            if (aimToAtttackChar != 0) {
                if (enemy_attacking_point != NULL) {
                if (enemy_attacking_point->occupied_by == this) {
#ifdef DEBUG_ATTACKING_POINTS
                    qDebug() << "---Detaching point---";
                    qDebug() << "From name      : " << aimToAtttackChar->character_name;
                    qDebug() << "From ID        : " << aimToAtttackChar->char_id;
                    qDebug() << "Character name : " << character_name;
                    qDebug() << "Character ID   : " << char_id;
                    qDebug() << "Point to detach: " << enemy_attacking_point->point;
#endif
                    enemy_attacking_point->occupied = false;
                    enemy_attacking_point->occupied_by = 0;
                }
            }
            }
        }
        if (savePre) {
//            qDebug() << "Saving prev animation enabled";
            if (!prevAnimationName.contains("super",Qt::CaseInsensitive)) {
//                qDebug() << "prev animation saved";
                prevAnimationName = currentAnimationName;
            }
        }
        currentAnimationName = rootJoint->animationsList.at(currentAnimationIndex)->animation_name;
        rootJoint->setAnimationIndex(currentAnimationIndex);
    }


    emit animationChaned();
    disconnect(SIGNAL(animationChaned()));

//    qDebug() << "New Animation applied";
//    qDebug() << "Current animation: " << currentAnimationName;
//    qDebug() << "Prev animation: " << prevAnimationName;
}

void character_base::set_animtion_at_point(QString animationType, float key_point) {
    bool found = false;
    for (int i = 0; i < rootJoint->animationsList.size()  && !found; i++) {
        if (rootJoint->animationsList.at(i)->animation_name == animationType) {
            currentAnimationIndex = i;
            found = true;
        }
    }
    if (found) {
        //animation is found, now let's try to set the shape of me to that point
        stopAnimation();
        rootJoint->set_animtion_at_point(currentAnimationIndex,key_point);
        setEffectiveRotation();
    }
}

void character_base::moveto(float x, float y) {

    //if am telling my character to move to somewhere, I don't want it to point to any other character
    resetPointedToEnemy();
    //      not used anymore due to new armor feature
    //    //first, add the circular y prefix
    //    y += below_char_elements_y_offset;

    //disconnection this signal from any other signal
    disconnect(SIGNAL(signal_check_move_done()));
    moveToPoint.setX(x);
    moveToPoint.setY(y);
    float xDist = x - pos().x();
    float yDist = y - pos().y();
    float dist = (xDist*xDist) + (yDist*yDist);
    dist = sqrt(dist);
    speedPoint.setX((xDist/dist)*character_speed);
    speedPoint.setY((yDist/dist)*character_speed);
    stopAnimation();
    setAnimationType("walking");
    connect(this,SIGNAL(stepChildsAnimation(double)),this,SLOT(walkingAnimationMover(double)));
    if (speedPoint.x() < 0) {
        setScaleX(-1);
        if (speedPoint.y() > 0) {
            connect(this,SIGNAL(signal_check_move_done()),this,SLOT(check_move_up_left()));
        } else {
            connect(this,SIGNAL(signal_check_move_done()),this,SLOT(check_move_down_left()));
        }
    } else {
        setScaleX(1);
        if (speedPoint.y() > 0) {
            connect(this,SIGNAL(signal_check_move_done()),this,SLOT(check_move_up_right()));
        } else {
            connect(this,SIGNAL(signal_check_move_done()),this,SLOT(check_move_down_right()));
        }
    }
    runAnimation();
}

//void character_base::setCurrentAnimationTime(double currentTime) {
//    if (!tryingtochangeanimation) {
//        tryingtochangeanimation = true;
//        while (currentTime > rootJoint->animationsList.at(currentAnimationIndex)->total_animation_time) {
//            currentTime -= rootJoint->animationsList.at(currentAnimationIndex)->total_animation_time;
//        }

//        float diffrence = currentTime - rootJoint->animationsList.at(currentAnimationIndex)->current_animation_time;
//        //    if (diffrence > 0) {
//        //        diffrence = rootJoint->animationsList.at(currentAnimationIndex)->current_animation_time - currentTime;
//        //    }
//        emit stepChildsAnimation( diffrence );
//        tryingtochangeanimation = false;
//    }
//}

void character_base::runAnimation() {
    if (number_of_freezes <= 0) {
        if (!animationRunning) {
            animationRunning = true;
            currentAnimationTime = 0;
            //        schedualUpdate();
            chdelta.restart();
            if (rootJoint->animationsList.at(currentAnimationIndex)->total_animation_time != 0) {
                chtimer->start();
                connect(chtimer,SIGNAL(timeout()),this,SLOT(chUpdate()),Qt::UniqueConnection);
            }
        }
    }
}

void character_base::stopAnimation() {
    if (animationRunning) {
        animationRunning = false;
        //        unSchedualUpdate();
        chdelta.restart();
        chtimer->stop();
        disconnect(chtimer,SIGNAL(timeout()),this,SLOT(chUpdate()));

    }
}

void character_base::update(double delta) {

    //    currentAnimationTime += delta;
    //    emit stepChildsAnimation(delta);
    //    setEffectiveRotation();
    //    if (currentAnimationTime > rootJoint->animationsList.at(currentAnimationIndex)->total_animation_time) {
    //        emit one_animation_round_done();
    //        currentAnimationTime -= rootJoint->animationsList.at(currentAnimationIndex)->total_animation_time;
    //    }
    //    while (currentAnimationTime > rootJoint->animationsList.at(currentAnimationIndex)->total_animation_time) {
    //        currentAnimationTime -= rootJoint->animationsList.at(currentAnimationIndex)->total_animation_time;
    //    }

}

void character_base::chUpdate() {

    double delta = chdelta.elapsed();
    chdelta.restart();
    delta /= 1000;
    if (computer_player) {
        delta *= game_controller::sharedGameController()->enemySpeed;
    } else {
        delta *= game_controller::sharedGameController()->playerSpeed;
    }
    delta *= local_speed;

    currentAnimationTime += delta;


    emit stepChildsAnimation(delta);

    setEffectiveRotation();
    if (currentAnimationTime > rootJoint->animationsList.at(currentAnimationIndex)->total_animation_time) {
        emit one_animation_round_done();
        currentAnimationTime -= rootJoint->animationsList.at(currentAnimationIndex)->total_animation_time;
    }
    while (currentAnimationTime > rootJoint->animationsList.at(currentAnimationIndex)->total_animation_time) {
        currentAnimationTime -= rootJoint->animationsList.at(currentAnimationIndex)->total_animation_time;
    }
}

void character_base::walkingAnimationMover(double delta) {
    QPointF nextPos = pos() + (speedPoint*delta);
    setIneffectivePos(nextPos);
    setZ(startZ - (nextPos.y() * 100));
//    qDebug() << "My z Level is " << z();
    emit signal_check_move_done();
}

void character_base::check_move_up_right() {
    if (pos().x() >= moveToPoint.x()) {
        if (pos().y() >= moveToPoint.y()) {
            stopAnimation();
            startBreathing();
            emit moveDone();
        }
    }
}

void character_base::check_move_up_left() {
    if (pos().x() <= moveToPoint.x()) {
        if (pos().y() >= moveToPoint.y()) {
            stopAnimation();
            startBreathing();
            emit moveDone();
        }
    }
}

void character_base::check_move_down_right() {
    if (pos().x() >= moveToPoint.x()) {
        if (pos().y() <= moveToPoint.y()) {
            stopAnimation();
            startBreathing();
            emit moveDone();
        }
    }
}

void character_base::check_move_down_left() {
    if (pos().x() <= moveToPoint.x()) {
        if (pos().y() <= moveToPoint.y()) {
            stopAnimation();
            startBreathing();
            emit moveDone();
        }
    }
}

void character_base::startBreathing() {
    setAnimationType("breathing");
    runAnimation();
}

void character_base::aim_to_char(character_base *character, bool attacking_point_skip) {
    if (!alreadyDead) {
        charaacter_close_to_attack = false;
        //remove myself from attachment to another character, or older character
        if (!attacking_point_skip) {
            if (aimToAtttackChar != 0) {
                if (enemy_attacking_point->occupied_by != 0) {
                    if (enemy_attacking_point->occupied_by->char_id == char_id) {
#ifdef DEBUG_ATTACKING_POINTS
                        qDebug() << "---Detaching point---";
                        qDebug() << "From name      : " << aimToAtttackChar->character_name;
                        qDebug() << "From ID        : " << aimToAtttackChar->char_id;
                        qDebug() << "Character name : " << character_name;
                        qDebug() << "Character ID   : " << char_id;
                        qDebug() << "Point to detach: " << enemy_attacking_point->point;
#endif
                        enemy_attacking_point->occupied = false;
                        enemy_attacking_point->occupied_by = 0;
                    }
                }
            }
        }
        aimToAtttackChar = character;
        emit aim_to_char_signal(character);
        run_all_queued_supers();
    }
}


void character_base::startEnemeyIntleegince() {
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    int randomValue;
    //set random hate values for all players in game
    for (int i = 0; i < game_controller::sharedGameController()->playerCharacters.size(); i++) {
        //real randomization
        randomValue = qrand() % 10;

        /* THE BELOW IF ELSE SHALL BE COMMENTED, IT'S FORCES THE RANDOM VALUES TO BE ON THE FIRST CHARACTER */
        //        if (i != 0) {
        //            randomValue = 0;
        //        } else {
        //            randomValue = 70;
        //        }
        /* COMMENT UP TO HERE */

        hateValues.append(randomValue * game_controller::sharedGameController()->playerCharacters.at(i)->myLevel);
    }

    selectMaxHatedCharacter();
}

void character_base::decreaseHealthBy(float value, character_base *fromCharacter) {
#ifndef characterbuilder
    if (!alreadyDead) {
        if (animatedWhenAttaqcked) {
            animatedWhenAttaqcked = false;
            //            QTimer::singleShot(1000,this,SLOT(setAnimateWhenAttacked()));
            setAnimationType("damaged");
            connect(this,SIGNAL(one_animation_round_done()),this,SLOT(damagedOneRoundDone()),Qt::UniqueConnection);
            runAnimation();
        }
        myHealthBar->decreaseHealthBy(value);
        numbers* damaged_numbers = numbers::layer();

        damaged_numbers->pre = "number_r_";
        game_controller::sharedGameController()->currentMap->addChild(damaged_numbers);
        damaged_numbers->setPos(pos().x(),pos().y() + die_red_numbers_y_offset);
//        damaged_numbers->setOpacity(100);
        damaged_numbers->setZ(200000);
        damaged_numbers->setScale(0.25);

        damaged_numbers->setNum(value,character_base::screenScale * die_red_numbers_scale);
        const float animation_time = 0.4;
        damaged_numbers->runSequence(Sequence::sequenceWithActions(action::fadeTo(animation_time/2,100),action::fadeTo(animation_time/2,0),NULL));
        damaged_numbers->runAction(action::easeinout(action::moveBy(animation_time,0,150*screenScale)));
        damaged_numbers->runAction(action::easeinout(action::scaleTo(animation_time,1)));

        if (myHealthBar->currentPercantageLevel() <= 0) {
            //am dead
            alreadyDead = true;
            stopAnimation();


            if (enemy_attacking_point != 0) {
                //release that point
                if (enemy_attacking_point->occupied_by == this) {
#ifdef DEBUG_ATTACKING_POINTS
                    qDebug() << "---Detaching point---";
                    qDebug() << "From name      : " << aimToAtttackChar->character_name;
                    qDebug() << "From ID        : " << aimToAtttackChar->char_id;
                    qDebug() << "Character name : " << character_name;
                    qDebug() << "Character ID   : " << char_id;
                    qDebug() << "Point to detach: " << enemy_attacking_point->point;
#endif
                    enemy_attacking_point->occupied_by = 0;
                    enemy_attacking_point->occupied = false;
                }
            }

            game_controller::sharedGameController()->removeAllConnectionToPlayer(this);
            if (computer_player) {
                game_controller::sharedGameController()->removeEnemyCharacter(this);
            }
            //            else {
            //                game_controller::sharedGameController()->removePlayerCharacter(this);
            //            }
            if (!computer_player) {
                armor->setOpacity(0);
            }
            number_of_freezes = 0;
            number_of_slow_downs = 0;
            setAnimationType("die");
            runAnimation();
            aimToAtttackChar = fromCharacter;
            connect(this,SIGNAL(one_animation_round_done()),this,SLOT(dieAnimationDone()),Qt::UniqueConnection);

        } else {
            if (hateValues.size() != 0) {
                for (int i = 0; i < game_controller::sharedGameController()->playerCharacters.size(); i++) {
                    if (game_controller::sharedGameController()->playerCharacters.at(i) == fromCharacter) {
                        float newValue = hateValues.at(i) + value;
                        hateValues.replace(i,newValue);
                    }
                }
                selectMaxHatedCharacter();
            } else {
                if (aimToAtttackChar == 0) {
                    if (!computer_player) {
                        if (currentAnimationName == "breathing") {
                            aim_to_char(fromCharacter);
                        }
                    }
                }
            }
        }
    }
#endif
}

void character_base::increaseHealthBy(float value) {
    myHealthBar->increaseHealthBy(value);
    game_controller::sharedGameController()->currentMap->total_xp_gained += value*healToXPRatio;
    game_controller::sharedGameController()->currentMap->total_silver_gained += value;
    shared_storage::sharedGameStorage()->increaseSilverBy(value);
    game_controller::sharedGameController()->currentMap->refreshDashBoard();
    if (shared_storage::sharedGameStorage()->increaseXPby(player_xml_file,value*healToXPRatio)) {
        //player level is changed
        myHealthBar->setXPMaxValue(shared_storage::sharedGameStorage()->getMaxXPforPlayer(player_xml_file));
        myLevel = shared_storage::sharedGameStorage()->getPlayerLevel(player_xml_file);
        characterLeveledUp();
    }
    myHealthBar->setXPLevel(shared_storage::sharedGameStorage()->getPlayerXP(player_xml_file));

    //here, damaged numbers represnts taking health

    numbers* damaged_numbers = numbers::layer();

    damaged_numbers->pre = "number_g_";
    game_controller::sharedGameController()->currentMap->addChild(damaged_numbers);
    damaged_numbers->setPos(pos().x(),pos().y() + die_red_numbers_y_offset + 150*screenScale);
//        damaged_numbers->setOpacity(100);
    damaged_numbers->setZ(200000);
    damaged_numbers->setScale(1.5);

    damaged_numbers->setNum(value,character_base::screenScale * die_red_numbers_scale);
    const float animation_time = 0.4;
    damaged_numbers->runSequence(Sequence::sequenceWithActions(action::fadeTo(animation_time/2,100),action::fadeTo(animation_time/2,0),NULL));
    damaged_numbers->runAction(action::easeinout(action::moveBy(animation_time,0,-150*screenScale)));
    damaged_numbers->runAction(action::easeinout(action::scaleTo(animation_time,0.5)));

}

void character_base::selectMaxHatedCharacter() {
    if (!isDead()) {
        if (!hateValues.isEmpty()) {
            //find the max index
            int maxIndex = 0;
            bool game_over = true;
            for (int i = 0; i < hateValues.size(); i++) {
                //                qDebug() << "Hate values for player " << game_controller::sharedGameController()->playerCharacters.at(i)->character_name << " hate value is " << hateValues.at(i);
                if (!game_controller::sharedGameController()->playerCharacters.at(i)->isDead()) {
                    //still some live characters
                    game_over = false;
                    if (hateValues.at(i) > hateValues.at(maxIndex)) {
                        maxIndex = i;
                    }
                }
            }
            if (game_over) {
                //we have won the game, no more characters are available
                maxIndex = -1;
                game_controller::sharedGameController()->currentMap->startLostGameOver();
            }

            //aim to the most hated character
            if (maxIndex >= 0 && maxIndex < game_controller::sharedGameController()->playerCharacters.size()) {
                if (game_controller::sharedGameController()->playerCharacters.at(maxIndex) != aimToAtttackChar || currentAnimationName != "attacking") {
                    aim_to_char(game_controller::sharedGameController()->playerCharacters.at(maxIndex));
                }
            } else {
                setAnimationType("breathing");
            }
        }
    }
}

void character_base::damagedOneRoundDone() {
    disconnect(this,SIGNAL(one_animation_round_done()),this,SLOT(damagedOneRoundDone()));
    restorePrevAnimation();
}

void character_base::restorePrevAnimation() {

    //    qDebug() << Q_FUNC_INFO << " prevAnimationName = " << prevAnimationName << " and current animation name = " << currentAnimationName;

    if (prevAnimationName == "walking") {
        if (aimToAtttackChar == 0) {
            moveto(moveToPoint.x(),moveToPoint.y());
        } else {
            aim_to_char(aimToAtttackChar);
        }
    } else if (prevAnimationName == "attacking") {
        if (aimToAtttackChar != 0) {
            aim_to_char(aimToAtttackChar);
        } else {
            setAnimationType("breathing");
        }
    } else {
        if (prevAnimationName.contains("super",Qt::CaseInsensitive)) {
            prevAnimationName = "breathing";
        }
        setAnimationType(prevAnimationName);
        runAnimation();
    }

    if (prevAnimationName == "damaged") {
        QTimer::singleShot(waitUntilNextDamagedAnimationTime,this,SLOT(setAnimateWhenAttacked()));
    }
}

bool character_base::isDead() {
    return alreadyDead;
}

void character_base::setAnimateWhenAttacked() {
    //if the character is super attacking, the effect will auto release itself once the super animation is done
    if (!Super_Attacking) {
        animatedWhenAttaqcked = true;
    }
}

void character_base::removeConnectionFromPlayer(character_base *fromCharacter) {
    if ( aimToAtttackChar == fromCharacter ) {
        stopAnimation();
        aimToAtttackChar = 0;
        if (computer_player) {
            for (int i = 0; i < game_controller::sharedGameController()->playerCharacters.size(); i++) {
                if (game_controller::sharedGameController()->playerCharacters.at(i) == fromCharacter) {
                    hateValues.replace(i,0);
                }
            }
            selectMaxHatedCharacter();
        } else {
            startBreathing();
            armor->glow_in_white(W_OUT_CIRCLE_GLOW);
        }
    }
}

void character_base::enterStage() {
    dieEffect->startEnterEffect();
}

void character_base::dieAnimationDone() {
    stopAnimation();
    //here we are re using aim to char pointer
    if (aimToAtttackChar != 0) {
        dieEffect->startDieEffect(aimToAtttackChar);
    }
}

//my point is the coming enemy point
attacking_point* character_base::get_nearest_free_point( character_base *requester) {
#ifdef DEBUG_ATTACKING_POINTS
    qDebug() << "---Attaching point---";
    qDebug() << "Requester name : " << requester->character_name;
    qDebug() << "Requester ID   : " << requester->char_id;
    qDebug() << "Character name : " << character_name;
    qDebug() << "Character ID   : " << char_id;
#endif

    attacking_point* attk_pnt_to_return = 0;
    QPointF diffrence = pos() - requester->pos();
    if (diffrence.x() > 0) {
        if (aimToAtttackChar != 0) {
            //if we're aiming at each other
            if (requester->aimToAtttackChar->char_id == char_id && aimToAtttackChar->char_id == requester->char_id) {
#ifdef DEBUG_ATTACKING_POINTS
                qDebug() << "---Aiming at each other---";
#endif
                //this character is aiming to me, and am aiming to him
                if (enemy_attacking_point->point == attacking_left_point.point) {
                    attk_pnt_to_return = &attacking_right_point;
                } else if (enemy_attacking_point->point == attacking_right_point.point) {
                    attk_pnt_to_return = &attacking_left_point;
                } else {
                    //a, pointing to the wrong point, he should point to another point now

                    QTimer::singleShot(200,this,SLOT(re_point_to_same()));
                    attk_pnt_to_return = &attacking_left_point;
                }

                if (attk_pnt_to_return->occupied) {
                    if (attk_pnt_to_return->occupied_by != 0) {
                        bool occupied_by_self = false;
                        if (attk_pnt_to_return->occupied_by->char_id == char_id) {
                            occupied_by_self = true;
                        }

                        if (!occupied_by_self) {
                            character_base* temp = attk_pnt_to_return->occupied_by;
                            if (temp->char_id != requester->char_id) {
                                //the point is not occupied by the requester
                                attk_pnt_to_return->occupied_by = requester;
#ifdef DEBUG_ATTACKING_POINTS
                                qDebug() << "---200ms to repoint---";
                                qDebug() << "Temp name      : " << temp->character_name;
                                qDebug() << "Temp ID        : " << temp->char_id;
#endif
                                QTimer::singleShot(200,temp,SLOT(re_point_to_same()));
                            }
                        }
                    }
                    attk_pnt_to_return->occupied_by = requester;
                    attk_pnt_to_return->occupied = true;
                    return attk_pnt_to_return;
                } else {
                    attk_pnt_to_return->occupied_by = requester;
                    attk_pnt_to_return->occupied = true;
                    return attk_pnt_to_return;
                }
            }
        }

        if (diffrence.y() > 0) {

            attk_pnt_to_return = &attacking_left_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_right_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_left_bottom_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_left_top_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_right_bottom_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_right_top_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

        } else {

            attk_pnt_to_return = &attacking_left_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_right_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_left_top_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_left_bottom_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_right_top_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_right_bottom_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }
        }
    } else {
        if (aimToAtttackChar != 0) {
            //if we're aiming at each other
            if (requester->aimToAtttackChar->char_id == char_id && aimToAtttackChar->char_id == requester->char_id) {
#ifdef DEBUG_ATTACKING_POINTS
                qDebug() << "---Aiming at each other---";
#endif
                //this character is aiming to me, and am aiming to him
                if (enemy_attacking_point->point == attacking_left_point.point) {
                    attk_pnt_to_return = &attacking_right_point;
                } else if (enemy_attacking_point->point == attacking_right_point.point) {
                    attk_pnt_to_return = &attacking_left_point;
                } else {
                    //a, pointing to the wrong point, he should point to another point now

                    QTimer::singleShot(200,this,SLOT(re_point_to_same()));
                    attk_pnt_to_return = &attacking_right_point;
                }

                if (attk_pnt_to_return->occupied) {
                    if (attk_pnt_to_return->occupied_by != 0) {
                        bool occupied_by_self = false;
                        if (attk_pnt_to_return->occupied_by->char_id == char_id) {
                            occupied_by_self = true;
                        }

                        if (!occupied_by_self) {
                            character_base* temp = attk_pnt_to_return->occupied_by;
                            if (temp->char_id != requester->char_id) {
                                //the point is not occupied by the requester
                                attk_pnt_to_return->occupied_by = requester;
#ifdef DEBUG_ATTACKING_POINTS
                                qDebug() << "---200ms to repoint---";
                                qDebug() << "Temp name      : " << temp->character_name;
                                qDebug() << "Temp ID        : " << temp->char_id;
#endif
                                QTimer::singleShot(200,temp,SLOT(re_point_to_same()));
                            }
                        }
                    }
                    attk_pnt_to_return->occupied_by = requester;
                    attk_pnt_to_return->occupied = true;
                    return attk_pnt_to_return;
                } else {
                    attk_pnt_to_return->occupied_by = requester;
                    attk_pnt_to_return->occupied = true;
                    return attk_pnt_to_return;
                }
            }
        }

        if (diffrence.y() > 0) {

            attk_pnt_to_return = &attacking_right_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_left_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_right_bottom_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_right_top_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_left_bottom_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_left_top_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

        } else {

            attk_pnt_to_return = &attacking_right_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_left_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_right_top_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_right_bottom_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_left_top_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }

            attk_pnt_to_return = &attacking_left_bottom_point;
            if (!attk_pnt_to_return->occupied) {
                if ((attk_pnt_to_return->point.x() + pos().x()) > human_char_arrow::topLeft.x() && (attk_pnt_to_return->point.x() + pos().x()) < human_char_arrow::bottomRight.x()) {
                    attk_pnt_to_return->occupied = true;
                    attk_pnt_to_return->occupied_by = requester;
                    return attk_pnt_to_return;
                }
            }
        }
    }
    //if the return value is 0, that means no more spaces are available, this case should be impossible to happen, but this is just in case
    return attk_pnt_to_return;
}

//run all queued supers
void character_base::run_all_queued_supers() {
#ifdef characterbuilder
    run_queded_super_attacks();
#else
    if (!computer_player) {
        //    if (mainWeapon->canFireFromFarAway || currentAnimationName == "attacking") {
        run_queded_super_attacks();
        //    } else {
        if (super_weapon_q != 0 || super_character_q != 0) {
            connect(this,SIGNAL(character_close_to_attack()),this,SLOT(run_queded_super_attacks()),Qt::UniqueConnection);
        }
    }
    //    }
#endif
}

void character_base::resetPointedToEnemy() {
    aimToAtttackChar = 0;
}



//start weapon super attack to q
void character_base::q_weapon_super() {
    mainWeapon->super_attack_object->disable_super_button();
    super_weapon_q++;
    run_all_queued_supers();
}

//super generic effect starts (Character provoke)
void character_base::start_weapon_super() {
    super_attack_lock();
    super_attack_effect_weapon->startBeforeEffect(pos().x(),pos().y(),scaleX(),pos().x(),pos().y(),scaleX());
    game_controller::sharedGameController()->currentMap->start_shaking_screen();
}

//custom effect start
void character_base::start_weapon_super_2() {
    if (aimToAtttackChar != 0 || mainWeapon->super_attack_object->super_affects_all) {
        if (aimToAtttackChar != 0) {
            super_aimToAtttackChar_weapon = aimToAtttackChar;
        } else {
            super_aimToAtttackChar_weapon = this;
        }
        stopAnimation();
        setAnimationType("superw",DONT_SAVE_PREV);
        runAnimation();
        mainWeapon->super_attack_object->startBeforeEffect(super_aimToAtttackChar_weapon->pos().x(),super_aimToAtttackChar_weapon->pos().y(),scaleX(),pos().x(),pos().y(),scaleX());
        connect(mainWeapon->super_attack_object,SIGNAL(effect_finished()),this,SLOT(finish_weapon_super()),Qt::UniqueConnection);
        QTimer::singleShot(1000*mainWeapon->super_attack_object->maxTime*0.5,this,SLOT(decrease_hp_weapon_super()));
    }
}

//add super character effect to q
void character_base::q_char_super() {
    super_attack_weapon->disable_super_button();
    super_character_q++;
    run_all_queued_supers();
}

//super generic effect starts (Character provoke)
void character_base::start_char_super() {
    super_attack_lock();
    super_attack_effect_character->startBeforeEffect(pos().x(),pos().y(),scaleX(),pos().x(),pos().y(),scaleX());
    game_controller::sharedGameController()->currentMap->start_shaking_screen();
}

//custom effect start
void character_base::start_char_super_2() {
    if (aimToAtttackChar != 0 || super_attack_weapon->super_affects_all) {
        if (aimToAtttackChar != 0) {
            super_aimToAtttackChar_character = aimToAtttackChar;
        } else {
            super_aimToAtttackChar_character = this;
        }

        stopAnimation();
        setAnimationType("superc",DONT_SAVE_PREV);
        runAnimation();
        super_attack_weapon->startBeforeEffect(super_aimToAtttackChar_character->pos().x(),super_aimToAtttackChar_character->pos().y(),scaleX(),pos().x(),pos().y(),scaleX());
        connect(super_attack_weapon,SIGNAL(effect_finished()),this,SLOT(finish_char_super()),Qt::UniqueConnection);
        QTimer::singleShot(1000*super_attack_weapon->maxTime*0.5,this,SLOT(decrease_hp_char_super()));
    }
}

void character_base::finish_char_super() {
    super_attack_release();
}
void character_base::finish_weapon_super() {
    super_attack_release();
}

void character_base::decrease_hp_char_super() {
    //remove some of character health
    if (super_aimToAtttackChar_character != 0 && super_aimToAtttackChar_character != this) {
        super_aimToAtttackChar_character->decreaseHealthBy((1.0 + (myLevel/decreaseHealLevelFix)) * super_attack_weapon->weapon_power, this);
    } else if (super_attack_weapon->super_affects_all) {
        for (int i = 0; i < game_controller::sharedGameController()->enemyCharacters.size(); i++) {
            if (!game_controller::sharedGameController()->enemyCharacters.at(i)->isDead()) {
                game_controller::sharedGameController()->enemyCharacters.at(i)->decreaseHealthBy((1.0 + (myLevel/decreaseHealLevelFix)) * super_attack_weapon->weapon_power, this);
            }
        }
    }

    s_attk_obj* object = super_attack_weapon->get_new_super_attack_object();
    object->weapon_super = false;
    object->start_effect(this);

}

void character_base::decrease_hp_weapon_super() {
    //remove some of character health
    if (super_aimToAtttackChar_weapon != 0 && super_aimToAtttackChar_weapon != this) {
        super_aimToAtttackChar_weapon->decreaseHealthBy((1.0 + (myLevel/decreaseHealLevelFix)) * mainWeapon->super_attack_object->weapon_power, this);
    } else if (mainWeapon->super_attack_object->super_affects_all) {
        for (int i = 0; i < game_controller::sharedGameController()->enemyCharacters.size(); i++) {
            if (!game_controller::sharedGameController()->enemyCharacters.at(i)->isDead()) {
                game_controller::sharedGameController()->enemyCharacters.at(i)->decreaseHealthBy((1.0 + (myLevel/decreaseHealLevelFix)) * mainWeapon->super_attack_object->weapon_power, this);
            }
        }
    }

    s_attk_obj* object = mainWeapon->super_attack_object->get_new_super_attack_object();
    object->weapon_super = true;
    object->start_effect(this);
}

bool character_base::run_queded_super_attacks() {
    bool super_attack_started = false;
    if ( (aimToAtttackChar != 0 && charaacter_close_to_attack) || super_attack_weapon->super_affects_all) {
        //run all the supers waiting in queue
        while (super_character_q > 0) {
            super_attack_started = true;
            super_character_q--;
            start_char_super();
        }
    }
    if ( (aimToAtttackChar != 0 && charaacter_close_to_attack) || mainWeapon->super_attack_object->super_affects_all) {
        while (super_weapon_q > 0) {
            super_attack_started = true;
            super_weapon_q--;
            start_weapon_super();
        }
    }
    if (super_weapon_q == 0 && super_character_q == 0) {
        //disconnect to not waste resources
        disconnect(this,SIGNAL(character_close_to_attack()),this,SLOT(run_queded_super_attacks()));
    }
    return super_attack_started;
}


void character_base::super_attack_release() {
    Super_Attacking = false;
    animatedWhenAttaqcked = true;
    restorePrevAnimation();
}

void character_base::characterLeveledUp() {
    //myLevel shall be updated before calling this methode
    numbers* level_numbers = numbers::layer();

    level_numbers->pre = "number_";
    game_controller::sharedGameController()->currentMap->addChild(level_numbers);
    level_numbers->setPos(pos().x(),pos().y() + die_red_numbers_y_offset + 150*screenScale);
    level_numbers->setOpacity(0);
    level_numbers->setZ(200000);

    level_numbers->setNum(myLevel,character_base::screenScale * 1.5);
    float animation_time = 3;
    level_numbers->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.3,100),action::fadeTo(animation_time/4*3,0),NULL));


//    animation_time = 1;

    Sprite* wing_r = Sprite::spriteWithSvg("wing.svg",screenScale/2);
    game_controller::sharedGameController()->currentMap->addChild(wing_r);
    wing_r->setPos(pos().x() + (30*screenScale),pos().y() + die_red_numbers_y_offset + 150*screenScale);
    wing_r->setOpacity(0);
    wing_r->setZ(200000);
    wing_r->setAnchor(0,1);
    wing_r->setRotation(180);

    wing_r->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.3,100),action::fadeTo(animation_time/4*3,0),NULL));
    wing_r->runAction(action::easCurve(action::rotateTo(animation_time*2,0),QEasingCurve::OutElastic));


    Sprite* wing_l = Sprite::spriteWithSvg("wing.svg",screenScale/2);
    game_controller::sharedGameController()->currentMap->addChild(wing_l);
    wing_l->setPos(pos().x() - (30*screenScale),pos().y() + die_red_numbers_y_offset + 150*screenScale);
    wing_l->setOpacity(0);
    wing_l->setZ(200000);
    wing_l->setAnchor(0,1);
    wing_l->setScaleX(-1);
    wing_l->setRotation(180);

    wing_l->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.3,100),action::fadeTo(animation_time/4*3,0),NULL));
    wing_l->runAction(action::easCurve(action::rotateTo(animation_time*2,0),QEasingCurve::OutElastic));


    level_numbers->runAction(action::moveBy(animation_time,0,50*screenScale));
    wing_l->runAction(action::moveBy(animation_time,0,50*screenScale));
    wing_r->runAction(action::moveBy(animation_time,0,50*screenScale));

}

void character_base::super_attack_lock() {
#ifdef characterbuilder
    if (true) {
#else
    if (!Super_Attacking) {
#endif
        animatedWhenAttaqcked = false;
        Super_Attacking = true;
        stopAnimation();
        setAnimationType("super");
        runAnimation();
    }
}

void character_base::slow_down_character() {
    if (!alreadyDead) {
        number_of_slow_downs++;
        local_speed *= 0.5;
    }
}
void character_base::un_slow_down_character() {
    number_of_slow_downs--;
#ifdef debug_super_effect_damage
    qDebug() << "Number of slow downs for character " << character_name << " is " << number_of_slow_downs;
#endif
    local_speed /= 0.5;
    if (local_speed > 1) {
        local_speed = 1;
    }
#ifdef debug_super_effect_damage
    qDebug() << "Walking speed for slow downs for character " << character_name << " is " << local_speed;
#endif
}

void character_base::re_point_to_same() {
    if (aimToAtttackChar != 0) {
        aim_to_char(aimToAtttackChar);
    }
}

void character_base::resetPlayerHealth() {
    myHealthBar->increaseHealthBy(myHealthBar->getMaxValue()/2);
}

void character_base::resetPlayerSuper() {
    super_attack_weapon->total_time_since_disabled = 0;
    mainWeapon->super_attack_object->total_time_since_disabled = 0;
}

void character_base::freeze_character() {
    if (!alreadyDead) {
        number_of_freezes++;
        local_speed = 0;
    }
}

void character_base::un_freeze_character() {
    number_of_freezes--;
#ifdef debug_super_effect_damage
    qDebug() << "Number of freezes for character " << character_name << " is " << number_of_freezes;
#endif
    if (number_of_freezes <= 0) {
        local_speed = 1;
    }
}
