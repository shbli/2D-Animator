#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>

class graphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit graphicsScene(QObject *parent = 0);
    void invalidate(const QRectF &rect, SceneLayers layers);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
signals:
    void signaltouchpressed(QGraphicsSceneMouseEvent * mouseEvent);
    void signaltouchmoved(QGraphicsSceneMouseEvent * mouseEvent);
    void signaltouchreleased(QGraphicsSceneMouseEvent * mouseEvent);
private:
    bool mouseDown;

};

#endif // GRAPHICSSCENE_H
