#ifndef SVGSPRITE_H
#define SVGSPRITE_H
#include "node.h"
#include "svgspriteitem.h"

class svgSprite : public Node {

public:
    static svgSprite* spriteSVGwith(QSvgRenderer *renderer,const QString eleID,float width,float height);
    ~svgSprite();
private:
    svgSprite(QSvgRenderer *renderer,const QString &eleID,float width,float height);
    svgspriteitem* item;
    QGraphicsScene* getSharedGraphicScene(){ return 0; }
    void setSharedGraphicScene(QGraphicsScene* graphicscene){ return; }
    qreal getwidth();
    qreal getheight();
    QGraphicsItem* getGraphicsItem(){ return Node::getGraphicsItem(); }
    void setGraphicsItem(QGraphicsItem* item) { return;}
    void setW(qreal w) {}
    void setH(qreal h) {}
    QPointF transformPoint;

};

#endif // SVGSPRITE_H
