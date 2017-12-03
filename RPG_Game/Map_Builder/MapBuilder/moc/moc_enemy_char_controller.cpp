/****************************************************************************
** Meta object code from reading C++ file 'enemy_char_controller.h'
**
** Created: Fri Nov 16 17:47:14 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../game_controller/enemy_char_controller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enemy_char_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_enemy_char_controller[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_enemy_char_controller[] = {
    "enemy_char_controller\0"
};

const QMetaObject enemy_char_controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_enemy_char_controller,
      qt_meta_data_enemy_char_controller, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &enemy_char_controller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *enemy_char_controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *enemy_char_controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_enemy_char_controller))
        return static_cast<void*>(const_cast< enemy_char_controller*>(this));
    return QObject::qt_metacast(_clname);
}

int enemy_char_controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
