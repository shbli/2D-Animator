#ifndef CONFIGRATIONWINDOW_H
#define CONFIGRATIONWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDomDocument>
#include "game_engine.h"
#include "svg_scene.h"
#include "png_scene.h"
#include <QTime>
#include <QDate>
#include <QSettings>
#include "attackeffects.h"

namespace Ui {
class ConfigrationWindow;
}

class ConfigrationWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ConfigrationWindow(QWidget *parent = 0);
    ~ConfigrationWindow();
    
private:
    Ui::ConfigrationWindow *ui;

protected:

public slots:

    void on_refresh_clicked();

    void on_SaveXML_clicked();

    void changeCurrentAnimationTime(int newTimeValue);

    void loadXML();

    bool checkAnimationValues();

    void super_attack_checked_states_changed(bool isChecked);

    void after_effect_selection_changed();

    void before_effect_selection_changed();

    void list_element_changed();

    void submitPrevChanges();


private slots:
    void on_runAnimationButton_clicked();

    void on_stopAnimationButton_clicked();

    void on_AddBeforeEffectpushButton_clicked();

    void on_RemoveBeforeEffectpushButton_clicked();

    void on_AddAfterEffectpushButton_clicked();

    void on_RemoveAfterEffectpushButton_clicked();

protected:
    void keyPressEvent(QKeyEvent *);

private:
    svg_scene* svgScene;
    void createPartsForms();
    QPoint offset;

    attackEffects* before;
    attackEffects* after;
    attackEffects* current_selected;
    QListWidget* current_selected_list;
    int currentElementID;

    void super_attack_enabler(bool isSuper);

    bool superAttack;
    bool moving;
    bool svgSceneSelected;
};

#endif // CONFIGRATIONWINDOW_H
