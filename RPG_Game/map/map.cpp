#include "map.h"

#define halfCharacterWidth 60
#define halfCharacterhight 100

QPointF map::enterPoint = QPointF(50,250);
bool map::coming_from_game_over = false;

map::map() {

    startCharacterSelectedIndex = -1;

    //testing the colorize effect

//    Sprite* big_sprite = Sprite::spriteWithSvg("armor.svg",1);
//    addChild(big_sprite);
//    big_sprite->setZ(1000000);
//    big_sprite->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);

//    QGraphicsColorizeEffect* color_effect = new QGraphicsColorizeEffect;
//    color_effect->setColor(Qt::red);
//    big_sprite->setGraphicsEffect(color_effect);

    game_controller::sharedGameController()->currentMap = this;
    humanLayer = 0;
    //set up the human layer
    int old_player_speed = game_controller::sharedGameController()->playerSpeed;
    int old_enemy_speed = game_controller::sharedGameController()->enemySpeed;
    game_controller::sharedGameController()->resetController();
    game_controller::sharedGameController()->playerSpeed = old_player_speed;
    game_controller::sharedGameController()->enemySpeed = old_enemy_speed;

    humanLayer = new human_char_controller;
    humanLayer->setTouchEnabled(false);
    addChild(humanLayer);

//    elips = new under_char_elips;
//    addChild(elips);
//    elips->setPos(200,200);
//    elips->setOpacity(0);
//    elips->setScale(0);
//    elips->setZ(1000);


//    arrow = new human_char_arrow;
//    addChild(arrow);
//    arrow->setOpacity(0);
//    arrow->setZ(1000);
//    arrow->topLeft.setY(Director::sharedDirector()->winSizeInPixels().height() - 20);
    setTouchEnabled(true);

    screenScale = Director::sharedDirector()->winSizeInPixels().width() / origwallw;

    game_controller::sharedGameController()->playerSpeed = 1;

//    QPen pen;
//    pen.setColor(Qt::black);
//    pen.setWidth(Director::sharedDirector()->winSizeInPixels().width()*2);
//    line = lineNode::lineWithPen(pen);
    line = Sprite::spriteWithSvg("black_layer.svg",screenScale);
//    line->setOpacity(0);
    addChild(line);
    line->setZ(20000000 - 50);
    line->setScale(110);
    line->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);
//    line->setLineEndPoints(0,0,Director::sharedDirector()->winSizeInPixels().width(),Director::sharedDirector()->winSizeInPixels().height());
//    setOpacity(0);

    gameOver = false;

    ghost_character = NULL;
}

void map::load_from_xml(QString xml_file_name) {


    current_shop_pointer = 0;
    current_home_pointer = 0;

#ifdef display_map_xml_name

    float posx = 100;
    float posy = 50;
    float fontSize = 15;
    Label* map_xml_label = Label::LabelWithText(xml_file_name,QColor(255,255,255),fontSize);
    map_xml_label->setPos(posx*screenScale,posy*screenScale);
    map_xml_label->setScale(screenScale);
    map_xml_label->setZ(200000);
    addChild(map_xml_label);

    posx += 3;
    posy += 3;
//    fontSize += 2;

    Label* map_xml_label_2 = Label::LabelWithText(xml_file_name,QColor(0,0,0),fontSize);
    map_xml_label_2->setPos(posx*screenScale,posy*screenScale);
    map_xml_label_2->setScale(screenScale);
    map_xml_label_2->setZ(200000-1);
    map_xml_label_2->setOpacity(50);
    addChild(map_xml_label_2);
#endif

//    QTimer::singleShot(5000,this,SLOT(start_battle_effect()));

    //this button should be clicked on a new empty character
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

        dashBoard = Sprite::spriteWithSvg("dash_board.svg",screenScale);
        dashBoard->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,dashBoard->height()/2);
        dashBoard->setZ(20000002);

        addChild(dashBoard);


        closing_door = Sprite::spriteWithSvg("dash_board_2.svg",screenScale);
        closing_door->setAnchor(0.5,1);
        closing_door->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,110*screenScale);
        closing_door->setZ(20000002);

        addChild(closing_door);


        closing_door_lost = Sprite::spriteWithSvg("dash_board_gameover.svg",screenScale);
        closing_door_lost->setAnchor(0.5,1);
        closing_door_lost->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,110*screenScale);
        closing_door_lost->setZ(20000002);

        closing_door_lost->setOpacity(0);

        addChild(closing_door_lost);

        if (coming_from_game_over) {
            coming_from_game_over = false;
            closing_door_lost->setOpacity(100);
            closing_door->setOpacity(0);
        }


        red_potion_button = MenuItemImage::itemWithSVG("red_potion.svg","red_potion_clicked.svg",this,SLOT(on_red_poition_clicked()),screenScale);
        red_potion_button->setPos(202*screenScale,54.46*screenScale);
        addChild(red_potion_button);
        red_potion_button->setZ(20000003);
        red_potion_button->setEnabled(false);



        red_jewel_button = MenuItemImage::itemWithSVG("red_jewel.svg","red_jewel_clicked.svg",this,SLOT(on_red_jewel_clicked()),screenScale);
        red_jewel_button->setPos(329*screenScale,54.46*screenScale);
        addChild(red_jewel_button);
        red_jewel_button->setZ(20000003);
        red_jewel_button->setEnabled(false);

        quest_button_open = false;



        quest_button_shadow = Sprite::spriteWithSvg("dash_board_quest_shadow.svg",screenScale);
        quest_button_shadow->setPos(86.72*screenScale,44.46*screenScale);
        quest_button_shadow->setZ(20000003);

        addChild(quest_button_shadow);

        dashboard_quest = MenuItemImage::itemWithSVG("dash_board_quest.svg","dash_board_quest.svg",this,SLOT(on_dashboard_quest_button_clicked()),screenScale);
        dashboard_quest->setPos(76.72*screenScale,54.46*screenScale);
        addChild(dashboard_quest);
        dashboard_quest->setZ(20000005);
        dashboard_quest->setEnabled(true);

        red_poition_count = NULL;
        red_jewel_count = NULL;
        silver_count = NULL;
        gold_count = NULL;

        quest_pop_layer = Layer::node();
        addChild(quest_pop_layer);
        quest_pop_layer->setPos(dashboard_quest->pos().x(),-455.0 * screenScale);
        quest_pop_layer->setZ(20000000);

        quest_pop_sprite = Sprite::spriteWithSvg("dash_board_pop.svg",screenScale);
        quest_pop_sprite->setPos(0,(quest_pop_sprite->height()/2) + (107.5*screenScale));
//        quest_pop_sprite->setZ(20000002);

        quest_pop_layer->addChild(quest_pop_sprite);
        keys_layer = Layer::node();
        quest_pop_layer->addChild(keys_layer);
        keys_layer->setPos(quest_pop_sprite->pos());




        refreshDashBoard();

        Sprite* golden_coin = Sprite::spriteWithSvg("money.svg",screenScale*0.8);
        golden_coin->setPos(433.56*screenScale,54.46*screenScale);
        addChild(golden_coin);
        golden_coin->setZ(20000003);




        Sprite* silver_coin = Sprite::spriteWithSvg("money_silver.svg",screenScale*0.6);
        silver_coin->setPos(590.82*screenScale,50.43*screenScale);
        addChild(silver_coin);
        silver_coin->setZ(20000003);

        xmlDocument.setContent(&openxml);

        QDomElement document = xmlDocument.documentElement();

        character_base::screenScale = screenScale*0.6;
        game_controller::sharedGameController()->playerSpeed = 1/0.7;

        mapName = document.attribute("name");


        int minute = QTime::currentTime().minute();
        int hour = QTime::currentTime().hour();

