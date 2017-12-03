#ifndef NUMBERS_H
#define NUMBERS_H

#include "game_engine.h"
#define extension ".svg"

class numbers : public Layer
{
public:
    static numbers* layer();
    void setNum(int num, float scale);
    QString pre;
    int currentNum;
private:
    numbers();
    Sprite* digit[3];
};

#endif // NUMBERS_H
