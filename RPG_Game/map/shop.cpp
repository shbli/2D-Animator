#include "shop.h"
#include "map.h"

int shop::selected_item_type = 0;
Layer* shop::sharedDetailsLayer = 0;

shop::shop() {

}

void shop::load_from_xml(QString xml_file_name) {
    screenScale = Director::sharedDirector()->winSizeInPixels().width() / origwallw;
    Sprite* background = Sprite::spriteWithSvg("shop_background_1.svg",screenScale);
    background->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);
    addChild(background);

    winSize = Director::sharedDirector()->winSizeInPixels();



    character_info info = get_super_svg_file_name_from_character(shared_storage::sharedGameStorage()->getFirstPlayer());
    Sprite* first_character_icon = Sprite::spriteWithSvg(info.buttonFileName,screenScale*resize_scale_player_icons);
    first_character_icon->setPos((winSize.width()/2) - (283*screenScale),(winSize.height()/2) - (216*screenScale));
    first_character_icon->setZ(10);
    addChild(first_character_icon);

    Sprite* first_character_type_icon = Sprite::spriteWithSvg(info.iconFileName,screenScale);
    first_character_type_icon->setPos((winSize.width()/2) - (181*screenScale),(winSize.height()/2) - (194*screenScale));
    first_character_type_icon->setZ(10);
    addChild(first_character_type_icon);

    //let's check if there's more than one characte


    numbers* level_number_first = numbers::layer();


    level_number_first->pre = "number_";
    addChild(level_number_first);

    level_number_first->setPos((winSize.width()/2) - (181*screenScale),(winSize.height()/2) - (235*screenScale));
    level_number_first->setZ(10);

    level_number_first->setNum(info.level,screenScale*level_numbers_scaling);

    if (shared_storage::sharedGameStorage()->getSecondPlayer() != "") {

        info = get_super_svg_file_name_from_character(shared_storage::sharedGameStorage()->getSecondPlayer());
        Sprite* second_character_icon = Sprite::spriteWithSvg(info.buttonFileName,screenScale*resize_scale_player_icons);
        second_character_icon->setPos((winSize.width()/2) - (89*screenScale),(winSize.height()/2) - (216*screenScale));
        second_character_icon->setZ(10);
        addChild(second_character_icon);


        Sprite* second_character_type_icon = Sprite::spriteWithSvg(info.iconFileName,screenScale);
        second_character_type_icon->setPos((winSize.width()/2) + (2*screenScale),(winSize.height()/2) - (194*screenScale));
        second_character_type_icon->setZ(10);
        addChild(second_character_type_icon);

        numbers* level_number_second = numbers::layer();

        level_number_second->pre = "number_";
        addChild(level_number_second);

        level_number_second->setPos((winSize.width()/2) + (2*screenScale),(winSize.height()/2) - (235*screenScale));
        level_number_second->setZ(10);

        level_number_second->setNum(info.level,screenScale*level_numbers_scaling);


    }

    //addiing the back button
    MenuItemImage *back_button = MenuItemImage::itemWithSVG("back.svg","back_clicked.svg",this,SLOT(on_back_button_clicked()),screenScale);
    back_button->setPos((winSize.width()/2) - (458*screenScale),(winSize.height()/2) - (203*screenScale));




    //open the document of the shop

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

        //get all childs

        QList <QPointF> weapons_positions;

        weapons_positions.append(QPointF((winSize.width()/2) - (397*screenScale),(winSize.height()/2) + (191*screenScale)));
        weapons_positions.append(QPointF((winSize.width()/2) - (213*screenScale),(winSize.height()/2) + (191*screenScale)));
        weapons_positions.append(QPointF((winSize.width()/2) - (31*screenScale),(winSize.height()/2) + (191*screenScale)));
        weapons_positions.append(QPointF((winSize.width()/2) - (397*screenScale),(winSize.height()/2) - (7*screenScale)));
        weapons_positions.append(QPointF((winSize.width()/2) - (213*screenScale),(winSize.height()/2) - (7*screenScale)));
        weapons_positions.append(QPointF((winSize.width()/2) - (31*screenScale),(winSize.height()/2) - (7*screenScale)));

        int i = 0;

        QDomNode shopItemNode = xmlDocument.documentElement().firstChild();
        while (!shopItemNode.isNull()) {
            if (shopItemNode.isElement()) {
                QDomElement itemElement = shopItemNode.toElement();

                if (itemElement.attribute("type") == "weapon") {
                    //xml is
                    shop_weapon* shop_weapon_obj = new shop_weapon(weapons_positions.at(i));
                    i++;
                    addChild(shop_weapon_obj);
                    shop_weapon_obj->setZ(10);
                    shop_weapon_obj->load_from_xml(itemElement.attribute("xml"));
                } else {
                    shop_item* shop_item_object = new shop_item(weapons_positions.at(i));
                    i++;
                    addChild(shop_item_object);
                    shop_item_object->setZ(10);
                    shop_item_object->load_from_type(itemElement.attribute("type"),itemElement.attribute("price").toInt());
                }

            }
            shopItemNode = shopItemNode.nextSibling();
        }


        openxml.close();

    }

    display_current_gold_amount();

    gold_coin = Sprite::spriteWithSvg("money.svg",screenScale*details_number_scale*1.3);

    addChild(gold_coin);

    gold_coin->setPos((winSize.width()/2) + (318.4*screenScale),(winSize.height()/2) + (-211.2*screenScale));
    gold_coin->setZ(10);


    accept_payment_button = MenuItemImage::itemWithSVG("accept.svg","",this,SLOT(on_accept_payment_button_clicked()),screenScale);

    accept_payment_button->setPos((winSize.width()/2) + (165.2*screenScale),(winSize.height()/2) + (-200.2*screenScale));
    accept_payment_button->setZ(10);


    confirm_payment_button = MenuItemImage::itemWithSVG("money.svg","",this,SLOT(on_confirm_payment_button_clicked()),screenScale);

    confirm_payment_button->setPos((winSize.width()/2) + (158.2*screenScale),(winSize.height()/2) + (-211.2*screenScale));
    confirm_payment_button->setZ(10);
    confirm_payment_button->setOpacity(0);


    menu = Menu::menuWithmenuItems(back_button,accept_payment_button,confirm_payment_button,NULL);

    addChild(menu);

    confirm_payment_button->setEnabled(false);


}

