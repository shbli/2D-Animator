#include "win_message.h"
#include "game_controller.h"
#include "map.h"

win_message::win_message(float total_silver_gained, float total_xp_gained, float total_time_elapsed,int sample_battle_level) {
    setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);
    screenScale = Director::sharedDirector()->winSizeInPixels().height() / origwallh;
    messageBoard = MenuItemImage::itemWithSVG("msg_board_large.svg","msg_board_large.svg",this,SLOT(on_message_board_clicked()),screenScale);
    messageBoard->setEnabled(true);
    addChild(messageBoard);
    setScale(2);
    setOpacity(0);
    runAction(action::easeinout(action::scaleTo(0.5,1)));
    runAction(action::easeinout(action::fadeTo(0.5,100)));

    silver = total_silver_gained;
    xp_value = total_xp_gained;
    if (xp_value > 999) {
        xp_value = 999;
    }

    time = total_time_elapsed;
    float diffrence = max_time - time;
    bonus_percantage = diffrence / max_time;

    if (time > 999) {
        time = 999;
    }

    //bonus XP

    bonus_xp = 10 + ( sample_battle_level / 2 ) * bonus_percantage;
    bonus_gold = 1 + ( sample_battle_level / 7 ) * bonus_percantage;

    if (bonus_xp > 999) {
        bonus_xp = 999;
    }
    if (bonus_gold > 999) {
        bonus_gold = 999;
    }



    //numbers
    xp_numbers = numbers::layer();


    xp_numbers->pre = "number_";
    addChild(xp_numbers);

    xp_numbers->setPos((-87.61*screenScale),(58.27*screenScale));
    xp_numbers->setZ(10);

    xp_numbers->setNum(0,screenScale/2);



    silver_numbers = numbers::layer();


    silver_numbers->pre = "number_";
    addChild(silver_numbers);

    silver_numbers->setPos((-87.61*screenScale),(-18.03*screenScale));
    silver_numbers->setZ(10);

    silver_numbers->setNum(0,screenScale/2);




    gold_numbers = numbers::layer();


    gold_numbers->pre = "number_";
    addChild(gold_numbers);

    gold_numbers->setPos((-87.61*screenScale),(-95.88*screenScale));
    gold_numbers->setZ(10);

    gold_numbers->setNum(0,screenScale/2);




    bonus_time_numbers = numbers::layer();


    bonus_time_numbers->pre = "number_";
    addChild(bonus_time_numbers);

    bonus_time_numbers->setPos((165.48*screenScale),(58.27*screenScale));
    bonus_time_numbers->setZ(10);

    bonus_time_numbers->setNum(0,screenScale/2);



    bonus_xp_numbers = numbers::layer();


    bonus_xp_numbers->pre = "number_";
    addChild(bonus_xp_numbers);

    bonus_xp_numbers->setPos((165.48*screenScale),(-18.03*screenScale));
    bonus_xp_numbers->setZ(10);

    bonus_xp_numbers->setNum(0,screenScale/2);



    bonus_gold_numbers = numbers::layer();


    bonus_gold_numbers->pre = "number_";
    addChild(bonus_gold_numbers);

    bonus_gold_numbers->setPos((165.48*screenScale),(-95.88*screenScale));
    bonus_gold_numbers->setZ(10);

    bonus_gold_numbers->setNum(0,screenScale/2);


    //numbers
    xp_numbers->setOpacity(0);
    silver_numbers->setOpacity(0);
    gold_numbers->setOpacity(0);
    //bonus numbers
    bonus_time_numbers->setOpacity(0);
    bonus_xp_numbers->setOpacity(0);
    bonus_gold_numbers->setOpacity(0);

//    current_step = 0;

    animation_timer.start(animationTime);
    xp_numbers->runAction(action::fadeTo(0.1,100));
    connect(&animation_timer,SIGNAL(timeout()),this,SLOT(xp_updates()),Qt::UniqueConnection);

    isAnimationDone = false;

}

