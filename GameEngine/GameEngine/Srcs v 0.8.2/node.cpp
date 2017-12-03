#include "node.h"
#include "qmath.h"

#define pi 3.1415926
#define degtorad pi/180
#define radtodeg 180/pi


qreal pointDistance(QPointF point1,QPointF point2) {
    qreal x = point1.x() - point2.x();
    x *= x;
    qreal y = point1.y() - point2.y();
    y *= y;
    y += x;
    y = sqrt(y);
    return y;
}


int Node::global_max_z = 0;
QGraphicsScene* Node::sharedGraphicScene = 0;

Node::Node() {
    parent = 0;
    graphicsItem = 0;
    center_x = 0;
    center_y = 0;
    z_ = 0;
    nodetag = 0;
    max_local_z = 0;
    w = 0;
    h = 0;
    updatescheduled = 0;
    rotaionAngle = 0;
    opacityValue = 100;
    x_anchor = 0.5;
    y_anchor = 0.5;
    scalingProperties = new QGraphicsScale;
    XscaleFactor = 1;
    YscaleFactor = 1;
    isTouchEnabled = false;
    ignoreParentRotation = false;
}

Node::~Node() {

    // before deleting the item, we'll stop all the actions running on that item!
    stopAllActions();
    // if our nodes includes a graphical item, then yes, we'll remove it from the scene it belongs to
    if (graphicsItem != 0) {
        // we are checking if it's actually belongs to a scene
        if (graphicsItem->scene() != 0) {
            graphicsItem->scene()->removeItem(graphicsItem);
        }
        else {
            qDebug() << "GameEngine :: Warning : deleting an item, which actually doesn't belong to a scene";
        }
        delete graphicsItem;
        graphicsItem = 0;
    } else {
        scalingProperties->deleteLater();
    }
    // we'll recursively delete the childs one by one
    Node* child;
    while (!childs.isEmpty()) {
        child = childs.takeFirst();
        child->deleteLater();
    }
    if (parent == 0) {
        global_max_z = 0;
    }
}

qreal Node::opacity() const {
    return opacityValue;
}

qreal Node::realTimeOpacity() const {
    if (parent != 0) {
        return (opacityValue/100.0) * parent->realTimeOpacity();
    }
    return (opacityValue/100.0);
}

void Node::setOpacity(qreal value) {
    opacityValue = value;
    if (graphicsItem != 0) {
        graphicsItem->setOpacity(realTimeOpacity());
    }

    emit updateChildsOpacity();
}

void Node::updateMyOpacity() {
    setOpacity(opacity());
}

void Node::setEffectiveRotation() {
    if (graphicsItem != 0) {
        //it's a graphics item not a layer nor a scene
        if (ignoreParentRotation) {
            graphicsItem->setRotation(rotaionAngle);
        } else {
            graphicsItem->setRotation((realTimeRotation()));
        }
    }

    emit updateChildsRotation();

    updateMyPos();
}

void Node::setRotation(qreal rotationDegree) {
    setIneffectiveRotation(rotationDegree);
    setEffectiveRotation();
}

void Node::setIneffectiveRotation(qreal rotationDegree) {
    rotaionAngle = rotationDegree;
}
qreal Node::rotation() {
    return rotaionAngle;
}
qreal Node::realTimeRotation() const {
    if (parent!=0)
        return rotaionAngle + parent->realTimeRotation();
    return rotaionAngle;
}
void Node::updateMyRotation() {
    setEffectiveRotation();
}

void Node::setPos(qreal x,qreal y) {
    setPos(QPointF(x,y));
}

void Node::setAnchor(qreal xanchorvalue, qreal yanchorvalue) {
    x_anchor = xanchorvalue;
    y_anchor = yanchorvalue;
    if (graphicsItem != 0) {
        //this doesn't need to update the childs, anchors are only for graphical items
        graphicsItem->setPos(realTimePos());
    }
}
void Node::setIneffectivePos(qreal x, qreal y) {
    center_x = x;
    center_y = y;
}

void Node::setIneffectivePos(const QPointF &point) {
    setIneffectivePos(point.x(),point.y());
}

void Node::setPos(const QPointF &pos)
{
    //here we are setting the position of our node according to it's parent, and it's parameter is the center point
    setIneffectivePos(pos.x(),pos.y());
    setEffectivePos();
}

