#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include "game_engine.h"
#include "global_keys.h"
#include "health_animation.h"

#define pen_width 8
#define xp_width 4

class health_bar : public Layer
{
public:
    health_bar(float screenScalePar);

    void setMaxValue(float value);
    void setXPMaxValue(float value);
    void setLevel(float value);
    void setXPLevel(float value);
    void decreaseHealthBy(float value);
    void increaseHealthBy(float value);
    float currentPercantageLevel();
    float getMaxValue();


    void setXPBarHidden();

private:

    lineNode* bar;
    float emptyX;
    float fullX;


    float XPemptyX;
    float XPfullX;

    float screenScale;

    QColor full;
    QColor half;
    QColor low;
    QColor XP;

    float currentLevel;
    float maxValue;
    float currentPercantage;


    float XPcurrentLevel;
    float XPmaxValue;
    float XPcurrentPercantage;

    float setLow();
    float setFull();
    float setHalf();

    float prevEndPoint;


    lineNode* XPbar;

};

#endif // HEALTH_BAR_H
