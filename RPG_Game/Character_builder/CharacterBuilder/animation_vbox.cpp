#include "animation_vbox.h"
#include "skeltal_part.h"

animation_vbox::animation_vbox(QString name, int type) {


    setExpanded(true);
    setFlags(Qt::ItemIsEnabled);

    animationName = name;
    parentPartType = type;
    QHBoxLayout* horizontalbox = new QHBoxLayout;

    //first, adding animation name to the layout

    if (parentPartType == 0) {
        //am the grad parent
        addNewStepBasic();
    }
}

animation_vbox::~animation_vbox() {
    while (!stepslist.isEmpty()) {
        deleteAnimationStep(stepslist.first());
    }
}

bool animation_vbox::allStepsMeetCritieria() {

    //first true, without even thinking, if the list is empty
    if (stepslist.isEmpty()) {
        return true;
    }

    int numbOfAnimationsTotalTime = 0;

    for (int i = 0; i < stepslist.size(); i++) {
        float animationTime = stepslist.at(i)->tBox;
        if (animationTime > animationTotalTime) {
            return false;
        } else {
            if (animationTime == animationTotalTime) {
                numbOfAnimationsTotalTime++;
            }
        }
    }
    if (numbOfAnimationsTotalTime == 1) {
        return true;
    }
    return false;
}

void animation_vbox::addNewStep(float time, int index, bool add_current) {

    for (int i = 0; i < parentHbox->child_joint.size(); i++) {
        parentHbox->child_joint.at(i)->animationsBoxes.at(index)->addNewStep(time,index);
    }



    //check where to add the child
    if (parentPartType != 0) {
        int indexToInsertInto = stepslist.size();
        bool found = false;
        for (int i = 0; i < stepslist.size() && !found; i++) {
            if (stepslist.at(i)->tBox > time) {
                indexToInsertInto = i;
                found = true;
            } else {
                if (stepslist.at(i)->tBox == time) {
                    //we don't want to add a duplicate
                    return;
                }
                indexToInsertInto = i + 1;
            }
        }

        float defaultR;
        float defaultY;
        defaultR = parentHbox->rValueBox;
        defaultY = parentHbox->yValueBox;

        if (!stepslist.isEmpty()) {
            defaultR = stepslist.last()->rBox;
            defaultY = stepslist.last()->yBox;
            if (indexToInsertInto - 1 >= 0) {
                defaultR = stepslist.at(indexToInsertInto - 1)->rBox;
                defaultY = stepslist.at(indexToInsertInto - 1)->yBox;
            }
        }

        //this is used when we double click the frames to add a new point at that point
        if (add_current) {
            if (parentHbox->partPointer != 0) {
                //we are safe to add the current values
                defaultR = parentHbox->partPointer->holderLayer->rotation();
                defaultY = -parentHbox->partPointer->pos().y();
            }
        }


        stepslist.insert(indexToInsertInto,new animationStep(parentPartType,this));
        insertChild(indexToInsertInto,stepslist.at(indexToInsertInto));
        stepslist.at(indexToInsertInto)->rBox = defaultR;
        stepslist.at(indexToInsertInto)->yBox = defaultY;
        stepslist.at(indexToInsertInto)->tBox = time;
        stepslist.at(indexToInsertInto)->refreshStepParameters();
    } else {
        if (stepslist.first()->tBox < time) {
            stepslist.first()->tBox = time;
            stepslist.first()->refreshStepParameters();
        }
    }

}

void animation_vbox::changeAStep(float fromtime, float totime, int index) {
    //call recursivly on all childs, call it first here so that we know the maximum time now! So we can assign that automatically
    for (int i = 0; i < parentHbox->child_joint.size(); i++) {
        parentHbox->child_joint.at(i)->animationsBoxes.at(index)->changeAStep(fromtime,totime,index);
    }

    //check where to add the child
    if (parentPartType != 0) {
        bool found = false;
        for (int i = 0; i < stepslist.size() && !found; i++) {
            if (stepslist.at(i)->tBox == fromtime) {
                stepslist.at(i)->tBox = totime;
                stepslist.at(i)->refreshStepParameters();
                if (totime > fromtime) {
                    while (i + 1 < stepslist.size()) {
                        if (stepslist.at(i)->tBox > stepslist.at(i+1)->tBox) {
                            stepslist.swap(i,i+1);
                        }
                        i++;
                    }
                } else {
                    while (i - 1 > 0) {
                        if (stepslist.at(i)->tBox < stepslist.at(i-1)->tBox) {
                            stepslist.swap(i,i-1);
                        }
                        i--;
                    }
                }
                found = true;
                while(childCount() != 0) {
                    removeChild(child(0));
                }
                for (int i = 0; i < stepslist.size(); i++) {
                    addChild(stepslist.at(i));
                }
            }
        }

    } else {
        if (!parentHbox->child_joint.isEmpty()  ) {
            if (parentHbox->child_joint.first()->animationsBoxes.at(index)->stepslist.isEmpty()) {
                stepslist.first()->tBox = 0;
            } else {
                stepslist.first()->tBox = parentHbox->child_joint.first()->animationsBoxes.at(index)->stepslist.last()->tBox;
            }
        } else {
            stepslist.first()->tBox = 0;
        }
    }
}


