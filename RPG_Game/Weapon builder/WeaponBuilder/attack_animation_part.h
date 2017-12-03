#ifndef ATTACK_ANIMATION_PART_H
#define ATTACK_ANIMATION_PART_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "attack_step.h"
#include "attackeffects.h"

class attackEffects;

class attack_animation_part : public QVBoxLayout
{

    Q_OBJECT

public:
    attack_animation_part();
    ~attack_animation_part();

    //three steps, that contains the animation
    attack_step* step1;
    attack_step* step2;
    attack_step* step3;
    QString svgBox;
    QString blurBox;
    QString xAnchBox;
    QString yAnchBox;
    attackEffects* parentAttackEffect;
    QDomElement effectsDomElement(QDomDocument* mainDocument);
    void loadeffectsDomElement(QDomElement* effectElement);

public slots:
    void deleteFromParent();


};

#endif // ATTACK_ANIMATION_PART_H
