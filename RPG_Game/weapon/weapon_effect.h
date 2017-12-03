#ifndef WEAPON_EFFECT_H
#define WEAPON_EFFECT_H

#include "game_engine.h"
#include <QDomDocument>
#include "global_keys.h"
#define numberOfSteps 3
/*
  This class, is an abstract layer, that reads from an under_char_elips.xml the specific values, and create from them an elips
*/

class weapon_effect : public Layer
{
    Q_OBJECT

public:
    float end_t[numberOfSteps];

public slots:
    void loadeffectsDomElement(QDomElement* effectElement,float screenScale);
    void startEffect();
    void runMOVAnimation();
    void runSXAnimation();
    void runSYAnimation();
    void runRAnimation();
    void runOAnimation();

signals:
    void signalEffect();

private:

    Sprite* effectSprite;
    float x[numberOfSteps];
    float y[numberOfSteps];
    float opacity[numberOfSteps];
    float sx[numberOfSteps];
    float sy[numberOfSteps];
    float rotation[numberOfSteps];

};

#endif // WEAPON_EFFECT_H
