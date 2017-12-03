#include "graphicsscene.h"
#include "QDebug"
#include <QGraphicsSceneMouseEvent>
#include "director.h"

graphicsScene::graphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
    mouseDown = 0;
    setSceneRect(0,0,Director::sharedDirector()->winSizeInPixels().width(),Director::sharedDirector()->winSizeInPixels().height());
}

void graphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit signaltouchpressed(event);
    mouseDown = 1;
}
void graphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (mouseDown) emit signaltouchmoved(event);
}
void graphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    emit signaltouchreleased(event);
    mouseDown = 0;
}
