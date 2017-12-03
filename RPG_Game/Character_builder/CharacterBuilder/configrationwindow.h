#ifndef CONFIGRATIONWINDOW_H
#define CONFIGRATIONWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDomDocument>
#include "game_engine.h"
#include "svg_scene.h"
#include "png_scene.h"
#include "skeltal_widget.h"
#include <QTime>
#include <QDate>
#include <QSettings>
#include <QComboBox>
#include <stdlib.h>


namespace Ui {
class ConfigrationWindow;
}

class ConfigrationWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ConfigrationWindow(QWidget *parent = 0);
    ~ConfigrationWindow();
    QTreeWidget* jointTreeWidget();
    
private:
    Ui::ConfigrationWindow *ui;

protected:

public slots:

    void setDragAndDropElement(skeltal_hbox* hBox);

    void on_refresh_clicked();

    void on_SaveXML_clicked();

    void changeCurrentAnimationTime(int newTimeValue);

    void loadXML();

    bool checkAnimationValues();

    void JointTreeSelectionChanged();
    void AnimationTreeSelectionChanged();
    void submitPrevChanges();
    void submitPrevAnimationChanges();
    void refreshAnimationTree();

    //keyframes timeline methodes
    void refresh_key_frames();

private slots:

    void on_runAnimationButton_clicked();

    void on_stopAnimationButton_clicked();

    void on_setValuesPushButton_clicked();

    void on_AddAnimationPointpushButton_clicked();

    void on_RemoveAnimationPointpushButton_clicked();

    void on_AddJointpushButton_clicked();

    void on_DeleteJointpushButton_clicked();

    void on_JointYDragDroppushButton_clicked();

    void on_JointRotationDragDroppushButton_clicked();

    void on_AnimationRDragDroppushButton_clicked();

    void on_AnimationYDragDroppushButton_clicked();

    void on_AnimationSetValuespushButton_clicked();

    void on_JointXDragDroppushButton_clicked();

    void on_slowAnimationPushButton_clicked();

    void on_ChangeAnimationPointpushButton_clicked();

    void on_WeaponSuperpushButton_clicked();

    void on_CharSuperpushButton_clicked();

    void on_JointtreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_JointResetAllOpacitypushButton_clicked();

    void on_keyFrameslistWidget_itemClicked(QListWidgetItem *item);

    void on_keyFrameslistWidget_itemPressed(QListWidgetItem *item);

    void on_keyFrameslistWidget_itemSelectionChanged();

    void on_KeyFramedoubleSpinBox_valueChanged(double arg1);

    void on_keyFrameslistWidget_itemDoubleClicked(QListWidgetItem *item);

protected:
    void keyPressEvent(QKeyEvent *);

private:
    void updateSelectedAnimationIndex();
    void selectUpdateSelectedAnimationIndex();

    void setUpMovementsDropDown();
    void enableRootAnimationItems();
    void enableAnyAnimationItems();
    void setRootAnimationEnabled(bool enable);
    void disableWholeAnimationSection();
    svg_scene* svgScene;
    png_scene* pngScene;
    skeltal_widget *skeltalwidget;
    QPoint offset;
    skeltal_hbox* selectedHbox;
    QString currentSettingforAnimation;
    animationStep* selectedAnimationStep;
    bool moving;
    bool svgSceneSelected;
    int selectedAnimationIndex;
    float selectedAnimationTimeLine;
    bool disableUpdateSave;
    QString key_animation_name;
    float time_diffrence;
    QList <QString> key_frames_strings;
};

#endif // CONFIGRATIONWINDOW_H
