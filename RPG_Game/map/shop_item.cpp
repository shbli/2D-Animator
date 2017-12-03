#include "shop_item.h"
#include <QDomDocument>
#include "numbers.h"
#include "shop.h"
#include "shared_storage.h"

shop_item* shop_item::currentSelecteditem = NULL;

shop_item::shop_item(QPointF pos) {
    itemPosition = pos;
    screenScale = Director::sharedDirector()->winSizeInPixels().width() / origwallw;
}

void shop_item::load_from_type(QString type,int price, bool position) {

    itemType = type;

    position_var = position;

    if (position_var == shop_positions) {
        itemButton = MenuItemImage::itemWithSVG(type,"",this,SLOT(on_item_item_clicked()),screenScale * weapon_item_scale);
        itemButton->setEnabled(true);
        addChild(itemButton);
    }
    if (position_var == shop_positions) {
        details_sprite_icon = Sprite::spriteWithSvg(type,screenScale * weapon_item_scale * 1.3);
    } else {
        details_sprite_icon = Sprite::spriteWithSvg(type,screenScale * resize_scale_player_icons);
    }

    item_price = price;


    if (position == home_positions) {
        item_price /= 2;
    }

    numbers* price_numbers;
    if (position_var == shop_positions) {

        itemButton->setPos(itemPosition);
        Sprite* coin = Sprite::spriteWithSvg("money.svg",screenScale*coin_under_item_scale);
        addChild(coin);
        coin->setPos(itemButton->pos() + QPointF(-27*screenScale,-93*screenScale));

        price_numbers = numbers::layer();

        price_numbers->pre = "number_";
        addChild(price_numbers);

        price_numbers->setPos(itemButton->pos() + QPointF(18*screenScale,-93*screenScale));
        price_numbers->setZ(10);
    }
    //before setting the price, we make sure it's not bigger than 999
    if (item_price > 999 || item_price < 0) {
        item_price = 999;
    }

    if (position_var == shop_positions) {
        price_numbers->setNum(item_price,screenScale*number_scale);
    }



    DetailsLayer = Layer::node();
    addChild(DetailsLayer);
    if (position_var == shop_positions) {
        DetailsLayer->setOpacity(0);
        DetailsLayer->setScale(2);
    }

    if (position_var == home_positions) {
        DetailsLayer->setPos(0,0);
    } else {
        DetailsLayer->setPos(QPointF(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2) + QPointF(279.5*screenScale,60.6*screenScale));
    }


    //adding price layer

    numbers* detail_price_numbers = numbers::layer();

    detail_price_numbers->pre = "number_";
    DetailsLayer->addChild(detail_price_numbers);

    if (position_var == shop_positions) {
        detail_price_numbers->setPos(QPointF(103.8*screenScale,-124.1*screenScale));
    } else {
        detail_price_numbers->setPos(itemPosition + QPointF(167.9*screenScale,-25.8*screenScale));
    }
    detail_price_numbers->setZ(10);

    if (position_var == shop_positions) {
        detail_price_numbers->setNum(item_price,screenScale*details_number_scale);
    } else {
        detail_price_numbers->setNum(item_price,screenScale*details_number_scale*0.75);
    }

    Sprite* details_coin;

    if (position_var == shop_positions) {
        details_coin = Sprite::spriteWithSvg("money.svg",screenScale*details_number_scale*1.3);
    } else {
        details_coin = Sprite::spriteWithSvg("money.svg",screenScale*details_number_scale*0.7);
    }

    DetailsLayer->addChild(details_coin);

    if (position_var == shop_positions) {
        details_coin->setPos(QPointF(4*screenScale,-124.1*screenScale));
    } else {
        details_coin->setPos(itemPosition + QPointF(87.6*screenScale,-25.8*screenScale));
    }
    details_coin->setZ(10);

    DetailsLayer->addChild(details_sprite_icon);


    if (position_var == shop_positions) {
        details_sprite_icon->setPos(QPointF(-101.2*screenScale,91.2*screenScale));
    } else {
        details_sprite_icon->setPos(QPointF(itemPosition));
    }
    details_sprite_icon->setZ(10);


    if (position_var == home_positions) {
        sequence_number = numbers::layer();

        sequence_number->pre = "number_";
        DetailsLayer->addChild(sequence_number);

        sequence_number->setPos(itemPosition + QPointF(297.1*screenScale,21.7*screenScale));

        sequence_number->setZ(10);

        sequence_number->setNum(position_number,screenScale*details_number_scale*0.4);





        sellButton = MenuItemImage::itemWithSVG("accept.svg","",this,SLOT(on_sell_button_clicked()),screenScale * 0.7);

        sellButton->setPos(itemPosition + QPointF(280.4*screenScale,-63.3*screenScale) );
        sellButton->setZ(10);
        sellButton->setEnabled(true);

        DetailsLayer->addChild(sellButton);


        confirmSellButton = MenuItemImage::itemWithSVG("money.svg","",this,SLOT(on_confirm_sell_button_clicked()),screenScale * 0.7);

        confirmSellButton->setPos(itemPosition + QPointF(280.4*screenScale,-63.3*screenScale) );
        confirmSellButton->setZ(10);
        confirmSellButton->setOpacity(0);
        confirmSellButton->setEnabled(false);

        DetailsLayer->addChild(confirmSellButton);


    }

    //display the number of elements available

    item_count = NULL;

    refreshItemCount();

}

