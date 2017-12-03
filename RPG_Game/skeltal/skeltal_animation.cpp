#include "skeltal_animation.h"
#include "character_base.h"



skeltal_animation::skeltal_animation(QObject *parent) :
    QObject(parent)
{
}

void skeltal_animation::updateOneCurrentAnimationTime(double delta) {

    //are we in the correct animation step or not
    while ( current_animation_time >= parentSkeltal->child_parts.at(0)->animationsList.at(parentSkeltal->characterPointer->currentAnimationIndex)->animation_steps.at(currentStep).end_time) {
        //let's go to the next step


        if (current_animation_time >= total_animation_time) {
            //we have to go back to step 0 and restart the animation here
            current_animation_time -= total_animation_time;
            currentStep = 0;
        } else {
            //go to next step
            current_animation_time = parentSkeltal->child_parts.at(0)->animationsList.at(parentSkeltal->characterPointer->currentAnimationIndex)->animation_steps.at(currentStep).end_time;
            currentStep = currentStep + 1 % parentSkeltal->child_parts.at(0)->animationsList.at(parentSkeltal->characterPointer->currentAnimationIndex)->animation_steps.size();
        }

        if (parentSkeltal->child_parts.at(0)->animationsList.at(parentSkeltal->characterPointer->currentAnimationIndex)->animation_steps.at(currentStep).fireW1Boolean) {
            parentSkeltal->runWeaponEffect();
        }

        if (!parentSkeltal->characterPointer->computer_player) {
            multiplyValues = game_controller::sharedGameController()->playerSpeed;
        } else {
            multiplyValues = game_controller::sharedGameController()->enemySpeed;
        }
        multiplyValues *= parentSkeltal->characterPointer->local_speed;

        callUpdate2OnAllChilds(delta);

        return;
    }

    float newmultiplyValues;
    if (!parentSkeltal->characterPointer->computer_player) {
        newmultiplyValues = game_controller::sharedGameController()->playerSpeed;
    } else {
        newmultiplyValues = game_controller::sharedGameController()->enemySpeed;
    }

    newmultiplyValues *= parentSkeltal->characterPointer->local_speed;

    if (newmultiplyValues != multiplyValues) {
        multiplyValues = newmultiplyValues;
        callUpdate2OnAllChilds(delta);
    }

    callUpdate2OnAllChilds(delta);

    //ok we are in safe side and in correct step, let's calculate the new animation value
}

void skeltal_animation::callUpdate2OnAllChilds(float delta) {
    for (int i = 0; i < parentSkeltal->child_parts.size(); i++) {
        parentSkeltal->child_parts.at(i)->animationsList.at(parentSkeltal->characterPointer->currentAnimationIndex)->currentStep = currentStep;
        parentSkeltal->child_parts.at(i)->animationsList.at(parentSkeltal->characterPointer->currentAnimationIndex)->current_animation_time = current_animation_time;
        parentSkeltal->child_parts.at(i)->animationsList.at(parentSkeltal->characterPointer->currentAnimationIndex)->multiplyValues = multiplyValues;
        parentSkeltal->child_parts.at(i)->animationsList.at(parentSkeltal->characterPointer->currentAnimationIndex)->updateOneCurrentAnimationTimeStep2(delta);
    }
}

