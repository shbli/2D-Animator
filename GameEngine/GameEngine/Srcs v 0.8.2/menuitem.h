#ifndef MENUITEM_H
#define MENUITEM_H
#include "node.h"

class MenuItem : public Node
{
    Q_OBJECT
public:
    MenuItem();
    virtual void setEnabled(bool) = 0;
    void buttonClicked() { emit signalClicked(); }
private:
    QGraphicsScene* getSharedGraphicScene(){ return 0; }
    void setSharedGraphicScene(QGraphicsScene* graphicscene){ return; }
    QGraphicsItem* getGraphicsItem(){ return 0; }
    void setGraphicsItem(QGraphicsItem* item) { return;}
    void setW(qreal w) {}
    void setH(qreal h) {}
signals:
    void signalClicked();
};

#endif // MENUITEM_H
