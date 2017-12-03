#include "home.h"
#include "map.h"

home::home() {

}

void home::load() {
    screenScale = Director::sharedDirector()->winSizeInPixels().width() / origwallw;
    Sprite* background = Sprite::spriteWithSvg("home_background_1.svg",screenScale);
    background->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);
    addChild(background);

    winSize = Director::sharedDirector()->winSizeInPixels();

    reloadFirstCharacter();

    //let's check if there's more than one characte
    if (shared_storage::sharedGameStorage()->getSecondPlayer() != "") {
        reloadSecondCharacter();
    }

    //addiing the back button
    MenuItemImage *back_button = MenuItemImage::itemWithSVG("back.svg","back_clicked.svg",this,SLOT(on_back_button_clicked()),screenScale);
    back_button->setPos((winSize.width()/2) - (455.3*screenScale),(winSize.height()/2) - (215.3*screenScale));








    MenuItemImage *change_character = MenuItemImage::itemWithSVG("home_char.svg","home_char_clicked.svg",this,SLOT(on_change_character_clicked()),screenScale);
    change_character->setPos((winSize.width()/2) + (400.3*screenScale),(winSize.height()/2) + (180.3*screenScale));



    MenuItemImage *change_wepon = MenuItemImage::itemWithSVG("home_weap.svg","home_weap_clicked.svg",this,SLOT(on_change_wepon_clicked()),screenScale);
    change_wepon->setPos((winSize.width()/2) + (400.3*screenScale),(winSize.height()/2) + (0*screenScale));



    MenuItemImage *change_items = MenuItemImage::itemWithSVG("home_item.svg","home_item_clicked.svg",this,SLOT(on_change_items_clicked()),screenScale);
    change_items->setPos((winSize.width()/2) + (400.3*screenScale),(winSize.height()/2) - (180.3*screenScale));

    display_current_gold_amount();

    gold_coin = Sprite::spriteWithSvg("money.svg",screenScale*details_number_scale);

    addChild(gold_coin);

    gold_coin->setPos((winSize.width()/2) - (338.1*screenScale),(winSize.height()/2) - (223.8*screenScale));
    gold_coin->setZ(10);



    up_button = MenuItemImage::itemWithSVG("home_up.svg","home_up_clicked.svg",this,SLOT(on_up_button_clicked()),screenScale);
    up_button->setPos((winSize.width()/2) + (61.8*screenScale),(winSize.height()/2) + (250.1*screenScale));


    down_button = MenuItemImage::itemWithSVG("home_down.svg","home_down_clicked.svg",this,SLOT(on_down_button_clicked()),screenScale);
    down_button->setPos((winSize.width()/2) + (61.8*screenScale),(winSize.height()/2) - (250.1*screenScale));



    menu = Menu::menuWithmenuItems(back_button,change_character,change_wepon,change_items,up_button,down_button,NULL);

    addChild(menu);

    currentLayer = 0;

    screenID = 0;

    on_change_wepon_clicked();

    first_weapon_glow = Sprite::spriteWithSvg("green_glow.svg",screenScale);

    addChild(first_weapon_glow);

    first_weapon_glow->setPos((winSize.width()/2) - (286.5*screenScale),(winSize.height()/2) + (206.53*screenScale));
    first_weapon_glow->setZ(9);
    first_weapon_glow->setOpacity(0);





    second_weapon_glow = Sprite::spriteWithSvg("green_glow.svg",screenScale);

    addChild(second_weapon_glow);

    second_weapon_glow->setPos((winSize.width()/2) - (286.5*screenScale),(winSize.height()/2) - (17*screenScale));
    second_weapon_glow->setZ(9);
    second_weapon_glow->setOpacity(0);



}

character_info home::get_super_svg_file_name_from_character(QString character_file_name) {

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
        QString weapon_xml = shared_storage::sharedGameStorage()->getWeaponForCharacter(character_file_name);

        info_to_return.buttonFileName = get_super_svg_file_name(super_xml);

        info_to_return.iconFileName = document.attribute("type") + ".svg";

        info_to_return.weaponFileName = get_super_svg_file_name_from_weapon(weapon_xml);

        //get character level

        info_to_return.level = shared_storage::sharedGameStorage()->getPlayerLevel(character_file_name);

        openxml.close();
    }

    //    qDebug() << "Icon name is " << info_to_return.iconFileName << " and character level is " << info_to_return.level;

    return info_to_return;
}