//        qDebug() << "Current minute is " << minute << " and hour is " << hour;

        opacity_night_level = 0;

        if (hour%2 == 1) {
            //decreasing
            opacity_night_level = 60 - minute;
        } else {
            //increasing
            opacity_night_level = minute;
        }

        QString extra_night_extension = "night_";

        clockRotation = 0;
        if (opacity_night_level < 30) {
            //it's morning
            extra_night_extension = "";
        }

        clockRotation += (opacity_night_level*3);


        Sprite* clock_body = Sprite::spriteWithSvg("clock_body.svg",screenScale * 0.65);
        addChild(clock_body);
        clock_body->setPos(Director::sharedDirector()->winSizeInPixels().width() - (clock_body->width()/3),10*screenScale);
        clock_body->setZ(20000005);

        sun_moon = Sprite::spriteWithSvg("sun_moon.svg",screenScale * 0.65);
        addChild(sun_moon);
        sun_moon->setPos(clock_body->pos());
        sun_moon->setZ(20000004);
        sun_moon->setRotation(clockRotation - 360);

        //checkpoint
        bool isCheckPoint = document.attribute("checkpoint").toInt();

        if (isCheckPoint) {
            Sprite* checkPoint = Sprite::spriteWithSvg("check_point.svg",screenScale);
            addChild(checkPoint);
//            checkPoint->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);

            checkPoint->setPos(clock_body->pos() + QPointF(0,50*screenScale));

            checkPoint->setZ(20000000);
//            checkPoint->runAction(action::easeinout(action::fadeTo(2,0)));

            checkPoint->setRotation(-90);

            checkPoint->setAnchor(0.5,1);
//            checkPoint->runAction(action::easeinout(action::fadeTo(2,0)));

            checkPoint->runSequence(Sequence::sequenceWithActions(action::fadeTo(1,100),action::easCurve(action::rotateTo(3,0),QEasingCurve::OutElastic),NULL));

            shared_storage::sharedGameStorage()->setCheckPoint(xml_file_name);

        }

        Sprite* background = Sprite::spriteWithSvg(extra_night_extension + document.attribute("background"),screenScale);
        addChild(background);
        background->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);
        background->setZ(-100);

        float y_offset = (origwallh - (Director::sharedDirector()->winSizeInPixels().height()/screenScale));
        y_offset /= 2;

        //loading the map elements
        QDomNode enemiesElementsNode = document.namedItem("enemies");
        bool containsRandomBattle = enemiesElementsNode.toElement().attribute("contains_random_battle").toInt();
        if (containsRandomBattle) {

            character_base::screenScale = (Director::sharedDirector()->winSizeInPixels().height()/origwallh) * 1;
            game_controller::sharedGameController()->playerSpeed = 1;

            //there's a random battle, we should display a character
            QString ghoost_xml = enemiesElementsNode.toElement().attribute("ghost_skeltal_xml");

            moving_character* xml_character = new moving_character;
            ghost_character = xml_character;
            xml_character->computer_player = true;
            enemies.append(xml_character);

            humanLayer->addChild(xml_character);

            //special case, get the first character level
            enemiesElementsNode = enemiesElementsNode.firstChild();

            if (enemiesElementsNode.isElement()) {
                QDomElement enemyElement = enemiesElementsNode.toElement();

                QString enemy_xml = enemyElement.attribute("skeltal_xml");
                int enemy_level = enemyElement.attribute("enemy_level").toInt();

                //this value is used for the bonus
                last_character_level = enemy_level;

                enemies.first()->myLevel = enemy_level;
                moving_character* xml_enemy = new moving_character;
                humanLayer->addChild(xml_enemy);
                xml_enemy->myLevel = enemy_level;
                xml_enemy->computer_player = true;
                xml_enemy->load_from_xml(enemy_xml);
                xml_enemy->setPos((150*screenScale) + Director::sharedDirector()->winSizeInPixels().width(), 150*screenScale);
                enemies.append(xml_enemy);

            }


            xml_character->load_from_xml(ghoost_xml);

            //calculate the opposite position where the character will, or is going to appear

            QPointF newEnterPointForGhost = enterPoint;

            if (enterPoint.x() < 200*screenScale) {
                newEnterPointForGhost.setX(Director::sharedDirector()->winSizeInPixels().width() * 1.1);
            } else if (enterPoint.x() > (Director::sharedDirector()->winSizeInPixels().width() - (200*screenScale) ) ) {
                newEnterPointForGhost.setX(Director::sharedDirector()->winSizeInPixels().width() * -0.1);
            } else if (enterPoint.y() > (Director::sharedDirector()->winSizeInPixels().height()/2 ) ) {
                newEnterPointForGhost.setX(Director::sharedDirector()->winSizeInPixels().width() * -0.1);
                newEnterPointForGhost.setY(Director::sharedDirector()->winSizeInPixels().height() * -0.1);
            } else {
                newEnterPointForGhost.setX(Director::sharedDirector()->winSizeInPixels().width() * 1.1);
                newEnterPointForGhost.setY(Director::sharedDirector()->winSizeInPixels().height() * 1.1);
            }

            xml_character->setPos(newEnterPointForGhost);
            xml_character->computer_player = true;
            xml_character->startBreathing();

            //once child has been treated manually, let's go to the next one
            enemiesElementsNode = enemiesElementsNode.nextSibling();

            while(!enemiesElementsNode.isNull()) {
                if (enemiesElementsNode.isElement()) {
                    QDomElement enemyElement = enemiesElementsNode.toElement();

                    QString enemy_xml = enemyElement.attribute("skeltal_xml");
                    int enemy_level = enemyElement.attribute("enemy_level").toInt();

                    moving_character* xml_enemy = new moving_character;
                    humanLayer->addChild(xml_enemy);
                    xml_enemy->myLevel = enemy_level;
                    xml_enemy->computer_player = true;
                    xml_enemy->load_from_xml(enemy_xml);
                    xml_enemy->setPos((150*screenScale) + Director::sharedDirector()->winSizeInPixels().width(), 150*screenScale);
                    enemies.append(xml_enemy);

                }
                enemiesElementsNode = enemiesElementsNode.nextSibling();
            }

        }
        //loading the map elements
        QDomNode mapElementsNode = document.namedItem("all-map-emlemnts");
        mapElementsNode = mapElementsNode.firstChild();
        while (!mapElementsNode.isNull()) {
            if (mapElementsNode.isElement()) {
                QDomElement mapElement = mapElementsNode.toElement();
                element newElement;

                newElement.name = mapElement.attribute("name");
                newElement.type = mapElement.attribute("type");
                float x = mapElement.attribute("x").toFloat();
                float y = mapElement.attribute("y").toFloat();
                float r = mapElement.attribute("r").toFloat();
                int Z = mapElement.attribute("z").toInt();
                int scaleX = mapElement.attribute("xscale").toInt();
                float elementscale = mapElement.attribute("scale").toFloat();
                newElement.toXML = mapElement.attribute("to-xml");
                if (newElement.type == "Quest" || newElement.type == "Drop" || newElement.type == "DummySkelton") {
                    character_base* quest_character = NULL;
                    if (newElement.type == "Quest" || newElement.type == "DummySkelton") {
                        quest_character = new character_base;
                        quest_character->computer_player = true;
                        quest_character->load_from_xml(mapElement.attribute("svg"));
                        quest_character->startBreathing();
                        newElement.elementSprite = quest_character;
                        quest_character->myHealthBar->setOpacity(0);
                    } else {
                        newElement.elementSprite = Layer::node();
                    }

                    addChild(newElement.elementSprite);

                    float xMargine = 150;
                    if (scaleX > 0) {
                        xMargine *= -1;
                    }

                    newElement.elementSprite->setPos(x*screenScale,(y*screenScale) - y_offset);
                    newElement.elementSprite->setRotation(r);
                    newElement.elementSprite->setZ(startZ - (newElement.elementSprite->pos().y() * 100) + Z);

//                    qDebug() << "element " << newElement.name << " z = " << newElement.elementSprite->z();
                    newElement.elementSprite->setScaleX(scaleX);
                    quest_logic* new_quest;
                    if (newElement.type == "Quest") {
                        new_quest = new quest_logic(newElement.elementSprite,mapElement.attribute("quest-key"),mapElement.attribute("reward-type"),newElement.toXML);
                    } else if (newElement.type == "Drop") {
                        if (shared_storage::sharedGameStorage()->isDropEnabled(xml_file_name + "_" + newElement.name)) {
                            //the scale value is set to be copied by it's sprite child in the quest, then we'll set it back to default value 1
                            float scaleXTemp = newElement.elementSprite->scaleX();
                            newElement.elementSprite->setScale(elementscale);
                            new_quest = new quest_logic(newElement.elementSprite,"",mapElement.attribute("reward-type"),newElement.toXML,mapElement.attribute("svg"),xml_file_name,newElement.name);
                            newElement.elementSprite->setScale(1);
                            newElement.elementSprite->setScaleX(scaleXTemp);
                        } else {
                            new_quest = 0;
                        }
                    }

                    if (quest_character != NULL) {
                        //this is to fix the z level for characters
                        newElement.elementSprite->setPos(x*screenScale + xMargine,(y*screenScale) - y_offset);
                        quest_character->moveto(x*screenScale,(y*screenScale) - y_offset);
                    }
                    if (new_quest != 0) {
                        addChild(new_quest);
                    }
                } else {
                    newElement.elementSprite = Sprite::spriteWithSvg(mapElement.attribute("svg"),screenScale*elementscale);

                    addChild(newElement.elementSprite);
                    newElement.elementSprite->setPos(x*screenScale,(y*screenScale) - y_offset);
                    newElement.elementSprite->setRotation(r);
                    newElement.elementSprite->setZ(startZ - (newElement.elementSprite->pos().y() * 100) + Z);
                    newElement.elementSprite->setScaleX(scaleX);

                    if (newElement.type == "Gate") {
                        QString svgName = mapElement.attribute("svg");
                        float widthPercentage = 0;
                        float heightPercantage = 0;

                        if (svgName.contains("arrow_l.svg",Qt::CaseInsensitive)) {
                            heightPercantage = 0;
                            widthPercentage = 0.1;
                        }

                        if (svgName.contains("arrow_r.svg",Qt::CaseInsensitive)) {
                            heightPercantage = 0;
                            widthPercentage = 0.9;
                        }

                        if (svgName.contains("arrow_u.svg",Qt::CaseInsensitive)) {
                            widthPercentage = 0.5;
                            heightPercantage = 0.30;
                        }

                        if (svgName.contains("arrow_d.svg",Qt::CaseInsensitive)) {
                            widthPercentage = 0.5;
                            float ypos_dashBoard = dashBoard->pos().y() + dashBoard->height();
                            ypos_dashBoard = ypos_dashBoard / Director::sharedDirector()->winSizeInPixels().height();
                            heightPercantage = ypos_dashBoard - 0.5;
                        }

                        newElement.elementSprite->setPos(Director::sharedDirector()->winSizeInPixels().width() * widthPercentage,(Director::sharedDirector()->winSizeInPixels().height()/2) + (Director::sharedDirector()->winSizeInPixels().height() * heightPercantage));
                    }

                    if (newElement.type == "Gate" || newElement.type == "Shop" || newElement.type == "House") {
                        newElement.elementSprite->setZ(background->z() + 5);
                    }

//                    if (newElement.elementSprite != 0) {
//                        qDebug() << "Element " << newElement.name << " z is " << newElement.elementSprite->z();
//                    }

                }
//                newElement.elementSprite->setAnchor(0.5,1);
                everySinglemapElementsList.append(newElement);
                if (newElement.type != "Dummy") {
                    if (enemies.isEmpty()) {
                        allmapElementsList.append(newElement);
                    } else {
                        if (newElement.type != "Gate") {
                            removeChild(newElement.elementSprite);
                            newElement.elementSprite = 0;
                        } else {
                            allmapElementsList.append(newElement);
                        }
                    }
                }
                if (newElement.toXML.contains(".xml",Qt::CaseInsensitive)) {
                    newElement.elementSprite->setZ(0);
                    mapElementsList.append(newElement);
                }
            }
            mapElementsNode = mapElementsNode.nextSibling();
        }

        openxml.close();

        addCharacterFromXML(shared_storage::sharedGameStorage()->getFirstPlayer());

        if (containsRandomBattle) {
            addCharacterFromXML(shared_storage::sharedGameStorage()->getSecondPlayer());

            //loading the armors
            float scale_pointer = 10;
            WeaponLeft = Sprite::spriteWithSvg("battle_mode_sword.svg",screenScale*scale_pointer);
            WeaponRight = Sprite::spriteWithSvg("battle_mode_sword.svg",screenScale*scale_pointer);

            armorGlow = Sprite::spriteWithSvg("pointer_white.svg",screenScale*scale_pointer);
            armorLeft = Sprite::spriteWithSvg("battle_armor.svg",screenScale*scale_pointer);
            armorRight = Sprite::spriteWithSvg("battle_armor.svg",screenScale*scale_pointer);

            armorLeft->setPos(-Director::sharedDirector()->winSizeInPixels().width()*0.75,0);
            armorRight->setPos(armorLeft->pos().x()*-1,armorLeft->pos().y());

            WeaponLeft->setPos(-Director::sharedDirector()->winSizeInPixels().width()*0.75,0);
            WeaponRight->setPos(armorLeft->pos().x()*-1,armorLeft->pos().y());

            armorLeft->setScale(0.5);
            armorRight->setScale(0.5);
            WeaponLeft->setScale(0.5);
            WeaponRight->setScale(0.5);

            WeaponLeft->setRotation(-45);
            WeaponRight->setRotation(45);

            armorGlow->setScale(1);

            armorLayer = Layer::node();
            armorLayer->setZ(20000000-10);

            armorRight->setZ(1);
            WeaponLeft->setZ(-2);
            WeaponRight->setZ(-2);

            armorLayer->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);
            armorLayer->addChild(armorLeft);
            armorLayer->addChild(armorRight);
            armorLayer->addChild(WeaponLeft);
            armorLayer->addChild(WeaponRight);
            armorGlow->setOpacity(0);
            armorLayer->addChild(armorGlow);
            addChild(armorLayer);
        } else {
            players.first()->armor->setZ(20000000 / 2);
            players.first()->armor->setIgnoreZ();
        }
        if (!enemies.isEmpty()) {
            connect(enemies.first(),SIGNAL(character_close_to_attack()),this,SLOT(start_battle_effect()),Qt::UniqueConnection);
            enemies.first()->aim_to_char(players.first());
            enemies.first()->check_type_by_distance = true;
        }

    }

    line->setOpacity(opacity_night_level/2.0);

}

