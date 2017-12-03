#ifndef SVG_SCENE_H
#define SVG_SCENE_H
#include "game_engine.h"
#include "human_char_controller.h"
#include "enemy_char_controller.h"
#include "health_bar.h"
#include "skeltal_hbox.h"

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
    skeltal_hbox* dragAndDropJoint;
    character_base* xml_test_character;
    character_base* xml_test_dump_enemy_character;
    bool rotation;
    QLineEdit* dragDropLineEdit;
    QLineEdit* dragDropLineEditX;

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

public slots:
    void decreaseHealthBar();
    void setXMLTestCharacterCurrentAnimationTime(QString newAnimationName,int time);
    void runAnimationOnCharacter();
    void stopAnimationOnCharacter();
    void update(double delta);
    void animation();
    void performanceRandomAnimationTest();
    void loadSVGasPixmap();
    void loadCharacterFromXML(QString xml_file_name, skeltal_hbox* root = 0);
    void testHealthBar();
    void stopAllAnimatedCharacters();
    void touchBegin(QGraphicsSceneMouseEvent *event);
    void touchMove(QGraphicsSceneMouseEvent *event);
    void touchEnd(QGraphicsSceneMouseEvent *event);
    void updateJointSelection();
    void hideLine();
    void run_sample_super_char();
    void run_sample_super_weapon();
    void set_key_point_on_character(QString animation_name, float key_point);

};

#endif // SVG_SCENE_H