void win_message::on_message_board_clicked() {
    if (isAnimationDone) {
        messageBoard->setEnabled(false);
        runAction(action::easeinout(action::scaleTo(0.5,2)));
        runAction(action::easeinout(action::fadeTo(0.5,0)));
        game_controller::sharedGameController()->currentMap->unclock_map_2();
    } else {
        final_step();
        animation_timer.stop();
        //numbers
        xp_numbers->setOpacity(100);
        silver_numbers->setOpacity(100);
        gold_numbers->setOpacity(100);
        //bonus numbers
        bonus_time_numbers->setOpacity(100);
        bonus_xp_numbers->setOpacity(100);
        bonus_gold_numbers->setOpacity(100);


        //numbers
        xp_numbers->setNum(xp_value,screenScale/2);
        silver_numbers->setNum(silver%1000,screenScale/2);
        gold_numbers->setNum(silver/1000,screenScale/2);
        //bonus numbers
        bonus_time_numbers->setNum(time,screenScale/2);
        bonus_xp_numbers->setNum(bonus_xp,screenScale/2);
        bonus_gold_numbers->setNum(bonus_gold,screenScale/2);

    }

}

void win_message::xp_updates() {
    int newXP = xp_numbers->currentNum + 1;
    xp_numbers->setNum(newXP,screenScale/2);
    if (newXP >= xp_value) {
        animation_timer.disconnect(SIGNAL(timeout()));
        silver_numbers->runAction(action::fadeTo(0.1,100));
        gold_numbers->runAction(action::fadeTo(0.1,100));
        connect(&animation_timer,SIGNAL(timeout()),this,SLOT(silver_updates()),Qt::UniqueConnection);
    }
}

void win_message::silver_updates() {
    int newSilver = silver_numbers->currentNum + 1;
    int newGold = gold_numbers->currentNum;
    if (newSilver >= 1000) {
        newSilver = 0;
        newGold += 1;
        gold_numbers->setNum(newGold,screenScale/2);
    }
    silver_numbers->setNum(newSilver,screenScale/2);
    if ((newSilver + (newGold*1000)) >= silver) {
        animation_timer.disconnect(SIGNAL(timeout()));
        bonus_time_numbers->runAction(action::fadeTo(0.1,100));
        connect(&animation_timer,SIGNAL(timeout()),this,SLOT(bonus_time_updates()),Qt::UniqueConnection);
    }
}

void win_message::bonus_time_updates() {
    int newTime = bonus_time_numbers->currentNum + 1;
    bonus_time_numbers->setNum(newTime,screenScale/2);
    if (newTime >= time) {
        animation_timer.disconnect(SIGNAL(timeout()));
        bonus_xp_numbers->runAction(action::fadeTo(0.1,100));
        connect(&animation_timer,SIGNAL(timeout()),this,SLOT(bonus_xp_updates()),Qt::UniqueConnection);
    }
}

void win_message::bonus_gold_updates() {
    int newGold = bonus_gold_numbers->currentNum + 1;
    bonus_gold_numbers->setNum(newGold,screenScale/2);
    if (newGold >= bonus_gold) {
        animation_timer.disconnect(SIGNAL(timeout()));
        animation_timer.stop();
        final_step();
    }
}

void win_message::bonus_xp_updates() {
    int newXP = bonus_xp_numbers->currentNum + 1;
    bonus_xp_numbers->setNum(newXP,screenScale/2);
    if (newXP >= bonus_xp) {
        animation_timer.disconnect(SIGNAL(timeout()));
        bonus_gold_numbers->runAction(action::fadeTo(0.1,100));
        connect(&animation_timer,SIGNAL(timeout()),this,SLOT(bonus_gold_updates()),Qt::UniqueConnection);
    }
}

void win_message::final_step() {
    isAnimationDone = true;
    game_controller::sharedGameController()->currentMap->send_bonus(bonus_gold,bonus_xp);
}
