#ifndef CHARACTER_BASE_H
#define CHARACTER_BASE_H

#include "game_engine.h"
#include "global_keys.h"
#include "skeltal_joint.h"
#include "weapon.h"
#include <QDomDocument>
#include "health_bar.h"
#include "game_controller.h"
#include "die_effect.h"

//this is the z, where the character is at the bottom
#define startZ 100000
#define attacking_horizontal_distance (100*character_base::screenScale)
#define attacking_horizontal_corner_spacing (20*character_base::screenScale)
#define attacking_vertical_distance (70*character_base::screenScale)
#define waitUntilNextDamagedAnimationTime 0.5*1000
#define DONT_SAVE_PREV false
#define die_red_numbers_scale 0.8
#define die_red_numbers_y_offset 80
#define decreaseHealLevelFix 4.0
//#define DEBUG_ATTACKING_POINTS

class skeltal_joint;
class die_and_join_effect;
class human_char_arrow;

struct attacking_point {
    QPointF point;
    bool left;
    bool occupied;
    character_base* occupied_by;
};

class character_base : public Layer
{
    Q_OBJECT

public:

    //if set to true, check for movement will be based on distance only
    bool check_type_by_distance;

    static float screenScale;
    ~character_base();
    //human readable skeltal part name
    QString character_name;
    QString character_type;
    QString weapon_xml;
    skeltal_joint* rootJoint;
#ifdef characterbuilder
    void load_from_xml(QString xml_file_name, skeltal_hbox* root = 0);
#else
    void load_from_xml(QString xml_file_name);
#endif
    void setAnimationType(QString animationType, bool savePre = true);
    void set_animtion_at_point(QString animationType, float key_point);
    int currentAnimationIndex;
    bool tryingtochangeanimation;
    float below_char_elements_y_offset;
    float character_speed;
    QPointF moveToPoint;
    QPointF speedPoint;
    void moveto(float x, float y);
    weapon* mainWeapon;
    weapon* super_attack_weapon;
    weapon* super_attack_effect_weapon;
    weapon* super_attack_effect_character;
    character_base* aimToAtttackChar;
    character_base* super_aimToAtttackChar_weapon;
    character_base* super_aimToAtttackChar_character;
    health_bar* myHealthBar;
    float currentAnimationTime;
    float myLevel;
    float maxHealth;
    QList <int> hateValues;
    QList <attacking_point*> attackingPoints;
    QTimer* chtimer;
    QTime chdelta;
    QString currentAnimationName;
    QString prevAnimationName;
    QString player_xml_file;
    //this value is set before loading the xml file, withing the controller
    bool computer_player;

    void resetPointedToEnemy();
    void restorePrevAnimation();
    bool isDead();
    human_char_arrow* armor;
    float local_speed;
    int char_id;
    QMutex nearest_point_mutex;
#ifdef characterbuilder
    friend class svg_scene;
#endif
    QString pointer_file_name;


    //the point am attacked to
    attacking_point* enemy_attacking_point;



public slots:
    //this function get called only for teesting puposes
//    void setCurrentAnimationTime(double currentTime);
    void runAnimation();
    void stopAnimation();
    void update(double delta);
    void chUpdate();
    void walkingAnimationMover(double delta);
    void check_move_up_right();
    void check_move_up_left();
    void check_move_down_right();
    void check_move_down_left();
    void startBreathing();
    void aim_to_char(character_base* character, bool attacking_point_skip = false);
    void startEnemeyIntleegince();
    void decreaseHealthBy(float value, character_base* fromCharacter);
    void increaseHealthBy(float value);
    void selectMaxHatedCharacter();
    void damagedOneRoundDone();
    void setAnimateWhenAttacked();
    void removeConnectionFromPlayer(character_base* fromCharacter);
    void enterStage();
    void dieAnimationDone();
    attacking_point* get_nearest_free_point(character_base* requester);

    //super attack methodes
    void run_all_queued_supers();

    void q_char_super();
    void q_weapon_super();

    void start_char_super();
    void start_weapon_super();

    void start_char_super_2();
    void start_weapon_super_2();

    void finish_char_super();
    void finish_weapon_super();


    void decrease_hp_char_super();
    void decrease_hp_weapon_super();

    bool run_queded_super_attacks();

    void freeze_character();
    void un_freeze_character();

    void slow_down_character();
    void un_slow_down_character();

    void re_point_to_same();

    void resetPlayerHealth();

    void resetPlayerSuper();


signals:
    void stepChildsAnimation(double delta);
    void signal_check_move_done();
    void one_animation_round_done();
    void aim_to_char_signal(character_base* character);
    void animationChaned();
    void moveDone();
    void character_close_to_attack();


private:
    bool animationRunning;
    bool animatedWhenAttaqcked;
    bool Super_Attacking;
    die_and_join_effect* dieEffect;
    bool alreadyDead;
    void super_attack_lock();
    void super_attack_release();
    int super_character_q;
    int super_weapon_q;

    attacking_point attacking_right_point;
    attacking_point attacking_right_top_point;
    attacking_point attacking_right_bottom_point;

    attacking_point attacking_left_point;
    attacking_point attacking_left_top_point;
    attacking_point attacking_left_bottom_point;

    int number_of_freezes;
    int number_of_slow_downs;

    void characterLeveledUp();

protected:

    bool charaacter_close_to_attack;
    float walking_speed;
};

#endif // CHARACTER_BASE_H
