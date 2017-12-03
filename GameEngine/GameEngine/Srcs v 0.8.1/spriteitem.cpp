#include "spriteitem.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QBitmap>
#include "graphicsscene.h"
#include <QTransform>
#include <QSvgRenderer>

spriteItem::spriteItem(const QString &filename,bool button,const QString &clickedFileName) {

    bool load = QPixmapCache::find(filename,&normal);
    if (!load) {
        load = normal.load(filename);
        if (load) {
            QPixmapCache::insert(filename,normal);
        } else {
            qDebug() << "Game Engine :: File \"" << filename << "\" is not successfuly loaded, make sure file exists";
        }
    }
    if (button) {
        if (clickedFileName == "") {
            if (load) {
                clicked.load(filename);
            }
        }
        else {
            bool load = QPixmapCache::find(clickedFileName,&clicked);
            if (!load) {
                load = clicked.load(clickedFileName);
                if (load) {
                    QPixmapCache::insert(clickedFileName,clicked);
                } else {
                    qDebug() << "Game Engine :: File \"" << clickedFileName << "\" is not successfuly loaded, make sure file exists";
                }
            }
        }
    }
    setSpriteFlags();
}

spriteItem::spriteItem(const QString &filename, bool button, float scaleValu, const QString &clickedFileName) {
    bool load = QPixmapCache::find(filename + QString().setNum(scaleValu),&normal);
    QSvgRenderer renderer;
    if (!load) {
        load = renderer.load(QLatin1String(filename.toAscii()));
        QPixmap image(renderer.defaultSize()*scaleValu);
        image.fill(Qt::transparent);
        QPainter painter(&image);
        renderer.render(&painter);

        normal = image;
        if (load) {
            QPixmapCache::insert(filename + QString().setNum(scaleValu),normal);
        } else {
            qDebug() << "Game Engine :: File \"" << filename << "\" is not successfuly loaded, make sure file exists";
        }
    }
    if (button) {
        if (clickedFileName == "") {
            if (load) {
                clicked = normal;
            }
        }
        else {
            bool load = QPixmapCache::find(clickedFileName + QString().setNum(scaleValu),&clicked);
            if (!load) {
                load = renderer.load(QLatin1String(clickedFileName.toAscii()));
                QPixmap image2(renderer.defaultSize()*scaleValu);
                image2.fill(Qt::transparent);
                QPainter painter(&image2);
                renderer.render(&painter);
                clicked = image2;
                if (load) {
                    QPixmapCache::insert(clickedFileName + QString().setNum(scaleValu),clicked);
                } else {
                    qDebug() << "Game Engine :: File \"" << clickedFileName << "\" is not successfuly loaded, make sure file exists";
                }
            }
        }
    }
    setSpriteFlags();

}
spriteItem::~spriteItem() {

}

qreal spriteItem::height() {
    return this->pixmap().height();
}
qreal spriteItem::width() {
    return this->pixmap().width();
}


void spriteItem::setParent(MenuItem *parent) {
    parentMenuItem = parent;
}

void spriteItem::setSpriteFlags()
{
    setPixmap(normal);
    setTransformationMode(Qt::SmoothTransformation);
    parentMenuItem = 0;
    setFlag(QGraphicsItem::ItemSendsGeometryChanges,0);
    setFlag(QGraphicsItem::ItemIsMovable,0);
    setFlag(QGraphicsItem::ItemIsSelectable,0);
    setFlag(QGraphicsItem::ItemIsFocusable,0);
    setFlag(QGraphicsItem::ItemIgnoresTransformations,0);
    setFlag(QGraphicsItem::ItemIgnoresParentOpacity,0);
    setFlag(QGraphicsItem::ItemAcceptsInputMethod,0);
    setFlag(QGraphicsItem::ItemNegativeZStacksBehindParent,0);
    setEnabled(0);
    setCacheMode(QGraphicsItem::NoCache);
}