void skeltal_animation::updateOneCurrentAnimationTimeStep2(float delta) {

    callUpdate2OnAllChilds(delta);

    if (currentStep >= 0 && currentStep < animation_steps.size()) {
//        float timeDiffrence = animation_steps.at(currentStep).end_time - current_animation_time;
//        if (timeDiffrence < 0 ) {
//            timeDiffrence *= -1;
//        }

//        timeDiffrence /= multiplyValues;


        //        if (animation_steps.at(currentStep).rotation_angle != parentSkeltal->holderLayer->rotation()) {
        //            parentSkeltal->holderLayer->stopAllActions();
        //            //        parentSkeltal->holderLayer->runAction(action::easeinout(action::rotateTo(timeDiffrence,animation_steps.at(currentStep).rotation_angle,action::Ineffective)));
        //            parentSkeltal->holderLayer->runAction(action::rotateTo(timeDiffrence,animation_steps.at(currentStep).rotation_angle,action::Ineffective));
        //        }

        //        if (animation_steps.at(currentStep).end_y != parentSkeltal->pos().y()) {
        //            parentSkeltal->stopAllActions();
        //            //        parentSkeltal->runAction(action::easeinout(action::moveTo(timeDiffrence,parentSkeltal->pos().x(),animation_steps.at(currentStep).end_y,action::Ineffective)));
        //            parentSkeltal->runAction(action::moveTo(timeDiffrence,parentSkeltal->pos().x(),animation_steps.at(currentStep).end_y,action::Ineffective));
        //        }

        currentSpeed = animation_steps.at(currentStep).rotation_angle - parentSkeltal->holderLayer->rotation();
        currentSpeed = currentSpeed / (animation_steps.at(currentStep).end_time - current_animation_time);

        currentYSpeed = animation_steps.at(currentStep).end_y - parentSkeltal->pos().y();
        currentYSpeed = currentYSpeed / (animation_steps.at(currentStep).end_time - current_animation_time);


        //avoiding overflow
        float newRotation = parentSkeltal->holderLayer->rotation() + (currentSpeed*delta);
        if (currentSpeed < 0) {
            //going in - direction
            if (newRotation < animation_steps.at(currentStep).rotation_angle ) {
                newRotation = animation_steps.at(currentStep).rotation_angle;
            }
        } else {
            //going in plus direction
            if (newRotation > animation_steps.at(currentStep).rotation_angle ) {
                newRotation = animation_steps.at(currentStep).rotation_angle;
            }
        }

        float newY = parentSkeltal->pos().y() + (currentYSpeed * delta);
        if (currentYSpeed < 0) {
            //going in - direction
            if (newY < animation_steps.at(currentStep).end_y ) {
                newY = animation_steps.at(currentStep).end_y;
            }
        } else {
            //going in plus direction
            if (newY > animation_steps.at(currentStep).end_y ) {
                newY = animation_steps.at(currentStep).end_y;
            }
        }



        parentSkeltal->holderLayer->setIneffectiveRotation(newRotation);
        parentSkeltal->setIneffectivePos(parentSkeltal->pos().x(),newY);



    }


}

void skeltal_animation::setW1(int stepNumber) {
    skeltal_animation_step tempStep = animation_steps.at(stepNumber);
    tempStep.fireW1Boolean = true;
    animation_steps.replace(stepNumber,tempStep);
}

void skeltal_animation::set_animation_at_point(float key_point) {
    int key_animation_step = 0;
    //are we in the correct animation step or not
    if (!animation_steps.isEmpty()) {
        while ( key_point >= animation_steps.at(key_animation_step).end_time) {
            //let's go to the next step
            if (key_point >= total_animation_time) {
                //we have to go back to step 0 and restart the animation here
                key_point -= total_animation_time;
                key_animation_step = 0;
            } else {
                //go to next step
                key_animation_step = key_animation_step + 1 % animation_steps.size();
            }
        }


        float before_key_point_t = 0;
        float before_rotation = 0;
        float before_y = 0;
        if (key_animation_step > 0) {
            before_key_point_t = animation_steps.at(key_animation_step - 1).end_time;
            before_rotation = animation_steps.at(key_animation_step - 1).rotation_angle;
            before_y = animation_steps.at(key_animation_step - 1).end_y;
        } else {
            before_rotation = animation_steps.last().rotation_angle;
            before_y = animation_steps.last().end_y;

        }

        float after_key_point_t = animation_steps.at(key_animation_step).end_time;
        float after_rotation = animation_steps.at(key_animation_step).rotation_angle;
        float after_y = animation_steps.at(key_animation_step).end_y;


        float key_point_percantage = (after_key_point_t - key_point)/(after_key_point_t - before_key_point_t);
        key_point_percantage = 1 - key_point_percantage;

        float new_rotation = before_rotation + ( (after_rotation - before_rotation) * key_point_percantage );
        float new_y = before_y + ( (after_y - before_y) * key_point_percantage );


        //        qDebug() << "Part name " << parentSkeltal->part_name;
        //        qDebug() << "R Values:";
        //        qDebug() << "R Before:" << before_rotation;
        //        qDebug() << "R After:" << after_rotation;
        //        qDebug() << "R New:" << new_rotation;



        //        qDebug() << "Y Values:";
        //        qDebug() << "Y Before:" << before_y;
        //        qDebug() << "Y After:" << after_y;
        //        qDebug() << "Y New:" << new_y;



        //        qDebug() << "T Values:";
        //        qDebug() << "T Before:" << before_key_point_t;
        //        qDebug() << "T After:" << after_key_point_t;
        //        qDebug() << "T New:" << key_point_percantage;

        parentSkeltal->holderLayer->setIneffectiveRotation(new_rotation);
        parentSkeltal->setIneffectivePos(parentSkeltal->pos().x(),new_y);
    }
}

