#ifndef SVGSPRITEITEM_H
#define SVGSPRITEITEM_H
#include <QGraphicsSvgItem>

class svgspriteitem : public QGraphicsSvgItem
{
public:
    svgspriteitem(QSvgRenderer *renderer,const QString &eleID,float width,float height);
    ~svgspriteitem();
    qreal width();
    qreal height();
private:
    QSvgRenderer *renderedSVG;
    float svgW;
    float svgH;
};

#endif // SVGSPRITEITEM_H
