#include "sequence.h"

Sequence::Sequence() {
    deaActivating = false;
}

Sequence* Sequence::sequenceWithActions(action* actionItem,...) {

    if (actionItem != NULL) {
        Sequence* newSeq = new Sequence;
        newSeq->actionList.append(actionItem);
        action* addAction;
        va_list list;
        va_start(list,actionItem);
        addAction = va_arg(list,action*);
        while (addAction != NULL) {
            newSeq->actionList.append(addAction);
            addAction = va_arg(list,action*);
        }
        va_end(list);
        return newSeq;
    }
    else {
        qDebug() << "Game Engine :: Warning : you are trying to construct an empty sequence action, it will return for you a NULL pointer";
        return NULL;
    }

}

void Sequence::setTarget(Node *target) {
    targetNode = target;
    runNextAction();
}

void Sequence::oneActionisDone() {
    runNextAction();
}

void Sequence::runNextAction() {
    if (!deaActivating) {
        if (!actionList.isEmpty()) {
            action* nextAction = actionList.takeFirst();
            connect(nextAction,SIGNAL(animationFinished(action*)),this,SLOT(oneActionisDone()));
            targetNode->runAction(nextAction);
        }
        else {
            targetNode->stopSequence(this);
        }
    }
}

void Sequence::stopActions() {
    deaActivating = true;
    while (!actionList.isEmpty()) {
        action* nextAction = actionList.takeFirst();
        if (nextAction->targetNode != 0) {
            nextAction->stopAnimation();
            nextAction->deleteLater();
        }
    }
}
