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

    static action* FuncCall(QObject* targeted,const char* slot);
    static action* moveTo(float duration,qreal x,qreal y);
    static action* moveBy(float duration,qreal x,qreal y);
    static action* scaleTo(float duration,qreal scale);
    static action* scaleBy(float duration,qreal scale);
    static action* fadeTo(float duration,qreal value);
    static action* fadeBy(float duration,qreal value);
    static action* rotateTo(float duration,qreal angle);
    static action* rotateBy(float duration,qreal angle);
    static action* easein(action* withAction,int rate = 4);
    static action* easeout(action* withAction,int rate = 4);
    static action* easeinout(action* withAction,int rate = 4);
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
    const char* slotCall;
public slots:
    void delete_self();
signals:
    void animationFinished(action *finishedAction);
};

#endif // ACTION_H
