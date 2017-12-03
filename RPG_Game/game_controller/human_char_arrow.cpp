#include "human_char_arrow.h"
#include "map.h"

//#define blurHint QGraphicsBlurEffect::QualityHint
#define blurHint QGraphicsBlurEffect::PerformanceHint
//#define blurHint QGraphicsBlurEffect::AnimationHint
QPointF human_char_arrow::topLeft;
QPointF human_char_arrow::bottomRight;


human_char_arrow::human_char_arrow(float margine_top, QString pointer_file) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    ignoreZLevel = false;
    if (game_controller::sharedGameController()->currentMap != 0) {
        game_controller::sharedGameController()->currentMap->addChild(this);
    }

    attachedChar = 0;
    pointedChar = 0;
    white_glowing = true;

    float screenScale = Director::sharedDirector()->winSizeInPixels().width()/origwallw;

    //set up the movement region
    topLeft.setX((Director::sharedDirector()->winSizeInPixels().width()/2) - (end_x_offset));
    topLeft.setY((Director::sharedDirector()->winSizeInPixels().height()/2) + (end_y_offset));
    bottomRight.setX((Director::sharedDirector()->winSizeInPixels().width()/2) + (end_x_offset));
    bottomRight.setY((Director::sharedDirector()->winSizeInPixels().height()/2) - (end_y_offset));

    armor_w_1 = Sprite::spriteWithSvg("pointer_white.svg", character_base::screenScale);
    armor_w_2 = Sprite::spriteWithSvg("pointer_white.svg", character_base::screenScale);

//    QGraphicsBlurEffect* blur = new QGraphicsBlurEffect();
//    blur->setBlurHints(blurHint);
//    blur->setBlurRadius(glowing_armor_blur_radius);
//    armor_w_1->setGraphicsEffect(blur);

//    blur = new QGraphicsBlurEffect();
//    blur->setBlurHints(blurHint);
//    blur->setBlurRadius(glowing_armor_blur_radius);
//    armor_w_2->setGraphicsEffect(blur);

    armor_r_1 = Sprite::spriteWithSvg(QString("glow_" + pointer_file), character_base::screenScale);
    armor_r_2 = Sprite::spriteWithSvg(QString("glow_" + pointer_file), character_base::screenScale);

//    blur = new QGraphicsBlurEffect();
//    blur->setBlurHints(blurHint);
//    blur->setBlurRadius(glowing_armor_blur_radius);
//    armor_r_1->setGraphicsEffect(blur);

//    blur = new QGraphicsBlurEffect();
//    blur->setBlurHints(blurHint);
//    blur->setBlurRadius(glowing_armor_blur_radius);
//    armor_r_2->setGraphicsEffect(blur);


    armor_c_white = Sprite::spriteWithSvg("armor_c.svg", character_base::screenScale);
    armor_c_red = Sprite::spriteWithSvg("armor_c_red.svg", character_base::screenScale);

    armor = Sprite::spriteWithSvg(pointer_file, character_base::screenScale);

    addChild(armor_c_white);
    addChild(armor_c_red);

    addChild(armor_r_1);
    addChild(armor_w_1);
    addChild(armor_r_2);
    addChild(armor_w_2);
    addChild(armor);


    armor_w_2->setOpacity(0);
    armor_r_2->setOpacity(0);
    armor_r_1->setOpacity(0);

    //adding nodes to be moving up from the character
    nodes_synced_w_armor.append(armor);
    nodes_synced_w_armor.append(armor_w_1);
    add_glowing_element(armor_w_1);
    armor_c_white->setZ(-202);
    armor_c_white->setScale(0);

    armor_c_red->setZ(-202);
    armor_c_red->setScale(0);
    //    setPos(0,Director::sharedDirector()->winSizeInPixels().height());
    margine_top_local = margine_top;
    armor->setAnchor(0.5,0.9);
    armor_w_1->setAnchor(0.5,0.9);
    armor_w_2->setAnchor(0.5,0.9);
    armor_r_1->setAnchor(0.5,0.9);
    armor_r_2->setAnchor(0.5,0.9);

//    setZ(1000);
    first_is_first = true;
    armor_w_1_node = armor_w_1;
    armor_w_2_node = armor_w_2;
    first_is_first_red = true;
    armor_r_1_node = armor_r_1;
    armor_r_2_node = armor_r_2;

    //by default, the white circule is showen, once pointing to an enemy, the red circle shall be showen
    armor_c = armor_c_white;

    //    QTimer::singleShot(0.2*1000,this,SLOT(glow_in_red()));
}

human_char_arrow::~human_char_arrow() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    while (!glowing_elements.isEmpty()) {
        delete glowing_elements.takeFirst();
    }
}

