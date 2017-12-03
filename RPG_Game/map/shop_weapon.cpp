#include "shop_weapon.h"
#include <QDomDocument>
#include "numbers.h"
#include "shop.h"

shop_weapon* shop_weapon::currentSelectedWeapon = NULL;

shop_weapon::shop_weapon(QPointF pos) {
    itemPosition = pos;
    screenScale = Director::sharedDirector()->winSizeInPixels().width() / origwallw;
}

void shop_weapon::load_from_xml(QString xml_file_name, bool position) {

    weaponXML = xml_file_name;
    weapon_price = 20;
    QDomDocument xmlDocument;
    QFile openxml(xml_file_name);

    position_var = position;

    int weapon_power = 0;

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("Error, can't read") + xml_file_name + " Please contact us with a screen shot, or a copy of this error message";
        box.setText(messagetext);
        box.exec();
    } else {
        xmlDocument.setContent(&openxml);

        QDomElement document = xmlDocument.documentElement();

        weapon_price += document.attribute("power").toFloat()*attack_power;
        original_weapon_power_percant = document.attribute("power").toFloat()*attack_percantage;

        weapon_power = document.attribute("power").toFloat();

        QString superAttackFile = document.attribute("super-attack-xml");

        weaponType = document.attribute("type");
        if (position_var == shop_positions) {
            details_sprite_type_icon = Sprite::spriteWithSvg(QString(document.attribute("type") + ".svg"),screenScale*1.4);
        } else {
            details_sprite_type_icon = Sprite::spriteWithSvg(QString(document.attribute("type") + ".svg"),screenScale);
        }

        load_super_properties(superAttackFile);

        openxml.close();
    }

    if (position == home_positions) {
        weapon_price /= 2;
    }

    numbers* price_numbers;
    if (position_var == shop_positions) {

        weaponButton->setPos(itemPosition);
        Sprite* coin = Sprite::spriteWithSvg("money.svg",screenScale*coin_under_weapon_scale);
        addChild(coin);
        coin->setPos(weaponButton->pos() + QPointF(-27*screenScale,-93*screenScale));

        price_numbers = numbers::layer();

        price_numbers->pre = "number_";
        addChild(price_numbers);

        price_numbers->setPos(weaponButton->pos() + QPointF(18*screenScale,-93*screenScale));
        price_numbers->setZ(10);
    }
    //before setting the price, we make sure it's not bigger than 999
    if (weapon_price > 999 || weapon_price < 0) {
        weapon_price = 999;
    }

    if (position_var == shop_positions) {
        price_numbers->setNum(weapon_price,screenScale*number_scale);
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
        detail_price_numbers->setNum(weapon_price,screenScale*details_number_scale);
    } else {
        detail_price_numbers->setNum(weapon_price,screenScale*details_number_scale*0.75);
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


    DetailsLayer->addChild(details_sprite_type_icon);

    if (position_var == shop_positions) {
        details_sprite_type_icon->setPos(QPointF(-115*screenScale,-122.5*screenScale));
    } else {
        details_sprite_type_icon->setPos(itemPosition + QPointF(1.5*screenScale,-81*screenScale));
    }
    details_sprite_type_icon->setZ(10);

    Sprite* details_power_icon;
    if (position_var == shop_positions) {
        details_power_icon = Sprite::spriteWithSvg("power_icon.svg",screenScale*details_number_scale*1.3);
    } else {
        details_power_icon = Sprite::spriteWithSvg("power_icon.svg",screenScale*details_number_scale*0.7);
    }
    DetailsLayer->addChild(details_power_icon);

    if (position_var == shop_positions) {
        details_power_icon->setPos(QPointF(6.3*screenScale,95.3*screenScale));
    } else {
        details_power_icon->setPos(itemPosition + QPointF(87.6*screenScale,25*screenScale));
    }
    details_power_icon->setZ(10);

    //if weapon power is more than 999, we'll set it to 999
    if (weapon_power > 999) {
        weapon_power = 999;
    }

    numbers* detail_power_numbers = numbers::layer();

    detail_power_numbers->pre = "number_";
    DetailsLayer->addChild(detail_power_numbers);

    if (position_var == shop_positions) {
        detail_power_numbers->setPos(QPointF(104.5*screenScale,95.3*screenScale));
    } else {
        detail_power_numbers->setPos(itemPosition + QPointF(167.9*screenScale,25*screenScale));
    }
    detail_power_numbers->setZ(10);

    if (position_var == shop_positions) {
        detail_power_numbers->setNum(weapon_power,screenScale*details_number_scale);
    } else {
        detail_power_numbers->setNum(weapon_power,screenScale*details_number_scale*0.75);
    }

    QList <QPointF> properties_posistions;

    if (position_var == shop_positions) {
        properties_posistions.append(QPointF(-122*screenScale,-24*screenScale));
        properties_posistions.append(QPointF(6*screenScale,-24*screenScale));
        properties_posistions.append(QPointF(133.3*screenScale,-24*screenScale));
    } else {
        properties_posistions.append(itemPosition + QPointF(71.3*screenScale,-81*screenScale));
        properties_posistions.append(itemPosition + QPointF(131.7*screenScale,-81*screenScale));
        properties_posistions.append(itemPosition + QPointF(191.3*screenScale,-81*screenScale));
    }

    for (int i = 0; i < special_attack_details.size(); i++) {
        special_attack_details.at(i)->setPos(properties_posistions.at(i));
        special_attack_details.at(i)->setZ(10);
        DetailsLayer->addChild(special_attack_details.at(i));
    }


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


}

