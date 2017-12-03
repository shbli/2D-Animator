#ifndef SHOP_ITEM_H
#define SHOP_ITEM_H

#include "game_engine.h"
#include "numbers.h"

#define item_item_scale 0.9
#define coin_under_item_scale 0.3
#define number_scale 0.3
#define details_number_scale 0.7


#define attack_power 1
#define attack_percantage 0.1
#define attack_all 3
#define provoke 3

#define shop_positions false
#define home_positions true

class shop_item : public Layer
{
    Q_OBJECT

public:
    shop_item(QPointF pos);
    void load_from_type(QString type,int price, bool position = shop_positions);
    int position_number;
    void setDisabled();
    void setEnabled();
    void refreshSequenceNumber();

public slots:
    void on_item_item_clicked();
    void on_sell_button_clicked();
    void on_confirm_sell_button_clicked();
private:
    QPointF itemPosition;
    MenuItemImage* itemButton;
    static shop_item* currentSelecteditem;
    Layer* DetailsLayer;
    float screenScale;
    int item_price;
    float original_item_power_percant;
    Sprite* details_sprite_icon;
    Sprite* details_sprite_type_icon;
    QString itemType;

    friend class shop;
    friend class home;

    bool position_var;

    MenuItemImage* sellButton;
    MenuItemImage* confirmSellButton;
    numbers* sequence_number;
    numbers* item_count;

    void refreshItemCount();


signals:
    void itemSold(int wepaonSequence);

};

#endif // SHOP_ITEM_H
