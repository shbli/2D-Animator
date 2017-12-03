#ifndef MENUITEMIMAGE_H
#define MENUITEMIMAGE_H
#include "menuitem.h"
#include "spriteitem.h"

class MenuItemImage : public MenuItem
{
    Q_OBJECT
public:
    static MenuItemImage* itemWith(const char* image,const char* clicked_image = "",QObject* target = 0,const char* slot = 0);
    virtual void setEnabled(bool);

private:
    MenuItemImage(const QString &filename,const QString &clickedfilename,QObject* target = 0,const char* slot = 0);
    spriteItem* item;
    qreal getwidth();
    qreal getheight();
    bool touchable;
    bool click;
    bool contains(QPointF point);
public slots:
    virtual void touchBegin(QGraphicsSceneMouseEvent *event);
    virtual void touchMove(QGraphicsSceneMouseEvent *event);
    virtual void touchEnd(QGraphicsSceneMouseEvent *event);
};

#endif // MENUITEMIMAGE_H
