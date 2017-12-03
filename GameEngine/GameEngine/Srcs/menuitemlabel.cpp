#include "menuitemlabel.h"
#include <QGraphicsSceneMouseEvent>
#include "graphicsscene.h"

MenuItemLabel::MenuItemLabel(const QString &text,QColor *color,int fontSize,QString font,QObject* target,const QString slot) {
    item = new textItem;
    item->setPlainText(text);
    if (color == 0)
        item->setDefaultTextColor(QColor(255,255,255,255));
    else
        item->setDefaultTextColor(*color);
    QFont newfont(font,fontSize);
    newfont.setPixelSize(newfont.pointSize());
    newfont.setBold(true);
    item->setFont(newfont);
    Node::setGraphicsItem(item);
    Node::setW(item->width());
    Node::setH(item->height());
    setPos(0,0);
    //item->setParent(this);
    if (target != 0) {
        connect(this,SIGNAL(signalClicked()),target,slot.toStdString().c_str());
    }
    setEnabled(0);
    click = false;
    touchable = 0;
    currAction = 0;

}

qreal MenuItemLabel::getwidth() {
    return item->width();
}

qreal MenuItemLabel::getheight() {
    return item->height();
}

MenuItemLabel* MenuItemLabel::LabelWith(const QString text, QColor *color, int fontSize, QString font, QObject *target, const QString slot) {
    MenuItemLabel* newlabelbutton = new MenuItemLabel(text,color,fontSize,font,target,slot);
    return newlabelbutton;
}

void MenuItemLabel::setEnabled(bool val) {
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

void MenuItemLabel::touchBegin(QGraphicsSceneMouseEvent *event) {
    originalscal = item->scale();
    touchMove(event);
    //qDebug() << "screen = (" << event->screenPos().x() << " , " << event->screenPos().y() << ").";
    //qDebug() << "scene = (" << event->scenePos().x() << " , " << event->scenePos().y() << ").";
}

void MenuItemLabel::touchMove(QGraphicsSceneMouseEvent *event) {
    if (touchable) {
        if (!click) {
            //we have to check if our finger is on our item
            if (contains(event->scenePos())) {
                stopAction(currAction);
                currAction = runAction(action::scaleTo(0.075,originalscal*1.5));
                click = true;
            }
        }
        else {
            //item is already click, we have to check if finger is out
            //we have to check if our finger is on our item
            if (!contains(event->scenePos())) {
                stopAction(currAction);
                currAction = runAction(action::scaleTo(0.075,originalscal));
                click = false;
            }
        }
    }
}

void MenuItemLabel::touchEnd(QGraphicsSceneMouseEvent *event) {
    if (touchable && contains(event->scenePos())) {
        // our item is clicked, do something
        buttonClicked();
        stopAction(currAction);
        currAction = runAction(action::scaleTo(0.075,originalscal));
    }
    click = false;
}

bool MenuItemLabel::contains(QPointF point) {
    QPointF pos = item->pos();
    //qDebug() <<"( " << pos.x() << " , " << pos.y() << " )";
    qreal scale = item->scale();
    if (point.x() >= pos.x())
        if (point.x() <= pos.x()+(width()*scale))
            if (point.y() >= pos.y())
                if (point.y() <= pos.y()+(height()*scale))
                    return 1;
    return 0;
}