QString home::get_super_svg_file_name(QString super_file_name) {
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

QString home::get_super_svg_file_name_from_weapon(QString super_file_name) {
    QString super_weapon_xml;

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

        super_weapon_xml = document.attribute("super-attack-xml");

        //        qDebug() << "Super SVG name is " << svg_button_name;

        openxml.close();
    }

    return get_super_svg_file_name(super_weapon_xml);
}

void home::display_current_gold_amount() {
    int currentAmount = shared_storage::sharedGameStorage()->getCurrentGold();


    currentGoldNumber = numbers::layer();


    currentGoldNumber->pre = "number_";
    addChild(currentGoldNumber);

    currentGoldNumber->setPos((winSize.width()/2) - (257.9*screenScale),(winSize.height()/2) - (323.8*screenScale));
    currentGoldNumber->setZ(10);

    currentGoldNumber->setNum(currentAmount,screenScale*level_numbers_scaling*1.4);

    currentGoldNumber->setOpacity(0);

    currentGoldNumber->runAction(action::easeinout(action::moveTo(coins_move_time,(winSize.width()/2) - (257.9*screenScale),(winSize.height()/2) - (223.8*screenScale))));
    currentGoldNumber->runAction(action::easeinout(action::fadeTo(coins_move_time,100)));

}

void home::on_back_button_clicked() {
    //disable all the buttons as we are exiting
    menu->setEnabled(false);
    game_controller::sharedGameController()->currentMap->exit_from_home();
}

void home::on_change_character_clicked() {
    if (currentLayer != 0) {
        removeChild(currentLayer);
        currentLayer = 0;
    }

    setTouchEnabled(false);

    screenID = characters_screen;
}

void home::on_change_items_clicked() {
    if (currentLayer != 0) {
        removeChild(currentLayer);
        currentLayer = 0;
    }

    setTouchEnabled(false);

    screenID = items_screen;

    itemsList.clear();

    currentLayer = Layer::node();
    currentLayer->setZ(10);

    addChild(currentLayer);

    int i = 0;

    shop_item* shop_item_obj;
    if (i % 2 == 0) {
        shop_item_obj = new shop_item(QPointF((winSize.width()/2) - (87.3*screenScale),(winSize.height()/2) + (139.7*screenScale)));
    } else {
        shop_item_obj = new shop_item(QPointF((winSize.width()/2) - (87.3*screenScale),(winSize.height()/2) - (75.2*screenScale)));
    }
    shop_item_obj->position_number = i+1;
    currentLayer->addChild(shop_item_obj);
    shop_item_obj->setOpacity(0);
    shop_item_obj->load_from_type("red_potion.svg",5,home_positions);
    itemsList.append(shop_item_obj);
    shop_item_obj->setDisabled();
    connect(shop_item_obj,SIGNAL(itemSold(int)),this,SLOT(itemSoldSlot(int)),Qt::UniqueConnection);

    i++;

    if (i % 2 == 0) {
        shop_item_obj = new shop_item(QPointF((winSize.width()/2) - (87.3*screenScale),(winSize.height()/2) + (139.7*screenScale)));
    } else {
        shop_item_obj = new shop_item(QPointF((winSize.width()/2) - (87.3*screenScale),(winSize.height()/2) - (75.2*screenScale)));
    }
    shop_item_obj->position_number = i+1;
    currentLayer->addChild(shop_item_obj);
    shop_item_obj->setOpacity(0);
    shop_item_obj->load_from_type("red_jewel.svg",5,home_positions);
    itemsList.append(shop_item_obj);
    shop_item_obj->setDisabled();
    connect(shop_item_obj,SIGNAL(itemSold(int)),this,SLOT(itemSoldSlot(int)),Qt::UniqueConnection);

    i++;

    currentSelectedID = 0;

    if (itemsList.count() >= 1) {
        itemsList.at(0)->setOpacity(100);
        itemsList.at(0)->setEnabled();
    }

    if (itemsList.count() >= 2) {
        itemsList.at(1)->setOpacity(100);
        itemsList.at(1)->setEnabled();
    }

}

