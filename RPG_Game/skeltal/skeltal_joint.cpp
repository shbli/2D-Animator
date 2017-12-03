#include "skeltal_joint.h"

skeltal_joint::skeltal_joint()
{
    parentSVGHeightOffset = 0;
}

void skeltal_joint::addSVG(const QString filename, float yAnchor, float xAnchor) {
    skeltal_part::addSVG(filename,yAnchor,xAnchor);
    //the new added item should ignore parent rotation
//    svgsList.last()->ignoreParentRotation = true;
    updateJointChildOffset();
    svgsList.last()->setEffectiveRotation();
}

#ifdef characterbuilder
void skeltal_joint::loadFromQDomElement(QDomElement *jointElement, skeltal_hbox* root) {
    skeltal_part::loadFromQDomElement(jointElement,root);
#else
void skeltal_joint::loadFromQDomElement(QDomElement *jointElement) {
    skeltal_part::loadFromQDomElement(jointElement);
#endif
    int i = 0;
    //I have a chance that I have many childs
    QDomNode jointChild = jointElement->namedItem("joint");
    while (!jointChild.isNull()) {
        if (jointChild.isElement()) {
            QDomElement jointChildElement = jointChild.toElement();
            //using the add button to add a child
            addChildPart(new skeltal_joint);
            //set the child svg offset
            updateJointChildOffset();
            //loading that element into that child
#ifdef characterbuilder
            if (root != 0) {
                child_parts.last()->loadFromQDomElement(&jointChildElement,root->child_joint.at(i));
            } else {
                child_parts.last()->loadFromQDomElement(&jointChildElement,0);
            }
#else
            child_parts.last()->loadFromQDomElement(&jointChildElement);
#endif
        }
        jointChild = jointChild.nextSibling();
        i++;
    }

    holderLayer->setEffectiveRotation();
}

void skeltal_joint::updateJointChildOffset() {
    if (!svgsList.isEmpty())
        if (!child_parts.isEmpty()) {
            //            child_parts.last()->parentSVGHeightOffset = svgsList.first()->height() * ( 1 - svgsList.first()->anchorPoint().y());
            child_parts.last()->setIneffectivePos(0,child_parts.last()->pos().y() - child_parts.last()->parentSVGHeightOffset);
        }
}