Scene *map::scene(QString xmlFile) {
    Scene* newscene = Scene::node();
    map* newmap = new map();
    newscene->addChild(newmap);
    newmap->load_from_xml(xmlFile);
    return newscene;
}

void map::send_bonus(int gold, int xp) {
    shared_storage::sharedGameStorage()->increaseGoldBy(gold);
    if (!players.first()->isDead()) {
        players.first()->increaseHealthBy(xp/healToXPRatio);
    }
    if (players.size() > 1) {
        if (!players.at(1)->isDead()) {
            players.at(1)->increaseHealthBy(xp/healToXPRatio);
        }
    }
}

character_base* map::addCharacterFromXML(QString xml_file_name) {

//    character_base::screenScale = screenScale * 0.8;
    moving_character* xml_character = new moving_character;
    addChild(xml_character);
    players.append(xml_character);
    xml_character->computer_player = false;
    if (players.size() < 2) {
        xml_character->pointer_file_name = "pointer.svg";
    } else {
        xml_character->pointer_file_name = "pointer_2.svg";
    }
    xml_character->load_from_xml(xml_file_name);


    if (players.size() < 2) {

//        QPointF beforeEnterPoint = enterPoint;


        float tempMargin = 150 * screenScale;

//        bool skipX = false;


//        if (enterPoint.y() < tempMargin + players.first()->armor->bottomRight.y()) {
//            skipX = true;
//            beforeEnterPoint.setY(enterPoint.y() - (300*screenScale));
//        } else if (enterPoint.y() > (players.first()->armor->topLeft.y() - tempMargin)) {
//            skipX = true;
//            beforeEnterPoint.setY(enterPoint.y() + (300*screenScale));
//        } else {
//            beforeEnterPoint.setY(enterPoint.y());
//        }

//        beforeEnterPoint.setX(enterPoint.x());


//        if (!skipX) {

//            if ( enterPoint.x() > (players.first()->armor->bottomRight.x() - tempMargin) ) {
//                beforeEnterPoint.setX(enterPoint.x() + (300*screenScale));
//            } else if (enterPoint.x() < (players.first()->armor->topLeft.x() + tempMargin)) {
//                beforeEnterPoint.setX(enterPoint.x() - (300*screenScale));
//            }

//        }

        float xScaleMargine = 1;

        if (enterPoint.x() < tempMargin + players.first()->armor->bottomRight.y()) {
            xScaleMargine = 1;
        } else {
            xScaleMargine = -1;
        }


        xml_character->setPos(enterPoint - QPointF(50*xScaleMargine,50));
        xml_character->moveto(enterPoint.x(),enterPoint.y());

        //no need for characters movements
//        xml_character->setPos(enterPoint);


    } else {
        xml_character->setPos(-300*screenScale,Director::sharedDirector()->winSizeInPixels().height()/2);
    }
    xml_character->computer_player = false;

    return xml_character;
}

void map::touchBegin(QGraphicsSceneMouseEvent *event) {

    arrowAttached = false;
    clickTimer.restart();
    startTouchPos = Director::sharedDirector()->convertTouchPoint(event->scenePos());
    startCharacterSelectedIndex = -1;
    int i = 0;
    if (startTouchPos.x() > (players.at(i)->pos().x() - (halfCharacterWidth * character_base::screenScale)) && startTouchPos.x() < (players.at(i)->pos().x() + (halfCharacterWidth * screenScale)) ) {
        if (startTouchPos.y() > (players.at(i)->pos().y() - (halfCharacterhight * screenScale)) && startTouchPos.y() < (players.at(i)->pos().y() + (halfCharacterhight * screenScale)) ) {
            startCharacterSelectedIndex = 0;
            return;
        }
    }
}


void map::touchMove(QGraphicsSceneMouseEvent *event) {


    touchPos = Director::sharedDirector()->convertTouchPoint(event->scenePos());

//    qDebug() << "touch moved " << touchPos;

    if (startCharacterSelectedIndex >= 0 && startCharacterSelectedIndex < players.size()) {
        //he's trying to move a character
        if (!arrowAttached) {
            arrowAttached = true;
            players.at(startCharacterSelectedIndex)->armor->showArrow();
//            players.at(startCharacterSelectedIndex)->armor->attachToChar(players.at(startCharacterSelectedIndex));
        }

        //first let's check if our last touch position is on a house
        for (int i = 0; i < allmapElementsList.size(); i++) {
            if (touchPos.x() > (allmapElementsList.at(i).elementSprite->pos().x() - ((allmapElementsList.at(i).elementSprite->width()/2))) && touchPos.x() < (allmapElementsList.at(i).elementSprite->pos().x() + ((allmapElementsList.at(i).elementSprite->width()/2))) ) {
                if (allmapElementsList.at(i).type != "Dummy3D") {
                    if (touchPos.y() > (allmapElementsList.at(i).elementSprite->pos().y() - ((allmapElementsList.at(i).elementSprite->height()/2))) && touchPos.y() < (allmapElementsList.at(i).elementSprite->pos().y() + ((allmapElementsList.at(i).elementSprite->height()/2)) ) ) {
                        touchPos = allmapElementsList.at(i).elementSprite->pos();
                    }
                }
            }
        }


//        players.at(startCharacterSelectedIndex)->armor->removePointedChar();
        players.at(startCharacterSelectedIndex)->armor->setEnd(touchPos.x(),touchPos.y());
    }
}

