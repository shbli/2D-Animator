#include "weapon.h"
#include "game_controller.h"
#include "map.h"

void weapon::load_from_xml(QString xml_file_name,Node* before_effects_parent, QObject *theConnection, const QString slot) {

    super_shakes_screen = false;
    super_affects_all = false;
    disabled_layer_button = 0;
    super_layer_added = false;
    super_attack_object = 0;
    effectsLayer = Layer::node();
    game_controller::sharedGameController()->mainPlayLayer->addChild(effectsLayer);
    effectsLayer->setZ(effectsLayerZ);
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



        //it's safe, the xml file is open for reading

        float screenScale = character_base::screenScale;

        xmlDocument.setContent(&openxml);

        QDomElement document = xmlDocument.documentElement();

        if (document.tagName() == "super-attack") {
            superAttack = true;
        } else {
            superAttack = false;
        }

        weapon_power = document.attribute("power").toFloat();

        if (superAttack) {

            super_affects_all = document.attribute("affect-all").toInt();
            super_decreases_hp = document.attribute("hp--").toInt();
            super_freezes_enemy = document.attribute("freeze").toInt();
            super_slow_down_enemies = document.attribute("slow-down").toInt();
            super_provoke_enemies = document.attribute("provoke").toInt();
            super_shakes_screen = document.attribute("shake-screen").toInt();

            //loading the line edits

            float hScreenScale = Director::sharedDirector()->winSizeInPixels().height() / origwallh;
            super_sprite_disabled_svg = Sprite::spriteWithSvg("button_disable.svg",hScreenScale*super_button_resize);
            disabled_layer_button = Layer::node();
            super_sprite_disabled_svg->setZ(-3);
            disabled_layer_button->setZ(-3);
            disabled_layer_button->addChild(super_sprite_disabled_svg);
            reset_time_numbers = numbers::layer();
            reset_time_numbers->pre = "number_";
            disabled_layer_button->addChild(reset_time_numbers);
            disabled_layer_button->setOpacity(0);

            super_sprite_svg =  MenuItemImage::itemWithSVG(document.attribute("button-svg"),"",theConnection,slot,hScreenScale*super_button_resize);
            super_reset_seconds = document.attribute("reset-seconds").toFloat();
            number_scaling = game_controller::sharedGameController()->currentMap->screenScale*super_numbers_resize;
            reset_time_numbers->setNum(super_reset_seconds,number_scaling);
            super_hp_reduction_value = document.attribute("hp-reduction").toFloat();
            super_hp_reduction_value_timeout = document.attribute("hp-reduction-timout").toFloat();
            super_freeze_timeout = document.attribute("freeze-timeout").toFloat();
            super_slow_down_timeout = document.attribute("slow-down-timeout").toFloat();
            super_shake_screen_timeout = document.attribute("shake-screen-timeout").toFloat();
        } else {
            weapon_type = document.attribute("type");
            weapon_name = document.attribute("name");
            canFireFromFarAway = document.attribute("fireFromFarAway").toInt();
            weaponSprite = Sprite::spriteWithSvg(document.attribute("svg"),screenScale);
            addChild(weaponSprite);
            weaponSprite->setAnchor(document.attribute("x-anch").toFloat(),document.attribute("y-anch").toFloat());
            QString super_attack_xml = document.attribute("super-attack-xml");
            if (super_attack_xml.contains(".xml")) {
                super_attack_object = new weapon;
                game_controller::sharedGameController()->mainPlayLayer->addChild(super_attack_object);
                super_attack_object->load_from_xml(super_attack_xml,before_effects_parent,theConnection,slot);
            }
        }

        QDomElement beforeElement = document.namedItem("Before").toElement();
        beforeSound = beforeElement.attribute("sound");

        QDomNode effects = beforeElement.firstChild();
        while (!effects.isNull()) {
            if (effects.isElement()) {
                QDomElement effectElement = effects.toElement();
                beforeList.append(new weapon_effect);
                before_effects_parent->addChild(beforeList.last());
                beforeList.last()->loadeffectsDomElement(&effectElement,screenScale);
                beforeList.last()->setZ(startZ - (20 * 100));
            }
            effects = effects.nextSibling();
        }


        QDomElement afterElement = document.namedItem("After").toElement();
        afterSound = afterElement.attribute("sound");

        effects = afterElement.firstChild();
        while (!effects.isNull()) {
            if (effects.isElement()) {
                QDomElement effectElement = effects.toElement();
                afterList.append(new weapon_effect);
                effectsLayer->addChild(afterList.last());
                afterList.last()->loadeffectsDomElement(&effectElement,screenScale);
            }
            effects = effects.nextSibling();
        }
    }

    connect(this,SIGNAL(effect_finished()),this,SLOT(effect_finished_slot()),Qt::UniqueConnection);


    maxTime = 0;

    for (int i = 0; i < afterList.size(); i++) {
        // max time to start the after effect
        if (afterList.at(i)->end_t[2] > maxTime) {
            maxTime = afterList.at(i)->end_t[2];
        }
    }

    for (int i = 0; i < beforeList.size(); i++) {
        // max time to start the after effect
        if (beforeList.at(i)->end_t[2] > maxTime) {
            maxTime = beforeList.at(i)->end_t[2];
        }
    }


}

