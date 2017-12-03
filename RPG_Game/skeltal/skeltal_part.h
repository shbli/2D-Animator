#ifndef SKELTAL_PART_H
#define SKELTAL_PART_H

#include "game_engine.h"
#include "skeltal_animation.h"
#include "global_keys.h"
#include <QDomElement>
#ifdef characterbuilder
#include "skeltal_hbox.h"
#endif

class skeltal_animation;
class character_base;

class skeltal_part : public Layer
{
    Q_OBJECT

public:
    skeltal_part();
    ~skeltal_part();
    //human readable skeltal part name
    QString part_name;
    //this is a small 2 booleans to indicate if this part have a child that contains W1 or W2
    bool containsW1;
    bool containsW2;
    //a list of svg files that this part contains
    QList <Sprite*> svgsList;
    //a list of animations that this list holds
    QList <skeltal_animation*> animationsList;
    //set the current animation to animation type as index
    void setAnimationIndex(int index);
    void setMaxAnimationTime(int index,float maxT);
    //a list of childs that this part have
    QList <skeltal_part*> child_parts;
    //add an svg image, as a rule for joints needs more than one svg, mostly bones will have only one svg loaded
    virtual void addSVG(const QString filename,float yAnchor,float xAnchor);
    virtual void addChildPart(skeltal_part* child_part);

    void set_animtion_at_point(int index, float key_point);



    QList <Sprite*> *getsvgsList();
#ifdef characterbuilder
    virtual void loadFromQDomElement(QDomElement* jointElement, skeltal_hbox* root = 0);
#else
    virtual void loadFromQDomElement(QDomElement* jointElement);
#endif
    skeltal_part* parent_part;
    void setW1();
    void setW2();
    void createAnimationsTypes();
    character_base* characterPointer;
    float parentSVGHeightOffset;
    Layer* holderLayer;
    void runWeaponEffect();
    void oneTimeAnimationDone();
};

#endif // SKELTAL_PART_H