void map::touchEnd(QGraphicsSceneMouseEvent *event) {

    bool movedetected = false;
    if (clickTimer.elapsed() > 70) {
        movedetected = true;
    }
    if (arrowAttached) {
        touchPos = players.at(startCharacterSelectedIndex)->armor->armor_c_pos();
        players.at(startCharacterSelectedIndex)->armor->hideArrow(false);
        if (movedetected) {
            collidesWith();
        }
    }
    arrowAttached = false;
    startCharacterSelectedIndex = -1;

//    if (clickTimer.elapsed() < 90) {
//        //this is a click, let's see if I clicked on one of human controlled characters
//        for (int i = 0; i < players.size(); i++) {
//            if (touchPos.x() > (players.at(i)->pos().x() - (halfCharacterWidth * character_base::screenScale)) && touchPos.x() < (players.at(i)->pos().x() + (halfCharacterWidth * character_base::screenScale)) ) {
//                if (touchPos.y() > (players.at(i)->pos().y() - (halfCharacterhight * character_base::screenScale)) && touchPos.y() < (players.at(i)->pos().y() + (halfCharacterhight * character_base::screenScale)) ) {
//                    elips->attachToChar(players.at(i));
//                    return;
//                }
//            }
//        }
//        return;
//    }
}

void map::onEnterTransitionDidFinish() {
//    setOpacity(100);
//    line->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.25,opacity_night_level)),NULL));
    sun_moon->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.05,100),action::easCurve(action::rotateTo(4,clockRotation),QEasingCurve::OutElastic),NULL));
    closing_door->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.05,closing_door->opacity()),action::easeinout(action::moveTo(0.5,closing_door->pos().x(),(110*screenScale) + (768*screenScale))),NULL));
    closing_door_lost->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.05,closing_door_lost->opacity()),action::easeinout(action::moveTo(0.5,closing_door_lost->pos().x(),(110*screenScale) + (768*screenScale))),NULL));
}

void map::character_collided_map_element() {
    disconnect(players.first(),SIGNAL(moveDone()),this,SLOT(character_collided_map_element()));
    if  (!characterMovementPoints.isEmpty()) {
        QPointF nextPoint = characterMovementPoints.takeFirst();
        players.first()->moveto(nextPoint.x(),nextPoint.y());
        connect(players.first(),SIGNAL(moveDone()),this,SLOT(character_collided_map_element()),Qt::UniqueConnection);
    } else {
        if (selectedElementID != -1) {
            if (allmapElementsList.at(selectedElementID).type == "Gate" || allmapElementsList.at(selectedElementID).type == "Shop" || allmapElementsList.at(selectedElementID).type == "House") {
//                players.first()->players.at(startCharacterSelectedIndex)->armor-(players.first()->pos().x(),players.first()->pos().y() + (20 * screenScale));
                closing_door->setOpacity(100);
                closing_door->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveTo(0.5,closing_door->pos().x(),110*screenScale)),action::FuncCall(this,SLOT(do_element_action())),NULL));
//                line->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.25,100)),action::FuncCall(this,SLOT(do_element_action())),NULL));
            }
        }
    }
}

void map::do_element_action() {
    setTouchEnabled(false);
    if (allmapElementsList.at(selectedElementID).type == "Gate") {

        if (ghost_character != NULL) {
            ghost_character->aimToAtttackChar = 0;
            ghost_character->startBreathing();
        }

        QString svgName;

//        QPointF newEnterPoint = enterPoint;
        if (players.first()->pos().x() < 200*screenScale) {
            svgName = "arrow_r.svg";
        } else if (players.first()->pos().x() > (Director::sharedDirector()->winSizeInPixels().width() - (200*screenScale) ) ) {
            svgName = "arrow_l.svg";
        } else if (players.first()->pos().y() > (Director::sharedDirector()->winSizeInPixels().height() - (200*screenScale) ) ) {
            svgName = "arrow_d.svg";
        } else {
            svgName = "arrow_u.svg";
        }

        float widthPercentage = 0;
        float heightPercantage = 0;

        if (svgName.contains("arrow_l.svg",Qt::CaseInsensitive)) {
            heightPercantage = 0;
            widthPercentage = 0.1;
        }

        if (svgName.contains("arrow_r.svg",Qt::CaseInsensitive)) {
            heightPercantage = 0;
            widthPercentage = 0.9;
        }

        if (svgName.contains("arrow_u.svg",Qt::CaseInsensitive)) {
            widthPercentage = 0.5;
            heightPercantage = 0.30;
        }

        if (svgName.contains("arrow_d.svg",Qt::CaseInsensitive)) {
            widthPercentage = 0.5;
            float ypos_dashBoard = dashBoard->pos().y() + dashBoard->height();
            ypos_dashBoard = ypos_dashBoard / Director::sharedDirector()->winSizeInPixels().height();
            heightPercantage = ypos_dashBoard - 0.5;
        }

        enterPoint.setX(Director::sharedDirector()->winSizeInPixels().width() * widthPercentage);
        enterPoint.setY((Director::sharedDirector()->winSizeInPixels().height()/2) + (Director::sharedDirector()->winSizeInPixels().height() * heightPercantage));

        setOpacity(0);

        Director::sharedDirector()->replaceScene(map::scene(allmapElementsList.at(selectedElementID).toXML));
    } else if (allmapElementsList.at(selectedElementID).type == "Shop") {
        setTouchEnabled(false);

        QString shop_xml = allmapElementsList.at(selectedElementID).toXML;

        current_shop_pointer = new shop();
        addChild(current_shop_pointer);
        current_shop_pointer->load_from_xml(shop_xml);
        current_shop_pointer->setZ(line->z() + 100);
//        line->setZ(line->z()+200);

        line->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.25,0)),NULL));
    } else if (allmapElementsList.at(selectedElementID).type == "House") {
        setTouchEnabled(false);


        current_home_pointer = new home();
        addChild(current_home_pointer);
        current_home_pointer->load();
        current_home_pointer->setZ(line->z() + 100);
//        line->setZ(line->z()+200);


        line->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.25,0)),NULL));
    }
}

void map::start_battle_effect() {
    lock_map();
    disconnect(enemies.first(),SIGNAL(character_close_to_attack()),this,SLOT(start_battle_effect()));
    enemies.first()->startBreathing();
    players.first()->startBreathing();


    armorLeft->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveTo(0.5,0,armorLeft->pos().y())),action::scaleTo(0.1,0.50),action::FuncCall(this,SLOT(start_battle_effect_2())),NULL));
    armorRight->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveTo(0.5,0,armorLeft->pos().y())),NULL));
    WeaponLeft->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveTo(0.5,0,armorLeft->pos().y())),NULL));
    WeaponRight->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveTo(0.5,0,armorLeft->pos().y())),NULL));
    WeaponLeft->runAction(action::easeinout(action::rotateTo(0.5,45)));
    WeaponRight->runAction(action::easeinout(action::rotateTo(0.5,-45)));

}

void map::start_battle_effect_2() {
    armorLeft->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.5,0)),NULL));
    armorRight->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.5,0)),NULL));
    WeaponLeft->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.5,0)),NULL));
    WeaponRight->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.5,0)),NULL));
    armorGlow->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.4,100)),action::easeinout(action::fadeTo(2.5,0)),action::FuncCall(this,SLOT(start_battle_effect_3())),NULL));
    armorLeft->runAction(action::easeinout(action::scaleTo(0.5,1*10)));
    armorRight->runAction(action::easeinout(action::scaleTo(0.5,0.75*10)));

    WeaponLeft->runAction(action::easeinout(action::scaleTo(0.5,1.25*10)));
    WeaponRight->runAction(action::easeinout(action::scaleTo(0.5,1.5*10)));

    armorGlow->runAction(action::easeinout(action::scaleTo(1.5,3*10)));

    QTimer::singleShot(1000*0.8,this,SLOT(move_players_to_battle_pos()));


}

void map::start_battle_effect_3() {

    //actually start the fight

    humanLayer->setTouchEnabled(true);

    for (int i = 0; i < players.size(); i++) {
        game_controller::sharedGameController()->addPlayerCharacter(players.at(i));
    }
    if (!enemies.isEmpty()) {
        character_base* xml_character = enemies.takeFirst();
        game_controller::sharedGameController()->addEnemyCharacter(xml_character);
        xml_character->enterStage();

    }
    if (!enemies.isEmpty()) {
        character_base* xml_character = enemies.takeFirst();
        game_controller::sharedGameController()->addEnemyCharacter(xml_character);
//        xml_character->setOpacity(0);
        xml_character->setPos(Director::sharedDirector()->winSizeInPixels().width()*2,Director::sharedDirector()->winSizeInPixels().height()/2);
        xml_character->enterStage();
    }

    load_battle_mode_layers();

    enable_battle_mood_buttons();

}

