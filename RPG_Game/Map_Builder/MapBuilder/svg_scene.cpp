#include "svg_scene.h"

Scene *svg_scene::scene() {
    Scene *scene = Scene::node();
    svg_scene* layer = new svg_scene;
    scene->addChild(layer);
    return scene;
}

svg_scene::svg_scene()
{

    xml_test_map = 0;

    //taking screen size, saving it to variable called winSize
    winSize = Director::sharedDirector()->winSizeInPixels();    

    bool enable_touch = true;
#ifndef COMPUTER
    loadMapFromXML("area_1_1.xml");
    enable_touch = false;
#endif
#ifdef viewerOnly
    //not to duplocate
    if (enable_touch) {
        loadMapFromXML("area_1_1.xml");
        enable_touch = false;
    }
#endif
    setTouchEnabled(enable_touch);
    if (enable_touch) {
        //that means, we are in the map editor, or builder, let's put our lines
        QPen pen;
        pen.setColor(Qt::blue);
        pen.setWidth(2);

        float line_aspect_ration = -0.285;

        line = lineNode::lineWithPen(pen);
        addChild(line);
        line->setLineEndPoints(0,(winSize.height()/2) + (winSize.width()*line_aspect_ration),winSize.width(),(winSize.height()/2) + (winSize.width()*line_aspect_ration));
        line->setZ(200000);
        line->setOpacity(50);

        line = lineNode::lineWithPen(pen);
        addChild(line);
        line->setLineEndPoints(0,(winSize.height()/2) - (winSize.width()*line_aspect_ration),winSize.width(),(winSize.height()/2) - (winSize.width()*line_aspect_ration));
        line->setZ(200000);
        line->setOpacity(30);

        pen.setColor(Qt::red);

        line = lineNode::lineWithPen(pen);
        addChild(line);
        line->setLineEndPoints(0,(winSize.height()/2),winSize.width(),(winSize.height()/2));
        line->setZ(200000);
        line->setOpacity(50);

        line = lineNode::lineWithPen(pen);
        addChild(line);
        line->setLineEndPoints(winSize.width()/2,(winSize.height()),winSize.width()/2,0);
        line->setZ(200000);
        line->setOpacity(30);

        int numOfRows = 30;
        int numOfColumns = 30;

        numOfRows++;
        numOfColumns++;

        pen.setWidth(1);
        pen.setColor(Qt::magenta);

        for (int i = 0; i < numOfRows; i++) {
            line = lineNode::lineWithPen(pen);
            addChild(line);
            line->setLineEndPoints(0,(winSize.height()/numOfRows*(i+1)),winSize.width(),(winSize.height()/numOfRows*(i+1)));
            line->setZ(200000);
            line->setOpacity(20);
        }

        pen.setColor(Qt::yellow);

        for (int j = 0; j < numOfColumns; j++) {
            line = lineNode::lineWithPen(pen);
            addChild(line);
            line->setLineEndPoints((winSize.width()/numOfColumns*(j+1)),0,(winSize.width()/numOfColumns*(j+1)),winSize.height());
            line->setZ(200000);
            line->setOpacity(20);

        }


    }

    mouse_pressed = false;

    //    dragDropLineEdit = 0;
    //    dragAndDropJoint = 0;
    //    dragDropLineEditX = 0;

    //    qDebug() << Q_FUNC_INFO;



    //    //we'll start by adding a sprite that represents the background for the menu
    //    background = Sprite::spriteWithImage("rpg_test_wallpaper.jpg");
    //    background->setPos(winSize.width()/2,winSize.height()/2);
    //    background->setZ(0);
    //    addChild(background);
    ////    if (origwallw == 1024)
    ////        background->setScale(0.5);
    //    QPen pen;
    //    pen.setColor(Qt::red);
    //    pen.setWidth(10);

    //    line = lineNode::lineWithPen(pen);

    //    pen.setColor(Qt::blue);

    //    elips = Elips::elipsWith(50,50,pen);

    //    pen.setColor(Qt::magenta);

    //    elipsstart = Elips::elipsWith(50,50,pen);

    //    addChild(line);
    //    addChild(elips);
    //    addChild(elipsstart);

    //    line->setOpacity(0);
    //    elips->setOpacity(0);
    //    elipsstart->setOpacity(0);

    //    line->setZ(10000000);
    //    elips->setZ(10000000);
    //    elipsstart->setZ(10000000);



    //#ifndef Q_OS_MAC64
    //    loadCharacterFromXML("testing.xml");
    //#endif

    //    human_char_controller* controller = new human_char_controller;
    //    controller->setTouchEnabled(false);



}

void svg_scene::set_transparent() {
    if (elementID >= 0 && elementID < xml_test_map->everySinglemapElementsList.size()) {
        Node* tempPart = xml_test_map->everySinglemapElementsList.at(elementID).elementSprite;
        tempPart->setOpacity(50);
        tempPart->runSequence(Sequence::sequenceWithActions(action::easeinout(action::scaleTo(0.5,2)),action::easeinout(action::scaleTo(0.5,1)),NULL));
    }
}

