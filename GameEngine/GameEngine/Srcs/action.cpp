#include "action.h"

action::action() {
    targetNode = 0;
    target = 0;
}

action* action::FuncCall(QObject* targeted, QString slot) {
    action *newAction = new action;
    newAction->slotCall = slot;
    newAction->actionTypeV = actionTypeFuncCall;
    newAction->target = targeted;
    return newAction;
}

action* action::moveTo(float duration,qreal x,qreal y, effectiveness effectivenessValue) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeMoveTo;
    newAction->endValue[0] = x;
    newAction->endValue[1] = y;
    newAction->animation.setDuration(1000*duration);
    if (effectivenessValue == Effective) {
        newAction->animation.setPropertyName("pos");
    } else {
        newAction->animation.setPropertyName("posIneffective");
    }
    return newAction;
}

action* action::moveBy(float duration,qreal x,qreal y, effectiveness effectivenessValue) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeMoveBy;
    newAction->endValue[0] = x;
    newAction->endValue[1] = y;
    newAction->animation.setDuration(1000*duration);
    if (effectivenessValue == Effective) {
        newAction->animation.setPropertyName("pos");
    } else {
        newAction->animation.setPropertyName("posIneffective");
    }
    return newAction;

}

action* action::scaleTo(float duration,qreal scale) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeScaleTo;
    newAction->endValue[0] = scale;
    newAction->animation.setDuration(1000*duration);
    newAction->animation.setPropertyName("scale");
    return newAction;

}

action* action::scaleBy(float duration,qreal scale) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeScaleBy;
    newAction->endValue[0] = scale;
    newAction->animation.setDuration(1000*duration);
    newAction->animation.setPropertyName("scale");
    return newAction;

}

action* action::scaleYTo(float duration,qreal scale) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeScaleYTo;
    newAction->endValue[0] = scale;
    newAction->animation.setDuration(1000*duration);
    newAction->animation.setPropertyName("scaleY");
    return newAction;

}

action* action::scaleYBy(float duration,qreal scale) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeScaleYBy;
    newAction->endValue[0] = scale;
    newAction->animation.setDuration(1000*duration);
    newAction->animation.setPropertyName("scaleY");
    return newAction;

}

action* action::scaleXTo(float duration,qreal scale) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeScaleXTo;
    newAction->endValue[0] = scale;
    newAction->animation.setDuration(1000*duration);
    newAction->animation.setPropertyName("scaleX");
    return newAction;

}

action* action::scaleXBy(float duration,qreal scale) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeScaleXBy;
    newAction->endValue[0] = scale;
    newAction->animation.setDuration(1000*duration);
    newAction->animation.setPropertyName("scaleX");
    return newAction;
}

action* action::fadeTo(float duration,qreal value) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeFadeTo;
    newAction->endValue[0] = value;
    newAction->animation.setDuration(1000*duration);
    newAction->animation.setPropertyName("opacity");
    return newAction;

}

action* action::fadeBy(float duration,qreal value) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeFadeBy;
    newAction->endValue[0] = value;
    newAction->animation.setDuration(1000*duration);
    newAction->animation.setPropertyName("opacity");
    return newAction;

}

action* action::rotateTo(float duration,qreal angle, effectiveness effectivenessValue) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeRotateTo;
    newAction->endValue[0] = angle;
    newAction->animation.setDuration(1000*duration);
    if (effectivenessValue == Effective) {
        newAction->animation.setPropertyName("rotate");
    } else {
        newAction->animation.setPropertyName("rotateIneffective");
    }
    return newAction;

}

action* action::rotateBy(float duration,qreal angle, effectiveness effectivenessValue) {
    action *newAction = new action;
    newAction->actionTypeV = actionTypeRotateBy;
    newAction->endValue[0] = angle;
    newAction->animation.setDuration(1000*duration);
    if (effectivenessValue == Effective) {
        newAction->animation.setPropertyName("rotate");
    } else {
        newAction->animation.setPropertyName("rotateIneffective");
    }
    return newAction;

}


action* action::easein(action* withAction,int rate) {
    if (rate < 0) {
        rate = 0;
        qDebug() << "GameEngine :: easing rate should have a range between 0 and 5, range has been set to 0 for you this time";
    }
    if (rate > 5) {
        rate = 5;
        qDebug() << "GameEngine :: easing rate should have a range between 0 and 5, range has been set to 5 for you this time";
    }
    if (rate == 0)
        withAction->animation.setEasingCurve(QEasingCurve::Linear);
    if (rate == 1)
        withAction->animation.setEasingCurve(QEasingCurve::InQuad);
    if (rate == 2)
        withAction->animation.setEasingCurve(QEasingCurve::InCubic);
    if (rate == 3)
        withAction->animation.setEasingCurve(QEasingCurve::InQuart);
    if (rate == 4)
        withAction->animation.setEasingCurve(QEasingCurve::InCirc);
    if (rate == 5)
        withAction->animation.setEasingCurve(QEasingCurve::InBack);

    return withAction;
}