void map::fillTempWithElements(float x, bool left, float y, bool down) {

    disconnect(players.first(),SIGNAL(moveDone()),this,SLOT(character_collided_map_element()));

    mapElementsSprtiesTemp2.clear();
    mapElementsSprtiesTemp.clear();
    bool accepted;
    for (int i = 0; i < allmapElementsList.size(); i++) {
        accepted = false;
        if (allmapElementsList.at(i).type == "Dummy3D") {
            if (left) {
                if (down) {
                    QPointF point = allmapElementsList.at(i).elementSprite->bottomleftPoint();
                    if (point.x() - x < 0) {
                        if (point.y() - y < 0) {
                            accepted = true;
                        }
                    }
                } else {
                    QPointF point = getleftPoint(allmapElementsList.at(i).elementSprite);
                    if (point.x() - x < 0) {
                        if (point.y() - y > 0) {
                            accepted = true;
                        }
                    }
                }
            } else {
                if (down) {
                    QPointF point = allmapElementsList.at(i).elementSprite->bottomrightPoint();
                    if (point.x() - x > 0) {
                        if (point.y() - y < 0) {
                            accepted = true;
                        }
                    }
                } else {
                    QPointF point =  getRightPoint(allmapElementsList.at(i).elementSprite);
                    if (point.x() - x > 0) {
                        if (point.y() - y > 0) {
                            accepted = true;
                        }
                    }
                }
            }
        }

        if (accepted) {
            mapElementsSprtiesTemp2.append(allmapElementsList.at(i).elementSprite);
        }
    }

    //sort the list from smallest to largest

    while (!mapElementsSprtiesTemp2.isEmpty()) {
        int shortestElementID = 0;
        float shortestDistance = Director::sharedDirector()->winSizeInPixels().width()*10;
        float tempLenth;
        for (int i = 0; i < mapElementsSprtiesTemp2.size(); i++) {
            if (left) {
                if (down) {
                    tempLenth = QLineF(players.first()->pos(),mapElementsSprtiesTemp2.at(i)->bottomleftPoint()).length();
                } else {
                    tempLenth = QLineF(players.first()->pos(),getleftPoint(mapElementsSprtiesTemp2.at(i))).length();
                }
            } else {
                if (down) {
                    tempLenth = QLineF(players.first()->pos(),mapElementsSprtiesTemp2.at(i)->bottomrightPoint()).length();
                } else {
                    tempLenth = QLineF(players.first()->pos(),getRightPoint(mapElementsSprtiesTemp2.at(i))).length();
                }
            }

            if (tempLenth < shortestDistance) {
                shortestElementID = i;
                shortestDistance = tempLenth;
            }
        }

        mapElementsSprtiesTemp.append(mapElementsSprtiesTemp2.takeAt(shortestElementID));
    }

    QLineF firstLine;
    QLineF secondLine;
    QLineF characterWayLineF;

    characterWayLineF.setPoints(players.first()->pos(),touchPos);
    characterMovementPoints.clear();

    bool skipAdding;
    //check all the collided elements
    if (left) {
        if (down) {
            //down and left
            for (int i = mapElementsSprtiesTemp.size() - 1; i >= 0; i--) {
                firstLine.setPoints(getRightPoint(mapElementsSprtiesTemp.at(i)),mapElementsSprtiesTemp.at(i)->bottomrightPoint());
                secondLine.setPoints(getRightPoint(mapElementsSprtiesTemp.at(i)),getleftPoint(mapElementsSprtiesTemp.at(i)));
                //check if am going to intersect with first line
                if (characterWayLineF.intersect(firstLine,NULL) == QLineF::BoundedIntersection) {
                    //lines here intersects
                    skipAdding = false;
                    if (characterWayLineF.p2().y() > firstLine.p2().y()) {
                        characterMovementPoints.prepend(mapElementsSprtiesTemp.at(i)->bottomleftPoint() + ( QPointF( - x_offset_collision*character_base::screenScale, - y_offset_collision*character_base::screenScale)));
                        skipAdding = true;
                        characterWayLineF.setP2(characterMovementPoints.first());
                    }
                    characterMovementPoints.prepend(mapElementsSprtiesTemp.at(i)->bottomrightPoint() + ( QPointF( + x_offset_collision*character_base::screenScale, - y_offset_collision*character_base::screenScale)));
                    if (!skipAdding) {
                        characterWayLineF.setP2(characterMovementPoints.first());
                    }

                } else {
                    if (characterWayLineF.intersect(secondLine,NULL) == QLineF::BoundedIntersection) {
                        //lines here intersects
                        skipAdding = false;

                        if (characterWayLineF.p2().x() > secondLine.p2().x()) {
                            characterMovementPoints.prepend(mapElementsSprtiesTemp.at(i)->bottomleftPoint() + ( QPointF( - x_offset_collision*character_base::screenScale, - y_offset_collision*character_base::screenScale)));
                            skipAdding = true;
                            characterWayLineF.setP2(characterMovementPoints.first());
                        }

                        characterMovementPoints.prepend(getleftPoint(mapElementsSprtiesTemp.at(i)) + ( QPointF( - x_offset_collision*character_base::screenScale, + y_offset_collision*character_base::screenScale)));
                        if (!skipAdding) {
                            characterWayLineF.setP2(characterMovementPoints.first());
                        }
                    }
                }
            }
        } else {
            //up and left
            for (int i = mapElementsSprtiesTemp.size() - 1; i >= 0; i--) {
                firstLine.setPoints(mapElementsSprtiesTemp.at(i)->bottomrightPoint(),getRightPoint(mapElementsSprtiesTemp.at(i)));
                secondLine.setPoints(mapElementsSprtiesTemp.at(i)->bottomrightPoint(),mapElementsSprtiesTemp.at(i)->bottomleftPoint());
                //check if am going to intersect with first line
                if (characterWayLineF.intersect(firstLine,NULL) == QLineF::BoundedIntersection) {
                    //lines here intersects
                    skipAdding = false;
                    if (characterWayLineF.p2().y() < firstLine.p2().y()) {
                        characterMovementPoints.prepend(getleftPoint(mapElementsSprtiesTemp.at(i)) + ( QPointF( - x_offset_collision*character_base::screenScale, + y_offset_collision*character_base::screenScale)));
                        skipAdding = true;
                        characterWayLineF.setP2(characterMovementPoints.first());
                    }
                    characterMovementPoints.prepend(getRightPoint(mapElementsSprtiesTemp.at(i)) + ( QPointF( + x_offset_collision*character_base::screenScale, + y_offset_collision*character_base::screenScale)));
                    if (!skipAdding) {
                        characterWayLineF.setP2(characterMovementPoints.first());
                    }

                } else {
                    if (characterWayLineF.intersect(secondLine,NULL) == QLineF::BoundedIntersection) {
                        //lines here intersects
                        skipAdding = false;

                        if (characterWayLineF.p2().x() > secondLine.p2().x()) {
                            characterMovementPoints.prepend(getleftPoint(mapElementsSprtiesTemp.at(i)) + ( QPointF( - x_offset_collision*character_base::screenScale, + y_offset_collision*character_base::screenScale)));
                            skipAdding = true;
                            characterWayLineF.setP2(characterMovementPoints.first());
                        }

                        characterMovementPoints.prepend(mapElementsSprtiesTemp.at(i)->bottomleftPoint() + ( QPointF( - x_offset_collision*character_base::screenScale, - y_offset_collision*character_base::screenScale)));

                        if (!skipAdding) {
                            characterWayLineF.setP2(characterMovementPoints.first());
                        }
                    }
                }
            }
        }


    } else {
        if (down) {
            //down and right
            for (int i = mapElementsSprtiesTemp.size() - 1; i >= 0; i--) {
                firstLine.setPoints(getleftPoint(mapElementsSprtiesTemp.at(i)),mapElementsSprtiesTemp.at(i)->bottomleftPoint());
                secondLine.setPoints(getleftPoint(mapElementsSprtiesTemp.at(i)),getRightPoint(mapElementsSprtiesTemp.at(i)));
                //check if am going to intersect with first line
                if (characterWayLineF.intersect(firstLine,NULL) == QLineF::BoundedIntersection) {
                    //lines here intersects
                    skipAdding = false;
                    if (characterWayLineF.p2().y() > firstLine.p2().y()) {
                        characterMovementPoints.prepend(mapElementsSprtiesTemp.at(i)->bottomrightPoint() + ( QPointF( + x_offset_collision*character_base::screenScale, - y_offset_collision*character_base::screenScale)));
                        skipAdding = true;
                        characterWayLineF.setP2(characterMovementPoints.first());
                    }
                    characterMovementPoints.prepend(mapElementsSprtiesTemp.at(i)->bottomleftPoint() + ( QPointF( - x_offset_collision*character_base::screenScale, - y_offset_collision*character_base::screenScale)));
                    if (!skipAdding) {
                        characterWayLineF.setP2(characterMovementPoints.first());
                    }

                } else {
                    if (characterWayLineF.intersect(secondLine,NULL) == QLineF::BoundedIntersection) {
                        //lines here intersects
                        skipAdding = false;

                        if (characterWayLineF.p2().x() < secondLine.p2().x()) {
                            characterMovementPoints.prepend(mapElementsSprtiesTemp.at(i)->bottomrightPoint() + ( QPointF( + x_offset_collision*character_base::screenScale, - y_offset_collision*character_base::screenScale)));
                            skipAdding = true;
                            characterWayLineF.setP2(characterMovementPoints.first());
                        }

                        characterMovementPoints.prepend(getRightPoint(mapElementsSprtiesTemp.at(i)) + ( QPointF( + x_offset_collision*character_base::screenScale, + y_offset_collision*character_base::screenScale)));
                        if (!skipAdding) {
                            characterWayLineF.setP2(characterMovementPoints.first());
                        }
                    }
                }
            }
        } else {
            //up and right
            for (int i = mapElementsSprtiesTemp.size() - 1; i >= 0; i--) {
                firstLine.setPoints(mapElementsSprtiesTemp.at(i)->bottomleftPoint(),getleftPoint(mapElementsSprtiesTemp.at(i)));
                secondLine.setPoints(mapElementsSprtiesTemp.at(i)->bottomleftPoint(),mapElementsSprtiesTemp.at(i)->bottomrightPoint());
                //check if am going to intersect with first line
                if (characterWayLineF.intersect(firstLine,NULL) == QLineF::BoundedIntersection) {
                    //lines here intersects
                    skipAdding = false;
                    if (characterWayLineF.p2().y() < firstLine.p2().y()) {
                        characterMovementPoints.prepend(getRightPoint(mapElementsSprtiesTemp.at(i)) + ( QPointF( + x_offset_collision*character_base::screenScale, + y_offset_collision*character_base::screenScale)));
                        skipAdding = true;
                        characterWayLineF.setP2(characterMovementPoints.first());
                    }
                    characterMovementPoints.prepend(getleftPoint(mapElementsSprtiesTemp.at(i)) + ( QPointF( - x_offset_collision*character_base::screenScale, + y_offset_collision*character_base::screenScale)));
                    if (!skipAdding) {
                        characterWayLineF.setP2(characterMovementPoints.first());
                    }

                } else {
                    if (characterWayLineF.intersect(secondLine,NULL) == QLineF::BoundedIntersection) {
                        //lines here intersects
                        skipAdding = false;

                        if (characterWayLineF.p2().x() < secondLine.p2().x()) {
                            characterMovementPoints.prepend(getRightPoint(mapElementsSprtiesTemp.at(i)) + ( QPointF( + x_offset_collision*character_base::screenScale, + y_offset_collision*character_base::screenScale)));
                            skipAdding = true;
                            characterWayLineF.setP2(characterMovementPoints.first());
                        }

                        characterMovementPoints.prepend(mapElementsSprtiesTemp.at(i)->bottomrightPoint() + ( QPointF( + x_offset_collision*character_base::screenScale, - y_offset_collision*character_base::screenScale)));

                        if (!skipAdding) {
                            characterWayLineF.setP2(characterMovementPoints.first());
                        }
                    }
                }
            }
        }
    }

    characterMovementPoints.append(touchPos);

//    for (int i = 0; i < characterMovementPoints.size(); i++) {
//        qDebug() << " Character movement step " << i << " is " << characterMovementPoints.at(i);
//    }

    QPointF nextPoint = characterMovementPoints.takeFirst();
    players.first()->moveto(nextPoint.x(),nextPoint.y());
    connect(players.first(),SIGNAL(moveDone()),this,SLOT(character_collided_map_element()),Qt::UniqueConnection);

//    for (int i = 0; i < mapElementsSprtiesTemp.size(); i++) {
//        mapElementsSprtiesTemp.at(i)->runSequence(Sequence::sequenceWithActions(action::fadeTo(i+1,0),action::fadeTo(i+1,100),NULL));
//    }

//    for (int i = 0; i < mapElementsSprtiesTemp.size(); i++) {
//        qDebug() << mapElementsSprtiesTemp.at(i)->pos() << " right position is " << getRightPoint(mapElementsSprtiesTemp.at(i)) << " left position is " << getleftPoint(mapElementsSprtiesTemp.at(i));
//    }

}

