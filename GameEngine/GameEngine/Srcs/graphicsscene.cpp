#include "graphicsscene.h"
#include "QDebug"
#include <QGraphicsSceneMouseEvent>
#include "director.h"

graphicsScene::graphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
    mouseDown = 0;
    setSceneRect(0,0,Director::sharedDirector()->winSizeInPixels().width(),Director::sharedDirector()->winSizeInPixels().height());
    setItemIndexMethod(QGraphicsScene::NoIndex);


}

void graphicsScene::invalidate(const QRectF &rect, QGraphicsScene::SceneLayers layers) {
    QGraphicsScene::invalidate(rect,QGraphicsScene::ItemLayer);
}

void graphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit signaltouchpressed(event);
    mouseDown = true;
}
void graphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (mouseDown)
        emit signaltouchmoved(event);
}
void graphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    emit signaltouchreleased(event);
    mouseDown = false;
}
