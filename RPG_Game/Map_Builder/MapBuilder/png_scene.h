#ifndef PNG_SCENE_H
#define PNG_SCENE_H

#include "game_engine.h"
#include "human_char_controller.h"
#include "enemy_char_controller.h"


class png_scene : public Layer
{
    Q_OBJECT

public:
    static Scene* scene();
    void onEnterTransitionDidStart();
    void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();
    void onExitTransitionDidFinish();
    ~png_scene();
    //this is for testing purposes only!!!, this shall never be public
    png_scene();
private:
//    QSvgRenderer *renderer;
    QRect winSize;
    human_char_controller* humanLayer;
    qreal backGroundHeight;
    Sprite *background;
    QString currentAnimationName;
public slots:
    void loadCharacterFromXML(QString xml_file_name);
    void stopAllAnimatedCharacters();

};

#endif // PNG_SCENE_H