character_info shop::get_super_svg_file_name_from_character(QString character_file_name) {

    character_info info_to_return;

    QDomDocument xmlDocument;
    QFile openxml(character_file_name);

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("Error, can't read") + character_file_name + " Please contact us with a screen shot, or a copy of this error message";
        box.setText(messagetext);
        box.exec();
    } else {
        xmlDocument.setContent(&openxml);

        QDomElement document = xmlDocument.documentElement();

        QString super_xml = document.attribute("super-attack-xml");

//        qDebug() << "Super xml for character xml " << character_file_name << " is " << super_xml;

        info_to_return.buttonFileName = get_super_svg_file_name(super_xml);

        info_to_return.iconFileName = document.attribute("type") + ".svg";

        //get character level

        info_to_return.level = shared_storage::sharedGameStorage()->getPlayerLevel(character_file_name);

        openxml.close();
    }

//    qDebug() << "Icon name is " << info_to_return.iconFileName << " and character level is " << info_to_return.level;

    return info_to_return;
}

QString shop::get_super_svg_file_name(QString super_file_name) {
    QString svg_button_name;

    QDomDocument xmlDocument;
    QFile openxml(super_file_name);

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("Error, can't read") + super_file_name + " Please contact us with a screen shot, or a copy of this error message";
        box.setText(messagetext);
        box.exec();
    } else {
        xmlDocument.setContent(&openxml);

        QDomElement document = xmlDocument.documentElement();

        svg_button_name = document.attribute("button-svg");

//        qDebug() << "Super SVG name is " << svg_button_name;

        openxml.close();
    }

    return svg_button_name;
}

void shop::display_current_gold_amount() {
    int currentAmount = shared_storage::sharedGameStorage()->getCurrentGold();


    currentGoldNumber = numbers::layer();


    currentGoldNumber->pre = "number_";
    addChild(currentGoldNumber);

    currentGoldNumber->setPos((winSize.width()/2) + (435.1*screenScale),(winSize.height()/2) + (-311.2*screenScale));
    currentGoldNumber->setZ(10);

    currentGoldNumber->setNum(currentAmount,screenScale*level_numbers_scaling*1.8);

    currentGoldNumber->setOpacity(0);

    currentGoldNumber->runAction(action::easeinout(action::moveTo(coins_move_time,(winSize.width()/2) + (435.1*screenScale),(winSize.height()/2) + (-211.2*screenScale))));
    currentGoldNumber->runAction(action::easeinout(action::fadeTo(coins_move_time,100)));

}

void shop::on_back_button_clicked() {
    //disable all the buttons as we are exiting
    menu->setEnabled(false);
    game_controller::sharedGameController()->currentMap->exit_from_shop();
}

void shop::on_accept_payment_button_clicked() {
    accept_payment_button->setEnabled(false);
    confirm_payment_button->setEnabled(true);

    float animation_part_time = 0.1;

    accept_payment_button->stopAllActions();
    confirm_payment_button->stopAllActions();

    accept_payment_button->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animation_part_time,-1)),action::easeinout(action::scaleXTo(animation_part_time,1)),NULL));
    confirm_payment_button->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animation_part_time,-1)),action::easeinout(action::scaleXTo(animation_part_time,1)),NULL));

    accept_payment_button->runAction(action::easeinout(action::fadeTo(animation_part_time*2,0)));
    confirm_payment_button->runAction(action::easeinout(action::fadeTo(animation_part_time*2,100)));

}

