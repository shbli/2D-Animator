#include "quest_logic.h"
#include "numbers.h"
#include "shared_storage.h"
#include "game_engine.h"
#include "map.h"


quest_logic::quest_logic(Node *quest_parent, QString quest_key_svg, QString reward_type, QString reward, QString dropSVG,QString mapXML,QString elementName) {

    element_name = elementName;
    map_xml_file_name = mapXML;
    quest_key_string = quest_key_svg;
    reward_type_string = reward_type;
    reward_string = reward;
    if (quest_key_svg == "" && dropSVG != "") {
        isDropElement = true;
    } else {
        isDropElement = false;
    }
    if (isDropElement) {
        //always make it available
        isKeyAvailable = true;
    } else {
        isKeyAvailable = shared_storage::sharedGameStorage()->isKeyAvailable(quest_key_svg);
    }

    float screenScale = Director::sharedDirector()->winSizeInPixels().width()/origwallw;
    hScreenScale = Director::sharedDirector()->winSizeInPixels().height()/origwallh;
    if (isDropElement) {
        //quest parent scale value is used just to resize the element here, it should be reset after creating the quest
        explenation_mark = MenuItemImage::itemWithSVG(dropSVG,"",this,SLOT(on_quest_button_clicked()),screenScale*quest_parent->scale());
        explenation_mark->setPos(quest_parent->pos());
    } else {
        explenation_mark = MenuItemImage::itemWithSVG("dash_board_quest.svg","",this,SLOT(on_quest_button_clicked()),screenScale*0.7);
        explenation_mark->setPos(quest_parent->pos() + QPointF(0,120*screenScale));
    }
    explenation_mark->setZ(quest_parent->z());
    quest_parent->parent->addChild(explenation_mark);
    explenation_mark->setEnabled(true);

    questDashPos = game_controller::sharedGameController()->currentMap->dashboard_quest->pos();


    decline_button = MenuItemImage::itemWithSVG("decline.svg","decline_clicked.svg",this,SLOT(on_declilned_button_clicked()),hScreenScale*0.5);
    decline_button->setPos(QPointF(-85.115*hScreenScale,-70.63*hScreenScale));
    addChild(decline_button);


    accept_button = MenuItemImage::itemWithSVG("accept.svg","accept_clicked.svg",this,SLOT(on_accept_button_clicked()),hScreenScale*0.6);
    accept_button->setPos(QPointF(85.115*hScreenScale,-65.63*hScreenScale));
    addChild(accept_button);

    decline_button->setEnabled(false);
    accept_button->setEnabled(false);

    Sprite* msg_board;
    if (isDropElement) {
        msg_board = Sprite::spriteWithSvg("msg_board_treasure.svg",hScreenScale);
    } else {
        msg_board = Sprite::spriteWithSvg("msg_board_quest.svg",hScreenScale);
    }
    setOpacity(0);
    setScale(4);
    addChild(msg_board);
    setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);
    setZ(20000002);
    msg_board->setZ(-1);


    reward_number_layer = 0;
    if (!isDropElement) {
        key = Sprite::spriteWithSvg(quest_key_svg,hScreenScale);
        addChild(key);
        key->setPos(QPointF(-84.86*hScreenScale,10.85*hScreenScale));
        keyPos = key->pos();
    }

    if (reward_type == "money") {
        Sprite* coin = Sprite::spriteWithSvg("money.svg",hScreenScale*0.75);
        addChild(coin);

        coin->setPos(QPointF(44.84*hScreenScale,10.85*hScreenScale));

        numbers* reward_value = numbers::layer();

        reward_value->pre = "number_";
        addChild(reward_value);

        reward_value->setPos(QPointF(119.91*hScreenScale,10.85*hScreenScale));

        reward_value->setNum(reward.toInt(),hScreenScale*0.5);

        if (isDropElement) {
            reward_value->setPos(reward_value->pos() - QPointF(84.86*screenScale,0));
            coin->setPos(coin->pos() - QPointF(84.86*screenScale,0));
        }

        reward_number_layer = reward_value;
        reward_sprite = coin;
    }

    if (reward_type == "item" || reward_type == "key") {
        Sprite* item = Sprite::spriteWithSvg(reward,hScreenScale);
        addChild(item);
        if (isDropElement) {
            item->setPos(QPointF(0*hScreenScale,10.85*hScreenScale));
        } else {
            item->setPos(QPointF(84.86*hScreenScale,10.85*hScreenScale));
        }
        reward_sprite = item;
    }

    if (reward_type.toLower() == "weapon") {
        QString weaponButtoSVG = get_super_svg_file_name_from_weapon(reward);
        Sprite* weapon = Sprite::spriteWithSvg(weaponButtoSVG,hScreenScale*0.75);
        addChild(weapon);
        if (isDropElement) {
            weapon->setPos(QPointF(0*hScreenScale,10.85*hScreenScale));
        } else {
            weapon->setPos(QPointF(84.86*hScreenScale,10.85*hScreenScale));
        }
        reward_sprite = weapon;
    }

    dashboard_bag = Sprite::spriteWithSvg("dashboard_bag.svg",screenScale);
    dashboard_bag->setPos(Director::sharedDirector()->winSizeInPixels().width() * 0.3, - 150 * screenScale);
    game_controller::sharedGameController()->currentMap->addChild(dashboard_bag);
    dashboard_bag->setZ(20000002 + 10);
}

