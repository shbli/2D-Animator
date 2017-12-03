#ifndef SVG_SCENE_H
#define SVG_SCENE_H
#include "game_engine.h"
#include "global_keys.h"
#include "weapon.h"

class svg_scene : public Layer
{
    Q_OBJECT

public:
    static Scene* scene();
    void onEnterTransitionDidStart();
    void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();
    void onExitTransitionDidFinish();
    ~svg_scene();
    //this is for testing purposes only!!!, this shall never be public
    svg_scene();
private:
//    QSvgRenderer *renderer;
    weapon* testWeapon;
    QRect winSize;
    qreal backGroundHeight;
    Sprite *background;
    QList<svgSprite*> cards;
    int counter;
    QString currentAnimationName;
//    QPixmap *image;
public slots:
    void setXMLTestCharacterCurrentAnimationTime(QString newAnimationName,int time);
    void runAnimationOnCharacter();
    void stopAnimationOnCharacter();
    void update(double delta);
    void animation();
    void performanceRandomAnimationTest();
    void loadSVGasPixmap();
    void loadCharacterFromXML(QString xml_file_name);

};

#endif // SVG_SCENE_H