void svg_scene::set_un_transparent() {
    if (elementID >= 0 && elementID < xml_test_map->everySinglemapElementsList.size()) {
        Node* tempPart = xml_test_map->everySinglemapElementsList.at(elementID).elementSprite;
        tempPart->setOpacity(100);

    }
}

void svg_scene::decreaseHealthBar() {
    //    testHealthBarLayer->setLevel(healthBarValue);
    //    healthBarValue -= 1;
    //    QTimer::singleShot(100,this,SLOT(decreaseHealthBar()));
}

void svg_scene::setXMLTestCharacterCurrentAnimationTime(QString newAnimationName, int time) {
    //        currentAnimationName = newAnimationName;
    //        xml_test_character->setAnimationType(currentAnimationName);
}

void svg_scene::runAnimationOnCharacter() {
    //    xml_test_character->runAnimation();
}

void svg_scene::performanceRandomAnimationTest() {

    //    for (int i = 0; i < cards.size(); i++)  {
    //        float x = qrand() % 1000;
    //        float y = qrand()  % 700;
    //        float s = qrand() % 10;
    //        s/=5.0;
    //        float r = qrand() % 1000;
    //        cards.at(i)->runAction(action::easeinout(action::scaleTo(1,s)));
    //        cards.at(i)->runAction(action::easeinout(action::moveTo(1,x,y)));
    //        cards.at(i)->runAction(action::easeinout(action::rotateTo(1,r)));
    //    }
}

void svg_scene::loadSVGasPixmap() {
}

void svg_scene::loadCharacterFromXML(QString xml_file_name) {

    //    moving_character* xml_character = new moving_character;
    //    addChild(xml_character);
    //    xml_character->load_from_xml(xml_file_name);
    //    xml_character->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);

    //    xml_test_character = xml_character;

    //    xml_test_character->computer_player = false;

    //    xml_test_character->setZ(1000);

    //    schedualUpdate();
}

void svg_scene::loadMapFromXML(QString xml_file_name) {
    xml_test_map = new map;
    addChild(xml_test_map);
    xml_test_map->load_from_xml(xml_file_name);
    xml_test_map->onEnterTransitionDidFinish();
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
    mouse_pressed = true;
}

void svg_scene::touchMove(QGraphicsSceneMouseEvent *event) {
    moveMentDetected = true;
    QPointF currentPoint = Director::sharedDirector()->convertTouchPoint(event->scenePos());
    QPointF diffrent = currentPoint - prevPoint;
    if (mouse_pressed) {
        if (elementID >= 0 && elementID < xml_test_map->everySinglemapElementsList.size()) {
            Node* tempPart = xml_test_map->everySinglemapElementsList.at(elementID).elementSprite;
            if (tempPart != 0) {
                if (rotation) {
                    tempPart->setRotation(tempPart->rotation() - diffrent.y());
                    int newR = tempPart->rotation();
                    emit signal_new_rotation(newR);

                } else {
                    float newY = tempPart->pos().y() + diffrent.y();
                    float newX = tempPart->pos().x() + diffrent.x();

                    tempPart->setPos(newX,newY);
                    emit signal_new_postion(newX,newY);

                }
                //            updateJointSelection();
            }
        }
    }
    prevPoint = currentPoint;
}

void svg_scene::touchEnd(QGraphicsSceneMouseEvent *event) {
    mouse_pressed = false;
    //    if (!moveMentDetected) {
    //        if (rotation) {
    //            rotation = false;
    //        } else {
    //            rotation = true;
    //        }
    //    }
}

void svg_scene::updateJointSelection() {
    //    elips->setPos(dragAndDropJoint->partPointer->realTimePos().x(),winSize.height() - dragAndDropJoint->partPointer->realTimePos().y());
    //    elipsstart->setPos(dragAndDropJoint->partPointer->parent_part->holderLayer->realTimePos().x(),winSize.height() - dragAndDropJoint->partPointer->parent_part->holderLayer->realTimePos().y());
    //    line->setLineEndPoints(dragAndDropJoint->partPointer->realTimePos().x(),winSize.height() - dragAndDropJoint->partPointer->realTimePos().y(),elipsstart->realTimePos().x() + elips->width()/2,winSize.height() - elipsstart->realTimePos().y() - elips->width()/2);
    //    line->setOpacity(40);
    //    elips->setOpacity(40);
    //    elipsstart->setOpacity(40);
}

void svg_scene::hideLine() {
    //    line->setOpacity(0);
    //    elips->setOpacity(0);
    //    elipsstart->setOpacity(0);
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
    //    xml_test_character->setPos(Director::sharedDirector()->winSizeInPixels().width()/2,Director::sharedDirector()->winSizeInPixels().height()/2);
}

void svg_scene::animation()
{
}

void svg_scene::stopAnimationOnCharacter() {
    //    xml_test_character->stopAnimation();
}