void quest_logic::on_quest_button_clicked() {
    explenation_mark->setEnabled(false);
    decline_button->setEnabled(true);
    accept_button->setEnabled(true);
    runAction(action::easeinout(action::fadeTo(0.25,100)));
    runAction(action::easeinout(action::scaleTo(0.25,1)));

}

void quest_logic::on_accept_button_clicked() {

    if (ok_to_grab()) {
        isKeyAvailable = false;
        explenation_mark->setEnabled(true);
        explenation_mark->setEnabled(false);
        explenation_mark->runAction(action::easeinout(action::fadeTo(1,0)));
        explenation_mark->runAction(action::easeinout(action::scaleTo(1,0)));
        if (isDropElement) {
            shared_storage::sharedGameStorage()->setDropDisable(map_xml_file_name + "_" + element_name);

        }
        decline_button->setEnabled(false);
        accept_button->setEnabled(false);


        //reward animation for sucess
        float screenScale = Director::sharedDirector()->winSizeInPixels().width()/origwallw;

        float RewardAnimationTime = 0.5;
        reward_sprite->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleTo(RewardAnimationTime/2,2)),action::easeinout(action::scaleTo(RewardAnimationTime/2,1)), action::easCurve(action::moveTo(RewardAnimationTime,-200*screenScale,(-pos().y())*screenScale),QEasingCurve::InCubic),action::FuncCall(this,SLOT(on_accept_button_hide())),NULL));
        if (reward_number_layer != 0) {
            reward_number_layer->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleTo(RewardAnimationTime/2,2)),action::easeinout(action::scaleTo(RewardAnimationTime/2,1)),action::easCurve(action::moveTo(RewardAnimationTime,-200*screenScale,(-pos().y())*screenScale),QEasingCurve::InCubic),NULL));
        }

        dashboard_bag->runAction(action::easCurve(action::moveTo(RewardAnimationTime*2,(pos().x()) - (200*screenScale),(150*screenScale)/2),QEasingCurve::OutElastic));



        if (quest_key_string != "") {
            shared_storage::sharedGameStorage()->removeOneKey(quest_key_string);
        }

        if (reward_type_string.toLower() == "weapon") {
            shared_storage::sharedGameStorage()->addNewWeapon(reward_string);
        }

        if (reward_type_string == "item") {
            if (reward_string == "red_jewel.svg") {
                shared_storage::sharedGameStorage()->increaseRedJewel(1);
            }
            if (reward_string == "red_potion.svg") {
                shared_storage::sharedGameStorage()->increaseRedPotion(1);
            }
        }

        if (reward_type_string == "key") {
            if (shared_storage::sharedGameStorage()->keyCount() < 5) {
                shared_storage::sharedGameStorage()->addNewKey(reward_string);
            }
        }

        if (reward_type_string == "money") {
            shared_storage::sharedGameStorage()->increaseGoldBy(reward_string.toInt());
        }

        game_controller::sharedGameController()->currentMap->refreshDashBoard();

    } else {
        float animation_time = 0.05;
        float moveValue = 20 * hScreenScale;
        if (!isDropElement) {
            key->stopAllActions();
            key->runSequence(Sequence::sequenceWithActions(action::moveTo(animation_time,keyPos.x() - (moveValue),keyPos.y()),action::moveTo(animation_time,keyPos.x() + (moveValue),keyPos.y()),action::moveTo(animation_time,keyPos.x() - (moveValue),keyPos.y()),action::moveTo(animation_time,keyPos.x() + (moveValue),keyPos.y()),action::moveTo(animation_time,keyPos.x() - (moveValue),keyPos.y()),action::moveTo(animation_time,keyPos.x() + (moveValue),keyPos.y()),action::moveTo(animation_time,keyPos.x() - (moveValue),keyPos.y()),action::moveTo(animation_time,keyPos.x() + (moveValue),keyPos.y()),action::moveTo(animation_time,keyPos.x(),keyPos.y()),NULL));
        }
        moveValue *= -1;
        game_controller::sharedGameController()->currentMap->dashboard_quest->stopAllActions();
        game_controller::sharedGameController()->currentMap->dashboard_quest->runSequence(Sequence::sequenceWithActions(action::moveTo(animation_time,questDashPos.x() - (moveValue),questDashPos.y()),action::moveTo(animation_time,questDashPos.x() + (moveValue),questDashPos.y()),action::moveTo(animation_time,questDashPos.x() - (moveValue),questDashPos.y()),action::moveTo(animation_time,questDashPos.x() + (moveValue),questDashPos.y()),action::moveTo(animation_time,questDashPos.x() - (moveValue),questDashPos.y()),action::moveTo(animation_time,questDashPos.x() + (moveValue),questDashPos.y()),action::moveTo(animation_time,questDashPos.x() - (moveValue),questDashPos.y()),action::moveTo(animation_time,questDashPos.x() + (moveValue),questDashPos.y()),action::moveTo(animation_time,questDashPos.x(),questDashPos.y()),NULL));

    }
}