void Node::setEffectivePos()
{
    if (graphicsItem != 0) {
        //it's a graphics item not a layer nor a scene we'll set that to the new position
        graphicsItem->setPos(realTimePos());
    }

    emit updateChildsPos();
}

void Node::setScale(qreal factor) {
    setScale(factor,factor);
}

void Node::setScale(qreal factorx, qreal factory) {
    XscaleFactor = factorx;
    YscaleFactor = factory;
    if (graphicsItem != 0) {
        //it's a graphics item not a layer nor a scene
        scalingProperties->setXScale(realTimeXScale());
        scalingProperties->setYScale(realTimeYScale());
    }
    emit updateChildsScale();

    updateMyPos();
}

void Node::setScaleX(qreal factorx) {
    setScale(factorx,YscaleFactor);
}

void Node::setScaleY(qreal factory) {
    setScale(XscaleFactor,factory);
}

QPointF Node::realTimePos() const {
    qreal scalew = 0;
    qreal scaleh = 0;
    qreal rotatedx = center_x;
    qreal rotatedy = center_y;
    qreal moveByX = 0;
    qreal moveByY = 0;
    qreal distance = 0;
    qreal xangleOnCircle = 0;
    if (parent != 0) {
        //find the rotated position
        if (rotatedx != 0 || rotatedy != 0) {
            distance = pointDistance(QPointF(0,0),QPointF(rotatedx,rotatedy));
            // we want to move in a circule so we'll try to find what angle x lies on
            // using this know equation x = cx + r * cos(a)
            // our cx = 0,0 so cos(a) = x/r or the distance, we'll get the inverse
            xangleOnCircle;
            if (rotatedy > 0) {
                xangleOnCircle = rotatedy/distance;
            } else {
                xangleOnCircle = -rotatedy/distance;
            }
            xangleOnCircle = asin(xangleOnCircle);
            xangleOnCircle *= radtodeg;
            xangleOnCircle += parent->realTimeRotation();
            xangleOnCircle *= degtorad;

            // now we'll use this angle, and the distance, to find the point in out circle
            if (rotatedx < 0) {
                rotatedx = (distance*cos(xangleOnCircle)) * -1;
            }
            else {
                rotatedx = distance*cos(xangleOnCircle);
            }
            if (rotatedy < 0) {
                rotatedy = (distance*sin(xangleOnCircle)) * -1;
            }
            else {
                rotatedy = distance*sin(xangleOnCircle);
            }



        }

    }

    if (w != 0 || h != 0) {


//        scalew=(w*graphicsItem->scale())/2;
//        scaleh=(h*graphicsItem->scale())/2;

//        //that was the new point for the layer, now we'll center the item iteself,so rotation is done around center
//        distance = pointDistance(QPointF(0,0),QPointF(scalew,scaleh));
//        // here, we already have the rotation of the item
//        xangleOnCircle = ((h*graphicsItem->scale())/2)/distance;


//start of new modification

        scalew=(w*scalingProperties->xScale())*x_anchor;
        scaleh=(h*scalingProperties->yScale())*y_anchor;

        //that was the new point for the layer, now we'll center the item iteself,so rotation is done around center
        distance = pointDistance(QPointF(0,0),QPointF(scalew,scaleh));
        // here, we already have the rotation of the item
        xangleOnCircle = 0;
        //we cannot divide on zero
        if (distance != 0) {
            xangleOnCircle = ((h*scalingProperties->yScale())*y_anchor)/distance;
        }
// end of the new modification

        xangleOnCircle = asin(xangleOnCircle);
        //convert it
        xangleOnCircle *= radtodeg;
        xangleOnCircle = 180.0 - xangleOnCircle;
        xangleOnCircle -= graphicsItem->rotation();
        xangleOnCircle *= degtorad;

        //now we just have to find the new diffrence
        moveByX = distance*cos(xangleOnCircle);
        moveByY = distance*sin(xangleOnCircle);
        if (scalingProperties->xScale() < 0) {
            moveByX *= -1;
        }
        moveByX = scalew + moveByX;
        moveByY = moveByY - scaleh;

    }
    if (parent != 0) {
        QPointF realtimePoint = parent->realTimePos();
        qreal realscalex = parent->realTimeXScale();
        qreal realscaley = parent->realTimeYScale();
        return QPointF(realtimePoint.x() + ((rotatedx) * realscalex) - scalew + moveByX ,realtimePoint.y() - (rotatedy* realscaley) - scaleh - moveByY);
    } else {
        return QPointF(center_x,center_y);
    }
}

