#include "sprite.h"

Sprite::Sprite(const QString &filename) {
    item = new spriteItem(filename,0,"");
    Node::setGraphicsItem(item);
    Node::setW(item->width());
    Node::setH(item->height());
    setPos(0,0);
}

Sprite::Sprite(const QString &filename, float scaleValue)
{
    item = new spriteItem(filename,false,scaleValue,"");
    Node::setGraphicsItem(item);
    Node::setW(item->width());
    Node::setH(item->height());
    setPos(0,0);
}

Sprite::~Sprite() {
    //deleting item will make the app crash, because it's already being deleted somewhere else
//    delete item;
}

qreal Sprite::getwidth() {
    return item->width();
}

qreal Sprite::getheight() {
    return item->height();
}

Sprite* Sprite::spriteWithImage(const char* filename) {
    Sprite* newsprite = new Sprite(QString(filename));
    return newsprite;
}

Sprite *Sprite::spriteWithSvg(const char *filename, float scaleValue)
{
    Sprite* newsprite = new Sprite(QString(filename),scaleValue);
    return newsprite;
}