void shop::on_confirm_payment_button_clicked() {
    accept_payment_button->setEnabled(true);
    confirm_payment_button->setEnabled(false);

    float animation_part_time = 0.1;

    accept_payment_button->stopAllActions();
    confirm_payment_button->stopAllActions();

    accept_payment_button->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animation_part_time,-1)),action::easeinout(action::scaleXTo(animation_part_time,1)),NULL));
    confirm_payment_button->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animation_part_time,-1)),action::easeinout(action::scaleXTo(animation_part_time,1)),NULL));

    accept_payment_button->runAction(action::easeinout(action::fadeTo(animation_part_time*2,100)));
    confirm_payment_button->runAction(action::easeinout(action::fadeTo(animation_part_time*2,0)));

    if (selected_item_type == shop_weapon_type) {
        if (shop_weapon::currentSelectedWeapon != NULL) {
            buy_weapon(shop_weapon::currentSelectedWeapon);
        }
    }

    if (selected_item_type == shop_item_type) {
        if (shop_item::currentSelecteditem != NULL) {
            buy_item(shop_item::currentSelecteditem);
        }
    }
}

void shop::buy_weapon(shop_weapon *to_be_bought) {
    float animationMoveTime = 0.1;
    if (shared_storage::sharedGameStorage()->getCurrentGold() >= to_be_bought->weapon_price) {
        gold_coin->stopAllActions();
        gold_coin->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animationMoveTime,-1)),action::easeinout(action::scaleXTo(animationMoveTime,1)),action::easeinout(action::scaleXTo(animationMoveTime,-1)),action::easeinout(action::scaleXTo(animationMoveTime,1)),NULL));
        shared_storage::sharedGameStorage()->decreaseGoldBy(to_be_bought->weapon_price);
        shared_storage::sharedGameStorage()->addNewWeapon(to_be_bought->weaponXML);
        currentGoldNumber->stopAllActions();
        currentGoldNumber->runAction(action::easeinout(action::moveBy(coins_move_time*2,0,100*screenScale)));
        currentGoldNumber->runAction(action::easeinout(action::fadeTo(coins_move_time*2,0)));
        display_current_gold_amount();
    } else {
        //no sufficent amount
        gold_coin->stopAllActions();
        QPointF currentGoldNumberOrigPos = gold_coin->pos();
        float animationMoveTime = 0.05;
        gold_coin->stopAllActions();
        gold_coin->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveTo(animationMoveTime,currentGoldNumberOrigPos.x(),currentGoldNumberOrigPos.y() + (30*screenScale))),action::easeinout(action::moveTo(animationMoveTime,currentGoldNumberOrigPos.x(),currentGoldNumberOrigPos.y() - (30*screenScale))),action::easeinout(action::moveTo(animationMoveTime,currentGoldNumberOrigPos.x(),currentGoldNumberOrigPos.y() + (30*screenScale))),action::easeinout(action::moveTo(animationMoveTime,currentGoldNumberOrigPos.x(),currentGoldNumberOrigPos.y())),NULL));

    }
}

void shop::buy_item(shop_item *to_be_bought) {
    float animationMoveTime = 0.1;
    if (shared_storage::sharedGameStorage()->getCurrentGold() >= to_be_bought->item_price) {
        gold_coin->stopAllActions();
        gold_coin->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animationMoveTime,-1)),action::easeinout(action::scaleXTo(animationMoveTime,1)),action::easeinout(action::scaleXTo(animationMoveTime,-1)),action::easeinout(action::scaleXTo(animationMoveTime,1)),NULL));
        shared_storage::sharedGameStorage()->decreaseGoldBy(to_be_bought->item_price);
        if (to_be_bought->itemType == "red_jewel.svg") {
            shared_storage::sharedGameStorage()->increaseRedJewel(1);
        }
        if (to_be_bought->itemType == "red_potion.svg") {
            shared_storage::sharedGameStorage()->increaseRedPotion(1);
        }
        currentGoldNumber->stopAllActions();
        currentGoldNumber->runAction(action::easeinout(action::moveBy(coins_move_time*2,0,100*screenScale)));
        currentGoldNumber->runAction(action::easeinout(action::fadeTo(coins_move_time*2,0)));
        display_current_gold_amount();
    } else {
        //no sufficent amount
        gold_coin->stopAllActions();
        QPointF currentGoldNumberOrigPos = gold_coin->pos();
        float animationMoveTime = 0.05;
        gold_coin->stopAllActions();
        gold_coin->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveTo(animationMoveTime,currentGoldNumberOrigPos.x(),currentGoldNumberOrigPos.y() + (30*screenScale))),action::easeinout(action::moveTo(animationMoveTime,currentGoldNumberOrigPos.x(),currentGoldNumberOrigPos.y() - (30*screenScale))),action::easeinout(action::moveTo(animationMoveTime,currentGoldNumberOrigPos.x(),currentGoldNumberOrigPos.y() + (30*screenScale))),action::easeinout(action::moveTo(animationMoveTime,currentGoldNumberOrigPos.x(),currentGoldNumberOrigPos.y())),NULL));

    }
}
