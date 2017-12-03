#include "under_char_elips.h"

under_char_elips::under_char_elips() {

    attachedChar = 0;

    float screenScale = Director::sharedDirector()->winSizeInPixels().width()/origwallw;

    QDomDocument xmlDocument;
    QFile openxml("under_char_elips.xml");

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        qFatal("Cannot read xml file!!");
    }
    xmlDocument.setContent(&openxml);

    openxml.close();

    QDomElement documentelement = xmlDocument.documentElement();

    QDomElement bottom = documentelement.namedItem("bottom_elips").toElement();

    QPen pen;  // creates a default pen

    pen.setWidth(bottom.attribute("line_width").toInt() * screenScale);
    pen.setBrush(QColor::fromRgb(bottom.attribute("R").toInt(),bottom.attribute("B").toInt(),bottom.attribute("G").toInt(),bottom.attribute("T").toInt()));
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);

    belowElips = Elips::elipsWith(bottom.attribute("width").toInt() * screenScale,bottom.attribute("hight").toInt() * screenScale,pen);
    addChild(belowElips);
    belowElips->setZ(-200);

    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(bottom.attribute("blur_radios").toFloat());
    belowElips->setGraphicsEffect(blur);

    bottom = documentelement.namedItem("top_elips").toElement();

    QPen pen2;  // creates a default pen

    pen2.setWidth(bottom.attribute("line_width").toFloat() * screenScale);
    pen2.setBrush(QColor::fromRgb(bottom.attribute("R").toFloat(),bottom.attribute("B").toFloat(),bottom.attribute("G").toFloat(),bottom.attribute("T").toFloat()));
    pen2.setCapStyle(Qt::RoundCap);
    pen2.setJoinStyle(Qt::RoundJoin);

    abovevElips = Elips::elipsWith(bottom.attribute("width").toFloat() * screenScale,bottom.attribute("hight").toFloat() * screenScale,pen2);
    addChild(abovevElips);
    abovevElips->setZ(-200);

    QGraphicsBlurEffect *blur2 = new QGraphicsBlurEffect;
    blur2->setBlurRadius(bottom.attribute("blur_radios").toFloat());
    abovevElips->setGraphicsEffect(blur2);
}

void under_char_elips::attachToChar(character_base *toBeAttachedTo) {
    attachedChar = toBeAttachedTo;
    if (attachedChar != 0) {
        //dissconnect it from attached char
        disconnect(attachedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(attachedCharPosChanges()));
    }
    //connect the parent character to any character changes
    connect(attachedChar,SIGNAL(updateChildsPos(qreal,qreal)),this,SLOT(attachedCharPosChanges()),Qt::UniqueConnection);
    setOpacity(0);
    setScale(0.5);
    attachedCharPosChanges();
    runAction(action::easCurve(action::scaleTo(0.5,1),QEasingCurve::OutBounce));
    runAction(action::fadeTo(0.5,100));
}

void under_char_elips::attachedCharPosChanges() {
    setPos(attachedChar->pos().x(),attachedChar->pos().y() - attachedChar->below_char_elements_y_offset);
}
