/****************************************************************************
** Meta object code from reading C++ file 'under_char_elips.h'
**
** Created: Fri Nov 16 17:47:06 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../game_controller/under_char_elips.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'under_char_elips.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_under_char_elips[] = {

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

static const char qt_meta_stringdata_under_char_elips[] = {
    "under_char_elips\0\0attachedCharPosChanges()\0"
};

const QMetaObject under_char_elips::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_under_char_elips,
      qt_meta_data_under_char_elips, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &under_char_elips::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *under_char_elips::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *under_char_elips::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_under_char_elips))
        return static_cast<void*>(const_cast< under_char_elips*>(this));
    return Layer::qt_metacast(_clname);
}

int under_char_elips::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: attachedCharPosChanges(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