void skeltal_animation::advanceOneStep(double delta) {
    //    float tempCurr = current_animation_time;
    current_animation_time += delta;
    //    if (currentStep >= 0 && currentStep < animation_steps.size()) {
    //        if (delta + tempCurr > animation_steps.at(currentStep).end_time) {
    //            delta = (animation_steps.at(current_animation_time).end_time - tempCurr);
    //        }
    //    }
    updateOneCurrentAnimationTime(delta);
}

void skeltal_animation::startAnimation() {
    if (!animation_steps.isEmpty())
        connect(Director::sharedDirector(),SIGNAL(update(double)),this,SLOT(advanceOneStep(double)),Qt::UniqueConnection);
}

void skeltal_animation::stopAnimation() {
    disconnect(Director::sharedDirector(),SIGNAL(update(double)),this,SLOT(advanceOneStep(double)));
}

void skeltal_animation::restartAnimation() {
    current_animation_time = total_animation_time;
    currentStep = 0;
}

void skeltal_animation::addAnimationStep(float endT, float anlge, float svgIndex, float yValue,bool fireW1Value) {
    skeltal_animation_step newAnimationStep;
    newAnimationStep.end_time = endT;
    newAnimationStep.rotation_angle = anlge;
    newAnimationStep.svg_index = svgIndex;
    newAnimationStep.end_y = yValue;
    newAnimationStep.fireW1Boolean = 0;


    if (animation_steps.isEmpty()) {
        animation_steps.append(newAnimationStep);
    } else {
        bool inserted = false;
        for (int i = 0; i < animation_steps.size() & !inserted; i++) {
            if (animation_steps.at(i).end_time > newAnimationStep.end_time) {
                animation_steps.insert(i,newAnimationStep);
                inserted = true;
            }
        }
        if (!inserted) {
            animation_steps.append(newAnimationStep);
        }
    }

    if (fireW1Value == true) {
        int animationIndex = -1;
        for (int i = 0; i < parentSkeltal->characterPointer->rootJoint->animationsList.size() && animationIndex == -1; i++) {
            if (animation_name == parentSkeltal->characterPointer->rootJoint->animationsList.at(i)->animation_name) {
                animationIndex = i;
            }
        }
        if (animationIndex != -1) {
            for (int i = 0; i < parentSkeltal->characterPointer->rootJoint->child_parts.first()->animationsList.at(animationIndex)->animation_steps.size(); i++) {
                if (endT == parentSkeltal->characterPointer->rootJoint->child_parts.first()->animationsList.at(animationIndex)->animation_steps.at(i).end_time) {
                    parentSkeltal->characterPointer->rootJoint->child_parts.first()->animationsList.at(animationIndex)->setW1(i);
                }
            }
        }
    }
}


void skeltal_animation::loadFromDomNode(QDomElement *animationNode) {
    float screenScale = parentSkeltal->characterPointer->screenScale;
    QDomNode step = animationNode->firstChild();
    while (!step.isNull()) {
        if (step.isElement()) {
            QDomElement stepElement = step.toElement();
            //using the add methode to add a child svg
            addAnimationStep(stepElement.attribute("end-time").toFloat(),stepElement.attribute("rotation-angle").toFloat(),stepElement.attribute("svg-index").toInt(), ( - stepElement.attribute("end-y").toFloat() - parentSkeltal->parentSVGHeightOffset) * screenScale,stepElement.attribute("fire-w1").toInt());
        }
        step = step.nextSibling();
    }
}
