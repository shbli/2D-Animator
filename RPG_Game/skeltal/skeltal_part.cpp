#include "skeltal_part.h"
#include "character_base.h"

skeltal_part::skeltal_part() {
    holderLayer = Layer::node();
    holderLayer->addChild(this);
    parent_part = 0;
}


skeltal_part::~skeltal_part() {
    while (!animationsList.isEmpty()) {
        animationsList.takeFirst()->deleteLater();
    }
}

void skeltal_part::setAnimationIndex(int index) {
    //for perfomance reasons, we'll only connect the animations that contains at least one step, otherwise there's no need to connect this animation
    if (!animationsList.at(index)->animation_steps.isEmpty()) {
        animationsList.at(index)->restartAnimation();
        if (parent_part == 0) {
            //am the root
            if (animationsList.at(index)->total_animation_time != 0) {
                animationsList.at(index)->current_animation_time = 0;
                connect(characterPointer,SIGNAL(stepChildsAnimation(double)),animationsList.at(index),SLOT(advanceOneStep(double)),Qt::UniqueConnection);
            }
        }
    }
    for (int i = 0; i < child_parts.size(); i++) {
        child_parts.at(i)->setAnimationIndex(index);
    }
}

void skeltal_part::setMaxAnimationTime(int index, float maxT) {
    animationsList.at(index)->total_animation_time = maxT;
    for (int i = 0; i < child_parts.size(); i++) {
        child_parts.at(i)->setMaxAnimationTime(index,maxT);
    }
}

void skeltal_part::addSVG(const QString filename, float yAnchor, float xAnchor) {
    Sprite* svgChild = Sprite::spriteWithSvg(filename,characterPointer->screenScale);
    svgsList.append(svgChild);
    addChild(svgChild);
    //if it's not the first one, we'll hide it
    if (svgsList.size() > 1) {
        svgsList.last()->setOpacity(0);
    }
    svgsList.last()->setAnchor(xAnchor,yAnchor);
    svgChild->setEffectiveRotation();
}

void skeltal_part::addChildPart(skeltal_part *child_part) {
    child_part->characterPointer = characterPointer;
    //adding the child to this list part
    child_parts.append(child_part);
    //adding the child to the layer part
    addChild(child_part->holderLayer);
    //setting me as the parent of this child
    child_part->parent_part = this;
}

void skeltal_part::set_animtion_at_point(int index, float key_point) {
    //for perfomance reasons, we'll only connect the animations that contains at least one step, otherwise there's no need to connect this animation
    if (!animationsList.at(index)->animation_steps.isEmpty()) {
        if (parent_part == 0) {
            //am the root
        } else {
            animationsList.at(index)->set_animation_at_point(key_point);
        }
    }
    for (int i = 0; i < child_parts.size(); i++) {
        child_parts.at(i)->set_animtion_at_point(index,key_point);
    }
}

QList<Sprite *> *skeltal_part::getsvgsList() {
    return &svgsList;
}