qreal Node::realTimeXScale() const {
    if (parent != 0)
        return XscaleFactor*parent->realTimeXScale();
    return XscaleFactor;
}

qreal Node::realTimeYScale() const {
    if (parent != 0)
        return YscaleFactor*parent->realTimeYScale();
    return YscaleFactor;
}

QPointF Node::pos() const {
    return QPointF(center_x,center_y);
}

QPointF Node::anchorPoint() const {
    return QPointF(x_anchor,y_anchor);
}

qreal Node::scale() {
    return XscaleFactor;
}

qreal Node::scaleX() {
    return XscaleFactor;
}

qreal Node::scaleY() {
    return YscaleFactor;
}
int Node::realTimeZ() const {
    if (parent != 0) {
        //am not the grand parent
        return parent->realTimeZ() + z_;
    }
    //here if am the grand parent, basically I'll return my Z level
    return z_ + global_max_z;
}

void Node::setZ(int zValue) {
    z_ = zValue;
    if (graphicsItem != 0) {
        graphicsItem->setZValue(realTimeZ());
    }

    emit updateChildsZ();

}
void Node::updateMyPos() {
    setEffectivePos();
}

void Node::updateMyScale() {
    setScale(XscaleFactor,YscaleFactor);
}

void Node::updateMyZ() {
    setZ(z());
}



action* Node::runAction(action* actionPara) {
    actionPara->setTarget(this);
    actions.append(actionPara);
    return actionPara;
}

void Node::actionDone(action* doneAction) {
    stopAction(doneAction);
}


void Node::stopAction(action* stopAction) {
    bool found = false;
    for (int i=0;i<actions.size()&&!found;i++) {
        if(actions.at(i) == stopAction) {
            found = true;
            stopAction->stopAnimation();
            actions.removeAt(i);
            stopAction->deleteLater();
        }
    }
}

void Node::setGraphicsEffect(QGraphicsEffect *effect) {
    if (graphicsItem != 0) {
        //the graphics item will automatically delete the old effect and create a new effect for that one
        graphicsItem->setGraphicsEffect(effect);
    } else {
        //there's no real item to apply the effect on, so we will delete that effect and debug a warning
        effect->deleteLater();
        qDebug() << "Warning, applying an effect on a Node that contains no GraphicsItem!!! ie, Layer or a scene, if you want to apply an effect on childs, you have to apply the effect manually on each child speratly";
    }
}

void Node::stopSequence(Sequence* stopAction) {
    bool found = false;
    for (int i=0;i<sequences.size()&&!found;i++) {
        if(sequences.at(i) == stopAction) {
            found = true;
            stopAction->stopActions();
            sequences.removeAt(i);
            stopAction->deleteLater();
        }
    }
}

void Node::stopAllActions() {
    while (!sequences.isEmpty()) {
        stopSequence(sequences.first());
    }
    while (!actions.isEmpty()) {
        stopAction(actions.first());
    }
}

QGraphicsScene * Node::getSharedGraphicScene() {
    return sharedGraphicScene;
}

void Node::setSharedGraphicScene(QGraphicsScene *graphicscene) {
    sharedGraphicScene = graphicscene;
}

int Node::getGlobalMaxZ() {
    return global_max_z;
}

void Node::setGraphicsItem(QGraphicsItem *item) {
    graphicsItem = item;
    //adding the scaling properties to the item tranformation
    graphicsItem->setTransformations(graphicsItem->transformations() << scalingProperties);
}

QGraphicsItem * Node::getGraphicsItem() {
    return graphicsItem;
}

void Node::setW(qreal ww) {
    w = ww;
}

void Node::setH(qreal hh) {
    h = hh;
}

void Node::schedualUpdate() {
    if (!updatescheduled) {
        updatescheduled = 1;
        connect(Director::sharedDirector(),SIGNAL(update(double)),this,SLOT(update(double)));
    }
    else {
        qDebug() << "Game Engine :: you cannot Schedual an update that is already schedualed!!";
    }
}

void Node::unSchedualUpdate() {
    if (updatescheduled) {
        updatescheduled = 0;
        disconnect(Director::sharedDirector(),SIGNAL(update(double)),this,SLOT(update(double)));
    }
    else {
        qDebug() << "Game Engine :: you cannot unSchedual an update that is already unschedualed!!";
    }
}