void shop_item::setDisabled() {
    sellButton->setEnabled(false);
    confirmSellButton->setEnabled(false);
    confirmSellButton->setOpacity(0);
    sellButton->setOpacity(0);
}

void shop_item::setEnabled() {
    sellButton->setEnabled(true);
    confirmSellButton->setEnabled(false);
    sellButton->setOpacity(100);

}

void shop_item::refreshSequenceNumber() {
    sequence_number->setNum(position_number,screenScale*details_number_scale*0.4);
}

void shop_item::on_item_item_clicked() {
    if (shop::sharedDetailsLayer != NULL) {
        //hide the details layer and replace it with the other layer
        shop::sharedDetailsLayer->stopAllActions();
        shop::sharedDetailsLayer->runAction(action::easeinout(action::scaleTo(0.2,2)));
        shop::sharedDetailsLayer->runAction(action::easeinout(action::fadeTo(0.2,0)));
    }

    shop::sharedDetailsLayer = DetailsLayer;
    shop::selected_item_type = shop_item_type;
    currentSelecteditem = this;
    shop::sharedDetailsLayer->stopAllActions();
    shop::sharedDetailsLayer->runAction(action::easeinout(action::scaleTo(0.2,1)));
    shop::sharedDetailsLayer->runAction(action::easeinout(action::fadeTo(0.2,100)));

    itemButton->stopAllActions();
    itemButton->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleTo(0.1,1.5)),action::easeinout(action::scaleTo(0.1,1)),NULL));
}

void shop_item::on_sell_button_clicked() {
    sellButton->setEnabled(false);
    confirmSellButton->setEnabled(true);

    float animation_part_time = 0.1;

    sellButton->stopAllActions();
    confirmSellButton->stopAllActions();

    sellButton->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animation_part_time,-1)),action::easeinout(action::scaleXTo(animation_part_time,1)),NULL));
    confirmSellButton->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animation_part_time,-1)),action::easeinout(action::scaleXTo(animation_part_time,1)),NULL));

    sellButton->runAction(action::easeinout(action::fadeTo(animation_part_time*2,0)));
    confirmSellButton->runAction(action::easeinout(action::fadeTo(animation_part_time*2,100)));
}

void shop_item::on_confirm_sell_button_clicked() {
    sellButton->setEnabled(true);
    confirmSellButton->setEnabled(false);

    float animation_part_time = 0.1;

    sellButton->stopAllActions();
    confirmSellButton->stopAllActions();

    sellButton->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animation_part_time,-1)),action::easeinout(action::scaleXTo(animation_part_time,1)),NULL));
    confirmSellButton->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animation_part_time,-1)),action::easeinout(action::scaleXTo(animation_part_time,1)),NULL));

    sellButton->runAction(action::easeinout(action::fadeTo(animation_part_time*2,100)));
    confirmSellButton->runAction(action::easeinout(action::fadeTo(animation_part_time*2,0)));

    emit itemSold(position_number);

    refreshItemCount();
}

void shop_item::refreshItemCount() {

    if (item_count != NULL) {
        DetailsLayer->removeChild(item_count);
    }

    if (position_var == home_positions) {
        item_count = numbers::layer();

        item_count->pre = "number_";
        DetailsLayer->addChild(item_count);

        item_count->setPos(itemPosition + QPointF(20*screenScale,20*screenScale));
        item_count->setZ(10);

        int itemCount = 0;

        if (itemType == "red_jewel.svg") {
            itemCount = shared_storage::sharedGameStorage()->getCurrentRedJewel();
        }

        if (itemType == "red_potion.svg") {
            itemCount = shared_storage::sharedGameStorage()->getCurrentRedPoition();
        }

        item_count->setNum(itemCount,screenScale*details_number_scale*0.5);
    }
}
