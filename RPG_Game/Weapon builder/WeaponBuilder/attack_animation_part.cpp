#include "attack_animation_part.h"

attack_animation_part::attack_animation_part() {
    step1 = new attack_step;
    step2 = new attack_step;
    step3 = new attack_step;
}

attack_animation_part::~attack_animation_part() {
    step1->deleteLater();
    step2->deleteLater();
    step3->deleteLater();
}

QDomElement attack_animation_part::effectsDomElement(QDomDocument *mainDocument) {
    QDomElement element = mainDocument->createElement("effect");
    element.setAttribute("svg",svgBox);
    element.setAttribute("blur",blurBox);
    element.setAttribute("x-anchor",xAnchBox);
    element.setAttribute("y-anchor",yAnchBox);
    element.appendChild(step1->effectsDomElement(mainDocument));
    element.appendChild(step2->effectsDomElement(mainDocument));
    element.appendChild(step3->effectsDomElement(mainDocument));
    return element;
}

void attack_animation_part::loadeffectsDomElement(QDomElement *effectElement) {
    svgBox = effectElement->attribute("svg");
    blurBox = effectElement->attribute("blur");
    xAnchBox = effectElement->attribute("x-anchor");
    yAnchBox = effectElement->attribute("y-anchor");

    QDomNode effects = effectElement->firstChild();
    if (effects.isElement()) {
        QDomElement effectElement = effects.toElement();
        step1->loadeffectsDomElement(&effectElement);
    }
    effects = effects.nextSibling();
    if (effects.isElement()) {
        QDomElement effectElement = effects.toElement();
        step2->loadeffectsDomElement(&effectElement);
    }
    effects = effects.nextSibling();
    if (effects.isElement()) {
        QDomElement effectElement = effects.toElement();
        step3->loadeffectsDomElement(&effectElement);
    }
}

void attack_animation_part::deleteFromParent() {
    parentAttackEffect->removeChild(this);
}
