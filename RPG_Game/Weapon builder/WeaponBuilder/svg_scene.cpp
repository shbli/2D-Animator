#include "svg_scene.h"
#include "game_controller.h"

Scene *svg_scene::scene() {
    Scene *scene = Scene::node();
    svg_scene* layer = new svg_scene;
    scene->addChild(layer);
    return scene;
}

svg_scene::svg_scene()
{

    qDebug() << Q_FUNC_INFO;

    //taking screen size, saving it to variable called winSize
    winSize = Director::sharedDirector()->winSizeInPixels();


    //we'll start by adding a sprite that represents the background for the menu
    background = Sprite::spriteWithSvg("ground_1_fight.svg",1);
    background->setPos(winSize.width()/2,winSize.height()/2);
    background->setZ(0);
    background->setScale(winSize.width()/origwallw);
    addChild(background);


    loadSVGasPixmap();

#ifndef COMPUTER
    loadCharacterFromXML("testing.xml");
#endif

    //    renderer = new QSvgRenderer(QLatin1String("svg-cards.svg"));
//    svgSprite* svg = svgSprite::spriteSVGwith(renderer,"red_joker",100,145);
//    cards.append(svg);
//    svg = svgSprite::spriteSVGwith(renderer,"black_joker",100,145);
//    cards.append(svg);
//    addChild(svg);
//    QList <QString> types;
//    types.append(QString("spade"));
//    types.append(QString("heart"));
//    types.append(QString("diamond"));
//    types.append(QString("club"));
//    QString tempelementID;
//    for (int i = 0; i < types.size(); i++) {
//        for (int j = 1; j < 11; j++) {
//            tempelementID = QString().setNum(j) + "_" + types.at(i);
//            svg = svgSprite::spriteSVGwith(renderer,tempelementID.toAscii(),100,145);
//            cards.append(svg);
//            addChild(svg);
//        }
//        tempelementID = "jack_" + types.at(i);
//        svg = svgSprite::spriteSVGwith(renderer,tempelementID.toAscii(),100,145);
//        cards.append(svg);
//        addChild(svg);
//        tempelementID = "queen_" + types.at(i);
//        svg = svgSprite::spriteSVGwith(renderer,tempelementID.toAscii(),100,145);
//        cards.append(svg);
//        addChild(svg);
//        tempelementID = "king_" + types.at(i);
//        svg = svgSprite::spriteSVGwith(renderer,tempelementID.toAscii(),100,145);
//        cards.append(svg);
//        addChild(svg);
//    }

//    for (int i = 0; i < cards.size(); i++) {
//        cards.at(i)->setPos(i*20,i*20);
//    }
//    performanceRandomAnimationTest();
    //    qDebug() << "Number of cards " << cards.size();
}

void svg_scene::setXMLTestCharacterCurrentAnimationTime(QString newAnimationName, int time) {

}

void svg_scene::runAnimationOnCharacter() {
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

void svg_scene::loadSVGasPixmap()
{
}

void svg_scene::loadCharacterFromXML(QString xml_file_name) {
    character_base::screenScale = 1;
    game_controller::sharedGameController()->mainPlayLayer = this;
    testWeapon = new weapon;
    testWeapon->setRotation(-90);
    addChild(testWeapon);
    testWeapon->setPos(winSize.width()/8,winSize.height()/2);
    Layer* beforeLayer = Layer::node();
    addChild(beforeLayer);
    beforeLayer->setPos(Director::sharedDirector()->winSizeInPixels().width()/8,Director::sharedDirector()->winSizeInPixels().height()/2);
    beforeLayer->setRotation(-90);
    testWeapon->load_from_xml(xml_file_name,beforeLayer,0,0);
    testWeapon->setZ(1000);
}

void svg_scene::onEnterTransitionDidStart()
{
}

void svg_scene::onEnterTransitionDidFinish()
{
}

void svg_scene::onExitTransitionDidFinish()
{
}

svg_scene::~svg_scene() {
//    renderer->deleteLater();
}

void svg_scene::onExitTransitionDidStart()
{
}

void svg_scene::update(double delta)
{
}

void svg_scene::animation() {
    testWeapon->startBeforeEffect((Director::sharedDirector()->winSizeInPixels().width()/8) + 150,(Director::sharedDirector()->winSizeInPixels().height()/2) + 0,1,(Director::sharedDirector()->winSizeInPixels().width()/8) + 150,(Director::sharedDirector()->winSizeInPixels().height()/2) + 0,1);
}

void svg_scene::stopAnimationOnCharacter() {
}
