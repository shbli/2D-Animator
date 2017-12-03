#include "menuitemimage.h"
#include <QGraphicsSceneMouseEvent>
#include "graphicsscene.h"

MenuItemImage::MenuItemImage(const QString &filename,const QString &clickedfilename,QObject* target,const char* slot) {
    if (filename.compare(clickedfilename)==0)
        item = new spriteItem(filename,1,"");
    else
        item = new spriteItem(filename,1,clickedfilename);
    Node::setGraphicsItem(item);
    Node::setW(item->width());
    Node::setH(item->height());
    setPos(0,0);
    //item->setTransformOriginPoint(getwidth()/2,getheight()/2);
    item->setParent(this);
    if (target != 0) {
        connect(this,SIGNAL(signalClicked()),target,slot);
    }
    setEnabled(0);
    click = false;
    touchable = 0;
}

qreal MenuItemImage::getwidth() {
    return item->width();
}

qreal MenuItemImage::getheight() {
    return item->height();
}

MenuItemImage* MenuItemImage::itemWith(const char* image,const char* clicked_image ,QObject* target,const char* slot) {
    MenuItemImage* newimagebutton = new MenuItemImage(QString(image),QString(clicked_image),target,slot);
    return newimagebutton;
}

void MenuItemImage::setEnabled(bool val) {
    item->setEnabled(val);
    if (val&&!touchable) {
        touchable = true;
        connect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchmoved(QGraphicsSceneMouseEvent*)),this,SLOT(touchMove(QGraphicsSceneMouseEvent*)));
        connect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchreleased(QGraphicsSceneMouseEvent*)),this,SLOT(touchEnd(QGraphicsSceneMouseEvent*)));
        connect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchpressed(QGraphicsSceneMouseEvent*)),this,SLOT(touchBegin(QGraphicsSceneMouseEvent*)));
    }
    if (!val&&touchable) {
        touchable = false;
        disconnect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchmoved(QGraphicsSceneMouseEvent*)),this,SLOT(touchMove(QGraphicsSceneMouseEvent*)));
        disconnect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchreleased(QGraphicsSceneMouseEvent*)),this,SLOT(touchEnd(QGraphicsSceneMouseEvent*)));
        disconnect(Director::sharedDirector()->sharedGraphicScene(),SIGNAL(signaltouchpressed(QGraphicsSceneMouseEvent*)),this,SLOT(touchBegin(QGraphicsSceneMouseEvent*)));
    }
}

void MenuItemImage::touchBegin(QGraphicsSceneMouseEvent *event) {
    touchMove(event);
//    qDebug() << "screen = (" << event->screenPos().x() << " , " << event->screenPos().y() << ").";
//    qDebug() << "scene = (" << event->scenePos().x() << " , " << event->scenePos().y() << ").";
}

void MenuItemImage::touchMove(QGraphicsSceneMouseEvent *event) {
    if (touchable) {
        if (!click) {
            //we have to check if our finger is on our item
            if (contains(event->scenePos())) {
                item->setClickedImage();
                click = true;
            }
        }
        else {
            //item is already click, we have to check if finger is out
            //we have to check if our finger is on our item
            if (!contains(event->scenePos())) {
                item->setNormalImage();
                click = false;
            }
        }
    }
}

void MenuItemImage::touchEnd(QGraphicsSceneMouseEvent *event) {
    if (touchable && contains(event->scenePos())) {
        // our item is clicked, do something
        buttonClicked();
    }
    if (click) {
        item->setNormalImage();
        click = false;
    }
}

bool MenuItemImage::contains(QPointF point) {
    QPointF pos = item->pos();
    qreal scale = item->scale();
    if (point.x() >= pos.x())
        if (point.x() <= pos.x()+(width()*scale))
            if (point.y() >= pos.y())
                if (point.y() <= pos.y()+(height()*scale))
                    return 1;
    return 0;
}