void home::on_up_button_clicked() {
    if (screenID == weapons_screen) {
        //we are in weapons screen
        if (currentSelectedID >= 0 && currentSelectedID < weaponsList.size()) {
            weaponsList.at(currentSelectedID)->setOpacity(0);
            weaponsList.at(currentSelectedID)->setDisabled();
        }

        if (currentSelectedID + 1 >= 0 && currentSelectedID + 1 < weaponsList.size()) {
            weaponsList.at(currentSelectedID + 1)->setOpacity(0);
            weaponsList.at(currentSelectedID + 1)->setDisabled();
        }

        currentSelectedID = (currentSelectedID - 1);
        if (currentSelectedID < 0) {
            currentSelectedID = weaponsList.size() - 1;
        }
        if(currentSelectedID != (weaponsList.size() - 1)) {
            currentSelectedID = (currentSelectedID - 1);
            if (currentSelectedID < 0) {
                currentSelectedID = weaponsList.size() - 1;
            }
        }

        if (currentSelectedID >= 0 && currentSelectedID < weaponsList.size()) {
            weaponsList.at(currentSelectedID)->setOpacity(100);
            weaponsList.at(currentSelectedID)->setEnabled();
        }

        if (currentSelectedID + 1 >= 0 && currentSelectedID + 1 < weaponsList.size()) {
            weaponsList.at(currentSelectedID + 1)->setOpacity(100);
            weaponsList.at(currentSelectedID + 1)->setEnabled();
        }
    }
}

void home::on_down_button_clicked() {

    if (screenID == weapons_screen) {
        //we are in weapons screen
        if (currentSelectedID >= 0 && currentSelectedID < weaponsList.size()) {
            weaponsList.at(currentSelectedID)->setOpacity(0);
            weaponsList.at(currentSelectedID)->setDisabled();
        }

        if (currentSelectedID + 1 >= 0 && currentSelectedID + 1 < weaponsList.size()) {
            weaponsList.at(currentSelectedID + 1)->setOpacity(0);
            weaponsList.at(currentSelectedID + 1)->setDisabled();
        }


        currentSelectedID = (currentSelectedID + 1) % weaponsList.size();
        if (currentSelectedID != 0) {
            currentSelectedID = (currentSelectedID + 1) % weaponsList.size();
        }

        if (currentSelectedID >= 0 && currentSelectedID < weaponsList.size()) {
            weaponsList.at(currentSelectedID)->setOpacity(100);
            weaponsList.at(currentSelectedID)->setEnabled();
        }

        if (currentSelectedID + 1 >= 0 && currentSelectedID + 1 < weaponsList.size()) {
            weaponsList.at(currentSelectedID + 1)->setOpacity(100);
            weaponsList.at(currentSelectedID + 1)->setEnabled();
        }
    }
}

void home::on_change_wepon_clicked(int defaultSelection) {
    if (currentLayer != 0) {
        removeChild(currentLayer);
        currentLayer = 0;
    }

    setTouchEnabled(false);

    screenID = weapons_screen;

    weaponsList.clear();

    currentLayer = Layer::node();
    currentLayer->setZ(10);

    addChild(currentLayer);

    for (int i = 0; i < shared_storage::sharedGameStorage()->weaponsCount(); i++) {
        shop_weapon* shop_weapon_obj;
        if (i % 2 == 0) {
            shop_weapon_obj = new shop_weapon(QPointF((winSize.width()/2) - (87.3*screenScale),(winSize.height()/2) + (139.7*screenScale)));
        } else {
            shop_weapon_obj = new shop_weapon(QPointF((winSize.width()/2) - (87.3*screenScale),(winSize.height()/2) - (75.2*screenScale)));
        }
        shop_weapon_obj->position_number = i+1;
        currentLayer->addChild(shop_weapon_obj);
        shop_weapon_obj->setOpacity(0);
        shop_weapon_obj->load_from_xml(shared_storage::sharedGameStorage()->getWeaponXMLAt(i),home_positions);
        weaponsList.append(shop_weapon_obj);
        shop_weapon_obj->setDisabled();
        connect(shop_weapon_obj,SIGNAL(weaponSold(int)),this,SLOT(weaponSoldSlot(int)),Qt::UniqueConnection);
    }


    currentSelectedID = defaultSelection;

    if (weaponsList.count() >= 1) {
        weaponsList.at(0)->setOpacity(100);
        weaponsList.at(0)->setEnabled();
    }

    if (weaponsList.count() >= 2) {
        weaponsList.at(1)->setOpacity(100);
        weaponsList.at(1)->setEnabled();
    }

    setTouchEnabled(true);

}



