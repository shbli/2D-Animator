#include "die_effect.h"

die_and_join_effect::die_and_join_effect() {
    setZ(200000);
    character_parent = 0;
    characterToGetLife = 0;
    QRect winSize = Director::sharedDirector()->winSizeInPixels();
    bigEffect = Sprite::spriteWithSvg("die_effect.svg",character_base::screenScale*2);
    addChild(bigEffect);
    bigEffect->setScale(0);

    screenScale = Director::sharedDirector()->winSizeInPixels().width()/origwallw;

    int xArray[numOfSmallEffects] = {3,1,-2,-6,3,-4};
    int yArray[numOfSmallEffects] = {1,-4,2,-3,1,-2};

    for (int i = 0; i < numOfSmallEffects; i++) {
        smallEffects.append(Sprite::spriteWithSvg("die_effect.svg",character_base::screenScale*smallEffectScale));
        addChild(smallEffects.last());
        smallEffects.at(i)->setPos(xArray[i]*screenScale,yArray[i]*screenScale);
        smallEffects.last()->setOpacity(0);
    }

//    int xArray2[numOfSmallEffectsEnter] = {-20,-22,-23,-21,-3,-2,-5,0,7,10,8,9,13,14,16,17,25,26,29,28};
//    int yArray2[numOfSmallEffectsEnter] = {-50,-20,10,40,-50,-20,10,40,-50,-20,10,40,-50,-20,10,40,-50,-20,10,40,};

//    for (int i = 0; i < numOfSmallEffectsEnter; i++) {
//        smallEnterEffects.append(Sprite::spriteWithSvg("die_effect.svg",winSize.width()/origwallw*smallEffectScale));
//        addChild(smallEnterEffects.last());
//        smallEnterEffects.at(i)->setPos(xArray2[i] * screenScale,yArray2[i] * screenScale);
//        smallEnterEffects.last()->setOpacity(0);
//    }
}

void die_and_join_effect::startDieEffect(character_base *character) {
    setZ(character_parent->z()+30);
    characterToGetLife = character;
    setPos(character_parent->pos());
    float time = 0.4;
    bigEffect->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleTo(time,1)),action::FuncCall(this,SLOT(hideDeadCharacter())),NULL));
    runAction(action::easeinout(action::rotateTo(time,360)));
}

void die_and_join_effect::hideDeadCharacter() {

    setZ(characterToGetLife->z()+30);
    character_parent->rootJoint->setOpacity(0);
    character_parent->myHealthBar->setOpacity(0);
    character_parent->stopAnimation();
    character_parent->setScale(1);
    character_parent->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);


    int x1;
    int y1;
    if (character_parent->computer_player) {
        //get the distance between our positions, and to get life position
        x1 = characterToGetLife->pos().x();
        y1 = characterToGetLife->pos().y() + (80*screenScale);
    } else {
        //get the distance between me and the space
        x1 = pos().x();
        y1 = (Director::sharedDirector()->winSizeInPixels().height()*1.3);
    }
//    float distance = (x1*x1) + (y1*y1);
//    distance = sqrt(distance);
//    originalDistance = distance;

    float time = 0.3;
    runAction(action::easeinout(action::moveTo(time,x1,y1)));
    runAction(action::easeinout(action::rotateTo(time,0)));
    bigEffect->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleYTo(time,0.2)),action::FuncCall(this,SLOT(finalStep())),NULL));
    bigEffect->runAction(action::easeinout(action::scaleTo(time,0.2)));


    //this is old effect can be enabled
//    schedualUpdate();
}

void die_and_join_effect::update(double delta) {

    //in this function, the character tries to move closer, and closer to the enemy, after that, starts attacking
    float x = characterToGetLife->pos().x();
    float y = characterToGetLife->pos().y();

    float xDist = x - pos().x();
    float yDist = y - pos().y();
    //    xDist *= -1;
    //    yDist *= -1;

    float dist_from_char = (xDist*xDist) + (yDist*yDist);
    dist_from_char = sqrt(dist_from_char);

    float screenScale = Director::sharedDirector()->winSizeInPixels().width() / origwallw;

    xDist = x - pos().x();
    float dist = (xDist*xDist) + (yDist*yDist);
    dist = sqrt(dist);

    float percantage = dist_from_char / originalDistance;

    //if the character is close enough to attack, let's start attacking, otherwise continue moving close
    if (dist_from_char <= ( 5 * screenScale )) {
        unSchedualUpdate();
        finalStep();

    } else {

        speedPoint.setX((xDist/dist)*400);
        speedPoint.setY((yDist/dist)*400);

        QPointF nextPos = pos() + (speedPoint*delta);
        setPos(nextPos);
    }

    bigEffect->setScale(0.2 + (0.8 * percantage));
}

void die_and_join_effect::deleteSelfFromParent() {

    parent->removeChild(this);
}

void die_and_join_effect::finalStep() {
    if (character_parent->computer_player) {
        characterToGetLife->increaseHealthBy((character_parent->myHealthBar->getMaxValue()/2));
    }

    bigEffect->setOpacity(0);

    int xArray[numOfSmallEffects] = {20, -21 , 10  , -23, -19 ,  18  };
    int yArray[numOfSmallEffects] = {3 ,  6  , -13 ,  0 , -21  , -13  };

    float time = 0.2;
    float multiple = 4 * character_base::screenScale;

    runAction(action::easeinout(action::rotateTo(time,360)));

    for (int i = 0; i < numOfSmallEffects; i++) {
        smallEffects.at(i)->setOpacity(100);
        smallEffects.at(i)->runAction(action::easeinout(action::moveBy(time,xArray[i] * multiple,yArray[i] * multiple)));
        smallEffects.at(i)->runAction(action::easeinout(action::fadeTo(time,0)));
    }

    QTimer::singleShot(time*1000 + 10,this,SLOT(deleteSelfFromParent()));
}

void die_and_join_effect::startEnterEffect() {
//    bigEffect->setOpacity(100);
//    bigEffect->setPos(character_parent->pos().x(),character_parent->pos().y() + (500 * Director::sharedDirector()->winSizeInPixels().width()/origwallw));
//    bigEffect->setScaleX(0);
//    bigEffect->setScaleY(1);
//    bigEffect->setAnchor(0.5,1);
//    setPos(character_parent->pos());

    character_parent->setOpacity(100);

    if (character_parent->computer_player) {
        character_parent->startEnemeyIntleegince();
    }

//    float time = 0.3;

//    for (int i = 0; i < numOfSmallEffectsEnter; i++) {
//        smallEnterEffects.at(i)->setOpacity(100);
//        smallEnterEffects.at(i)->runAction(action::easeinout(action::moveBy(time,0,30*screenScale)));
//        smallEnterEffects.at(i)->runAction(action::easeinout(action::fadeTo(time,0)));
//    }

//    bigEffect->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(time,1)),action::FuncCall(this,SLOT(enterEffectShowParentHideEffect())),NULL));
//    bigEffect->runAction(action::easeinout(action::moveTo(time+0.05,character_parent->pos().x(),character_parent->pos().y() - (bigEffect->height()/2))));
}

void die_and_join_effect::enterEffectShowParentHideEffect() {
    character_parent->setOpacity(100);
    if (character_parent->computer_player) {
        character_parent->startEnemeyIntleegince();
    }

    float time = 0.2;

    bigEffect->runAction(action::easeinout(action::scaleYTo(time,0)));
}
