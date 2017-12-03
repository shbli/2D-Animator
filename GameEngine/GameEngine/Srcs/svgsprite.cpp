#include "svgsprite.h"

svgSprite *svgSprite::spriteSVGwith(QSvgRenderer *renderer, const QString eleID, float width, float height) {
    svgSprite* newsvgsprite = new svgSprite(renderer,QString(eleID),width,height);
    return newsvgsprite;
}

svgSprite::~svgSprite() {
}

svgSprite::svgSprite(QSvgRenderer *renderer, const QString &eleID, float width, float height) {
    item = new svgspriteitem(renderer,eleID,width,height);
    Node::setGraphicsItem(item);
    Node::setW(item->width());
    Node::setH(item->height());
    setPos(0,0);
}

qreal svgSprite::getwidth() {
    return item->width();
}

qreal svgSprite::getheight() {
    return item->height();
}
