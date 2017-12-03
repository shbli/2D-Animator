/****************************************************************************
** Meta object code from reading C++ file 'health_animation.h'
**
** Created: Fri Nov 16 17:46:49 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../health_bar/health_animation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'health_animation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_health_animation[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_health_animation[] = {
    "health_animation\0\0deleteSelf()\0"
};

const QMetaObject health_animation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_health_animation,
      qt_meta_data_health_animation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &health_animation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *health_animation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *health_animation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_health_animation))
        return static_cast<void*>(const_cast< health_animation*>(this));
    return QObject::qt_metacast(_clname);
}

int health_animation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: deleteSelf(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
