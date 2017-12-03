#ifndef SVG_SCENE_H
#define SVG_SCENE_H
#include "game_engine.h"
#include "global_keys.h"
#include "human_char_controller.h"
#include "enemy_char_controller.h"
#include "health_bar.h"
#include "map.h"

#define testBuild


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
    character_base* xml_test_character;
    map* xml_test_map;
    bool rotation;
    int elementID;
    QLineEdit* dragDropLineEdit;
    QLineEdit* dragDropLineEditX;
    void set_transparent();
    void set_un_transparent();

private:
//    QSvgRenderer *renderer;
    QRect winSize;
    qreal backGroundHeight;
    Sprite *background;
    QList<svgSprite*> cards;
    int counter;
    health_bar* testHealthBarLayer;
    QString currentAnimationName;
    float healthBarValue;
    QPointF prevPoint;
    bool moveMentDetected;
    lineNode* line;
    Elips* elips;
    Elips* elipsstart;
    bool mouse_pressed;

public slots:
    void decreaseHealthBar();
    void setXMLTestCharacterCurrentAnimationTime(QString newAnimationName,int time);
    void runAnimationOnCharacter();
    void stopAnimationOnCharacter();
    void update(double delta);
    void animation();
    void performanceRandomAnimationTest();
    void loadSVGasPixmap();
    void loadCharacterFromXML(QString xml_file_name);
    void loadMapFromXML(QString xml_file_name);
    void testHealthBar();
    void stopAllAnimatedCharacters();
    void touchBegin(QGraphicsSceneMouseEvent *event);
    void touchMove(QGraphicsSceneMouseEvent *event);
    void touchEnd(QGraphicsSceneMouseEvent *event);
    void updateJointSelection();
    void hideLine();
signals:
    void signal_new_postion(float x,float y);
    void signal_new_rotation(float r);

};

#endif // SVG_SCENE_H
