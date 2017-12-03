#ifndef ANIMATION_VBOX_H
#define ANIMATION_VBOX_H

#include <QVBoxLayout>
#include <QLabel>
#include <QDomDocument>
#include <QPushButton>
#include "animationstep.h"
#include "skeltal_hbox.h"

#define animationTitleType 1100

class skeltal_hbox;

class animation_vbox : public QTreeWidgetItem
{

public:
    float animationTotalTime;
    animation_vbox(QString name, int type);
    ~animation_vbox();
    QString animationName;
    QList <animationStep*> stepslist;
    int parentPartType;
    bool allStepsMeetCritieria();
    skeltal_hbox* parentHbox;

    void addNewStep(float time, int index, bool add_current = false);
    void changeAStep(float fromtime,float totime, int index);
    void removeStep(float time, int index);
    void addNewStep1();
    void addNewStepBasic();
    void deleteAnimationStep(animationStep* toBeDeleted);
    void loadFromDomNode(QDomElement* animationNode);
    void setDragDrop(QLineEdit* rotate, QLineEdit* ybox);
    void setValues(QLineEdit* rotate, QLineEdit* ybox);
    void refreshParametersList();
    QDomElement animationsDomElement(QDomDocument *domDocumnet);
};

#endif // ANIMATION_VBOX_H
