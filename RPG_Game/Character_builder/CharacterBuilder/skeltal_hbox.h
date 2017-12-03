#ifndef SKELTAL_HBOX_H
#define SKELTAL_HBOX_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QDomDocument>
#include <QMessageBox>
#include <QDebug>
#include <animation_vbox.h>
#include "global_keys.h"
#include <QGraphicsView>
#include <QTreeWidgetItem>

#define skeltalJointType 1300

class skeltal_part;
class ConfigrationWindow;

class skeltal_hbox : public QTreeWidgetItem
{
//    Q_OBJECT

public:

    ConfigrationWindow* configWindow;
    bool part_type;
    explicit skeltal_hbox(skeltal_hbox *parent, QTreeWidget* parentScrollArea);
    ~skeltal_hbox();
    QTreeWidget* prntScrllArea;
    QList <skeltal_hbox*> child_joint;
    skeltal_hbox* parent_joint;
    QHBoxLayout* hbox;
    QLabel* label;
    QString partName;
    float zValueBox;
    float rValueBox;
    float yValueBox;
    float yAnchValueBox;
    float xAnchValueBox;
    bool containsW1Box;
    bool containsW2Box;
    QList <QString> skeltalSVGs;
    QList <animation_vbox*> animationsBoxes;
    QList <QWidget*> childWidgets;
    bool doesntContainChilds();
    skeltal_part* partPointer;
    void refreshParameters();
    void setPartValues(float time, int animationIndex);
    bool checkAnimationValues();
    QDomElement partDomElement(QDomDocument* domDocumnet);
    void addMovementsForms();
    void addJoint_button();
    void removeJoint_button();
    void removeChildFromTree(skeltal_hbox* child);
    void addSVGBoxForJoint_button();
    void loadFromQDomElement(QDomElement* jointElement);
    void dim_all_svgs();
    void un_dim_all_svgs();
    void show_current_one();

};

#endif // SKELTAL_HBOX_H
