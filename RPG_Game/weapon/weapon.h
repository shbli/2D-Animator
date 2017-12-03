#ifndef WEAPON_H
#define WEAPON_H

#include "game_engine.h"
#include "global_keys.h"
#include <QDomDocument>
#include "weapon_effect.h"
#include "s_attk_obj.h"
#include "numbers.h"

#define super_button_resize 0.9
#define super_numbers_resize 0.4
#define effectsLayerZ 2000000

class weapon : public Layer
{
    Q_OBJECT

public:

    ~weapon();
    //human readable skeltal part name
    QString weapon_name;
    QString weapon_type;
    bool canFireFromFarAway;
    float weapon_power;
    Sprite* weaponSprite;
    float weaponSpeed_speed;
    QPointF moveToPoint;
    QPointF speedPoint;
    Layer* effectsLayer;
    QList <weapon_effect*> afterList;
    QList <weapon_effect*> beforeList;
    QString afterSound;
    QString beforeSound;
    bool superAttack;

    void load_from_xml(QString xml_file_name,Node* before_effects_parent,QObject* theConnection,const QString slot = 0);
    void moveto(float x, float y);

    //SUPER ATTACK PROPERTIES
    bool super_affects_all;
    bool super_decreases_hp;
    bool super_freezes_enemy;
    bool super_slow_down_enemies;
    bool super_provoke_enemies;
    bool super_shakes_screen;

    MenuItemImage* super_sprite_svg;
    Layer* disabled_layer_button;
    numbers* reset_time_numbers;
    Sprite* super_sprite_disabled_svg;
    int super_reset_seconds;
    float super_hp_reduction_value;
    float super_hp_reduction_value_timeout;
    float super_freeze_timeout;
    float super_slow_down_timeout;
    float super_shake_screen_timeout;
    //END OF SUPER ATTACK PROPERTIES

    float total_time_since_disabled;
    float number_scaling;


    float local_enemy_x;
    float local_enemy_y;
    int local_enemy_direction;
    //for a normal weapon
    weapon* super_attack_object;
    float maxTime;
    bool super_layer_added;

public slots:
    void update(double delta);
    // -1 if on opposite direction, 1 if on correct direction for enemyDirection variable
    void startAfterEffect();
    void startBeforeEffect(float enemyX,float enemyY,int enemyDirection,float myX,float myY, int myDirection);
    void start_super_attack_effect();
    s_attk_obj* get_new_super_attack_object();
    void effect_finished_slot();
    void disable_super_button();
    void enable_super_button();


signals:

    void effect_finished();
private:
    bool animationRunning;
};

#endif // WEAPON_H
