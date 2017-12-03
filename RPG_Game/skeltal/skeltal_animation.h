#ifndef SKELTAL_ANIMATION_H
#define SKELTAL_ANIMATION_H

#include <QObject>
#include <QDomElement>
#include "game_engine.h"
#include "skeltal_part.h"

class skeltal_part;

struct skeltal_animation_step {
    float end_time;
    float rotation_angle;
    float svg_index;
    float end_y;
    bool fireW1Boolean;

};

class skeltal_animation : public QObject
{
    Q_OBJECT
public:
    QString animation_name;
    void loadFromDomNode(QDomElement* animationNode);
    explicit skeltal_animation(QObject *parent = 0);
    //this is to save the total animation time, once done, current time shall restart
    float total_animation_time;
    float current_animation_time;
    skeltal_part* parentSkeltal;
    void updateOneCurrentAnimationTime(double delta);
    void updateOneCurrentAnimationTimeStep2(float delta);
    void setW1(int stepNumber);
    QList <skeltal_animation_step> animation_steps;

    void set_animation_at_point(float key_point);
signals:
    
public slots:
    void advanceOneStep(double delta);

    void startAnimation();
    void stopAnimation();
    void restartAnimation();
    void addAnimationStep(float endT, float anlge, float svgIndex = 0, float yvalue = 0,bool fireW1Value = 0);
private:
    int currentStep;
    float multiplyValues;
    float currentSpeed;
    float currentYSpeed;
    void callUpdate2OnAllChilds(float delta);

};

#endif // SKELTAL_ANIMATION_H
