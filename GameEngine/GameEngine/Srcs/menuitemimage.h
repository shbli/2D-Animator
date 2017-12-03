#ifndef MENUITEMIMAGE_H
#define MENUITEMIMAGE_H
#include "menuitem.h"
#include "spriteitem.h"

class MenuItemImage : public MenuItem
{
    Q_OBJECT
public:
    static MenuItemImage* itemWith(const QString image,const QString clicked_image = "",QObject* target = 0,const QString slot = 0);
    static MenuItemImage* itemWithSVG(const QString image,const QString clicked_image ,QObject* target,const QString slot,float scale);
    virtual void setEnabled(bool);
    QString spriteFileName;
    QString spriteFileNameClicked;


private:
    MenuItemImage(const QString &filename,const QString &clickedfilename,QObject* target = 0,const QString slot = 0, bool isVector = 0,float scale = 0);
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
