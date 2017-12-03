/****************************************************************************
** Meta object code from reading C++ file 'character_base.h'
**
** Created: Thu Jun 14 21:21:15 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../character/character_base.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'character_base.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_character_base[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x05,
      50,   15,   15,   15, 0x05,
      75,   15,   15,   15, 0x05,
     112,  102,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     160,  148,   15,   15, 0x0a,
     192,   15,   15,   15, 0x0a,
     207,   15,   15,   15, 0x0a,
     223,   16,   15,   15, 0x0a,
     238,   15,   15,   15, 0x0a,
     249,   16,   15,   15, 0x0a,
     279,   15,   15,   15, 0x0a,
     301,   15,   15,   15, 0x0a,
     322,   15,   15,   15, 0x0a,
     346,   15,   15,   15, 0x0a,
     369,   15,   15,   15, 0x0a,
     386,  102,   15,   15, 0x0a,
     415,   15,   15,   15, 0x0a,
     460,  440,   15,   15, 0x0a,
     506,  500,   15,   15, 0x0a,
     530,   15,   15,   15, 0x0a,
     556,   15,   15,   15, 0x0a,
     578,   15,   15,   15, 0x0a,
     617,  603,   15,   15, 0x0a,
     661,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_character_base[] = {
    "character_base\0\0delta\0stepChildsAnimation(double)\0"
    "signal_check_move_done()\0"
    "one_animation_round_done()\0character\0"
    "aim_to_char_signal(character_base*)\0"
    "currentTime\0setCurrentAnimationTime(double)\0"
    "runAnimation()\0stopAnimation()\0"
    "update(double)\0chUpdate()\0"
    "walkingAnimationMover(double)\0"
    "check_move_up_right()\0check_move_up_left()\0"
    "check_move_down_right()\0check_move_down_left()\0"
    "startBreathing()\0aim_to_char(character_base*)\0"
    "startEnemeyIntleegince()\0value,fromCharacter\0"
    "decreaseHealthBy(float,character_base*)\0"
    "value\0increaseHealthBy(float)\0"
    "selectMaxHatedCharacter()\0"
    "damagedOneRoundDone()\0setAnimateWhenAttacked()\0"
    "fromCharacter\0removeConnectionFromPlayer(character_base*)\0"
    "enterStage()\0"
};

void character_base::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        character_base *_t = static_cast<character_base *>(_o);
        switch (_id) {
        case 0: _t->stepChildsAnimation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->signal_check_move_done(); break;
        case 2: _t->one_animation_round_done(); break;
        case 3: _t->aim_to_char_signal((*reinterpret_cast< character_base*(*)>(_a[1]))); break;
        case 4: _t->setCurrentAnimationTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->runAnimation(); break;
        case 6: _t->stopAnimation(); break;
        case 7: _t->update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->chUpdate(); break;
        case 9: _t->walkingAnimationMover((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->check_move_up_right(); break;
        case 11: _t->check_move_up_left(); break;
        case 12: _t->check_move_down_right(); break;
        case 13: _t->check_move_down_left(); break;
        case 14: _t->startBreathing(); break;
        case 15: _t->aim_to_char((*reinterpret_cast< character_base*(*)>(_a[1]))); break;
        case 16: _t->startEnemeyIntleegince(); break;
        case 17: _t->decreaseHealthBy((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< character_base*(*)>(_a[2]))); break;
        case 18: _t->increaseHealthBy((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 19: _t->selectMaxHatedCharacter(); break;
        case 20: _t->damagedOneRoundDone(); break;
        case 21: _t->setAnimateWhenAttacked(); break;
        case 22: _t->removeConnectionFromPlayer((*reinterpret_cast< character_base*(*)>(_a[1]))); break;
        case 23: _t->enterStage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData character_base::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject character_base::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_character_base,
      qt_meta_data_character_base, &staticMetaObjectExtraData }
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
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
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
QT_END_MOC_NAMESPACE
