#ifndef PNG_SCENE_H
#define PNG_SCENE_H

#include "game_engine.h"
#include "global_keys.h"
#include <QList>


class png_scene : public Layer
{
    Q_OBJECT

public:
    static Scene* scene();
    explicit png_scene();
    void onEnterTransitionDidStart();
    void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();
    void onExitTransitionDidFinish();
private:
    QRect winSize;
    qreal backGroundHeight;
    Sprite *background;
    QList<Sprite*> cards;
    int counter;
public slots:
    void update(double delta);
    void animation();
    void performanceRandomAnimationTest();
};

#endif // PNG_SCENE_H
