/****************************************************************************
** Meta object code from reading C++ file 'character_base.h'
**
** Created: Fri Nov 16 17:46:27 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../character/character_base.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'character_base.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_character_base[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x05,
      50,   15,   15,   15, 0x05,
      75,   15,   15,   15, 0x05,
     112,  102,   15,   15, 0x05,
     148,   15,   15,   15, 0x05,
     166,   15,   15,   15, 0x05,
     177,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     205,   15,   15,   15, 0x0a,
     220,   15,   15,   15, 0x0a,
     236,   16,   15,   15, 0x0a,
     251,   15,   15,   15, 0x0a,
     262,   16,   15,   15, 0x0a,
     292,   15,   15,   15, 0x0a,
     314,   15,   15,   15, 0x0a,
     335,   15,   15,   15, 0x0a,
     359,   15,   15,   15, 0x0a,
     382,   15,   15,   15, 0x0a,
     430,  399,   15,   15, 0x0a,
     464,  102,   15,   15, 0x2a,
     493,   15,   15,   15, 0x0a,
     538,  518,   15,   15, 0x0a,
     584,  578,   15,   15, 0x0a,
     608,   15,   15,   15, 0x0a,
     634,   15,   15,   15, 0x0a,
     656,   15,   15,   15, 0x0a,
     695,  681,   15,   15, 0x0a,
     739,   15,   15,   15, 0x0a,
     752,   15,   15,   15, 0x0a,
     806,  788,  771,   15, 0x0a,
     854,   15,   15,   15, 0x0a,
     878,   15,   15,   15, 0x0a,
     893,   15,   15,   15, 0x0a,
     910,   15,   15,   15, 0x0a,
     929,   15,   15,   15, 0x0a,
     950,   15,   15,   15, 0x0a,
     971,   15,   15,   15, 0x0a,
     994,   15,   15,   15, 0x0a,
    1014,   15,   15,   15, 0x0a,
    1041,   15, 1036,   15, 0x0a,
    1068,   15,   15,   15, 0x0a,
    1087,   15,   15,   15, 0x0a,
    1109,   15,   15,   15, 0x0a,
    1131,   15,   15,   15, 0x0a,
    1156,   15,   15,   15, 0x0a,
    1175,   15,   15,   15, 0x0a,
    1195,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_character_base[] = {
    "character_base\0\0delta\0stepChildsAnimation(double)\0"
    "signal_check_move_done()\0"
    "one_animation_round_done()\0character\0"
    "aim_to_char_signal(character_base*)\0"
    "animationChaned()\0moveDone()\0"
    "character_close_to_attack()\0runAnimation()\0"
    "stopAnimation()\0update(double)\0"
    "chUpdate()\0walkingAnimationMover(double)\0"
    "check_move_up_right()\0check_move_up_left()\0"
    "check_move_down_right()\0check_move_down_left()\0"
    "startBreathing()\0character,attacking_point_skip\0"
    "aim_to_char(character_base*,bool)\0"
    "aim_to_char(character_base*)\0"
    "startEnemeyIntleegince()\0value,fromCharacter\0"
    "decreaseHealthBy(float,character_base*)\0"
    "value\0increaseHealthBy(float)\0"
    "selectMaxHatedCharacter()\0"
    "damagedOneRoundDone()\0setAnimateWhenAttacked()\0"
    "fromCharacter\0removeConnectionFromPlayer(character_base*)\0"
    "enterStage()\0dieAnimationDone()\0"
    "attacking_point*\0myPoint,requester\0"
    "get_nearest_free_point(QPointF,character_base*)\0"
    "run_all_queued_supers()\0q_char_super()\0"
    "q_weapon_super()\0start_char_super()\0"
    "start_weapon_super()\0start_char_super_2()\0"
    "start_weapon_super_2()\0finish_char_super()\0"
    "finish_weapon_super()\0bool\0"
    "run_queded_super_attacks()\0"
    "freeze_character()\0un_freeze_character()\0"
    "slow_down_character()\0un_slow_down_character()\0"
    "re_point_to_same()\0resetPlayerHealth()\0"
    "resetPlayerSuper()\0"
};

const QMetaObject character_base::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_character_base,
      qt_meta_data_character_base, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &character_base::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *character_base::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *character_base::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_character_base))
        return static_cast<void*>(const_cast< character_base*>(this));
    return Layer::qt_metacast(_clname);
}

int character_base::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: stepChildsAnimation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: signal_check_move_done(); break;
        case 2: one_animation_round_done(); break;
        case 3: aim_to_char_signal((*reinterpret_cast< character_base*(*)>(_a[1]))); break;
        case 4: animationChaned(); break;
        case 5: moveDone(); break;
        case 6: character_close_to_attack(); break;
        case 7: runAnimation(); break;
        case 8: stopAnimation(); break;
        case 9: update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: chUpdate(); break;
        case 11: walkingAnimationMover((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: check_move_up_right(); break;
        case 13: check_move_up_left(); break;
        case 14: check_move_down_right(); break;
        case 15: check_move_down_left(); break;
        case 16: startBreathing(); break;
        case 17: aim_to_char((*reinterpret_cast< character_base*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: aim_to_char((*reinterpret_cast< character_base*(*)>(_a[1]))); break;
        case 19: startEnemeyIntleegince(); break;
        case 20: decreaseHealthBy((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< character_base*(*)>(_a[2]))); break;
        case 21: increaseHealthBy((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 22: selectMaxHatedCharacter(); break;
        case 23: damagedOneRoundDone(); break;
        case 24: setAnimateWhenAttacked(); break;
        case 25: removeConnectionFromPlayer((*reinterpret_cast< character_base*(*)>(_a[1]))); break;
        case 26: enterStage(); break;
        case 27: dieAnimationDone(); break;
        case 28: { attacking_point* _r = get_nearest_free_point((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< character_base*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< attacking_point**>(_a[0]) = _r; }  break;
        case 29: run_all_queued_supers(); break;
        case 30: q_char_super(); break;
        case 31: q_weapon_super(); break;
        case 32: start_char_super(); break;
        case 33: start_weapon_super(); break;
        case 34: start_char_super_2(); break;
        case 35: start_weapon_super_2(); break;
        case 36: finish_char_super(); break;
        case 37: finish_weapon_super(); break;
        case 38: { bool _r = run_queded_super_attacks();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 39: freeze_character(); break;
        case 40: un_freeze_character(); break;
        case 41: slow_down_character(); break;
        case 42: un_slow_down_character(); break;
        case 43: re_point_to_same(); break;
        case 44: resetPlayerHealth(); break;
        case 45: resetPlayerSuper(); break;
        default: ;
        }
        _id -= 46;
    }
    return _id;
}

// SIGNAL 0
void character_base::stepChildsAnimation(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void character_base::signal_check_move_done()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void character_base::one_animation_round_done()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void character_base::aim_to_char_signal(character_base * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void character_base::animationChaned()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void character_base::moveDone()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void character_base::character_close_to_attack()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
