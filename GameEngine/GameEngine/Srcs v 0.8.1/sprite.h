#ifndef SPRITE_H
#define SPRITE_H
#include "node.h"
#include "spriteitem.h"

class Sprite : public Node {

private:

public:
    static Sprite* spriteWithImage(const char* filename);
    static Sprite* spriteWithSvg(const char* filename,float scaleValue);
    ~Sprite();
private:
    Sprite(const QString &filename);
    Sprite(const QString &filename,float scaleValue);
    spriteItem* item;
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

#endif // SPRITE_H
