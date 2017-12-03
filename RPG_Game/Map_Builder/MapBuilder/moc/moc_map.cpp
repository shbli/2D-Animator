/****************************************************************************
** Meta object code from reading C++ file 'map.h'
**
** Created: Fri Nov 16 17:47:19 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../map/map.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_map[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,    5,    4,    4, 0x0a,
      49,    5,    4,    4, 0x0a,
      86,    5,    4,    4, 0x0a,
     122,    4,    4,    4, 0x0a,
     151,    4,    4,    4, 0x0a,
     184,    4,    4,    4, 0x0a,
     204,    4,    4,    4, 0x0a,
     226,    4,    4,    4, 0x0a,
     250,    4,    4,    4, 0x0a,
     274,    4,    4,    4, 0x0a,
     285,    4,    4,    4, 0x0a,
     299,    4,    4,    4, 0x0a,
     315,    4,    4,    4, 0x0a,
     341,    4,    4,    4, 0x0a,
     370,    4,    4,    4, 0x0a,
     393,    4,    4,    4, 0x0a,
     410,    4,    4,    4, 0x0a,
     427,    4,    4,    4, 0x0a,
     444,    4,    4,    4, 0x0a,
     461,    4,    4,    4, 0x0a,
     480,    4,    4,    4, 0x0a,
     497,    4,    4,    4, 0x0a,
     516,    4,    4,    4, 0x0a,
     539,    4,    4,    4, 0x0a,
     564,    4,    4,    4, 0x0a,
     587,    4,    4,    4, 0x0a,
     608,    4,    4,    4, 0x0a,
     644,    4,    4,    4, 0x0a,
     663,    4,    4,    4, 0x0a,
     681,    4,    4,    4, 0x0a,
     695,    4,    4,    4, 0x0a,
     715,    4,    4,    4, 0x0a,
     740,    4,    4,    4, 0x0a,
     769,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_map[] = {
    "map\0\0event\0touchBegin(QGraphicsSceneMouseEvent*)\0"
    "touchMove(QGraphicsSceneMouseEvent*)\0"
    "touchEnd(QGraphicsSceneMouseEvent*)\0"
    "onEnterTransitionDidFinish()\0"
    "character_collided_map_element()\0"
    "do_element_action()\0start_battle_effect()\0"
    "start_battle_effect_2()\0start_battle_effect_3()\0"
    "lock_map()\0unclock_map()\0unclock_map_2()\0"
    "load_battle_mode_layers()\0"
    "move_players_to_battle_pos()\0"
    "start_shaking_screen()\0shake_screen_1()\0"
    "shake_screen_2()\0shake_screen_3()\0"
    "exit_from_shop()\0exit_from_shop_2()\0"
    "exit_from_home()\0exit_from_home_2()\0"
    "refreshMainCharacter()\0on_red_poition_clicked()\0"
    "on_red_jewel_clicked()\0reset_line_z_level()\0"
    "on_dashboard_quest_button_clicked()\0"
    "refreshDashBoard()\0refreshQuestPop()\0"
    "openMapDoor()\0startLostGameOver()\0"
    "returnToLastCheckPoint()\0"
    "enable_battle_mood_buttons()\0"
    "disable_battle_mood_buttons()\0"
};

const QMetaObject map::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_map,
      qt_meta_data_map, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &map::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *map::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *map::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_map))
        return static_cast<void*>(const_cast< map*>(this));
    return Layer::qt_metacast(_clname);
}

int map::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: touchBegin((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 1: touchMove((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 2: touchEnd((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 3: onEnterTransitionDidFinish(); break;
        case 4: character_collided_map_element(); break;
        case 5: do_element_action(); break;
        case 6: start_battle_effect(); break;
        case 7: start_battle_effect_2(); break;
        case 8: start_battle_effect_3(); break;
        case 9: lock_map(); break;
        case 10: unclock_map(); break;
        case 11: unclock_map_2(); break;
        case 12: load_battle_mode_layers(); break;
        case 13: move_players_to_battle_pos(); break;
        case 14: start_shaking_screen(); break;
        case 15: shake_screen_1(); break;
        case 16: shake_screen_2(); break;
        case 17: shake_screen_3(); break;
        case 18: exit_from_shop(); break;
        case 19: exit_from_shop_2(); break;
        case 20: exit_from_home(); break;
        case 21: exit_from_home_2(); break;
        case 22: refreshMainCharacter(); break;
        case 23: on_red_poition_clicked(); break;
        case 24: on_red_jewel_clicked(); break;
        case 25: reset_line_z_level(); break;
        case 26: on_dashboard_quest_button_clicked(); break;
        case 27: refreshDashBoard(); break;
        case 28: refreshQuestPop(); break;
        case 29: openMapDoor(); break;
        case 30: startLostGameOver(); break;
        case 31: returnToLastCheckPoint(); break;
        case 32: enable_battle_mood_buttons(); break;
        case 33: disable_battle_mood_buttons(); break;
        default: ;
        }
        _id -= 34;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
