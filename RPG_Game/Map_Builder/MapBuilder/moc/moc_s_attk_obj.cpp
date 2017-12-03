/****************************************************************************
** Meta object code from reading C++ file 's_attk_obj.h'
**
** Created: Fri Nov 16 17:46:47 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../weapon/s_attk_obj.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 's_attk_obj.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_s_attk_obj[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   12,   11,   11, 0x0a,
      57,   11,   11,   11, 0x0a,
      91,   11,   11,   11, 0x0a,
     105,   11,   11,   11, 0x0a,
     117,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_s_attk_obj[] = {
    "s_attk_obj\0\0from_character\0"
    "start_effect(character_base*)\0"
    "end_effect_if_nothing_remaining()\0"
    "decrease_hp()\0slow_down()\0freeze()\0"
};

const QMetaObject s_attk_obj::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_s_attk_obj,
      qt_meta_data_s_attk_obj, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &s_attk_obj::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *s_attk_obj::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *s_attk_obj::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_s_attk_obj))
        return static_cast<void*>(const_cast< s_attk_obj*>(this));
    return QObject::qt_metacast(_clname);
}

int s_attk_obj::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: start_effect((*reinterpret_cast< character_base*(*)>(_a[1]))); break;
        case 1: end_effect_if_nothing_remaining(); break;
        case 2: decrease_hp(); break;
        case 3: slow_down(); break;
        case 4: freeze(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