action* action::easeout(action* withAction,int rate) {
    if (rate < 0) {
        rate = 0;
        qDebug() << "GameEngine :: easing rate should have a range between 0 and 5, range has been set to 0 for you this time";
    }
    if (rate > 5) {
        rate = 5;
        qDebug() << "GameEngine :: easing rate should have a range between 0 and 5, range has been set to 5 for you this time";
    }
    if (rate == 0)
        withAction->animation.setEasingCurve(QEasingCurve::Linear);
    if (rate == 1)
        withAction->animation.setEasingCurve(QEasingCurve::OutQuad);
    if (rate == 2)
        withAction->animation.setEasingCurve(QEasingCurve::OutCubic);
    if (rate == 3)
        withAction->animation.setEasingCurve(QEasingCurve::OutQuart);
    if (rate == 4)
        withAction->animation.setEasingCurve(QEasingCurve::OutCirc);
    if (rate == 5)
        withAction->animation.setEasingCurve(QEasingCurve::OutBack);
    return withAction;
}

action* action::easeinout(action* withAction,int rate) {
    if (rate < 0) {
        rate = 0;
        qDebug() << "GameEngine :: easing rate should have a range between 0 and 5, range has been set to 0 for you this time";
    }
    if (rate > 5) {
        rate = 5;
        qDebug() << "GameEngine :: easing rate should have a range between 0 and 5, range has been set to 5 for you this time";
    }
    if (rate == 0)
        withAction->animation.setEasingCurve(QEasingCurve::Linear);
    if (rate == 1)
        withAction->animation.setEasingCurve(QEasingCurve::InOutQuad);
    if (rate == 2)
        withAction->animation.setEasingCurve(QEasingCurve::InOutCubic);
    if (rate == 3)
        withAction->animation.setEasingCurve(QEasingCurve::InOutQuart);
    if (rate == 4)
        withAction->animation.setEasingCurve(QEasingCurve::InOutCirc);
    if (rate == 5)
        withAction->animation.setEasingCurve(QEasingCurve::InOutBack);
    return withAction;
}

action *action::easCurve(action *withAction, QEasingCurve curve) {
    withAction->animation.setEasingCurve(curve);
    return withAction;
}


void action::setTarget(Node *targeted) {
    connect(this,SIGNAL(animationFinished(action*)),targeted,SLOT(actionDone(action*)));
    if (actionTypeV == actionTypeFuncCall) {
        connect(this,SIGNAL(animationFinished(action*)),target,slotCall.toStdString().c_str());
        delete_self();
    }
    else {
        target = targeted;
        targetNode = targeted;
        qreal newY;
        qreal newX;
        switch (actionTypeV) {
        case actionTypeMoveTo :
            animation.setStartValue(targeted->pos());
            //here we are setting the new position
            animation.setEndValue(QPointF(endValue[0],endValue[1]));
            break;
        case actionTypeMoveBy :
            animation.setStartValue(targeted->pos());
            //here we'll calculate the new point as it's moveBy, we'll add the value to the original
            newX = endValue[0] + targeted->pos().x();
            newY = endValue[1] + targeted->pos().y();
            animation.setEndValue(QPointF(newX,newY));
            break;
        case actionTypeFadeTo :
            animation.setStartValue(targeted->opacity());
            //here we'll set the new scale
            animation.setEndValue(endValue[0]);
            break;
        case actionTypeFadeBy :
            animation.setStartValue(targeted->opacity());
            //here we'll calculate the new scale as it's multiplied by original scale
            animation.setEndValue(endValue[0]+targeted->opacity());
            break;
        case actionTypeScaleTo:
            animation.setStartValue(targeted->scale());
            //here we'll set the new scale
            animation.setEndValue(endValue[0]);
            break;
        case actionTypeScaleBy :
            animation.setStartValue(targeted->scale());
            //here we'll calculate the new scale as it's multiplied by original scale
            animation.setEndValue(endValue[0]*targeted->scale());
            break;
        case actionTypeScaleYTo:
            animation.setStartValue(targeted->scaleY());
            //here we'll set the new scale
            animation.setEndValue(endValue[0]);
            break;
        case actionTypeScaleYBy :
            animation.setStartValue(targeted->scaleY());
            //here we'll calculate the new scale as it's multiplied by original scale
            animation.setEndValue(endValue[0]*targeted->scaleY());
            break;
        case actionTypeScaleXTo:
            animation.setStartValue(targeted->scaleX());
            //here we'll set the new scale
            animation.setEndValue(endValue[0]);
            break;
        case actionTypeScaleXBy :
            animation.setStartValue(targeted->scaleX());
            //here we'll calculate the new scale as it's multiplied by original scale
            animation.setEndValue(endValue[0]*targeted->scaleX());
            break;
        case actionTypeRotateTo :
            animation.setStartValue(targeted->rotation());
            //here we'll set the new scale
            animation.setEndValue(endValue[0]);
            break;
        case actionTypeRotateBy :
            animation.setStartValue(targeted->rotation());
            //here we'll calculate the new scale as it's multiplied by original scale
            animation.setEndValue(endValue[0]+targeted->rotation());
            break;
        default:
            emit animationFinished(this);
            break;
        }
        animation.setTargetObject(target);
        animation.start();
        //here we are connecting it to delete itself slot, and emit done signal
        connect(&animation,SIGNAL(finished()),this,SLOT(delete_self()));
    }

}


void action::delete_self() {
    emit animationFinished(this);
}

void action::stopAnimation() {
    animation.stop();
}