void shop_weapon::load_super_properties(QString xml_file_name) {

    QDomDocument xmlDocument;
    QFile openxml(xml_file_name);

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("Error, can't read") + xml_file_name + " Please contact us with a screen shot, or a copy of this error message";
        box.setText(messagetext);
        box.exec();
    } else {
        xmlDocument.setContent(&openxml);

        QDomElement document = xmlDocument.documentElement();


        bool super_affects_all = document.attribute("affect-all").toInt();
        bool super_decreases_hp = document.attribute("hp--").toInt();
        bool super_freezes_enemy = document.attribute("freeze").toInt();
        bool super_slow_down_enemies = document.attribute("slow-down").toInt();
        bool super_provoke_enemies = document.attribute("provoke").toInt();


        float super_reset_seconds = document.attribute("reset-seconds").toFloat();

        float special_attacks_scale = 1;
        if (position_var == home_positions) {
            special_attacks_scale = 0.5;
        }
        weapon_price -= (super_reset_seconds/3.0);
        if (super_affects_all) {
            weapon_price += (attack_all*original_weapon_power_percant);
            special_attack_details.append(Sprite::spriteWithSvg("state_group.svg",screenScale*special_attacks_scale));
        }
        if (super_decreases_hp) {
            float super_hp_reduction_value = document.attribute("hp-reduction").toFloat();
            float super_hp_reduction_value_timeout = document.attribute("hp-reduction-timout").toFloat();
            weapon_price += (super_hp_reduction_value*super_hp_reduction_value_timeout*original_weapon_power_percant);
            special_attack_details.append(Sprite::spriteWithSvg("state_bleed.svg",screenScale*special_attacks_scale));
        }
        if (super_freezes_enemy) {
            float super_freeze_timeout = document.attribute("freeze-timeout").toFloat();
            weapon_price += (super_freeze_timeout*original_weapon_power_percant);
            special_attack_details.append(Sprite::spriteWithSvg("state_stop.svg",screenScale*special_attacks_scale));
        }
        if (super_slow_down_enemies) {
            float super_slow_down_timeout = document.attribute("slow-down-timeout").toFloat();
            weapon_price += (super_slow_down_timeout*original_weapon_power_percant);
            special_attack_details.append(Sprite::spriteWithSvg("state_slow.svg",screenScale*special_attacks_scale));
        }
        if (super_provoke_enemies) {
            weapon_price += (provoke*original_weapon_power_percant);
        }


        //this power exists in both super and normal attack, so we add both values
        weapon_price += document.attribute("power").toFloat()*attack_power;
        if (position_var == shop_positions) {
            weaponButton = MenuItemImage::itemWithSVG(document.attribute("button-svg"),"",this,SLOT(on_weapon_item_clicked()),screenScale * weapon_item_scale);
            weaponButton->setEnabled(true);
            addChild(weaponButton);
        }
        if (position_var == shop_positions) {
            details_sprite_icon = Sprite::spriteWithSvg(document.attribute("button-svg"),screenScale * weapon_item_scale * 1.3);
        } else {
            details_sprite_icon = Sprite::spriteWithSvg(document.attribute("button-svg"),screenScale * resize_scale_player_icons);
        }

        openxml.close();
    }

}

void shop_weapon::setDisabled() {
    sellButton->setEnabled(false);
    confirmSellButton->setEnabled(false);
    confirmSellButton->setOpacity(0);
    sellButton->setOpacity(0);
}

void shop_weapon::setEnabled() {
    sellButton->setEnabled(true);
    confirmSellButton->setEnabled(false);
    sellButton->setOpacity(100);

}

void shop_weapon::refreshSequenceNumber() {
    sequence_number->setNum(position_number,screenScale*details_number_scale*0.4);
}

void shop_weapon::on_weapon_item_clicked() {
    if (shop::sharedDetailsLayer != NULL) {
        //hide the details layer and replace it with the other layer
        shop::sharedDetailsLayer->stopAllActions();
        shop::sharedDetailsLayer->runAction(action::easeinout(action::scaleTo(0.2,2)));
        shop::sharedDetailsLayer->runAction(action::easeinout(action::fadeTo(0.2,0)));
    }

    shop::sharedDetailsLayer = DetailsLayer;
    shop::selected_item_type = shop_weapon_type;
    currentSelectedWeapon = this;
    shop::sharedDetailsLayer->stopAllActions();
    shop::sharedDetailsLayer->runAction(action::easeinout(action::scaleTo(0.2,1)));
    shop::sharedDetailsLayer->runAction(action::easeinout(action::fadeTo(0.2,100)));

    weaponButton->stopAllActions();
    weaponButton->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleTo(0.1,1.5)),action::easeinout(action::scaleTo(0.1,1)),NULL));
}

void shop_weapon::on_sell_button_clicked() {
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

void shop_weapon::on_confirm_sell_button_clicked() {
    sellButton->setEnabled(true);
    confirmSellButton->setEnabled(false);

    float animation_part_time = 0.1;

    sellButton->stopAllActions();
    confirmSellButton->stopAllActions();

    sellButton->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animation_part_time,-1)),action::easeinout(action::scaleXTo(animation_part_time,1)),NULL));
    confirmSellButton->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animation_part_time,-1)),action::easeinout(action::scaleXTo(animation_part_time,1)),NULL));

    sellButton->runAction(action::easeinout(action::fadeTo(animation_part_time*2,100)));
    confirmSellButton->runAction(action::easeinout(action::fadeTo(animation_part_time*2,0)));

    emit weaponSold(position_number);
}
