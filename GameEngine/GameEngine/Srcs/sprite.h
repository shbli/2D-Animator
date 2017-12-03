#ifndef SPRITE_H
#define SPRITE_H
#include "node.h"
#include "spriteitem.h"

class Sprite : public Node {

protected:
    Sprite(const QString &filename);
    Sprite(const QString &filename,float scaleValue);

public:
    static Sprite* spriteWithImage(const QString filename);
    QString SpriteFileName;
    static Sprite* spriteWithSvg(const QString filename,float scaleValue);
    ~Sprite();
private:
    spriteItem* item;
    QGraphicsScene* getSharedGraphicScene(){ return 0; }
    void setSharedGraphicScene(QGraphicsScene* graphicscene){ return; }
    qreal getwidth();
    qreal getheight();
    QGraphicsItem* getGraphicsItem(){ return Node::getGraphicsItem(); }
    void setGraphicsItem(QGraphicsItem* item) { return;}
    void setW(qreal w) {}
    void setH(qreal h) {}
};

#endif // SPRITE_H
