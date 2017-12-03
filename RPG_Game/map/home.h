#ifndef HOME_H
#define HOME_H

#include "game_engine.h"
#include "shop.h"

#define resize_scale_player_icons 0.85
#define level_numbers_scaling 0.4
#define coins_move_time 0.2

#define weapons_screen 1
#define characters_screen 2
#define items_screen 3


class numbers;


class home : public Layer
{
    Q_OBJECT

public:
    home();
    void load();
    static character_info get_super_svg_file_name_from_character(QString character_file_name);
    static QString get_super_svg_file_name(QString super_file_name);
    static QString get_super_svg_file_name_from_weapon(QString super_file_name);
    Menu* menu;
    void display_current_gold_amount();

public slots:
    void on_back_button_clicked();

    void on_change_character_clicked();
    void on_change_wepon_clicked(int defaultSelection = 0);
    void on_change_items_clicked();

    void on_up_button_clicked();
    void on_down_button_clicked();


    void weaponSoldSlot(int weaponSequence);
    void itemSoldSlot(int itemSequence);

    void refreshWeaponsSequence();

    virtual void touchBegin(QGraphicsSceneMouseEvent *event);
    virtual void touchMove(QGraphicsSceneMouseEvent *event);
    virtual void touchEnd(QGraphicsSceneMouseEvent *event);

    virtual void onExitTransitionDidStart();

    void enable_drag_drop_for_weapon(int weaponID);

private:
    int screenID;
    numbers* currentGoldNumber;
    QRect winSize;
    float screenScale;
    Sprite* gold_coin;
    Layer* currentLayer;
    QList <shop_weapon*> weaponsList;
    QList <shop_item*> itemsList;
    int currentSelectedID;

    MenuItemImage* up_button;
    MenuItemImage* down_button;

    int touchID;

    character_info firstCharacter;
    character_info secondCharaacter;

    Sprite* first_weapon_glow;
    Sprite* second_weapon_glow;

    bool first_pos_ok;
    bool second_pos_ok;
    Sprite* second_character_weapon_icon;
    Sprite* first_character_weapon_icon;

    numbers* level_number_first;
    Sprite* first_character_type_icon;
    Sprite* first_character_icon;

    Sprite* second_character_icon;
    Sprite* second_character_type_icon;
    numbers* level_number_second;

    QPointF previous_item_pos;

    void reloadFirstCharacter();
    void reloadSecondCharacter();

};

#endif // HOME_H
