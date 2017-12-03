/****************************************************************************
** Meta object code from reading C++ file 'weapon.h'
**
** Created: Thu Jun 14 21:21:24 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../weapon/weapon.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weapon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_weapon[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,    8,    7,    7, 0x0a,
      58,   29,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_weapon[] = {
    "weapon\0\0delta\0update(double)\0"
    "enemyX,enemyY,enemyDirection\0"
    "startAfterEffect(float,float,int)\0"
};

void weapon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        weapon *_t = static_cast<weapon *>(_o);
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->startAfterEffect((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData weapon::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject weapon::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_weapon,
      qt_meta_data_weapon, &staticMetaObjectExtraData }
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
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
