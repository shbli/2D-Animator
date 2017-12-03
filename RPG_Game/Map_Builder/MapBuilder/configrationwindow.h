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
#include <QComboBox>

struct map_element {
    QString name;
    QString type;
    QString rewardType;
    QString key;
    QString elementSprite;
    QString toXML;
    int Z;
    float scale;
    float x;
    float y;
    float r;
    bool flipped;
};

struct enemey_element {
    int enemey_level;
    QString enemy_xml;
};

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
    QList <map_element> mapElements;
    QList <enemey_element> enemyElements;

private:
    Ui::ConfigrationWindow *ui;
    svg_scene* svgScene;
    void setUpElementTypesDropDown();

protected:

public slots:

    void on_refresh_clicked();

    void on_SaveXML_clicked();

    void loadXML();

    void submitPrevChanges();

    void submit_prev_enemy_changes();

    void enemy_list_changed();

    void listElementChanged();

    void on_rotation_element_changed(float chagedR);

    void on_position_element_changed(float changedX,float changedY);

private slots:

    void on_loadXMLpushButton_clicked();

    void on_AddElementpushButton_clicked();

    void on_DeleteElementPushButton_clicked();

    void on_ElementXDragDroppushButton_clicked();

    void on_ElementYDragDroppushButton_clicked();

    void on_ElementRotationDragDroppushButton_clicked();

    void print_all_elements(int elemtid = -1);


    void on_EnemycheckBox_toggled(bool checked);

    void on_EnemyAddpushButton_clicked();

    void on_EnemyDeletepushButton_clicked();

    void on_slowAnimationPushButton_clicked();

protected:

private:

    int currentElementID;
    int currentEnemyID;
    void clearElementProperties();

};

#endif // CONFIGRATIONWINDOW_H
