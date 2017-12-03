#ifndef SHOP_H
#define SHOP_H

#include "game_engine.h"
#include "shop_weapon.h"
#include "shop_item.h"

#define resize_scale_player_icons 0.85
#define level_numbers_scaling 0.4
#define coins_move_time 0.2

#define shop_weapon_type 0
#define shop_item_type 1

class numbers;

struct character_info {
    QString iconFileName;
    QString buttonFileName;
    QString weaponFileName;
    int level;
};

class shop : public Layer
{
    Q_OBJECT

public:
    shop();
    void load_from_xml(QString xml_file_name);
    static character_info get_super_svg_file_name_from_character(QString character_file_name);
    static QString get_super_svg_file_name(QString super_file_name);
    Menu* menu;
    void display_current_gold_amount();
    MenuItemImage* accept_payment_button;
    MenuItemImage* confirm_payment_button;
    static int selected_item_type;
    static Layer* sharedDetailsLayer;

public slots:
    void on_back_button_clicked();
    void on_accept_payment_button_clicked();
    void on_confirm_payment_button_clicked();
    void buy_weapon(shop_weapon* to_be_bought);
    void buy_item(shop_item* to_be_bought);
private:
    numbers* currentGoldNumber;
    QRect winSize;
    float screenScale;
    Sprite* gold_coin;

};

#endif // SHOP_H