QPointF map::getRightPoint(Node* anyMapElement) {
    return (anyMapElement->toprightPoint() - (QPointF(0,anyMapElement->height()*0.48)));
}

QPointF map::getleftPoint(Node* anyMapElement) {
    return (anyMapElement->topleftPoint() - (QPointF(0,anyMapElement->height()*0.48)));
}

void map::refreshDashBoard() {

    if (red_poition_count != NULL) {
        removeChild(red_poition_count);
    }

    //red poition count
    red_poition_count = numbers::layer();


    red_poition_count->pre = "number_";
    addChild(red_poition_count);

    red_poition_count->setPos((225.51*screenScale),(60.8*screenScale));
    red_poition_count->setZ(20000003);

    red_poition_count->setNum(shared_storage::sharedGameStorage()->getCurrentRedPoition(),screenScale*0.3);

    if (red_jewel_count != NULL) {
        removeChild(red_jewel_count);
    }

    //red poition count
    red_jewel_count = numbers::layer();


    red_jewel_count->pre = "number_";
    addChild(red_jewel_count);

    red_jewel_count->setPos((359.87*screenScale),(60.8*screenScale));
    red_jewel_count->setZ(20000003);

    red_jewel_count->setNum(shared_storage::sharedGameStorage()->getCurrentRedJewel(),screenScale*0.3);


    //gold count

    if (gold_count != NULL) {
        removeChild(gold_count);
    }

    gold_count = numbers::layer();


    gold_count->pre = "number_";
    addChild(gold_count);

    gold_count->setPos((513.72*screenScale),(54.46*screenScale));
    gold_count->setZ(20000003);

    gold_count->setNum(shared_storage::sharedGameStorage()->getCurrentGold(),screenScale*0.5);



    if (silver_count != NULL) {
        removeChild(silver_count);
    }

    silver_count = numbers::layer();


    silver_count->pre = "number_";
    addChild(silver_count);

    silver_count->setPos((660.9*screenScale),(50.43*screenScale));
    silver_count->setZ(20000003);

    silver_count->setNum(shared_storage::sharedGameStorage()->getCurrentSilver(),screenScale*0.4);

    refreshQuestPop();

}

void map::refreshQuestPop() {

    quest_pop_layer->removeChild(keys_layer);
    keys_layer = Layer::node();
    quest_pop_layer->addChild(keys_layer);
    keys_layer->setPos(0,(quest_pop_sprite->height()/2) + (107.5*screenScale));

    QStringList keys = shared_storage::sharedGameStorage()->getKeysCopy();

    int y[5] = {-171,-88,-7,80,161};

    for (int i = 0; i < keys.size(); i++) {
        Sprite* NewKey = Sprite::spriteWithSvg(keys.at(i),screenScale);
        keys_layer->addChild(NewKey);
        NewKey->setPos(QPointF(0,y[i]*screenScale));
        NewKey->setZ(1);
    }
}

void map::openMapDoor() {
        closing_door->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.05,closing_door->opacity()),action::easeinout(action::moveTo(0.5,closing_door->pos().x(),(110*screenScale) + (768*screenScale))),NULL));
        closing_door_lost->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.05,closing_door_lost->opacity()),action::easeinout(action::moveTo(0.5,closing_door_lost->pos().x(),(110*screenScale) + (768*screenScale))),NULL));
}

void map::startLostGameOver() {
    if (!gameOver) {
        gameOver = true;
        coming_from_game_over = true;
        closing_door_lost->setOpacity(100);
        closing_door_lost->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveTo(0.5,closing_door_lost->pos().x(),110*screenScale)),action::FuncCall(this,SLOT(start_shaking_screen())),action::fadeTo(3,100),action::FuncCall(this,SLOT(returnToLastCheckPoint())),NULL));

    }
}

void map::returnToLastCheckPoint() {
    setOpacity(0);
    Director::sharedDirector()->replaceScene(map::scene(shared_storage::sharedGameStorage()->getCheckPoint()));

}


bool map::collidesWith() {
    selectedElementID = -1;
    //first let's check if our last touch position is on a house
    for (int i = 0; i < allmapElementsList.size(); i++) {
        if (touchPos.x() > (allmapElementsList.at(i).elementSprite->pos().x() - ((allmapElementsList.at(i).elementSprite->width()/2))) && touchPos.x() < (allmapElementsList.at(i).elementSprite->pos().x() + ((allmapElementsList.at(i).elementSprite->width()/2))) ) {
            if (allmapElementsList.at(i).type != "Dummy3D") {
                if (touchPos.y() > (allmapElementsList.at(i).elementSprite->pos().y() - ((allmapElementsList.at(i).elementSprite->height()/2))) && touchPos.y() < (allmapElementsList.at(i).elementSprite->pos().y() + ((allmapElementsList.at(i).elementSprite->height()/2)) ) ) {
                    selectedElementID = i;
//                    touchPos = allmapElementsList.at(selectedElementID).elementSprite->bottomleftPoint() + (QPointF(allmapElementsList.at(selectedElementID).elementSprite->width()/2,-5 * screenScale));
                    touchPos = allmapElementsList.at(selectedElementID).elementSprite->pos();
                }
            } else {
                if (touchPos.y() > (allmapElementsList.at(i).elementSprite->pos().y() - ((allmapElementsList.at(i).elementSprite->height()/2))) && touchPos.y() < (allmapElementsList.at(i).elementSprite->pos().y() ) ) {
                    selectedElementID = i;
                    touchPos = allmapElementsList.at(selectedElementID).elementSprite->bottomleftPoint() + (QPointF(allmapElementsList.at(selectedElementID).elementSprite->width()/2,-5 * screenScale));
//                    touchPos = allmapElementsList.at(selectedElementID).elementSprite->pos();
                }
            }
        }
    }

    //character line
    QLineF characterLine;
    characterLine.setP1(players.first()->pos());
    characterLine.setP2(touchPos);
    bool goingleft;
    if (characterLine.dx() > 0) {
        goingleft = false;
    } else {
        goingleft = true;
    }
    bool goingdown;
    if (characterLine.dy() > 0) {
        goingdown = false;
    } else {
        goingdown = true;
    }

    fillTempWithElements(players.first()->pos().x(),goingleft,players.first()->pos().y(),goingdown);

}

