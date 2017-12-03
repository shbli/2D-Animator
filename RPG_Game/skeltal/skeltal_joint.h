#ifndef SKELTAL_JOINT_H
#define SKELTAL_JOINT_H

#include "skeltal_part.h"

class skeltal_joint : public skeltal_part
{
public:
    skeltal_joint();
    virtual void addSVG(const QString filename,float yAnchor,float xAnchor);
#ifdef characterbuilder
    virtual void loadFromQDomElement(QDomElement* jointElement, skeltal_hbox* root = 0);
#else
    virtual void loadFromQDomElement(QDomElement* jointElement);
#endif

    void updateJointChildOffset();
};

#endif // SKELTAL_JOINT_H
