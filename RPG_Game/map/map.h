#ifndef MAP_H
#define MAP_H

#include "moving_character.h"
#include "under_char_elips.h"
#include "human_char_arrow.h"
#include "game_controller.h"
#include "shared_storage.h"
#include "human_char_controller.h"
#include "enemy_char_controller.h"
#include <QLineF>
#include "home.h"
#include "quest_logic.h"
#include "win_message.h"

#define x_offset_collision 30
#define y_offset_collision 5
//comment the below to hide the file xml name from being shown
#define display_map_xml_name
#define x_offset_player_battle 200

#define shaking_speed 0.05
#define shaking_distance 30

/*
  This class is disigned to hold human controlled characters, and take touch input as needed, perform the needed steps on that character
*/
struct element {
    QString name;
    QString type;
    Node* elementSprite;
    QString toXML;
};

class map : public Layer
{
    Q_OBJECT

public:
    map();
    //adds a character child, and returns it as a pointer
    character_base* addCharacterFromXML(QString xml_file_name);
    //under character, attach it to selected characters, with call attach methode
//    under_char_elips* elips;
    //used to attache to it a character, and it's end is moved depnding on user finger position
//    human_char_arrow* arrow;

    void load_from_xml(QString xml_file_name);

    static Scene* scene(QString xmlFile);
    QString mapName;

    QList <element> allmapElementsList;
    QList <element> everySinglemapElementsList;

    QList <character_base*> enemies;

    // 2 super attack menus
    Layer* top_battle_mode_layer;
    Layer* bottom_battle_mode_layer;
    Menu* first_p_super_buttons;
    Menu* second_p_super_buttons;
    Layer* armorLayer;
    float screenScale;

    QList <character_base*> players;

    MenuItemImage* dashboard_quest;

    //this is to be filled
    float total_xp_gained;
    float total_silver_gained;
    QTime total_match_time;

    void send_bonus(int gold,int xp);

    human_char_controller* humanLayer;

public slots:
    virtual void touchBegin(QGraphicsSceneMouseEvent *event);
    virtual void touchMove(QGraphicsSceneMouseEvent *event);
    virtual void touchEnd(QGraphicsSceneMouseEvent *event);
    virtual void onEnterTransitionDidFinish();
    void character_collided_map_element();
    void do_element_action();
    void start_battle_effect();
    void start_battle_effect_2();
    void start_battle_effect_3();
    void lock_map();
    void unclock_map();
    void unclock_map_2();
    void load_battle_mode_layers();
    void move_players_to_battle_pos();

    void start_shaking_screen();
    void shake_screen_1();
    void shake_screen_2();
    void shake_screen_3();

    void exit_from_shop();
    void exit_from_shop_2();
    void exit_from_home();
    void exit_from_home_2();


    void refreshMainCharacter();

    void on_red_poition_clicked();
    void on_red_jewel_clicked();
    void reset_line_z_level();

    void on_dashboard_quest_button_clicked();

    void refreshDashBoard();
    void refreshQuestPop();

    void openMapDoor();

    void startLostGameOver();

    void returnToLastCheckPoint();

    void enable_battle_mood_buttons();
    void disable_battle_mood_buttons();



private:
    void fillTempWithElements(float x, bool left,float y, bool down);
    QTime clickTimer;
    QPointF startTouchPos;
    int startCharacterSelectedIndex;
    bool arrowAttached;
    QList <element> mapElementsList;
    QList <Node*> mapElementsSprtiesTemp;
    QList <Node*> mapElementsSprtiesTemp2;
    QList <QPointF> characterMovementPoints;
//    lineNode* line;
    Sprite* line;
    int selectedElementID;
    bool collidesWith();
    QPointF touchPos;
    QPointF getRightPoint(Node* anyMapElement);
    QPointF getleftPoint(Node* anyMapElement);
    Sprite* armorRight;
    Sprite* armorLeft;
    Sprite* armorGlow;
    Sprite* WeaponLeft;
    Sprite* WeaponRight;
    static QPointF enterPoint;
    bool moved_players_to_correct_pos;
    bool moved_enemy_to_correct_pos;

    int opacity_night_level;

    shop* current_shop_pointer;
    home* current_home_pointer;

    numbers* red_poition_count;
    numbers* red_jewel_count;
    numbers* gold_count;
    numbers* silver_count;

    Sprite* quest_button_shadow;
    Sprite* quest_pop_sprite;
    Layer* quest_pop_layer;
    Layer* keys_layer;


    bool quest_button_open;

    Sprite* closing_door;
    Sprite* closing_door_lost;
    Sprite* sun_moon;
    int clockRotation;

    bool gameOver;

    MenuItemImage* red_potion_button;
    MenuItemImage* red_jewel_button;

    static bool coming_from_game_over;

    int last_character_level;

    Sprite* dashBoard;

    character_base* ghost_character;

};

#endif // MAP_H
