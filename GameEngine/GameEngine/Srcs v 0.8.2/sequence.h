#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <stdarg.h> //va_list, va_start, va_arg, va_end
#include "action.h"

class Node;
class action;

class Sequence : public QObject
{
    Q_OBJECT
public:
    static Sequence* sequenceWithActions(action* action,...);
    void setTarget(Node *target);
    void stopActions();

signals:

public slots:
    void oneActionisDone();
private:
    explicit Sequence();
    QList <action*> actionList;
    Node *targetNode;
    void runNextAction();
    bool deaActivating;

};

#endif // SEQUENCE_H
