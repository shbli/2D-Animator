/****************************************************************************
** Meta object code from reading C++ file 'game_controller.h'
**
** Created: Fri Nov 16 17:46:53 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../game_controller/game_controller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_game_controller[] = {

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

static const char qt_meta_stringdata_game_controller[] = {
    "game_controller\0"
};

const QMetaObject game_controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_game_controller,
      qt_meta_data_game_controller, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &game_controller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *game_controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *game_controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_game_controller))
        return static_cast<void*>(const_cast< game_controller*>(this));
    return QObject::qt_metacast(_clname);
}

int game_controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
