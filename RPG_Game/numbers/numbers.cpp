#include "numbers.h"

numbers::numbers() {
    for (int i = 0; i < 3; i++) {
        digit[i] = 0;
    }
    pre = "";
    currentNum = 99999;

}

numbers * numbers::layer() {
    return new numbers;
}

void numbers::setNum(int num,float scale) {
    if (num != currentNum) {
        currentNum = num;
        //deleting any old numbers that exisits
        for (int i = 0; i < 3; i++) {
            if (digit[i] != 0) {
                removeChild(digit[i]);
                digit[i] = 0;
            }
        }
        //adding numbers to that layer
        //the first case, is that we have a number that is less than 10
        if (num >= 0 && num < 10) {
            digit[0] = Sprite::spriteWithSvg((pre + QString().setNum(num) + QString(extension)),scale);
            addChild(digit[0]);
        } else if (num >= 10 && num < 100) {
            QString number;
            number.setNum(num);
            digit[0] = Sprite::spriteWithSvg(( pre + QString(number.at(1)) + QString(extension)),scale);
            digit[1] = Sprite::spriteWithSvg(( pre + QString(number.at(0)) + QString(extension)),scale);
            addChild(digit[0]);
            addChild(digit[1]);
            digit[0]->setPos(digit[0]->width()/2,0);
            digit[1]->setPos(- digit[1]->width()/2,0);

        } else if (num >= 100 && num < 1000) {
            QString number;
            number.setNum(num);
            digit[0] = Sprite::spriteWithSvg(( pre + QString(number.at(2)) + QString(extension)),scale);
            digit[1] = Sprite::spriteWithSvg(( pre + QString(number.at(1)) + QString(extension)),scale);
            digit[2] = Sprite::spriteWithSvg(( pre + QString(number.at(0)) + QString(extension)),scale);
            addChild(digit[0]);
            addChild(digit[1]);
            addChild(digit[2]);
            digit[0]->setPos(digit[0]->width(),0);
            digit[1]->setPos(0,0);
            digit[2]->setPos(- digit[2]->width(),0);
        } else {
            qDebug() << "Out of range number in class numbers, number requested more than 1000 it's " << num;
        }
    }
}