void map::lock_map() {
    setTouchEnabled(false);
    for (int i = 0; i < allmapElementsList.size(); i++) {
        if (allmapElementsList.at(i).type == "Gate") {
            //hide this element
            allmapElementsList.at(i).elementSprite->runAction(action::easCurve(action::scaleTo(0.5,0),QEasingCurve::InBack));
            allmapElementsList.at(i).elementSprite->runAction(action::easCurve(action::fadeTo(0.5,0),QEasingCurve::InBack));
        }
    }
    total_match_time.start();
}

void map::unclock_map() {
    //character has won the game
    humanLayer->setTouchEnabled(false);
    top_battle_mode_layer->runAction(action::easeinout(action::moveTo(1,top_battle_mode_layer->pos().x(),top_battle_mode_layer->pos().y() + (350 * screenScale))));
    win_message* battle_win_message = new win_message(total_silver_gained,total_xp_gained,total_match_time.elapsed()/1000,last_character_level);
    battle_win_message->setZ(20000000);
    addChild(battle_win_message);
    float margin_x = 380 * screenScale;
    float margin_y = 80 * character_base::screenScale;
    players.first()->setPos((Director::sharedDirector()->winSizeInPixels().width()/2) - margin_x,(Director::sharedDirector()->winSizeInPixels().height()/2) - margin_y);
    players.first()->setScaleX(1);
    if (players.size() > 1) {
        players.at(1)->setPos((Director::sharedDirector()->winSizeInPixels().width()/2) + margin_x,(Director::sharedDirector()->winSizeInPixels().height()/2) - margin_y);
        players.at(1)->setScaleX(-1);
    }
}

void map::unclock_map_2() {
    humanLayer->setTouchEnabled(false);
    setTouchEnabled(true);
    for (int i = 0; i < allmapElementsList.size(); i++) {
        if (allmapElementsList.at(i).type == "Gate") {
            //hide this element
            allmapElementsList.at(i).elementSprite->runAction(action::easCurve(action::scaleTo(0.5,1),QEasingCurve::OutBack));
            allmapElementsList.at(i).elementSprite->runAction(action::easCurve(action::fadeTo(0.5,100),QEasingCurve::OutBack));
        }
    }

    character_base* secondCharacter = players.takeLast();
    secondCharacter->moveto(-100*screenScale,Director::sharedDirector()->winSizeInPixels().height()/2);
}

void map::load_battle_mode_layers() {
    top_battle_mode_layer = Layer::node();
//    bottom_battle_mode_layer = Layer::node();

    //adding both to the current layer

    addChild(top_battle_mode_layer);
//    addChild(bottom_battle_mode_layer);

    //setting the z level, to be on top of everything
    top_battle_mode_layer->setZ(20000000);
//    bottom_battle_mode_layer->setZ(200000);

    //positiong the top and bottom layer

    QPointF top_pos_after;
//    QPointF bottom_pos_after;

    QPointF top_pos_before;
//    QPointF bottom_pos_before;

    top_pos_after.setX(Director::sharedDirector()->winSizeInPixels().width()/2);
//    bottom_pos_after.setX(top_pos_after.x());

    float margine = 64;

    top_pos_after.setY(Director::sharedDirector()->winSizeInPixels().height() - (margine * screenScale));
//    bottom_pos_after.setY((margine * screenScale));

    top_pos_before.setX(top_pos_after.x());
//    bottom_pos_before.setX(bottom_pos_after.x());

    top_pos_before.setY(top_pos_after.y() + (margine * screenScale));
//    bottom_pos_before.setY(bottom_pos_after.y() - (margine * screenScale));

    top_battle_mode_layer->setPos(top_pos_before);
//    bottom_battle_mode_layer->setPos(bottom_pos_before);

    //super bottom right value
    float bottom_decrease_in_x = (Director::sharedDirector()->winSizeInPixels().width()/2) - (200*screenScale);
    float one_button_width = players.first()->super_attack_weapon->super_sprite_svg->width() * 1.05;

    players.first()->mainWeapon->super_attack_object->super_sprite_svg->setPos(-bottom_decrease_in_x,0);
    players.first()->super_attack_weapon->super_sprite_svg->setPos(-bottom_decrease_in_x - one_button_width,0);


    players.first()->mainWeapon->super_attack_object->disabled_layer_button->setPos(-bottom_decrease_in_x,0);
    players.first()->super_attack_weapon->disabled_layer_button->setPos(-bottom_decrease_in_x - one_button_width,0);

    players.first()->mainWeapon->super_attack_object->disabled_layer_button->setOpacity(100);
    players.first()->super_attack_weapon->disabled_layer_button->setOpacity(100);

    players.first()->mainWeapon->super_attack_object->super_layer_added = true;
    players.first()->super_attack_weapon->super_layer_added = true;

    top_battle_mode_layer->addChild(players.first()->mainWeapon->super_attack_object->disabled_layer_button);
    top_battle_mode_layer->addChild(players.first()->super_attack_weapon->disabled_layer_button);

    //adding buttons for first character
    first_p_super_buttons = Menu::menuWithmenuItems(players.first()->super_attack_weapon->super_sprite_svg,players.first()->mainWeapon->super_attack_object->super_sprite_svg,NULL);
    top_battle_mode_layer->addChild(first_p_super_buttons);


    //if we have more than one character, add second character weapons
    if (players.size() > 1) {
        second_p_super_buttons = Menu::menuWithmenuItems(players.at(1)->super_attack_weapon->super_sprite_svg,players.at(1)->mainWeapon->super_attack_object->super_sprite_svg,NULL);
//        bottom_battle_mode_layer->addChild(second_p_super_buttons);
        top_battle_mode_layer->addChild(second_p_super_buttons);

        players.at(1)->mainWeapon->super_attack_object->super_sprite_svg->setPos(bottom_decrease_in_x,0);
        players.at(1)->super_attack_weapon->super_sprite_svg->setPos(bottom_decrease_in_x + one_button_width,0);


        players.at(1)->mainWeapon->super_attack_object->disabled_layer_button->setPos(bottom_decrease_in_x,0);
        players.at(1)->super_attack_weapon->disabled_layer_button->setPos(bottom_decrease_in_x + one_button_width,0);

        players.at(1)->mainWeapon->super_attack_object->disabled_layer_button->setOpacity(100);
        players.at(1)->super_attack_weapon->disabled_layer_button->setOpacity(100);


        players.at(1)->mainWeapon->super_attack_object->super_layer_added = true;
        players.at(1)->super_attack_weapon->super_layer_added = true;

        top_battle_mode_layer->addChild(players.at(1)->mainWeapon->super_attack_object->disabled_layer_button);
        top_battle_mode_layer->addChild(players.at(1)->super_attack_weapon->disabled_layer_button);
    }

    top_battle_mode_layer->runAction(action::easCurve(action::moveTo(1,top_pos_after.x(),top_pos_after.y()),QEasingCurve::OutElastic));
    //    bottom_battle_mode_layer->runAction(action::easCurve(action::moveTo(1,bottom_pos_after.x(),bottom_pos_after.y()),QEasingCurve::OutElastic));

}

void map::move_players_to_battle_pos() {
    players.first()->setPos((Director::sharedDirector()->winSizeInPixels().width()/2) - (screenScale*x_offset_player_battle-30),Director::sharedDirector()->winSizeInPixels().height()*0.4);
    enemies.first()->setPos((Director::sharedDirector()->winSizeInPixels().width()/2) + (screenScale*x_offset_player_battle-30),Director::sharedDirector()->winSizeInPixels().height()*0.4);

    players.first()->moveto((Director::sharedDirector()->winSizeInPixels().width()/2) - (screenScale*x_offset_player_battle),Director::sharedDirector()->winSizeInPixels().height()*0.4);
    enemies.first()->moveto((Director::sharedDirector()->winSizeInPixels().width()/2) + (screenScale*x_offset_player_battle),Director::sharedDirector()->winSizeInPixels().height()*0.4);
    players.first()->setScaleX(1);

    if (players.size() > 1) {
        players.at(1)->setPos((Director::sharedDirector()->winSizeInPixels().width()/2) - (2*screenScale*x_offset_player_battle-30),Director::sharedDirector()->winSizeInPixels().height()*0.4);

        players.at(1)->moveto((Director::sharedDirector()->winSizeInPixels().width()/2) - (2*screenScale*x_offset_player_battle),Director::sharedDirector()->winSizeInPixels().height()*0.4);
        players.at(1)->setScaleX(1);
//        players.at(1)->startBreathing();
    }

    enemies.first()->setScaleX(-1);
}

void map::start_shaking_screen() {
    runSequence(Sequence::sequenceWithActions(action::moveTo(shaking_speed,-shaking_distance*screenScale,-shaking_distance*screenScale),action::FuncCall(this,SLOT(shake_screen_1())),NULL));
}

void map::shake_screen_1() {
    runSequence(Sequence::sequenceWithActions(action::moveTo(shaking_speed,shaking_distance*screenScale,shaking_distance*screenScale),action::FuncCall(this,SLOT(shake_screen_2())),NULL));
}

void map::shake_screen_2() {
    runSequence(Sequence::sequenceWithActions(action::moveTo(shaking_speed,-shaking_distance*screenScale,-shaking_distance*screenScale),action::FuncCall(this,SLOT(shake_screen_3())),NULL));
}