void Node::update(double delta) {
    qDebug() << "Game Engine :: to schedual an update, please overload this methode as a public slot, \"void ClassName::update(double delta)\", delta is the time elapsed in seconds since last update, with milliseconds after decimal points, this methode is called at every frame, now this will unschedual itself!!";
    unSchedualUpdate();
}

void Node::runSequence(Sequence *sequencePara) {
    sequencePara->setTarget(this);
    sequences.append(sequencePara);
}

qreal Node::width() {
    return w;
}

qreal Node::height() {
    return h;
}

int Node::z() {
    return z_;
}

//child managment methodes

void Node::addChild(Node *child, int tag, int z) {
    // I'm this child parent!!
    child->parent = this;
    //move the childs to parents thread
    child->moveToThread(this->thread());
    //I'll add this child to my childs list
    this->childs.append(child);
    //I'll also set it's tag
    child->nodetag = tag;
    // setting the Z
    child->setZ(child->z());
    child->setPos(child->pos());
    child->setScale(child->scale());
    connect(this,SIGNAL(updateChildsPos()),child,SLOT(updateMyPos()));
    connect(this,SIGNAL(updateChildsScale()),child,SLOT(updateMyScale()));
    connect(this,SIGNAL(updateChildsZ()),child,SLOT(updateMyZ()));
    connect(this,SIGNAL( updateChildsRotation() ),child,SLOT( updateMyRotation() ) );
    connect(this,SIGNAL( updateChildsOpacity() ),child,SLOT( updateMyOpacity() ) );
    if (child->graphicsItem != 0) {
        // if this is actually some item, ie, not a layer nor a scene, we'll add it to the view
        sharedGraphicScene->addItem(child->graphicsItem);
    } else {
    }
}

Node* Node::getChildByTag(int tag) {
    bool found = false;
    Node *child = 0;
    for (int i=0; !found && i<childs.size() ;i++) {
        child = childs.at(i);
        if(child->nodetag == tag) {
            found = true;
        }
    }
    return child;
}

void Node::removeChildByTag(int tag) {
    bool found = false;
    Node *child = 0;
    for (int i=0; !found && i<childs.size() ;i++) {
        child = childs.at(i);
        if(child->nodetag == tag) {
            found = true;
            childs.removeAt(i);
            child->deleteLater();
        }
    }
    if (!found)
        qDebug() << "Node :: Child tag " << tag << " is not found, cannot delete it";
}

void Node::removeChild(Node *child) {
    bool found = false;
    Node *c = 0;
    for (int i=0; !found && i<childs.size() ;i++) {
        c = childs.at(i);
        if(c == child) {
            found = true;
            childs.removeAt(i);
            child->deleteLater();
        }
    }
    if (!found)
        qDebug() << "Node :: Child Address " << child << " is not found, cannot delete it";
}


//endOf child managment methodes


void Node::setTouchEnabled(bool enabled) {
    if (!isTouchEnabled) {
        if (enabled) {
            //enable the touch, it was disabled and a request to enable it for this layer
            isTouchEnabled = true;
            connect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchmoved(QGraphicsSceneMouseEvent*)),this,SLOT(touchMove(QGraphicsSceneMouseEvent*)));
            connect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchreleased(QGraphicsSceneMouseEvent*)),this,SLOT(touchEnd(QGraphicsSceneMouseEvent*)));
            connect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchpressed(QGraphicsSceneMouseEvent*)),this,SLOT(touchBegin(QGraphicsSceneMouseEvent*)));
        }
    } else {
        if (!enabled) {
            //disable the touch, and a request to disable it is sent
            isTouchEnabled = false;
            disconnect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchmoved(QGraphicsSceneMouseEvent*)),this,SLOT(touchMove(QGraphicsSceneMouseEvent*)));
            disconnect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchreleased(QGraphicsSceneMouseEvent*)),this,SLOT(touchEnd(QGraphicsSceneMouseEvent*)));
            disconnect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchpressed(QGraphicsSceneMouseEvent*)),this,SLOT(touchBegin(QGraphicsSceneMouseEvent*)));
        }
    }
}

qreal Node::getwidth() {
    return w;
}

qreal Node::getheight() {
    return h;
}


