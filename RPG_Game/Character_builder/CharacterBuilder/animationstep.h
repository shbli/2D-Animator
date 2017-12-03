#ifndef ANIMATIONSTEP_H
#define ANIMATIONSTEP_H

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "global_keys.h"
#include <QTreeWidgetItem>

class animation_vbox;

class animationStep : public QTreeWidgetItem
{

public:

    ~animationStep();
    explicit animationStep(int type, animation_vbox* parentAnimation);
    float tBox;
    float yBox;
    float rBox;
    float svgNumberBox;
    bool fireW1Box;
    int parentPartType;
    animation_vbox* parentAnimationBox;
    void deleteSelfFromParent();
    void refreshStepParameters();

};

#endif // ANIMATIONSTEP_H