void map::shake_screen_3() {
    runSequence(Sequence::sequenceWithActions(action::moveTo(shaking_speed,0,0),NULL));
}

void map::exit_from_shop() {
    if (current_shop_pointer != 0) {
        //just to make sure, that there's a visiable shop
        line->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.25,100)),action::FuncCall(this,SLOT(exit_from_shop_2())),NULL));
    }
}

void map::exit_from_shop_2() {
    if (current_shop_pointer != 0) {
        shop* tempShop = current_shop_pointer;
        tempShop->setOpacity(0);
        current_shop_pointer = 0;
        removeChild(tempShop);

        int minute = QTime::currentTime().minute();
        int hour = QTime::currentTime().hour();

//        qDebug() << "Current minute is " << minute << " and hour is " << hour;

        opacity_night_level = 0;
        if (hour%2 == 1) {
            //decreasing
            opacity_night_level = 60 - minute;
        } else {
            //increasing
            opacity_night_level = minute;
        }

        refreshDashBoard();

        //just to make sure, that there's a visiable shop
        line->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.25,opacity_night_level/2.0)),action::FuncCall(this,SLOT(reset_line_z_level())),NULL));

        setTouchEnabled(true);

        openMapDoor();
    }
}

void map::exit_from_home() {
    if (current_home_pointer != 0) {
        //just to make sure, that there's a visiable shop
        line->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.25,100)),action::FuncCall(this,SLOT(exit_from_home_2())),NULL));
    }
}

void map::exit_from_home_2() {
    if (current_home_pointer != 0) {
        home* tempHome = current_home_pointer;
        tempHome->setOpacity(0);
        current_home_pointer = 0;
        removeChild(tempHome);

        int minute = QTime::currentTime().minute();
        int hour = QTime::currentTime().hour();

        opacity_night_level = 0;
        if (hour%2 == 1) {
            //decreasing
            opacity_night_level = 60 - minute;
        } else {
            //increasing
            opacity_night_level = minute;
        }

        refreshMainCharacter();

        refreshDashBoard();

        //just to make sure, that there's a visiable shop
        line->runSequence(Sequence::sequenceWithActions(action::easeinout(action::fadeTo(0.25,opacity_night_level/2.0)),action::FuncCall(this,SLOT(reset_line_z_level())),NULL));

        setTouchEnabled(true);

        openMapDoor();
    }
}

void map::refreshMainCharacter() {
    QString xml_file_name = shared_storage::sharedGameStorage()->getFirstPlayer();

    moving_character* xml_character = new moving_character;
    addChild(xml_character);
    xml_character->computer_player = false;
    xml_character->load_from_xml(xml_file_name);
    xml_character->computer_player = false;

    xml_character->setPos(players.first()->pos());
    xml_character->setZ(players.first()->z());
    xml_character->setScaleX(players.first()->scaleX());

    character_base* xml_character_temp = players.first();
    removeChild(xml_character_temp->armor);
    players.replace(0,xml_character);
    removeChild(xml_character_temp);

}

void map::on_red_poition_clicked() {
    if (shared_storage::sharedGameStorage()->getCurrentRedPoition() > 0) {
        shared_storage::sharedGameStorage()->decreaseRedPotion(1);
        refreshDashBoard();
        for (int i = 0; i < players.size(); i++) {
            players.at(i)->resetPlayerHealth();
        }



        const int count = 5;


        float animation_time[count] = {4,6,4,5,3};
        float pointX[count] = {30,20,-40,20,-30};
        float pointY[count] = {-30,20,-40,-20,30};


        float pointXmove[count] = {70,40,-80,45,-60};
        float pointYmove[count] = {-70,40,-80,-40,65};

        float scaleSmoke[count] = {1,0.5,1.30,2,1.7};

        Sprite* smoke_1;

        for (int i = 0; i < count; i++) {
            smoke_1= Sprite::spriteWithSvg("red_smoke_small.svg",screenScale*scaleSmoke[i]);
            addChild(smoke_1);
            smoke_1->setPos((Director::sharedDirector()->winSizeInPixels().width()/2) + (pointX[i]*screenScale),(Director::sharedDirector()->winSizeInPixels().height()/2) + (pointY[i]*screenScale));
            smoke_1->setOpacity(0);
            smoke_1->setZ(200000);

            smoke_1->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.3,100),action::fadeTo(animation_time[i]/4*3,0),NULL));
            smoke_1->runAction(action::easCurve(action::rotateTo(animation_time[i],180),QEasingCurve::OutElastic));

            smoke_1->runAction(action::moveBy(animation_time[i],pointXmove[i]*screenScale,pointYmove[i]*screenScale));
        }


        smoke_1 = Sprite::spriteWithSvg("red_potion_clicked.svg",screenScale*5);
        addChild(smoke_1);
        smoke_1->setPos((Director::sharedDirector()->winSizeInPixels().width()/2) + (0*screenScale),(Director::sharedDirector()->winSizeInPixels().height()/2) + (0*screenScale));
        smoke_1->setOpacity(0);
        smoke_1->setZ(200000);
        smoke_1->setAnchor(0.35,0.5);

        smoke_1->setScale(0.5);

        smoke_1->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.3,100),action::fadeTo(0.3,0),NULL));

        smoke_1->runAction(action::scaleTo(0.6,1));

    } else {
        //run error sound
    }
}

void map::on_red_jewel_clicked() {
    if (shared_storage::sharedGameStorage()->getCurrentRedJewel() > 0) {
        shared_storage::sharedGameStorage()->decreaseRedJewel(1);
        refreshDashBoard();
        for (int i = 0; i < players.size(); i++) {
            players.at(i)->resetPlayerSuper();
        }


        Sprite* smoke_1;


        smoke_1 = Sprite::spriteWithSvg("red_jewel_clicked.svg",screenScale*10);
        addChild(smoke_1);
        smoke_1->setPos((Director::sharedDirector()->winSizeInPixels().width()/2) + (0*screenScale),(Director::sharedDirector()->winSizeInPixels().height()/2) + (0*screenScale));
        smoke_1->setOpacity(0);
        smoke_1->setZ(200000);
        smoke_1->setAnchor(0.35,0.5);

        smoke_1->setScale(0.25);
        smoke_1->setRotation(50);

        smoke_1->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.2,100),action::fadeTo(0.2,0),NULL));
        smoke_1->runAction(action::rotateTo(0.4,180));
        smoke_1->runAction(action::scaleTo(0.4,1));




        smoke_1 = Sprite::spriteWithSvg("red_jewel_clicked.svg",screenScale*5);
        addChild(smoke_1);
        smoke_1->setPos((Director::sharedDirector()->winSizeInPixels().width()/2) + (0*screenScale),(Director::sharedDirector()->winSizeInPixels().height()/2) + (0*screenScale));
        smoke_1->setOpacity(0);
        smoke_1->setZ(200000);
        smoke_1->setAnchor(0.35,0.5);

        smoke_1->setScale(1);
        smoke_1->setRotation(50);

        smoke_1->runSequence(Sequence::sequenceWithActions(action::fadeTo(0.2,100),action::fadeTo(0.2,0),NULL));
        smoke_1->runAction(action::rotateTo(0.4,-180));
        smoke_1->runAction(action::scaleTo(0.4,0.5));

    } else {
        //run error sound
    }
}

void map::reset_line_z_level() {
    line->setZ(20000000 - 50);
}

void map::on_dashboard_quest_button_clicked() {
    float animtaion_time = 0.3;
    if (quest_button_open) {
        quest_button_open = false;
        dashboard_quest->stopAllActions();
        quest_button_shadow->stopAllActions();
        quest_pop_layer->stopAllActions();
        dashboard_quest->runAction(action::easeinout(action::rotateTo(animtaion_time,0)));
        dashboard_quest->runAction(action::easeinout(action::scaleTo(animtaion_time,1)));
        quest_button_shadow->runAction(action::easeinout(action::scaleTo(animtaion_time,1)));
        quest_button_shadow->runAction(action::easeinout(action::moveTo(animtaion_time,86.72*screenScale,44.46*screenScale)));
        quest_pop_layer->runAction(action::easeinout(action::moveTo(animtaion_time,quest_pop_layer->pos().x(),-455*screenScale)));

    } else {
        quest_button_open = true;
        dashboard_quest->stopAllActions();
        quest_button_shadow->stopAllActions();
        quest_pop_layer->stopAllActions();
        dashboard_quest->runAction(action::easeinout(action::rotateTo(animtaion_time,360*2)));
        dashboard_quest->runAction(action::easeinout(action::scaleTo(animtaion_time,0.9)));
        quest_button_shadow->runAction(action::easeinout(action::scaleTo(animtaion_time,0.9)));
        quest_button_shadow->runAction(action::easeinout(action::moveTo(animtaion_time,76.72*screenScale,54.46*screenScale)));
        quest_pop_layer->runAction(action::easeinout(action::moveTo(animtaion_time,quest_pop_layer->pos().x(),0)));

    }
}

void map::disable_battle_mood_buttons() {
    bool enabled = false;
    red_potion_button->setEnabled(enabled);
    red_jewel_button->setEnabled(enabled);
}

void map::enable_battle_mood_buttons() {
    bool enabled = true;
    red_potion_button->setEnabled(enabled);
    red_jewel_button->setEnabled(enabled);

}