void weapon::moveto(float x, float y) {
}

void weapon::update(double delta) {
    total_time_since_disabled -= delta;
    reset_time_numbers->setNum(total_time_since_disabled,number_scaling);
    if (total_time_since_disabled <= 0) {
        //reenable the super attack, stop the updater
        unSchedualUpdate();
        enable_super_button();
    }
}

void weapon::startAfterEffect() {
    //    qDebug() << Q_FUNC_INFO;
    //    if (!afterList.isEmpty()) {
    if (super_affects_all) {
        effectsLayer->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);
    } else {
        if (effectsLayer->scaleX() != local_enemy_direction) {
            effectsLayer->setScaleX(local_enemy_direction);
        }
        effectsLayer->setPos(local_enemy_x,local_enemy_y);
    }

    audioManager::playSound(afterSound);

    for (int i = 0; i < afterList.size(); i++) {
        afterList.at(i)->startEffect();
    }

    QTimer::singleShot(1000*maxTime,this,SIGNAL(effect_finished()));

    //    } else {
    //        emit effect_finished();
    //    }
}

void weapon::startBeforeEffect(float enemyX, float enemyY, int enemyDirection,float myX,float myY, int myDirection) {

    effectsLayer->setOpacity(100);

    local_enemy_x = enemyX;
    local_enemy_y = enemyY;
    local_enemy_direction = enemyDirection;


    //play the before sound
    if (!beforeList.isEmpty()) {
        audioManager::playSound(beforeSound);
        for (int i = 0; i < beforeList.size(); i++) {
            beforeList.at(i)->startEffect();
            // max time to start the after effect
        }
    }

    startAfterEffect();

    if (super_shakes_screen) {
        QTimer::singleShot(super_shake_screen_timeout*1000,game_controller::sharedGameController()->currentMap,SLOT(start_shaking_screen()));
    }

}

void weapon::start_super_attack_effect() {
    //    qDebug() << "Starting super attack for weapon " << weapon_name;
}

s_attk_obj *weapon::get_new_super_attack_object() {
    s_attk_obj* return_object = new s_attk_obj;

    return_object->super_affects_all = super_affects_all;
    return_object->super_decreases_hp = super_decreases_hp;
    return_object->super_freezes_enemy = super_freezes_enemy;
    return_object->super_slow_down_enemies = super_slow_down_enemies;
    return_object->super_provoke_enemies = super_provoke_enemies;

    return_object->super_reset_seconds = super_reset_seconds;
    return_object->super_hp_reduction_value = super_hp_reduction_value;
    return_object->super_hp_reduction_value_timeout = super_hp_reduction_value_timeout;
    return_object->super_freeze_timeout = super_freeze_timeout;
    return_object->super_slow_down_timeout = super_slow_down_timeout;

    return return_object;
}

void weapon::effect_finished_slot() {
    effectsLayer->setOpacity(0);
}

void weapon::disable_super_button() {
    super_sprite_svg->setEnabled(false);
    super_sprite_svg->runAction(action::easeinout(action::rotateTo(0.5,5000)));
    super_sprite_svg->runAction(action::easeinout(action::scaleTo(0.5,3)));
    super_sprite_svg->runAction(action::easeinout(action::fadeTo(0.5,0)));
    total_time_since_disabled = super_reset_seconds;
    schedualUpdate();
}

void weapon::enable_super_button() {
    super_sprite_svg->setEnabled(true);
    super_sprite_svg->runAction(action::easeinout(action::rotateTo(0.5,0)));
    super_sprite_svg->runAction(action::easeinout(action::scaleTo(0.5,1)));
    super_sprite_svg->runAction(action::easeinout(action::fadeTo(0.5,100)));
    total_time_since_disabled = super_reset_seconds;

}

weapon::~weapon() {
    //    qDebug() << "Disabled layer node parent = " << disabled_layer_button->parent;
    if (!super_layer_added ) {
        if (disabled_layer_button != 0) {
            disabled_layer_button->deleteLater();
        }
    }
}

