#ifndef HUMAN_CHAR_ARROW_H
#define HUMAN_CHAR_ARROW_H

#include "game_engine.h"
#include <QDomDocument>
#include "global_keys.h"
#include "character_base.h"

#define flashingSpeed 200
#define W_OUT_CIRCLE_GLOW false
#define end_y_offset 250*screenScale
#define end_x_offset 400*screenScale
//#define debugGlowingArmor
/*
  This class, is a layer that holds the arrow, when selecting a player, this arrow should then point to where the user is pointing to
*/

struct glowing {
    Node* glowing_node;
    bool increasing;
};

class human_char_arrow : public Layer
{

    Q_OBJECT

public:
    human_char_arrow(float margine_top,QString pointer_file);
    ~human_char_arrow();
    void attachToChar(character_base* toBeAttachedTo);
    void pointToChar(character_base* toBeAttachedTo);
    void removePointedChar(bool circule = false);
    void setStart(float x,float y);
    void setEnd(float x,float y);
    void setEndUpdate(float x,float y);
    void hideArrow(bool move);
    void showArrow();
    void startFlashing();
    void stopFlashing();
    static QPointF topLeft;
    static QPointF bottomRight;

    //this, will make the line follow the pointed char
    character_base* attachedChar;
    character_base* pointedChar;
    float margine_top_local;
    QPointF armor_c_pos();
    void setIgnoreZ(bool ignore = true);
//    QMutex changeGlowMutex;

public slots:
    void attachedCharPosChanges();
    void pointedCharPosChanges();
    void update(double delta);
    void start_bounce_effect();
    void start_circle_effect();
    void start_teleport_effect();
    void glow_in_white(bool circle_glow = true);
    void glow_in_red();

    void start_red_teleport();
    void start_red_teleport_2();


private:

    Sprite* armor;
    Sprite* armor_w_1;
    Sprite* armor_w_2;
    Sprite* armor_w_1_node;
    Sprite* armor_w_2_node;
    Sprite* armor_r_1;
    Sprite* armor_r_2;
    Sprite* armor_r_1_node;
    Sprite* armor_r_2_node;
    bool first_is_first;
    bool first_is_first_red;

    Sprite* armor_c;
    Sprite* armor_c_white;
    Sprite* armor_c_red;
    //boundries points

    QList <glowing*> glowing_elements;
    QList <Node*> nodes_synced_w_armor;

    void add_glowing_element(Node* node_to_glow);
    void remove_glowing_element(Node* node_to_unglow);

    void swap_sprites();
    void swap_red_sprites();

    bool white_glowing;
    bool ignoreZLevel;

};

#endif // HUMAN_CHAR_ARROW_H
