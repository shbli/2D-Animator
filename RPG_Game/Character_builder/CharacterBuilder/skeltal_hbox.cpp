#include "skeltal_hbox.h"
#include "skeltal_part.h"
#include "configrationwindow.h"

skeltal_hbox::skeltal_hbox(skeltal_hbox *parent, QTreeWidget* parentScrollArea)
{

    QTreeWidgetItem::QTreeWidgetItem(skeltalJointType);

    partPointer = 0;
    prntScrllArea = parentScrollArea;
    parent_joint = parent;
    if (parent_joint == 0) {
        //that means am the root
        part_type = 0;
    } else {
        //am not root
        part_type = 1;
    }


    //adding a horizontal widget to save the name for the join
    partName = "";
    //adding a horizontal widget to save the SVG File name for the join
    skeltalSVGs.append("");

    rValueBox = 0;
    yValueBox = 0;
    yAnchValueBox = 0.5;
    xAnchValueBox = 0.5;
    zValueBox = 0;
    containsW1Box = false;
    containsW2Box = false;

    addMovementsForms();

}

skeltal_hbox::~skeltal_hbox() {
    while (!animationsBoxes.isEmpty()) {
        delete animationsBoxes.takeFirst();
    }
    while (!childWidgets.isEmpty()) {
        childWidgets.takeFirst()->deleteLater();
    }
    for (int i = 0; i < child_joint.size(); i++) {
        removeChild(child_joint.at(i));
        delete child_joint.at(i);
    }
}


bool skeltal_hbox::doesntContainChilds() {
    return child_joint.isEmpty();
}

void skeltal_hbox::refreshParameters() {
    setText(0,partName);
}

void skeltal_hbox::setPartValues(float time, int animationIndex) {
    if (partPointer != 0) {
        if (time == 0) {
            partPointer->holderLayer->setRotation(rValueBox);
            partPointer->setPos(partPointer->pos().x(),-yValueBox);
        } else {
            for (int i = 0; i < animationsBoxes.at(animationIndex)->stepslist.size(); i++) {
                if (animationsBoxes.at(animationIndex)->stepslist.at(i)->tBox == time) {
                    partPointer->holderLayer->setRotation(animationsBoxes.at(animationIndex)->stepslist.at(i)->rBox);
                    partPointer->setPos(partPointer->pos().x(),- animationsBoxes.at(animationIndex)->stepslist.at(i)->yBox * 2);
                }
             }
        }

        //call this on all childs
        for (int i = 0; i < child_joint.size(); i++) {
            child_joint.at(i)->setPartValues(time,animationIndex);
        }
    }
}


bool skeltal_hbox::checkAnimationValues() {
    //assuming all entries are correct
    bool returnValue = true;
    if (parent_joint == 0) {
        //Am the grand parent, I'll set my animation total times, to my first step values
        for (int i = 0; i < animationsBoxes.size(); i++) {
            animationsBoxes.at(i)->animationTotalTime = animationsBoxes.at(i)->stepslist.first()->tBox;
        }
    } else {
        // I have a parent, I'll take the value from my parent animation
        for (int i = 0; i < animationsBoxes.size(); i++) {
            animationsBoxes.at(i)->animationTotalTime = parent_joint->animationsBoxes.at(i)->animationTotalTime;
        }

        //I'll check my animation values if they meet the critiria
        for (int i = 0; i < animationsBoxes.size(); i++) {
            if (!animationsBoxes.at(i)->allStepsMeetCritieria()) {
                returnValue = false;
            }
        }
    }

    if (returnValue == false) {
        //I have a mistake in my own animation
        QMessageBox box;
        QString messagetext;
        messagetext = "Wrong animation time or t value found in part name " + partName + " the problem might be either you have a value that is more than the total time, or you don't have an end value that matches the total time, please revise your entered values";
        box.setText(messagetext);
        box.exec();
    }

    //I'll check over all my child animations
    for (int i = 0; i < child_joint.size(); i++) {
        //first, check that all the animations
        if (child_joint.at(i)->checkAnimationValues() == false) {
            //one of the childs is incorrect
            returnValue = false;
        }
    }

    return returnValue;
}

QDomElement skeltal_hbox::partDomElement(QDomDocument *domDocumnet) {
    QDomElement part;
    part = domDocumnet->createElement("joint");

    part.setAttribute("w1",containsW1Box);
    part.setAttribute("w2",containsW2Box);
    part.setAttribute("r",rValueBox);

    part.setAttribute("name",partName);
    part.setAttribute("z",zValueBox);
    part.setAttribute("y",yValueBox);
    part.setAttribute("yAnch",yAnchValueBox);
    part.setAttribute("xAnch",xAnchValueBox);

    //adding svg files one by one
    QDomElement svgsDomElements = domDocumnet->createElement("svg-files");
    for (int i = 0; i < skeltalSVGs.size(); i++) {
        if (skeltalSVGs.at(i) != "") {
            QDomElement svgElement = domDocumnet->createElement("svg");
            svgElement.setAttribute("file",skeltalSVGs.at(i));
            svgsDomElements.appendChild(svgElement);
        }
    }
    part.appendChild(svgsDomElements);

    //adding all kinds of animations
    QDomElement animations = domDocumnet->createElement("animations");
    for (int i = 0; i <  animationsBoxes.size(); i++) {
        animations.appendChild(animationsBoxes.at(i)->animationsDomElement(domDocumnet));
    }
    part.appendChild(animations);
    //adding all child elements
    for (int i = 0; i < child_joint.size(); i++) {
        part.appendChild(child_joint.at(i)->partDomElement(domDocumnet));
    }

    return part;
}

