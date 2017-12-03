#include "attack_step.h"

attack_step::attack_step() {
}

attack_step::~attack_step() {
}

QDomElement attack_step::effectsDomElement(QDomDocument *mainDocument) {
    QDomElement part = mainDocument->createElement("effect-step");
    part.setAttribute("end-t",tLineEdit);
    part.setAttribute("r",rLineEdit);
    part.setAttribute("x",xLineEdit);
    part.setAttribute("y",yLineEdit);
    part.setAttribute("sx",sxLineEdit);
    part.setAttribute("sy",syLineEdit);
    part.setAttribute("opacity",opaLineEdit);
    return part;
}

void attack_step::loadeffectsDomElement(QDomElement *effectElement) {
    tLineEdit = effectElement->attribute("end-t");
    rLineEdit = effectElement->attribute("r");
    xLineEdit = effectElement->attribute("x");
    yLineEdit = effectElement->attribute("y");
    sxLineEdit = effectElement->attribute("sx");
    syLineEdit = effectElement->attribute("sy");
    opaLineEdit = effectElement->attribute("opacity");
}
