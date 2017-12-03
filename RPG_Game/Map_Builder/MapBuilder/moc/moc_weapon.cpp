/****************************************************************************
** Meta object code from reading C++ file 'weapon.h'
**
** Created: Fri Nov 16 17:46:40 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../weapon/weapon.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weapon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_weapon[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   26,    7,    7, 0x0a,
      47,    7,    7,    7, 0x0a,
     115,   66,    7,    7, 0x0a,
     166,    7,    7,    7, 0x0a,
     206,    7,  194,    7, 0x0a,
     236,    7,    7,    7, 0x0a,
     259,    7,    7,    7, 0x0a,
     282,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_weapon[] = {
    "weapon\0\0effect_finished()\0delta\0"
    "update(double)\0startAfterEffect()\0"
    "enemyX,enemyY,enemyDirection,myX,myY,myDirection\0"
    "startBeforeEffect(float,float,int,float,float,int)\0"
    "start_super_attack_effect()\0s_attk_obj*\0"
    "get_new_super_attack_object()\0"
    "effect_finished_slot()\0disable_super_button()\0"
    "enable_super_button()\0"
};

const QMetaObject weapon::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_weapon,
      qt_meta_data_weapon, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &weapon::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *weapon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *weapon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_weapon))
        return static_cast<void*>(const_cast< weapon*>(this));
    return Layer::qt_metacast(_clname);
}

int weapon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: effect_finished(); break;
        case 1: update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: startAfterEffect(); break;
        case 3: startBeforeEffect((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 4: start_super_attack_effect(); break;
        case 5: { s_attk_obj* _r = get_new_super_attack_object();
            if (_a[0]) *reinterpret_cast< s_attk_obj**>(_a[0]) = _r; }  break;
        case 6: effect_finished_slot(); break;
        case 7: disable_super_button(); break;
        case 8: enable_super_button(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void weapon::effect_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
