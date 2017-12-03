#include "health_animation.h"


void health_animation::deleteSelf() {
    line->parent->removeChild(line);
    deleteLater();
}

health_animation::health_animation(QPointF start, QPointF end, QPen linePen, Layer* parentLayer) {

    linePen.setWidth(20);
    line = lineNode::lineWithPen(linePen);
    line->setLineEndPoints(start.x(),0,end.x(),0);
    line->setPos(15,0);
    line->setOpacity(0);
    line->setZ(10);
    parentLayer->addChild(line);
    line->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.1,100),action::fadeTo(0.4,0),action::FuncCall(this,SLOT(deleteSelf())),NULL));
}