void quest_logic::on_declilned_button_clicked() {
    explenation_mark->setEnabled(true);
    decline_button->setEnabled(false);
    accept_button->setEnabled(false);
    runAction(action::easeinout(action::fadeTo(0.25,0)));
    runAction(action::easeinout(action::scaleTo(0.25,4)));
}

void quest_logic::on_accept_button_hide() {
    runAction(action::easeinout(action::fadeTo(0.25,0)));
    runAction(action::easeinout(action::scaleTo(0.25,4)));
    reward_sprite->setOpacity(0);
    if (reward_number_layer != 0) {
        reward_number_layer->setOpacity(0);
    }
    float screenScale = Director::sharedDirector()->winSizeInPixels().width()/origwallw;

    dashboard_bag->runAction(action::easCurve(action::moveTo(0.5,Director::sharedDirector()->winSizeInPixels().width() * 0.3, - 150 * screenScale),QEasingCurve::InOutCirc));
}

QString quest_logic::get_super_svg_file_name_from_weapon(QString super_file_name) {
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

bool quest_logic::ok_to_grab() {

    if (isDropElement) {
        //always make it available
        isKeyAvailable = true;
    } else {
        isKeyAvailable = shared_storage::sharedGameStorage()->isKeyAvailable(quest_key_string);
    }

    bool return_val = false;

    if (isKeyAvailable) {
        if (reward_type_string == "key") {
            if (shared_storage::sharedGameStorage()->keyCount() < 5) {
                if (!shared_storage::sharedGameStorage()->isKeyAvailable(reward_string)) {
                    return_val = true;
                }
            }
        } else {
            return_val = true;
        }
    }

    return return_val;
}

QString quest_logic::get_super_svg_file_name(QString super_file_name) {
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

