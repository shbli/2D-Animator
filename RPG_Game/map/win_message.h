#ifndef WIN_MESSAGE_H
#define WIN_MESSAGE_H

#include "game_engine.h"
#include "numbers.h"

#define max_time (60*2.5)
#define animationTime 20

//#define xp_step 0
//#define silver_step 1
//#define bonus_time_step 2
//#define bonus_xp_step 3
//#define bonus_gold_step 4

class win_message : public Layer
{
    Q_OBJECT

public:
    win_message(float total_silver_gained,float total_xp_gained,float total_time_elapsed,int sample_battle_level);
public slots:
    void on_message_board_clicked();

    void xp_updates();
    void silver_updates();
    void bonus_time_updates();
    void bonus_gold_updates();
    void bonus_xp_updates();
    void final_step();

private:

    int silver;
    int xp_value;

    //bonus
    int time;
    float bonus_percantage;
    int bonus_gold;
    int bonus_xp;

    //numbers
    numbers* xp_numbers;
    numbers* silver_numbers;
    numbers* gold_numbers;
    //bonus numbers
    numbers* bonus_time_numbers;
    numbers* bonus_xp_numbers;
    numbers* bonus_gold_numbers;
    MenuItemImage* messageBoard;

    int current_step;
    float screenScale;

    QTimer animation_timer;

    bool isAnimationDone;




};

#endif // WIN_MESSAGE_H