void skeltal_hbox::addMovementsForms() {
    QDomDocument xmlDocument;
    QFile openxml("movements_types.xml");

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("File movements_types.xml must be in the character directory, application will now close");
        box.setText(messagetext);
        box.exec();
        qFatal("Cannot read xml file!!");
    }
    xmlDocument.setContent(&openxml);

    openxml.close();

    QDomElement animationtypes = xmlDocument.documentElement();
    QDomNode animationNode = animationtypes.firstChild();
    while (!animationNode.isNull()) {
        animationsBoxes.append(new animation_vbox(animationNode.nodeName(),part_type));
        animationsBoxes.last()->parentHbox = this;
        animationsBoxes.last()->refreshParametersList();
        animationNode = animationNode.nextSibling();
    }
}

//this is a function to add a new joint to the existing joint
void skeltal_hbox::addJoint_button() {
    child_joint.append(new skeltal_hbox(this,prntScrllArea));
    addChild(child_joint.last());
    child_joint.last()->configWindow = configWindow;
    child_joint.last()->partName = "New";
    child_joint.last()->refreshParameters();
}

void skeltal_hbox::removeJoint_button() {
    if (parent_joint != 0 && child_joint.isEmpty()) {
        parent_joint->removeChildFromTree(this);
        delete this;
    }
}

void skeltal_hbox::removeChildFromTree(skeltal_hbox *child) {
    child_joint.removeOne(child);
    removeChild(child);

}

void skeltal_hbox::addSVGBoxForJoint_button() {

//    QHBoxLayout *svgLayout = new QHBoxLayout;

//    //adding a label to indicate a svg needed here
//    QLabel *name = new QLabel;
//    name->setText("SVG");
//    svgLayout->addWidget(name);


//    //adding a horizontal widget to save the SVG File name for the join
//    skeltalSVGs.append(new QLineEdit());
//    skeltalSVGs.last()->setFixedWidth(textBoxesSize);
//    svgLayout->addWidget(skeltalSVGs.last());
//    svgLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding));

//    insertLayout(animationsBoxes.size() + 1,svgLayout);
}

void skeltal_hbox::loadFromQDomElement(QDomElement *jointElement) {
    //shared variable done before the if statement
    partName = (jointElement->attribute("name"));
    zValueBox = (jointElement->attribute("z").toFloat());
    if (jointElement->tagName() == "joint") {
        containsW1Box = jointElement->attribute("w1").toInt();
        containsW2Box = jointElement->attribute("w2").toInt();
        //a loop adding svg files
        QDomNode svg = jointElement->namedItem("svg-files").firstChild();
        if (svg.isElement()) {
            QDomElement svgElement = svg.toElement();
            //the last element shall contain the newly created svg box
            skeltalSVGs.last() = svgElement.attribute("file");
        }
        svg = svg.nextSibling();
        while (!svg.isNull()) {
            if (svg.isElement()) {
                QDomElement svgElement = svg.toElement();
                //using the add button to add a child svg
                addSVGBoxForJoint_button();
                //the last element shall contain the newly created svg box
                skeltalSVGs.last() = svgElement.attribute("file");
            }
            svg = svg.nextSibling();
        }
        rValueBox = jointElement->attribute("r").toFloat();
        yValueBox = jointElement->attribute("y").toFloat();
        yAnchValueBox = jointElement->attribute("yAnch").toFloat();
        xAnchValueBox = jointElement->attribute("xAnch").toFloat();
    }

    //add all animations
    QDomNode animation = jointElement->namedItem("animations").firstChild();
    int i = 0;
    while (!animation.isNull()) {
        if (animation.isElement()) {
            QDomElement animationElement = animation.toElement();
            //using the add button to add a child svg
            animationsBoxes.at(i)->loadFromDomNode(&animationElement);
        }
        i++;
        animation = animation.nextSibling();
    }

    //add all other child elements

    //I have a chance that I have many childs
    QDomNode jointChild = jointElement->namedItem("joint");
    while (!jointChild.isNull()) {
        if (jointChild.isElement()) {
            QDomElement jointChildElement = jointChild.toElement();
            //using the add button to add a child
            addJoint_button();
            //loading that element into that child
            child_joint.last()->loadFromQDomElement(&jointChildElement);
        }
        jointChild = jointChild.nextSibling();
    }

    setText(0,partName);
}

void skeltal_hbox::dim_all_svgs() {
    partPointer->characterPointer->mainWeapon->setOpacity(20);
    if (partPointer != 0) {

        if (!partPointer->svgsList.isEmpty()) {
            partPointer->svgsList.first()->setOpacity(20);
        }
    }
    //call this on all childs
    for (int i = 0; i < child_joint.size(); i++) {
        child_joint.at(i)->dim_all_svgs();
    }
}

void skeltal_hbox::un_dim_all_svgs() {
    if (partPointer != 0) {
        if (!partPointer->svgsList.isEmpty()) {
            partPointer->svgsList.first()->setOpacity(100);
        }
        if (partPointer->containsW1) {
            partPointer->characterPointer->mainWeapon->setOpacity(100);
        }
    }
    //call this on all childs
    for (int i = 0; i < child_joint.size(); i++) {
        child_joint.at(i)->un_dim_all_svgs();
    }
}

void skeltal_hbox::show_current_one() {
    if (partPointer != 0) {
        if (!partPointer->svgsList.isEmpty()) {
            partPointer->svgsList.first()->setOpacity(100);
        } else {
            if (partPointer->containsW1) {
                partPointer->characterPointer->mainWeapon->setOpacity(100);
            }
        }
    }
}


