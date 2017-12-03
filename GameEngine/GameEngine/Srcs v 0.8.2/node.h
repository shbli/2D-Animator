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
    Q_PROPERTY (qreal scaleX READ scaleX WRITE setScaleX)
    Q_PROPERTY (qreal scaleY READ scaleY WRITE setScaleY)
    Q_PROPERTY (qreal opacity READ opacity WRITE setOpacity)
    Q_PROPERTY (qreal rotate READ rotation WRITE setRotation)
    Q_PROPERTY (QPointF pos READ pos WRITE setPos)
public:
    //these functions should be implemented in the subclass
    virtual qreal getwidth();
    virtual qreal getheight();
    virtual QPointF pos() const;
    virtual QPointF anchorPoint() const;
    virtual qreal opacity() const;
    virtual qreal scale();
    virtual qreal scaleX();
    virtual qreal scaleY();
    virtual qreal rotation();
    virtual int z();
    virtual void setOpacity(qreal value);
    virtual void setPos ( const QPointF & pos );
    virtual void setPos ( qreal x, qreal y );

    //due to some heavy calculations, these are used to do the real effect on a position
    virtual void setEffectivePos();
    virtual void setEffectiveRotation();
    virtual void setAnchor (qreal xanchorvalue,qreal yanchorvalue);
    virtual void setScale ( qreal factor );
    virtual void setScale ( qreal factorx, qreal factory );
    virtual void setScaleX ( qreal factorx );
    virtual void setScaleY ( qreal factory );
    virtual void setZ ( int zValue );
    virtual void setRotation ( qreal rotationDegree );
    virtual void setIneffectiveRotation ( qreal rotationDegree );
    virtual void setIneffectivePos ( qreal x, qreal y );
    virtual void setIneffectivePos ( const QPointF &point );
    virtual action* runAction(action* actionPara);
    virtual void runSequence(Sequence* sequencePara);
    virtual void stopAction(action* stopAction);
    virtual void setGraphicsEffect(QGraphicsEffect * effect);
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
    bool ignoreParentRotation;
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
    QGraphicsScale* scalingProperties;
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
    qreal     realTimeXScale() const;
    qreal     realTimeYScale() const;
    int     realTimeZ() const;
    qreal     realTimeRotation() const;
    qreal     realTimeOpacity() const;
    qreal center_x;
    qreal center_y;
    qreal XscaleFactor;
    qreal YscaleFactor;
    qreal w;
    qreal h;
    qreal rotaionAngle;
    qreal opacityValue;
    qreal x_anchor;
    qreal y_anchor;
    int nodetag;
    bool isTouchEnabled;

};

#endif // CCNODE_H