#include "animationstep.h"
#include "animation_vbox.h"
#include "game_engine.h"

animationStep::animationStep(int type, animation_vbox *parentAnimation) {

    parentAnimationBox = parentAnimation;
    parentPartType = type;
    tBox = 0;
    rBox = 0;
    yBox = 0;
    svgNumberBox = 0;
    fireW1Box = false;
}



void animationStep::deleteSelfFromParent() {
    parentAnimationBox->deleteAnimationStep(this);
}

void animationStep::refreshStepParameters() {
    setText(0,QString().setNum(tBox));
    setText(1,QString().setNum(rBox));
    setText(2,QString().setNum(yBox * (Director::sharedDirector()->winSizeInPixels().width() / origwallw)));
}

animationStep::~animationStep() {
}
