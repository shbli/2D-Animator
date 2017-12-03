#include "svg_scene.h"
#include "map.h"

Scene *svg_scene::scene() {
    Scene *scene = Scene::node();
    svg_scene* layer = new svg_scene;
    scene->addChild(layer);
    return scene;
}

svg_scene::svg_scene()
{

    game_controller::sharedGameController()->currentMap = new map;
    dragDropLineEdit = 0;
    dragAndDropJoint = 0;
    dragDropLineEditX = 0;

    qDebug() << Q_FUNC_INFO;

    //taking screen size, saving it to variable called winSize
    winSize = Director::sharedDirector()->winSizeInPixels();


    //we'll start by adding a sprite that represents the background for the menu
    background = Sprite::spriteWithSvg("ground_1_fight.svg",1);
    background->setPos(winSize.width()/2,winSize.height()/2);
    background->setZ(0);
    addChild(background);
//    if (origwallw == 1024)
//        background->setScale(0.5);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(10);



    line = lineNode::lineWithPen(pen);

    pen.setColor(Qt::blue);

    elips = Elips::elipsWith(50,50,pen);

    pen.setColor(Qt::magenta);

    elipsstart = Elips::elipsWith(50,50,pen);

    addChild(line);
    addChild(elips);
    addChild(elipsstart);

    line->setOpacity(0);
    elips->setOpacity(0);
    elipsstart->setOpacity(0);

    line->setZ(10000000);
    elips->setZ(10000000);
    elipsstart->setZ(10000000);



#ifndef COMPUTER
    loadCharacterFromXML("testing.xml");
#else
    character_base::screenScale = 2;
#endif

    game_controller::sharedGameController()->currentMap->screenScale = character_base::screenScale;

    human_char_controller* controller = new human_char_controller;
    controller->setTouchEnabled(false);

    game_controller::sharedGameController()->mainPlayLayer = this;
    setTouchEnabled(true);

}

void svg_scene::decreaseHealthBar() {
    testHealthBarLayer->setLevel(healthBarValue);
    healthBarValue -= 1;
    QTimer::singleShot(100,this,SLOT(decreaseHealthBar()));
}

void svg_scene::setXMLTestCharacterCurrentAnimationTime(QString newAnimationName, int time) {
        currentAnimationName = newAnimationName;
        xml_test_character->setAnimationType(currentAnimationName);
}

void svg_scene::runAnimationOnCharacter() {
    xml_test_character->runAnimation();
}

void svg_scene::performanceRandomAnimationTest() {

    for (int i = 0; i < cards.size(); i++)  {
        float x = qrand() % 1000;
        float y = qrand()  % 700;
        float s = qrand() % 10;
        s/=5.0;
        float r = qrand() % 1000;
        cards.at(i)->runAction(action::easeinout(action::scaleTo(1,s)));
        cards.at(i)->runAction(action::easeinout(action::moveTo(1,x,y)));
        cards.at(i)->runAction(action::easeinout(action::rotateTo(1,r)));
    }
}

void svg_scene::loadSVGasPixmap() {
}

void svg_scene::loadCharacterFromXML(QString xml_file_name, skeltal_hbox* root) {

    moving_character* xml_character = new moving_character;
    addChild(xml_character);
    xml_character->load_from_xml(xml_file_name,root);
    xml_character->setPos(Director::sharedDirector()->winSizeInPixels().width()/8,Director::sharedDirector()->winSizeInPixels().height()/3);

    xml_test_character = xml_character;

    xml_test_character->computer_player = false;

    xml_test_character->setZ(1000);

    xml_character = new moving_character;
    addChild(xml_character);
    xml_character->load_from_xml("warrior_enemy_1.xml",0);
    xml_character->setPos(Director::sharedDirector()->winSizeInPixels().width()/2.75,Director::sharedDirector()->winSizeInPixels().height()/3);
    xml_character->setScaleX(-1);

    xml_test_dump_enemy_character = xml_character;

    xml_test_dump_enemy_character->computer_player = true;

    xml_test_dump_enemy_character->setZ(900);

    xml_test_character->aimToAtttackChar = xml_test_dump_enemy_character;

    xml_test_dump_enemy_character->startBreathing();

//    schedualUpdate();
}

