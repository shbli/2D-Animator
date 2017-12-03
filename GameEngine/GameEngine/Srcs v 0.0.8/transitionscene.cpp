#include "transitionscene.h"


transitionScene::transitionScene() {

}

transitionScene * transitionScene::FadeTransition(Scene *otherScene,float duration) {
    transitionScene* newTrans = new transitionScene;
    newTrans->nextScene = otherScene;
    otherScene->mainLayer->onEnterTransitionDidStart();
    newTrans->dur = duration;
    newTrans->origFade = newTrans->nextScene->opacity();
    newTrans->nextScene->setOpacity(0);
    connect(newTrans,SIGNAL(transitionDoneSignal(Scene*)),Director::sharedDirector(),SLOT(transitionDone(Scene*)));
    return newTrans;
}

void transitionScene::setCurrScene(Scene *scene) {
    currScene = scene;
    currScene->mainLayer->onExitTransitionDidStart();
    action* firststep = action::fadeTo(dur/2,0);
    action* gotostep2 = action::FuncCall(this,SLOT(FadeTransition_half_done()));
    scene->runSequence(Sequence::sequenceWithActions(firststep,gotostep2,NULL));
}

void transitionScene::FadeTransition_half_done() {
    action* firststep = action::fadeTo(dur/2,origFade);
    action* gotostep3 = action::FuncCall(this,SLOT(transition_done()));
    nextScene->runSequence(Sequence::sequenceWithActions(firststep,gotostep3,NULL));
}
void transitionScene::transition_done() {
    currScene->mainLayer->onExitTransitionDidFinish();
    nextScene->mainLayer->onEnterTransitionDidFinish();
    emit transitionDoneSignal(nextScene);
    deleteLater();
}
