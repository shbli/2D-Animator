#ifndef DIE_EFFECT_H
#define DIE_EFFECT_H

#include "game_engine.h"
#include "character_base.h"

#define numOfSmallEffects 6
#define smallEffectScale 0.1

class die_and_join_effect : public Layer
{
    Q_OBJECT

public:
    die_and_join_effect();
    character_base* character_parent;
    character_base* characterToGetLife;
    Sprite* bigEffect;
    QList <Sprite*> smallEffects;
    QList <Sprite*> smallEnterEffects;
    float screenScale;
public slots:
    void startDieEffect(character_base* character);
    void hideDeadCharacter();
    void update(double delta);
    void deleteSelfFromParent();
    void finalStep();
    void startEnterEffect();
    void enterEffectShowParentHideEffect();
private:
    float originalDistance;
    QPointF speedPoint;


};

#endif // DIE_EFFECT_H
