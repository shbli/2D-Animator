#include "linenode.h"

lineNode::lineNode() {

}

lineNode *lineNode::lineWithPen(const QPen &pen) {
    lineNode* newLine = new lineNode;
    newLine->item = new QGraphicsLineItem();
    newLine->item->setPen(pen);
    newLine->Node::setGraphicsItem(newLine->item);
    return newLine;
}

void lineNode::setLineEndPoints(float x1, float y1, float x2, float y2) {
    item->setLine(x1,-y1,x2,-y2);
}
