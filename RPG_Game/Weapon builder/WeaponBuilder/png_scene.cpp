#include "png_scene.h"

Scene* png_scene::scene() {
    Scene *scene = Scene::node();
    png_scene* layer = new png_scene;
    scene->addChild(layer);
    return scene;
}


png_scene::png_scene()
{
    qDebug() << Q_FUNC_INFO;
    //taking screen size, saving it to variable called winSize
    winSize = Director::sharedDirector()->winSizeInPixels();

    //we'll start by adding a sprite that represents the background for the menu
    background = Sprite::spriteWithSvg("ground_1_fight.svg",1);
    background->setPos(winSize.width()/2,winSize.height()/2);
    addChild(background);
    QString fileName;
    QString temp;
    Sprite *newCard;
    qreal offset = 100;
    //we'll creat the 13 club cards
    fileName = "c.png";
    for (int i = 1; i <= 13; i++) {
        temp = QString().setNum(i);
        temp.append(fileName);
        newCard = Sprite::spriteWithImage(temp.toAscii());
        cards.append(newCard);
        newCard->setPos(offset,offset);
        addChild(newCard);
    }
    //we'll creat the 13 diamond cards
    fileName = "d.png";
    for (int i = 1; i <= 13; i++) {
        temp = QString().setNum(i);
        temp.append(fileName);
        newCard = Sprite::spriteWithImage(temp.toAscii());
        cards.append(newCard);
        newCard->setPos(offset,offset);
        addChild(newCard);
    }
    //we'll creat the 13 heart cards
    fileName = "h.png";
    for (int i = 1; i <= 13; i++) {
        temp = QString().setNum(i);
        temp.append(fileName);
        newCard = Sprite::spriteWithImage(temp.toAscii());
        cards.append(newCard);
        newCard->setPos(offset,offset);
        addChild(newCard);
    }
    //we'll creat the 13 Spade cards
    fileName = "s.png";
    for (int i = 1; i <= 13; i++) {
        temp = QString().setNum(i);
        temp.append(fileName);
        newCard = Sprite::spriteWithImage(temp.toAscii());
        cards.append(newCard);
        newCard->setPos(offset,offset);
        addChild(newCard);
    }
    counter = 0;
//    animation();
    performanceRandomAnimationTest();
}

void png_scene::animation() {
    if (counter < cards.size()) {
        cards.at(counter)->runSequence(Sequence::sequenceWithActions(action::easeinout(action::moveBy(0.5,300,200)),action::FuncCall(this,SLOT(animation())),NULL));
        cards.at(counter)->runAction(action::easeinout(action::rotateBy(0.5,360)));
        audioManager::playSound("alert.wav");
        audioManager::playSound("play_card.wav");
        counter++;
    }
}

void png_scene::performanceRandomAnimationTest() {

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

void png_scene::update(double delta) {
//    runAction(action::rotateBy(4,360));
    runAction(action::easeinout(action::scaleTo(1,1)));
    runAction(action::fadeTo(1,100));
    unSchedualUpdate();
}


void png_scene::onEnterTransitionDidStart() {
    qDebug() << Q_FUNC_INFO;
}

void png_scene::onEnterTransitionDidFinish() {
    qDebug() << Q_FUNC_INFO;
}

void png_scene::onExitTransitionDidStart() {
    qDebug() << Q_FUNC_INFO;
}

void png_scene::onExitTransitionDidFinish() {
    qDebug() << Q_FUNC_INFO;
}