void human_char_arrow::attachToChar(character_base *toBeAttachedTo) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    if (attachedChar != 0) {
        //dissconnect it from attached char
        disconnect(attachedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(attachedCharPosChanges()));
    }

    attachedChar = toBeAttachedTo;
    glow_in_red();

    //connect the parent character to any character changes
    connect(attachedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(attachedCharPosChanges()),Qt::UniqueConnection);
    attachedCharPosChanges();
}

void human_char_arrow::pointToChar(character_base *toBeAttachedTo) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

//    if (pointedChar != 0) {
//        //dissconnect it from attached char
//        disconnect(pointedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(pointedCharPosChanges()));
//    }

    pointedChar = toBeAttachedTo;

    //connect the parent character to any character changes
    connect(pointedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(pointedCharPosChanges()),Qt::UniqueConnection);
    pointedCharPosChanges();
//    startFlashing();
}

void human_char_arrow::removePointedChar(bool circule) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    glow_in_white(circule);
    if (attachedChar != 0) {
        //dissconnect it from attached char
        disconnect(attachedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(attachedCharPosChanges()));
        attachedChar = 0;
    }
//    stopFlashing();
}

void human_char_arrow::setStart(float x, float y) {
//    belowLine->setLineEndPoints(x,y,belowLine->x2(),belowLine->y2());
//    aboveLine->setLineEndPoints(x,y,aboveLine->x2(),aboveLine->y2());
}

void human_char_arrow::setEnd(float x, float y) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    setEndUpdate(x,y);

    if  (x < topLeft.x()) {
        x = topLeft.x();
    } else if (x > bottomRight.x()) {
        x = bottomRight.x();
    }
    if  (y > topLeft.y()) {
        y = topLeft.y();
    } else if (y < bottomRight.y()) {
        y = bottomRight.y();
    }

    armor_c->setPos(x,y);
    if (!ignoreZLevel) {
        armor_c->setZ(startZ - (y * 102));
    }
}

void human_char_arrow::setEndUpdate(float x, float y) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

//    belowLine->setLineEndPoints(belowLine->x1(),belowLine->y1(),x,y);
//    aboveLine->setLineEndPoints(aboveLine->x1(),aboveLine->y1(),x,y);
//    belowElips->setPos(x,y);
//    abovevElips->setPos(x,y);
//    armor->setPos(x,y + (margine_top_local * character_base::screenScale));
    for (int i = 0; i < nodes_synced_w_armor.size(); i++) {
        nodes_synced_w_armor.at(i)->setPos(x,y + (margine_top_local));
        if (!ignoreZLevel) {
            nodes_synced_w_armor.at(i)->setZ(startZ - (y * 100));
        }
    }
}

//if we want to move the current character to that position, pass true, pass false to just hide the arrow
void human_char_arrow::hideArrow(bool move) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    if (move) {
        if (attachedChar != 0) {
            pointedChar->aim_to_char(attachedChar);
        } else {
            pointedChar->moveto(armor_c->pos().x(),armor_c->pos().y());
        }
    }

    if (attachedChar != 0) {
        //dissconnect it from attached char
        disconnect(attachedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(attachedCharPosChanges()));
        attachedChar = 0;
    }

//    if (pointedChar != 0) {
//        //dissconnect it from attached char
//        disconnect(pointedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(pointedCharPosChanges()));
//    }

    stopFlashing();

//    changeGlowMutex.lock();
    if (white_glowing) {
        start_bounce_effect();
        remove_glowing_element(armor_r_1_node);
        remove_glowing_element(armor_r_2_node);
    } else {
        start_red_teleport();
        remove_glowing_element(armor_w_1_node);
        remove_glowing_element(armor_w_2_node);
    }
//    changeGlowMutex.unlock();

//    runAction(action::fadeTo(0.1,0));
}

void human_char_arrow::showArrow() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    disconnect(pointedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(pointedCharPosChanges()));
    armor_c->stopAllActions();
    armor_c->setScale(1);
    armor_c->setOpacity(100);
    stopAllActions();
    setOpacity(100);
    startFlashing();
}

void human_char_arrow::startFlashing() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

//    schedualUpdate();
    add_glowing_element(armor_c);
}

void human_char_arrow::stopFlashing() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

//    unSchedualUpdate();
//    setOpacity(100);
    remove_glowing_element(armor_c);
}

QPointF human_char_arrow::armor_c_pos() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    return armor_c_white->pos();
}

void human_char_arrow::setIgnoreZ(bool ignore) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    ignoreZLevel = ignore;
    armor_c_white->setZ(-202);
    armor_c_red->setZ(-202);

}

void human_char_arrow::attachedCharPosChanges() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    setEnd(attachedChar->pos().x(),attachedChar->pos().y());
}