void svg_scene::testHealthBar() {
//    testHealthBarLayer = new health_bar;
//    testHealthBarLayer->setZ(100);
//    testHealthBarLayer->setPos(400,400);
//    addChild(testHealthBarLayer);
//    healthBarValue = 100;
//    decreaseHealthBar();
}

void svg_scene::stopAllAnimatedCharacters() {

}

void svg_scene::touchBegin(QGraphicsSceneMouseEvent *event) {
    QPointF currentPoint = Director::sharedDirector()->convertTouchPoint(event->scenePos());
    prevPoint = currentPoint;
    moveMentDetected = false;
}

void svg_scene::touchMove(QGraphicsSceneMouseEvent *event) {
    moveMentDetected = true;
    QPointF currentPoint = Director::sharedDirector()->convertTouchPoint(event->scenePos());
    QPointF diffrent = currentPoint - prevPoint;
    if (dragAndDropJoint != 0) {
        skeltal_part* tempPart = dragAndDropJoint->partPointer;
        if (tempPart != 0) {
            if (rotation) {
                tempPart->holderLayer->setRotation(tempPart->holderLayer->rotation() - diffrent.y());
                int newR = tempPart->holderLayer->rotation();
                if (dragDropLineEdit) {
                    dragDropLineEdit->setText(QString().setNum(newR));
                }

            } else {
                int newY = tempPart->pos().y() - diffrent.y();
                if (-newY >= 0) {
                    tempPart->setPos(tempPart->pos().x(),newY);
                    if (dragDropLineEdit) {
                        dragDropLineEdit->setText(QString().setNum(-newY/2));
                    }
                }
//                if (dragDropLineEditX) {
//                    dragDropLineEditX->setText(QString().setNum(newX));
//                }
            }
            updateJointSelection();
        }
    }
    prevPoint = currentPoint;
}

void svg_scene::touchEnd(QGraphicsSceneMouseEvent *event) {
//    if (!moveMentDetected) {
//        if (rotation) {
//            rotation = false;
//        } else {
//            rotation = true;
//        }
    //    }
}

void svg_scene::updateJointSelection() {
    elips->setPos(dragAndDropJoint->partPointer->realTimePos().x(),winSize.height() - dragAndDropJoint->partPointer->realTimePos().y());
    elipsstart->setPos(dragAndDropJoint->partPointer->parent_part->holderLayer->realTimePos().x(),winSize.height() - dragAndDropJoint->partPointer->parent_part->holderLayer->realTimePos().y());
    line->setLineEndPoints(dragAndDropJoint->partPointer->realTimePos().x(),winSize.height() - dragAndDropJoint->partPointer->realTimePos().y(),elipsstart->realTimePos().x() + elips->width()/2,winSize.height() - elipsstart->realTimePos().y() - elips->width()/2);
    line->setOpacity(40);
    elips->setOpacity(40);
    elipsstart->setOpacity(40);
}

void svg_scene::hideLine() {
    line->setOpacity(0);
    elips->setOpacity(0);
    elipsstart->setOpacity(0);
}

void svg_scene::run_sample_super_char() {
    if (xml_test_character != 0) {
        xml_test_character->charaacter_close_to_attack = true;
        xml_test_character->q_char_super();
    }
}

void svg_scene::onEnterTransitionDidStart() {
}

void svg_scene::onEnterTransitionDidFinish()
{
}

void svg_scene::onExitTransitionDidFinish()
{
}

svg_scene::~svg_scene() {
}

void svg_scene::onExitTransitionDidStart()
{
}

void svg_scene::update(double delta)
{
    xml_test_character->setPos(Director::sharedDirector()->winSizeInPixels().width()/8,Director::sharedDirector()->winSizeInPixels().height()/3);
}

void svg_scene::animation()
{
}

void svg_scene::stopAnimationOnCharacter() {
    xml_test_character->stopAnimation();
}

void svg_scene::run_sample_super_weapon() {
    if (xml_test_character != 0) {
        xml_test_character->charaacter_close_to_attack = true;
        xml_test_character->q_weapon_super();
    }
}

void svg_scene::set_key_point_on_character(QString animation_name, float key_point) {
    if (xml_test_character != 0) {
        xml_test_character->set_animtion_at_point(animation_name,key_point);
    }
}
