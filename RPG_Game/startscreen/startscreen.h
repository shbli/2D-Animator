#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "game_engine.h"


class startscreen : public Layer
{
    Q_OBJECT

public:
    startscreen();
    static Scene* scene();
public slots:
    void start_screen_after_glow();
    void hide_screen_after_glow();
    void show_sky();

    void touchEnd(QGraphicsSceneMouseEvent *event);
private:
    float screenScale;
    Sprite* logo;
    Sprite* sky;
};

#endif // STARTSCREEN_H