void home::weaponSoldSlot(int weaponSequence) {
    int wepaonID = weaponSequence - 1;
    float animationMoveTime = 0.1;
    if (wepaonID >= 0 && wepaonID < weaponsList.size()) {
        shared_storage::sharedGameStorage()->increaseGoldBy(weaponsList.at(wepaonID)->weapon_price);
        shared_storage::sharedGameStorage()->removeOneWeapon(wepaonID);
        gold_coin->stopAllActions();
        gold_coin->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animationMoveTime,-1)),action::easeinout(action::scaleXTo(animationMoveTime,1)),action::easeinout(action::scaleXTo(animationMoveTime,-1)),action::easeinout(action::scaleXTo(animationMoveTime,1)),NULL));
        currentGoldNumber->stopAllActions();
        currentGoldNumber->runAction(action::easeinout(action::moveBy(coins_move_time*2,0,100*screenScale)));
        currentGoldNumber->runAction(action::easeinout(action::fadeTo(coins_move_time*2,0)));
        display_current_gold_amount();
        currentLayer->removeChild(weaponsList.takeAt(wepaonID));
        if (wepaonID % 2 != 0) {
            wepaonID -= 1;
        }
        on_change_wepon_clicked(0);
    }
}

void home::itemSoldSlot(int itemSequence) {
    int itemID = itemSequence - 1;
    float animationMoveTime = 0.1;
    if (itemID >= 0 && itemID < itemsList.size()) {
        bool itemSold = false;
        if (itemsList.at(itemID)->itemType == "red_jewel.svg") {
            if (shared_storage::sharedGameStorage()->getCurrentRedJewel() > 0) {
                itemSold = true;
                shared_storage::sharedGameStorage()->decreaseRedJewel(1);
            }
        }

        if (itemsList.at(itemID)->itemType == "red_potion.svg") {
            if (shared_storage::sharedGameStorage()->getCurrentRedPoition() > 0) {
                itemSold = true;
                shared_storage::sharedGameStorage()->decreaseRedPotion(1);
            }
        }
        if (itemSold) {
            shared_storage::sharedGameStorage()->increaseGoldBy(itemsList.at(itemID)->item_price);
        }
        gold_coin->stopAllActions();
        gold_coin->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleXTo(animationMoveTime,-1)),action::easeinout(action::scaleXTo(animationMoveTime,1)),action::easeinout(action::scaleXTo(animationMoveTime,-1)),action::easeinout(action::scaleXTo(animationMoveTime,1)),NULL));
        currentGoldNumber->stopAllActions();
        currentGoldNumber->runAction(action::easeinout(action::moveBy(coins_move_time*2,0,100*screenScale)));
        currentGoldNumber->runAction(action::easeinout(action::fadeTo(coins_move_time*2,0)));
        display_current_gold_amount();
    }
}

void home::refreshWeaponsSequence() {
    for (int i = 0; i < weaponsList.count(); i++) {
        weaponsList.at(i)->position_number = i+1;
        weaponsList.at(i)->refreshSequenceNumber();
    }
}

void home::touchBegin(QGraphicsSceneMouseEvent *event) {
    QPointF touchPos = Director::sharedDirector()->convertTouchPoint(event->scenePos());

    first_pos_ok = false;
    second_pos_ok = false;

    touchID = -1;
    if (screenID == weapons_screen) {
        if (currentSelectedID >= 0 && currentSelectedID < weaponsList.size()) {
            if (Director::sharedDirector()->position_in_sprite(touchPos,weaponsList.at(currentSelectedID)->details_sprite_icon)) {
                enable_drag_drop_for_weapon(currentSelectedID);
                return;
            }

        }


        if (currentSelectedID + 1 >= 0 && currentSelectedID + 1 < weaponsList.size()) {
            if (Director::sharedDirector()->position_in_sprite(touchPos,weaponsList.at(currentSelectedID+1)->details_sprite_icon)) {
                enable_drag_drop_for_weapon(currentSelectedID+1);
                return;
            }

        }
    }

}

void home::touchEnd(QGraphicsSceneMouseEvent *event) {
    int tempTouchID = touchID;
    touchID = -1;
    QPointF touchPos = Director::sharedDirector()->convertTouchPoint(event->scenePos());

    if (screenID == weapons_screen) {
        bool replaced = false;

        if (tempTouchID >= 0 && tempTouchID < weaponsList.size()) {
            if (first_pos_ok && Director::sharedDirector()->position_in_sprite(touchPos,first_character_weapon_icon)) {
                replaced = true;
                shared_storage::sharedGameStorage()->replaceCharacterWeapon(shared_storage::sharedGameStorage()->getFirstPlayer(),tempTouchID);
                reloadFirstCharacter();
            }

            if (!replaced && second_pos_ok && Director::sharedDirector()->position_in_sprite(touchPos,second_character_weapon_icon)) {
                replaced = true;
                shared_storage::sharedGameStorage()->replaceCharacterWeapon(shared_storage::sharedGameStorage()->getSecondPlayer(),tempTouchID);
                reloadSecondCharacter();
            }

            if (replaced) {
                on_change_wepon_clicked(0);
            } else {
                weaponsList.at(tempTouchID)->details_sprite_icon->setPos(previous_item_pos);
            }
        }
        first_weapon_glow->setOpacity(0);
        second_weapon_glow->setOpacity(0);
    }


}

