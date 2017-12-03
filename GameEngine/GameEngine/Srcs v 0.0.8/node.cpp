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
    scaleFactor = 1.0;
    z_ = 0;
    max_local_z = 0;
    w = 0;
    h = 0;
    updatescheduled = 0;
    rotaionAngle = 0;
    opacityValue = 100;
    isTouchEnabled = false;
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
    else {
        emit updateChildsOpacity();
    }
}

void Node::updateMyOpacity() {
    setOpacity(opacity());
}

void Node::setRotation(qreal rotationDegree) {
    rotaionAngle = rotationDegree;
    if (graphicsItem != 0) {
        //it's a graphics item not a layer nor a scene
        graphicsItem->setRotation((-realTimeRotation()));
        int realrotation = graphicsItem->rotation();
        if (realrotation%90 == 0) {
            //disable antianalising
        }
        else {
            //enable antianalising
        }
    }
    else {
        emit updateChildsRotation();
    }
    updateMyPos();

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
    setRotation(rotation());
}

void Node::setPos(qreal x,qreal y) {
    setPos(QPointF(x,y));
}

void Node::setPos(const QPointF &pos)
{
    //here we are setting the position of our node according to it's parent, and it's parameter is the center point
    center_x = pos.x();
    center_y = pos.y();
    if (graphicsItem != 0) {
        //it's a graphics item not a layer nor a scene we'll set that to the new position
        graphicsItem->setPos(realTimePos());
    }
    else {
        emit updateChildsPos();
    }
}

void Node::setScale(qreal factor)
{
    scaleFactor = factor;
    if (graphicsItem != 0) {
        //it's a graphics item not a layer nor a scene
        qreal realScale = realTimeScale();
        graphicsItem->setScale(realScale);
    }
    else {
        emit updateChildsScale();
    }
    updateMyPos();
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

    if (graphicsItem != 0) {


        scalew=(w*graphicsItem->scale())/2;
        scaleh=(h*graphicsItem->scale())/2;

        //that was the new point for the layer, now we'll center the item iteself,so rotation is done around center
        distance = pointDistance(QPointF(0,0),QPointF(scalew,scaleh));
        // here, we already have the rotation of the item
        xangleOnCircle = ((h*graphicsItem->scale())/2)/distance;
        xangleOnCircle = asin(xangleOnCircle);
        //convert it
        xangleOnCircle *= radtodeg;
        xangleOnCircle = 180.0 - xangleOnCircle;
        xangleOnCircle -= graphicsItem->rotation();
        xangleOnCircle *= degtorad;

        //now we just have to find the new diffrence
        moveByX = distance*cos(xangleOnCircle);
        moveByY = distance*sin(xangleOnCircle);

        moveByX = scalew + moveByX;
        moveByY = moveByY - scaleh;

    }
    if (parent != 0) {
        QPointF realtimePoint = parent->realTimePos();
        qreal realscale = parent->realTimeScale();
        return QPointF(realtimePoint.x() + ((rotatedx) * realscale) - scalew + moveByX ,realtimePoint.y() - (rotatedy* realscale) - scaleh - moveByY);
    }
    else {
        return QPointF(center_x,center_y);
    }
}

qreal Node::realTimeScale() const {
    if (parent != 0)
        return scaleFactor*parent->realTimeScale();
    return scaleFactor;
}

QPointF Node::pos() const {
    return QPointF(center_x,center_y);
}

qreal Node::scale() {
    return scaleFactor;
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
    else {
        emit updateChildsZ();
    }
}
void Node::updateMyPos() {
    setPos(pos());
}

void Node::updateMyScale() {
    setScale(scale());
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

