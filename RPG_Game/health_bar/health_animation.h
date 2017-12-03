#ifndef HEALTH_ANIMATION_H
#define HEALTH_ANIMATION_H

#include <QObject>
#include "game_engine.h"

class health_animation : public QObject
{
    Q_OBJECT
public:
    health_animation(QPointF start, QPointF end,QPen linePen, Layer* parentLayer);
    lineNode* line;
    
signals:
    
public slots:
    void deleteSelf();
};

#endif // HEALTH_ANIMATION_H
