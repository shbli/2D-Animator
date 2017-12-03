#ifndef MENUITEMLABEL_H
#define MENUITEMLABEL_H
#include "menuitem.h"
#include "textitem.h"

class MenuItemLabel : public MenuItem
{
    Q_OBJECT
public:
    static MenuItemLabel* LabelWith(const QString text,QColor *color = 0,int fontSize = 16, QString font = "Times",QObject* target = 0,const QString slot = "");

private:
    MenuItemLabel(const QString &text,QColor *color = 0,int fontSize = 16,
                  QString font = "Times",QObject* target = 0,const QString slot = 0);
    textItem* item;
    qreal getwidth();
    qreal getheight();
    qreal originalscal;
    void setEnabled(bool);
    bool touchable;
    bool click;
    bool contains(QPointF point);
    action* currAction;
public slots:
    virtual void touchBegin(QGraphicsSceneMouseEvent *event);
    virtual void touchMove(QGraphicsSceneMouseEvent *event);
    virtual void touchEnd(QGraphicsSceneMouseEvent *event);
};

#endif // MENUITEMLABEL_H
