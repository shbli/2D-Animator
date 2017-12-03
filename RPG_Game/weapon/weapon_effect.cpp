#include "weapon_effect.h"

void weapon_effect::loadeffectsDomElement(QDomElement* effectElement,float screenScalePar) {


    float screenScale = screenScalePar;

    effectSprite = Sprite::spriteWithSvg(effectElement->attribute("svg"),screenScale);
    float blur_amount = effectElement->attribute("blur").toFloat();
    if (blur_amount > 0) {
        //we need to set blue on that element
        QGraphicsBlurEffect* blur = new QGraphicsBlurEffect();
        blur->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
        blur->setBlurRadius(blur_amount);
        effectSprite->setGraphicsEffect(blur);

    }
    effectSprite->setAnchor(effectElement->attribute("x-anchor").toFloat(),effectElement->attribute("y-anchor").toFloat());
    effectSprite->setOpacity(0);
    addChild(effectSprite);

    int i = 0;
    QDomNode effects = effectElement->firstChild();
    while (!effects.isNull()) {
        if (effects.isElement()) {
            QDomElement effectElement = effects.toElement();
            end_t[i] = effectElement.attribute("end-t").toFloat();
            x[i] = effectElement.attribute("x").toFloat() * screenScale;
            y[i] = effectElement.attribute("y").toFloat() * screenScale;
            sx[i] = effectElement.attribute("sx").toFloat();
            sy[i] = effectElement.attribute("sy").toFloat();
            rotation[i] = effectElement.attribute("r").toFloat();
            opacity[i] = effectElement.attribute("opacity").toFloat();
            i++;
        }
        effects = effects.nextSibling();
    }



    //checking the effects
    if (x[0] == x[1] && x[1] == x[2]) {
        effectSprite->setPos(x[0],effectSprite->pos().y());
    } else {
        connect(this,SIGNAL(signalEffect()),this,SLOT(runMOVAnimation()),Qt::UniqueConnection);
    }

    if (y[0] == y[1] && y[1] == y[2]) {
        effectSprite->setPos(effectSprite->pos().x(),y[0]);
    } else {
        connect(this,SIGNAL(signalEffect()),this,SLOT(runMOVAnimation()),Qt::UniqueConnection);
    }

    if (sx[0] == sx[1] && sx[1] == sx[2]) {
        effectSprite->setScaleX(sx[0]);
    } else {
        connect(this,SIGNAL(signalEffect()),this,SLOT(runSXAnimation()));
    }

    if (sy[0] == sy[1] && sy[2] == sy[1]) {
        effectSprite->setScaleY(sy[0]);
    } else {
        connect(this,SIGNAL(signalEffect()),this,SLOT(runSYAnimation()));
    }

    if (rotation[0] == rotation[1] && rotation[1] == rotation[2]) {
        effectSprite->setRotation(rotation[0]);
    } else {
        connect(this,SIGNAL(signalEffect()),this,SLOT(runRAnimation()));
    }

    if (opacity[0] == opacity[1] && opacity[1] == opacity[2]) {
        effectSprite->setOpacity(opacity[0]);
    } else {
        connect(this,SIGNAL(signalEffect()),this,SLOT(runOAnimation()));
    }

//    qDebug() << "Number of elements loaded is " << i;

    //this is for testing purpose
//    for (int j = 0; j < numberOfSteps; j++) {
//        qDebug() << "End T for number " << j << " is equal to " << end_t[j] ;
//    }
}

void weapon_effect::startEffect() {
    effectSprite->setPos(x[0],y[0]);
    effectSprite->setScale(sx[0],sy[0]);
    effectSprite->setRotation(rotation[0]);
    effectSprite->setOpacity(opacity[0]);
    if (end_t[0] <= 0) {
        emit signalEffect();
    } else {
        QTimer::singleShot(1000*end_t[0],this,SIGNAL(signalEffect()));
    }
}

void weapon_effect::runMOVAnimation() {
//    effectSprite->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveTo(end_t[1],x[1],y[1])),action::easeinout(action::moveTo(end_t[2] - end_t[1],x[2],y[2])),NULL));
    effectSprite->runSequence(Sequence::sequenceWithActions(action::moveTo(end_t[1] - end_t[0],x[1],y[1]),action::moveTo(end_t[2] - end_t[1],x[2],y[2]),NULL));
}

void weapon_effect::runSXAnimation() {
//    effectSprite->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(end_t[1],sx[1])),action::easeinout(action::scaleXTo(end_t[2] - end_t[1],sx[2])),NULL));
    effectSprite->runSequence(Sequence::sequenceWithActions(action::scaleXTo(end_t[1] - end_t[0],sx[1]),action::scaleXTo(end_t[2] - end_t[1],sx[2]),NULL));
}

void weapon_effect::runSYAnimation() {
//    effectSprite->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleYTo(end_t[1],sy[1])),action::easeinout(action::scaleYTo(end_t[2] - end_t[1],sy[2])),NULL));
    effectSprite->runSequence(Sequence::sequenceWithActions(action::scaleYTo(end_t[1] - end_t[0],sy[1]),action::scaleYTo(end_t[2] - end_t[1],sy[2]),NULL));
}

void weapon_effect::runRAnimation() {
//    effectSprite->runSequence(Sequence::sequenceWithActions(action::easeinout(action::rotateTo(end_t[1],rotation[1])),action::easeinout(action::rotateTo(end_t[2] - end_t[1],rotation[2])),NULL));
    effectSprite->runSequence(Sequence::sequenceWithActions(action::rotateTo(end_t[1] - end_t[0],rotation[1]),action::rotateTo(end_t[2] - end_t[1],rotation[2]),NULL));
}

void weapon_effect::runOAnimation() {
//    effectSprite->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(end_t[1],opacity[1])),action::easeinout(action::fadeTo(end_t[2] - end_t[1],opacity[2])),NULL));
    effectSprite->runSequence(Sequence::sequenceWithActions(action::fadeTo(end_t[1] - end_t[0],opacity[1]),action::fadeTo(end_t[2] - end_t[1],opacity[2]),NULL));
}
