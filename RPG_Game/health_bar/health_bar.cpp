#include "health_bar.h"

health_bar::health_bar(float screenScalePar)
{

    screenScale = screenScalePar;

    Sprite* background = Sprite::spriteWithSvg("health_bar.svg",screenScale);

    addChild(background);


    full.setRgb(0,161,75);
    half.setRgb(255,222,23);
    low.setRgb(237,28,36);
    XP.setRgb(0,46,255);


    QPen pen;  // creates a default pen
    pen.setWidth(pen_width * screenScale);
    pen.setBrush(full);

    bar = lineNode::lineWithPen(pen);


    addChild(bar);

    emptyX = ( 23 * screenScale ) - (background->width()/2);
    fullX = - emptyX;
    prevEndPoint = fullX;
    bar->setLineEndPoints(emptyX,0,fullX,0);

    setMaxValue(100);

    pen.setWidth(xp_width * screenScale);
    pen.setBrush(XP);

    XPbar = lineNode::lineWithPen(pen);
    XPbar->setZ(1);

    addChild(XPbar);

    float xpValue = 2 * screenScale;
    XPemptyX = emptyX - xpValue;
    XPfullX = fullX + xpValue;

    XPbar->setLineEndPoints(XPemptyX,-xpValue,XPfullX,-xpValue);

}

void health_bar::setMaxValue(float value) {
    maxValue = value;
    currentLevel = value;
    currentPercantage = 1;
}

void health_bar::setXPMaxValue(float value) {
    XPmaxValue = value;
    XPcurrentLevel = value;
    XPcurrentPercantage = 1;
}

void health_bar::setLevel(float value) {
    float Newpercantage = (value) / maxValue;
//    if (Newpercantage < 0.5 && currentPercantage >= 0.5) {
//        if (Newpercantage > 0.25) {
//            //set color to half
//            setHalf();
//        } else {
//            //set color to low
//            setLow();
//        }
//    }

//    if (Newpercantage < 0.25 && currentPercantage >= 0.25) {
//        //set color to low
//        setLow();
//    }
    if (Newpercantage > 0.5) {
        setFull();
    } else {
        if (Newpercantage > 0.25) {
            setHalf();
        } else {
            setLow();
        }
    }
    QPen pen;  // creates a default pen
    pen.setWidth(pen_width * screenScale);

    if (Newpercantage > currentPercantage) {
        //make a green line
        pen.setBrush(full);
    } else {
        //make a red line
        pen.setBrush(low);
    }

    //    float prevEndPoint = emptyX + ( (fullX - emptyX) * currentPercantage );
    currentPercantage = Newpercantage;
    float endPoint = emptyX + ( (fullX - emptyX ) * currentPercantage );
    if (endPoint < (emptyX)) {
        endPoint = (emptyX);
//        bar->setOpacity(0);
    }
    //this is going to delete itself by itself, so no need to worry about having a pointer for this kind of element
//    new health_animation(QPointF(prevEndPoint,0),QPointF(endPoint,0),pen,this);


    prevEndPoint = endPoint;
    bar->setLineEndPoints(emptyX,0,endPoint,0);
}

void health_bar::setXPLevel(float value) {
    float Newpercantage = (value) / XPmaxValue;
    //    float prevEndPoint = emptyX + ( (fullX - emptyX) * currentPercantage );
    XPcurrentPercantage = Newpercantage;
    float endPoint = XPemptyX + ( (XPfullX - XPemptyX ) * XPcurrentPercantage );
    if (endPoint < (XPemptyX)) {
        endPoint = (XPemptyX);
    }

    float xpValue = 2 * screenScale;

    XPbar->setLineEndPoints(XPemptyX,-xpValue,endPoint,-xpValue);
}

void health_bar::decreaseHealthBy(float value) {
    float curent = currentPercantage * maxValue;
    curent -= value;
    setLevel(curent);
}

void health_bar::increaseHealthBy(float value) {
    float curent = currentPercantage * maxValue;
    curent += value;
    if (curent > maxValue) {
        curent = maxValue;
    }
    setLevel(curent);
}

float health_bar::currentPercantageLevel() {
    return currentPercantage;
}

float health_bar::getMaxValue() {
    return maxValue;
}

void health_bar::setXPBarHidden() {
    XPbar->setOpacity(0);
}

float health_bar::setLow() {
    QPen pen;  // creates a default pen
    pen.setWidth(pen_width * screenScale);
    pen.setBrush(low);
    bar->setPen(pen);
}

float health_bar::setFull() {
    QPen pen;  // creates a default pen
    pen.setWidth(pen_width * screenScale);
    pen.setBrush(full);
    bar->setPen(pen);
}

float health_bar::setHalf() {
    QPen pen;  // creates a default pen
    pen.setWidth(pen_width * screenScale);
    pen.setBrush(half);
    bar->setPen(pen);
}