void human_char_arrow::pointedCharPosChanges() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    setEndUpdate(pointedChar->pos().x(),pointedChar->pos().y());
}

void human_char_arrow::update(double delta) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    //in this update methode, we're going to make the elements glow
    for (int i = 0; i < glowing_elements.size(); i++) {
        if (glowing_elements.at(i)->increasing) {
            //increase the opacity
            glowing_elements.at(i)->glowing_node->setOpacity(glowing_elements.at(i)->glowing_node->opacity() + (flashingSpeed*delta));
            if (glowing_elements.at(i)->glowing_node->opacity() > 100) {
                glowing_elements.at(i)->increasing = false;
            }
        } else {
            //decrease the opacity
            glowing_elements.at(i)->glowing_node->setOpacity(glowing_elements.at(i)->glowing_node->opacity() - (flashingSpeed*delta));
            if (glowing_elements.at(i)->glowing_node->opacity() < 0) {
                glowing_elements.at(i)->increasing = true;
            }
        }
    }
}

void human_char_arrow::start_bounce_effect() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

//    armor_c->setPos(armor->pos().x(),armor->pos().y() - (margine_top_local * character_base::screenScale));
    armor_c->runAction(action::easeinout(action::fadeTo(0.1,100)));

    float animation_time = 0.2;
    int easType = 4;
    remove_glowing_element(armor_w_1_node);
    armor_w_1_node->runAction(action::easeinout(action::fadeTo(0.3,100)));
    // - (margine_top_local * character_base::screenScale))
    armor_w_1_node->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveTo(animation_time,armor_c->pos().x(),armor_c->pos().y()),easType),action::FuncCall(this,SLOT(start_circle_effect())),NULL));

    nodes_synced_w_armor.removeAll(armor_w_1_node);
    nodes_synced_w_armor.removeAll(armor);

    // - (margine_top_local * character_base::screenScale))
    armor->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveTo(animation_time,armor_c->pos().x(),armor_c->pos().y()),easType),action::easeinout(action::fadeTo(0.3,0)),action::FuncCall(this,SLOT(start_teleport_effect())),NULL));

    connect(pointedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(pointedCharPosChanges()),Qt::UniqueConnection);

    nodes_synced_w_armor.append(armor_w_2_node);
    armor_w_2_node->setScale(1.5);
    armor_w_2_node->runAction(action::easeinout(action::scaleTo(0.3,1)));
    armor_w_2_node->runAction(action::easeinout(action::fadeTo(0.3,100)));

    swap_sprites();
}

void human_char_arrow::start_circle_effect() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    armor_c->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleTo(0.1,0)),action::easeinout(action::scaleTo(1,2)),NULL));
    armor_c->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.1,100)),action::easeinout(action::fadeTo(1,0)),NULL));
    //    armor_c->runAction(action::easeinout(action::fadeTo(1,0)));
    //    changeGlowMutex.unlock();
}

void human_char_arrow::start_teleport_effect() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    armor_w_2_node->runAction(action::easeinout(action::fadeTo(0.3,0)));
    armor_w_2_node->runAction(action::easeinout(action::scaleTo(0.3,1.5)));
    nodes_synced_w_armor.removeAll(armor);
    nodes_synced_w_armor.append(armor);
    armor->runAction(action::easeinout(action::fadeTo(0.3,100)));
//    changeGlowMutex.lock();
    if (white_glowing) {
        add_glowing_element(armor_w_1_node);
    }
//    changeGlowMutex.unlock();
}

void human_char_arrow::start_red_teleport() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    armor_c->setPos(armor->pos().x(),armor->pos().y() - (margine_top_local));
    armor_c->runAction(action::easeinout(action::fadeTo(0.1,100)));

    remove_glowing_element(armor_r_1_node);
    armor_r_1_node->stopAllActions();
    armor_r_1_node->stopAllActions();
    armor_r_1_node->stopAllActions();
    armor_r_1_node->runAction(action::easeinout(action::fadeTo(0.3,100)));
    start_circle_effect();
//    armor_r_1_node->runSequence(Sequence::sequenceWithActions(action::FuncCall(this,SLOT(start_circle_effect())),NULL));

    nodes_synced_w_armor.removeAll(armor_r_1_node);
    nodes_synced_w_armor.removeAll(armor);

    armor->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.3,0)),action::FuncCall(this,SLOT(start_red_teleport_2())),NULL));

    connect(pointedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(pointedCharPosChanges()),Qt::UniqueConnection);

    nodes_synced_w_armor.append(armor_r_2_node);
    armor_r_2_node->setScale(1.5);
    armor_r_2_node->runAction(action::easeinout(action::scaleTo(0.3,1)));
    armor_r_2_node->runAction(action::easeinout(action::fadeTo(0.3,100)));

    swap_red_sprites();
}

