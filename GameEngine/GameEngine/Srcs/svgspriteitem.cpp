#include "svgspriteitem.h"


svgspriteitem::svgspriteitem(QSvgRenderer *renderer, const QString &eleID,float width,float height) {
    renderedSVG = renderer;
    setSharedRenderer(renderer);
    setElementId(eleID);
    svgW = width;
    svgH = height;
    setFlag(QGraphicsItem::ItemSendsGeometryChanges,0);
    setFlag(QGraphicsItem::ItemIsMovable,0);
    setFlag(QGraphicsItem::ItemIsSelectable,0);
    setFlag(QGraphicsItem::ItemIsFocusable,0);
    setFlag(QGraphicsItem::ItemIgnoresTransformations,0);
    setFlag(QGraphicsItem::ItemIgnoresParentOpacity,0);
    setFlag(QGraphicsItem::ItemAcceptsInputMethod,0);
    setFlag(QGraphicsItem::ItemNegativeZStacksBehindParent,0);

}

svgspriteitem::~svgspriteitem() {
}

qreal svgspriteitem::width() {
    return svgW;
}

qreal svgspriteitem::height() {
    return svgH;
}

