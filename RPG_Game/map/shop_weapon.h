#ifndef SHOP_WEAPON_H
#define SHOP_WEAPON_H

#include "game_engine.h"
#include "numbers.h"

#define weapon_item_scale 0.9
#define coin_under_weapon_scale 0.3
#define number_scale 0.3
#define details_number_scale 0.7


#define attack_power 1
#define attack_percantage 0.1
#define attack_all 3
#define provoke 3

#define shop_positions false
#define home_positions true

class shop_weapon : public Layer
{
    Q_OBJECT

public:
    shop_weapon(QPointF pos);
    void load_from_xml(QString xml_file_name,bool position = shop_positions);
    void load_super_properties(QString xml_file_name);
    int position_number;
    void setDisabled();
    void setEnabled();
    void refreshSequenceNumber();

public slots:
    void on_weapon_item_clicked();
    void on_sell_button_clicked();
    void on_confirm_sell_button_clicked();
private:
    QPointF itemPosition;
    MenuItemImage* weaponButton;
    static shop_weapon* currentSelectedWeapon;
    Layer* DetailsLayer;
    float screenScale;
    int weapon_price;
    float original_weapon_power_percant;
    Sprite* details_sprite_icon;
    Sprite* details_sprite_type_icon;
    QList <Sprite*> special_attack_details;
    QString weaponXML;
    QString weaponType;

    friend class shop;
    friend class home;

    bool position_var;

    MenuItemImage* sellButton;
    MenuItemImage* confirmSellButton;
    numbers* sequence_number;

signals:
    void weaponSold(int wepaonSequence);

};

#endif // SHOP_WEAPON_H
