#include "attackeffects.h"

attackEffects::attackEffects(QString name) {
    effectName = name;
    attackParts = new QList <attack_animation_part*>;
}

attackEffects::~attackEffects() {
    delete attackParts;
}

void attackEffects::on_add_button() {
//    qDebug() << "Add button is working";
    attackParts->append(new attack_animation_part);
    attackParts->last()->parentAttackEffect = this;
    attackParts->last()->svgBox = ".svg";
    attackParts->last()->blurBox = "0";
}

QDomElement attackEffects::effectsDomElement(QDomDocument *mainDocument) {
    QDomElement effects = mainDocument->createElement(effectName);
    effects.setAttribute("sound",soundFile->text());
    //add all child effects as child dom elements to be saved in the xml file as well
    for (int i = 0; i < attackParts->size(); i++) {
        effects.appendChild(attackParts->at(i)->effectsDomElement(mainDocument));
    }
    return effects;
}

void attackEffects::loadeffectsDomElement(QDomElement *effectElement) {

    soundFile->setText(effectElement->attribute("sound"));

    QDomNode effects = effectElement->firstChild();
    while (!effects.isNull()) {
        if (effects.isElement()) {
            QDomElement effectElement = effects.toElement();
            on_add_button();
            attackParts->last()->loadeffectsDomElement(&effectElement);
            listWidget->addItem(attackParts->last()->svgBox);
        }
        effects = effects.nextSibling();
    }
}

void attackEffects::removeChild(attack_animation_part *toBeRemoved) {
    //removing a part from the list
    attackParts->removeOne(toBeRemoved);
    toBeRemoved->deleteLater();
}

int attackEffects::size() {
    return attackParts->size();
}