void animation_vbox::removeStep(float time, int index) {

    //call recursivly on all childs, call it first here so that we know the maximum time now! So we can assign that automatically
    for (int i = 0; i < parentHbox->child_joint.size(); i++) {
        parentHbox->child_joint.at(i)->animationsBoxes.at(index)->removeStep(time,index);
    }

    //check where to add the child
    if (parentPartType != 0) {
        bool found = false;
        for (int i = 0; i < stepslist.size() && !found; i++) {
            if (stepslist.at(i)->tBox == time) {
                takeChild(i);
                delete stepslist.takeAt(i);
                found = true;
            }
        }
    } else {
        if (!parentHbox->child_joint.isEmpty()  ) {
            if (parentHbox->child_joint.first()->animationsBoxes.at(index)->stepslist.isEmpty()) {
                stepslist.first()->tBox = 0;
            } else {
                stepslist.first()->tBox = parentHbox->child_joint.first()->animationsBoxes.at(index)->stepslist.last()->tBox;
            }
        } else {
            stepslist.first()->tBox = 0;
        }
    }
}

void animation_vbox::addNewStep1() {
    int index;
    for (int i = 0; i < parentHbox->animationsBoxes.size(); i++) {
        if (parentHbox->animationsBoxes.at(i)->animationName == animationName) {
            index = i;
        }
    }
    for (int i = 0; i < parentHbox->child_joint.size(); i++) {
        parentHbox->child_joint.at(i)->animationsBoxes.at(index)->addNewStep(stepslist.first()->tBox,index);
    }
}

void animation_vbox::addNewStepBasic() {
    stepslist.append(new animationStep(parentPartType,this));
    addChild(stepslist.last());
}


void animation_vbox::deleteAnimationStep(animationStep *toBeDeleted) {
    stepslist.removeOne(toBeDeleted);
    delete toBeDeleted;
}

void animation_vbox::loadFromDomNode(QDomElement *animationNode) {
    QDomNode step = animationNode->firstChild();
    while (!step.isNull()) {
        if (step.isElement()) {
            QDomElement stepElement = step.toElement();
            //using the add button to add a child svg, if not parent we'll skip this step
            if (parentPartType != 0) {
                addNewStepBasic();
            }
            //the last element shall contain the newly created svg box
            stepslist.last()->tBox = stepElement.attribute("end-time").toFloat();
            stepslist.last()->rBox = stepElement.attribute("rotation-angle").toFloat();
            stepslist.last()->yBox = stepElement.attribute("end-y").toFloat();
            stepslist.last()->svgNumberBox = stepElement.attribute("svg-index").toFloat();
            stepslist.last()->fireW1Box = stepElement.attribute("fire-w1","0").toInt();
            stepslist.last()->refreshStepParameters();

        }
        step = step.nextSibling();
    }
}

void animation_vbox::setDragDrop(QLineEdit *rotate, QLineEdit *ybox) {
    //    parentHbox->rDragValueBox = rotate;
    //    parentHbox->yDragValueBox = ybox;
    //    parentHbox->setAsDragandDropElement2();
}

void animation_vbox::setValues(QLineEdit *rotate, QLineEdit *ybox) {
    //    parentHbox->rDragValueBox = rotate;
    //    parentHbox->yDragValueBox = ybox;
    //    parentHbox->setPartValues2();
}

void animation_vbox::refreshParametersList() {
    setText(0,animationName);
}

QDomElement animation_vbox::animationsDomElement(QDomDocument *domDocumnet) {
    QDomElement animation = domDocumnet->createElement(animationName);
    for (int i = 0; i < stepslist.size(); i++) {
        if(stepslist.at(i)->tBox != 0 || parentPartType == 0) {
            QDomElement animationStepElement = domDocumnet->createElement("animation-step");
            animationStepElement.setAttribute("end-time",stepslist.at(i)->tBox);
            animationStepElement.setAttribute("rotation-angle",stepslist.at(i)->rBox);
            animationStepElement.setAttribute("end-y",stepslist.at(i)->yBox);
            animationStepElement.setAttribute("svg-index",stepslist.at(i)->svgNumberBox);
            animationStepElement.setAttribute("fire-w1",stepslist.at(i)->fireW1Box);
            animation.appendChild(animationStepElement);
        }
    }
    return animation;
}