void human_char_arrow::start_red_teleport_2() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

//    changeGlowMutex.lock();
    armor_r_2_node->runAction(action::easeinout(action::fadeTo(0.3,0)));
    armor_r_2_node->runAction(action::easeinout(action::scaleTo(0.3,1.5)));
    nodes_synced_w_armor.removeAll(armor);
    nodes_synced_w_armor.append(armor);
    armor->runAction(action::easeinout(action::fadeTo(0.3,100)));
    if (!white_glowing) {
        add_glowing_element(armor_r_1_node);
    }
//    changeGlowMutex.unlock();
}

void human_char_arrow::add_glowing_element(Node *node_to_glow) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    for (int i = 0; i < glowing_elements.size(); i++) {
        if (glowing_elements.at(i)->glowing_node == node_to_glow) {
            glowing_elements.removeAt(i);
        }
    }
    remove_glowing_element(node_to_glow);
    if (glowing_elements.isEmpty()) {
        schedualUpdate();
    }
    glowing* new_glowing_node = new glowing;
    new_glowing_node->glowing_node = node_to_glow;
    new_glowing_node->increasing = false;
    glowing_elements.append(new_glowing_node);
}

void human_char_arrow::remove_glowing_element(Node *node_to_unglow) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif
    for (int i = 0; i < glowing_elements.size(); i++) {
        if (glowing_elements.at(i)->glowing_node == node_to_unglow) {
//            glowing_elements.at(i)->glowing_node->stopAllActions();
//            glowing_elements.at(i)->glowing_node->stopAllActions();
//            glowing_elements.at(i)->glowing_node->stopAllActions();
//            glowing_elements.at(i)->glowing_node->runAction(action::fadeTo(0.2,0));
            delete glowing_elements.takeAt(i);
            if (glowing_elements.isEmpty()) {
                unSchedualUpdate();
            }
            return;
        }
    }
}

void human_char_arrow::swap_sprites() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    if (first_is_first) {
        first_is_first = false;
        armor_w_1_node = armor_w_2;
        armor_w_2_node = armor_w_1;
    } else {
        first_is_first = true;
        armor_w_1_node = armor_w_1;
        armor_w_2_node = armor_w_2;
    }
}

void human_char_arrow::swap_red_sprites() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

    if (first_is_first_red) {
        first_is_first_red = false;
        armor_r_1_node = armor_r_2;
        armor_r_2_node = armor_r_1;
    } else {
        first_is_first_red = true;
        armor_r_1_node = armor_r_1;
        armor_r_2_node = armor_r_2;
    }
}

void human_char_arrow::glow_in_white(bool circle_glow) {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

//    changeGlowMutex.lock();
    if (!white_glowing) {
        white_glowing = true;
        //remove older armor_c
        remove_glowing_element(armor_c);
        armor_c->stopAllActions();
        armor_c->setScale(1);
        armor_c->setOpacity(0);

        //change it to a white one
        armor_c = armor_c_white;
        armor_c->setScale(1);
        armor_c->setOpacity(0);
        if (circle_glow) {
            add_glowing_element(armor_c);
        }

        remove_glowing_element(armor_r_1_node);
//        remove_glowing_element(armor_r_1_node);
        armor_r_1_node->stopAllActions();
        armor_r_1_node->stopAllActions();
        armor_r_1_node->runAction(action::easeinout(action::fadeTo(0.3,0)));
        nodes_synced_w_armor.append(armor_w_1_node);
        add_glowing_element(armor_w_1_node);
    }
//    changeGlowMutex.unlock();
}

void human_char_arrow::glow_in_red() {
#ifdef debugGlowingArmor
    qDebug() << Q_FUNC_INFO;
#endif

//    changeGlowMutex.lock();
    if (white_glowing) {
        white_glowing = false;
        //remove older armor_c
        remove_glowing_element(armor_c);
        armor_c->stopAllActions();
        armor_c->setScale(1);
        armor_c->setOpacity(0);

        //change it to a red one
        armor_c = armor_c_red;
        armor_c->setScale(1);
        add_glowing_element(armor_c);

        remove_glowing_element(armor_w_1_node);
        nodes_synced_w_armor.removeAll(armor_w_1_node);
        armor_w_1_node->stopAllActions();
        armor_w_1_node->stopAllActions();
        armor_w_1_node->runAction(action::easeinout(action::fadeTo(0.3,0)));
        nodes_synced_w_armor.append(armor_r_1_node);
        add_glowing_element(armor_r_1_node);
    }
//    changeGlowMutex.unlock();
}
