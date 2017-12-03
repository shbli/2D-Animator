#ifndef QUEST_LOGIC_H
#define QUEST_LOGIC_H

#include "game_engine.h"
#include "QDomDocument"



class numbers;

class quest_logic : public Layer
{
    Q_OBJECT

public:
    quest_logic(Node* quest_parent,QString quest_key_svg,QString reward_type,QString reward,QString dropSVG = "",QString mapXML = "",QString elementName = "");
public slots:
    void on_quest_button_clicked();
    void on_accept_button_clicked();
    void on_declilned_button_clicked();
    void on_accept_button_hide();

private:
    MenuItemImage* explenation_mark;
    MenuItemImage* accept_button;
    MenuItemImage* decline_button;
    static QString get_super_svg_file_name(QString super_file_name);
    static QString get_super_svg_file_name_from_weapon(QString super_file_name);
    bool isKeyAvailable;
    Sprite* key;
    QPointF keyPos;
    QPointF questDashPos;
    float hScreenScale;
    bool isDropElement;
    QString quest_key_string;
    QString reward_type_string;
    QString reward_string;
    QString map_xml_file_name;
    QString element_name;
    bool ok_to_grab();
    Sprite* reward_sprite;
    numbers* reward_number_layer;
    Sprite* dashboard_bag;

};

#endif // QUEST_LOGIC_H
