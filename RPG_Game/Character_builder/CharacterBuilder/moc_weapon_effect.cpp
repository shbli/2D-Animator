/****************************************************************************
** Meta object code from reading C++ file 'weapon_effect.h'
**
** Created: Thu Jun 14 21:21:27 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../weapon/weapon_effect.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weapon_effect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_weapon_effect[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   30,   14,   14, 0x0a,
      80,   14,   14,   14, 0x0a,
      94,   14,   14,   14, 0x0a,
     112,   14,   14,   14, 0x0a,
     129,   14,   14,   14, 0x0a,
     146,   14,   14,   14, 0x0a,
     162,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_weapon_effect[] = {
    "weapon_effect\0\0signalEffect()\0"
    "effectElement\0loadeffectsDomElement(QDomElement*)\0"
    "startEffect()\0runMOVAnimation()\0"
    "runSXAnimation()\0runSYAnimation()\0"
    "runRAnimation()\0runOAnimation()\0"
};

void weapon_effect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        weapon_effect *_t = static_cast<weapon_effect *>(_o);
        switch (_id) {
        case 0: _t->signalEffect(); break;
        case 1: _t->loadeffectsDomElement((*reinterpret_cast< QDomElement*(*)>(_a[1]))); break;
        case 2: _t->startEffect(); break;
        case 3: _t->runMOVAnimation(); break;
        case 4: _t->runSXAnimation(); break;
        case 5: _t->runSYAnimation(); break;
        case 6: _t->runRAnimation(); break;
        case 7: _t->runOAnimation(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData weapon_effect::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject weapon_effect::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_weapon_effect,
      qt_meta_data_weapon_effect, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &weapon_effect::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *weapon_effect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *weapon_effect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_weapon_effect))
        return static_cast<void*>(const_cast< weapon_effect*>(this));
    return Layer::qt_metacast(_clname);
}

int weapon_effect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void weapon_effect::signalEffect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
