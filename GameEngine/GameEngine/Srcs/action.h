#ifndef ACTION_H
#define ACTION_H
#include <QPropertyAnimation>
#include <QDebug>
#include "node.h"

class Node;

class action : public QObject
{
    Q_OBJECT

public:

    enum effectiveness {
        Effective = 0,
        Ineffective
    };

    static action* FuncCall(QObject* targeted, QString slot);
    static action* moveTo(float duration,qreal x,qreal y, effectiveness effectivenessValue = Effective);
    static action* moveBy(float duration,qreal x,qreal y, effectiveness effectivenessValue = Effective);
    static action* scaleTo(float duration,qreal scale);
    static action* scaleBy(float duration,qreal scale);
    static action* scaleYTo(float duration,qreal scale);
    static action* scaleYBy(float duration,qreal scale);
    static action* scaleXTo(float duration,qreal scale);
    static action* scaleXBy(float duration,qreal scale);
    static action* fadeTo(float duration,qreal value);
    static action* fadeBy(float duration,qreal value);
    static action* rotateTo(float duration,qreal angle, effectiveness effectivenessValue = Effective);
    static action* rotateBy(float duration,qreal angle, effectiveness effectivenessValue = Effective);
    static action* easein(action* withAction,int rate = 4);
    static action* easeout(action* withAction,int rate = 4);
    static action* easeinout(action* withAction,int rate = 4);
    static action* easCurve(action* withAction,QEasingCurve curve);
    void setTarget(Node *targeteted);
    void stopAnimation();
    Node* targetNode;

private:
    enum actionType {
        actionTypeMoveTo = 0,
        actionTypeMoveBy,
        actionTypeFadeTo,
        actionTypeFadeBy,
        actionTypeScaleTo,
        actionTypeScaleBy,
        actionTypeScaleYTo,
        actionTypeScaleYBy,
        actionTypeScaleXTo,
        actionTypeScaleXBy,
        actionTypeRotateTo,
        actionTypeRotateBy,
        actionTypeFuncCall
    };

    QObject *target;
    action();
    //this is the animation variable
    QPropertyAnimation animation;
    actionType actionTypeV;
    qreal endValue[2];
    QString slotCall;
public slots:
    void delete_self();
signals:
    void animationFinished(action *finishedAction);
};

#endif // ACTION_H
