#ifndef NODE_H
#define NODE_H
#include "QPointF"
#include "QGraphicsScene"
#include <QGraphicsItem>
#include <QDebug>
#include "sequence.h"
#include "director.h"

class action;
class Sequence;

class Node : public QObject
{
    Q_OBJECT
    Q_PROPERTY (qreal scale READ scale WRITE setScale)
    Q_PROPERTY (qreal opacity READ opacity WRITE setOpacity)
    Q_PROPERTY (qreal rotate READ rotation WRITE setRotation)
    Q_PROPERTY (QPointF pos READ pos WRITE setPos)
public:
    //these functions should be implemented in the subclass
    virtual qreal getwidth() = 0;
    virtual qreal getheight() = 0;
    virtual QPointF pos() const;
    virtual qreal opacity() const;
    virtual qreal scale();
    virtual qreal rotation();
    virtual int z();
    virtual void setOpacity(qreal value);
    virtual void setPos ( const QPointF & pos );
    virtual void setPos ( qreal x, qreal y );
    virtual void setScale ( qreal factor );
    virtual void setZ ( int zValue );
    virtual void setRotation ( qreal rotationDegree );
    virtual action* runAction(action* actionPara);
    virtual void runSequence(Sequence* sequencePara);
    virtual void stopAction(action* stopAction);
    void stopSequence(Sequence* stopAction);
    virtual void stopAllActions();
    void schedualUpdate();
    void unSchedualUpdate();
    qreal width();
    qreal height();
    ~Node();
    Node();
    virtual void addChild(Node* child,int tag = 0,int z = 0);
    virtual Node* getChildByTag(int tag);
    virtual void removeChildByTag(int tag);
    virtual void removeChild(Node* child);
    virtual void onEnterTransitionDidStart(){}
    virtual void onEnterTransitionDidFinish(){}
    virtual void onExitTransitionDidStart(){}
    virtual void onExitTransitionDidFinish(){}
    virtual void touchBegin(QGraphicsSceneMouseEvent *event) {}
    virtual void touchMove(QGraphicsSceneMouseEvent *event) {}
    virtual void touchEnd(QGraphicsSceneMouseEvent *event) {}
    void setTouchEnabled(bool enabled = true);
protected:
    // these functions are overloaded in base classes as private with no implementation, because they need to be protected
    virtual QGraphicsScene* getSharedGraphicScene();
    virtual void setSharedGraphicScene(QGraphicsScene* graphicscene);
    virtual int getGlobalMaxZ();
    virtual QGraphicsItem* getGraphicsItem();
    virtual void setGraphicsItem(QGraphicsItem* item);
    virtual void setW(qreal w);
    virtual void setH(qreal h);
    // end of protected members
signals:
    void updateChildsPos();
    void updateChildsScale();
    void updateChildsZ();
    void updateChildsRotation();
    void updateChildsOpacity();

public slots:
    void actionDone(action* doneAction);
    virtual void update(double delta);
public slots:
    void updateMyPos();
    void updateMyScale();
    void updateMyZ();
    void updateMyRotation();
    void updateMyOpacity();

private:
    bool updatescheduled;
    static QGraphicsScene *sharedGraphicScene;
    int z_;
    static int global_max_z;
    int max_local_z;
    Node *parent;
    QList <Node *> childs;
    QList <action *> actions;
    QList <Sequence *> sequences;
    QGraphicsItem *graphicsItem;
    QPointF     realTimePos() const;
    qreal     realTimeScale() const;
    int     realTimeZ() const;
    qreal     realTimeRotation() const;
    qreal     realTimeOpacity() const;
    qreal center_x;
    qreal center_y;
    qreal scaleFactor;
    qreal w;
    qreal h;
    qreal rotaionAngle;
    qreal opacityValue;
    int nodetag;
    bool isTouchEnabled;

};

#endif // CCNODE_H