void home::onExitTransitionDidStart() {
    menu->setEnabled(false);
    setTouchEnabled(false);
}

void home::enable_drag_drop_for_weapon(int weaponID) {
    touchID = weaponID;

    if (screenID == weapons_screen) {

        previous_item_pos = weaponsList.at(touchID)->details_sprite_icon->pos();

        if (weaponsList.at(touchID)->weaponType.toLower() == firstCharacter.iconFileName.remove(".svg").toLower()) {
            first_weapon_glow->setOpacity(100);
            first_pos_ok = true;
        }

        if (weaponsList.at(touchID)->weaponType.toLower() == secondCharaacter.iconFileName.remove(".svg").toLower()) {
            second_weapon_glow->setOpacity(100);
            second_pos_ok = true;
        }
    }
}

void home::reloadFirstCharacter() {
    character_info info = get_super_svg_file_name_from_character(shared_storage::sharedGameStorage()->getFirstPlayer());
    first_character_icon = Sprite::spriteWithSvg(info.buttonFileName,screenScale*resize_scale_player_icons);
    first_character_icon->setPos((winSize.width()/2) - (415.15*screenScale),(winSize.height()/2) + (203.53*screenScale));
    first_character_icon->setZ(10);
    addChild(first_character_icon);

    first_character_type_icon = Sprite::spriteWithSvg(info.iconFileName,screenScale);
    first_character_type_icon->setPos((winSize.width()/2) - (286.5*screenScale),(winSize.height()/2) + (120*screenScale));
    first_character_type_icon->setZ(10);
    addChild(first_character_type_icon);

    firstCharacter = info;



    level_number_first = numbers::layer();


    level_number_first->pre = "number_";
    addChild(level_number_first);

    level_number_first->setPos((winSize.width()/2) - (415.15*screenScale),(winSize.height()/2) + (120*screenScale));
    level_number_first->setZ(10);

    level_number_first->setNum(info.level,screenScale*level_numbers_scaling);


    first_character_weapon_icon = Sprite::spriteWithSvg(info.weaponFileName,screenScale*resize_scale_player_icons);
    first_character_weapon_icon->setPos((winSize.width()/2) - (286.5*screenScale),(winSize.height()/2) + (203.53*screenScale));
    first_character_weapon_icon->setZ(10);
    addChild(first_character_weapon_icon);
}

void home::reloadSecondCharacter() {
    character_info info = get_super_svg_file_name_from_character(shared_storage::sharedGameStorage()->getSecondPlayer());
    secondCharaacter = info;
    second_character_icon = Sprite::spriteWithSvg(info.buttonFileName,screenScale*resize_scale_player_icons);
    second_character_icon->setPos((winSize.width()/2) - (415.15*screenScale),(winSize.height()/2) - (20*screenScale));
    second_character_icon->setZ(10);
    addChild(second_character_icon);


    second_character_type_icon = Sprite::spriteWithSvg(info.iconFileName,screenScale);
    second_character_type_icon->setPos((winSize.width()/2) - (286.5*screenScale),(winSize.height()/2) - (106.1*screenScale));
    second_character_type_icon->setZ(10);
    addChild(second_character_type_icon);

    level_number_second = numbers::layer();

    level_number_second->pre = "number_";
    addChild(level_number_second);

    level_number_second->setPos((winSize.width()/2) - (415.15*screenScale),(winSize.height()/2) - (106.1*screenScale));
    level_number_second->setZ(10);

    level_number_second->setNum(info.level,screenScale*level_numbers_scaling);

    second_character_weapon_icon = Sprite::spriteWithSvg(info.weaponFileName,screenScale*resize_scale_player_icons);
    second_character_weapon_icon->setPos((winSize.width()/2) - (286.5*screenScale),(winSize.height()/2) - (20*screenScale));
    second_character_weapon_icon->setZ(10);
    addChild(second_character_weapon_icon);
}

void home::touchMove(QGraphicsSceneMouseEvent *event) {
    QPointF touchPos = Director::sharedDirector()->convertTouchPoint(event->scenePos());
    if (screenID == weapons_screen) {
        if (touchID >= 0 && touchID < weaponsList.size()) {
            weaponsList.at(touchID)->details_sprite_icon->setPos(touchPos);

        }
    }
}