#ifdef characterbuilder
void skeltal_part::loadFromQDomElement(QDomElement *jointElement, skeltal_hbox* root) {
    if (root != 0) {
        root->partPointer = this;
    }
#else
void skeltal_part::loadFromQDomElement(QDomElement *jointElement) {
#endif

    float screenScale = characterPointer->screenScale;
    //shared variable done before the if statement
    part_name = jointElement->attribute("name");
    setZ(jointElement->attribute("z").toInt());
    if (jointElement->tagName() == "joint") {
        if (jointElement->attribute("w1") == "1") {
//            qDebug() << "Part " << part_name << " contains w1";
            setW1();
            addChild(characterPointer->mainWeapon);
            if (characterPointer->weapon_xml != "") {
                characterPointer->mainWeapon->load_from_xml(characterPointer->weapon_xml,characterPointer->mainWeapon,characterPointer,SLOT(q_weapon_super()));
            }
        }
        if (jointElement->attribute("w2") == "1") {
            setW2();
        }
        //a loop adding svg files

        QDomNode svg = jointElement->namedItem("svg-files").firstChild();
        while (!svg.isNull()) {
            if (svg.isElement()) {
                QDomElement svgElement = svg.toElement();
                //the last element shall contain the newly created svg box
                addSVG(svgElement.attribute("file").toLower(),jointElement->attribute("yAnch").toFloat(),jointElement->attribute("xAnch").toFloat());
            }
            svg = svg.nextSibling();
        }
        holderLayer->setRotation(jointElement->attribute("r").toFloat());
        //set the y offset
        setPos(0,- (jointElement->attribute("y").toFloat() * screenScale));
    }

    createAnimationsTypes();
    //add all animations
    QDomNode animation = jointElement->namedItem("animations").firstChild();
    int i = 0;
    while (!animation.isNull()) {
        if (animation.isElement()) {
            QDomElement animationElement = animation.toElement();
            //using the add button to add a child svg
            animationsList.at(i)->loadFromDomNode(&animationElement);
        }
        i++;
        animation = animation.nextSibling();
    }

    //add all other child elements
    //this is done in base classes, each depending on type

}

void skeltal_part::setW1() {
    containsW1 = true;
//    if (parent_part != 0) {
//        parent_part->setW1();
//    }
}

void skeltal_part::setW2() {
    containsW2 = true;
//    if (parent_part != 0) {
//        parent_part->setW2();
//    }
}

void skeltal_part::createAnimationsTypes() {
    QDomDocument xmlDocument;
    QFile openxml("movements_types.xml");

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        qFatal("Cannot read xml file!!");
    }
    xmlDocument.setContent(&openxml);

    openxml.close();

    QDomElement animationtypes = xmlDocument.documentElement();
    QDomNode animationNode = animationtypes.firstChild();
    while (!animationNode.isNull()) {
        animationsList.append(new skeltal_animation);
        animationsList.last()->animation_name = animationNode.nodeName();
        animationsList.last()->parentSkeltal = this;
        animationNode = animationNode.nextSibling();
    }
}

void skeltal_part::runWeaponEffect() {
    if (characterPointer->aimToAtttackChar != 0) {
        characterPointer->mainWeapon->startBeforeEffect(characterPointer->aimToAtttackChar->pos().x(),characterPointer->aimToAtttackChar->pos().y(),characterPointer->scaleX(),characterPointer->pos().x(),characterPointer->pos().y(),characterPointer->scaleX());
    } else {
        characterPointer->mainWeapon->startBeforeEffect(characterPointer->pos().x() + 100,characterPointer->pos().y(),1,characterPointer->pos().x(),characterPointer->pos().y(),1);
    }
    //remove some of character health
    if (characterPointer->aimToAtttackChar != 0) {
        characterPointer->aimToAtttackChar->decreaseHealthBy((1.0 + (characterPointer->myLevel/decreaseHealLevelFix)) * characterPointer->mainWeapon->weapon_power, characterPointer);
        if (characterPointer->enemy_attacking_point != NULL) {
            if (characterPointer->enemy_attacking_point->occupied_by != 0) {
            if (characterPointer->enemy_attacking_point->occupied_by->char_id != characterPointer->char_id) {
//                qDebug() << "Warning - point attached to me but not related to me";
//                qDebug() << "Occubid = " << characterPointer->enemy_attacking_point->occupied;
//                qDebug() << "Occubied by = " << characterPointer->enemy_attacking_point->occupied_by->char_id;
                if (!characterPointer->enemy_attacking_point->occupied) {
                }
                characterPointer->aim_to_char(characterPointer->aimToAtttackChar);
            } else {
//                qDebug() << "Point is attached to me";
            }
        } else {
//            qDebug() << "Warning - Point is not occubied by anyone";
//            qDebug() << "Occubid = " << characterPointer->enemy_attacking_point->occupied;
//            qDebug() << "Character name " << characterPointer->character_name;
//            qDebug() << "Character id " << characterPointer->char_id;
//            qDebug() << "Char xml " << characterPointer->player_xml_file;
            if (!characterPointer->computer_player) {
                characterPointer->aim_to_char(characterPointer->aimToAtttackChar);
            }
//            qDebug() << "Occubied by = " << characterPointer->enemy_attacking_point->occupied_by->char_id;
        }
    }
    }
}
