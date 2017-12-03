/****************************************************************************
** Meta object code from reading C++ file 'under_char_elips.h'
**
** Created: Thu Jun 14 21:21:36 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../game_controller/under_char_elips.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'under_char_elips.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_under_char_elips[] = {

 // content:
       6,       // revision
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

void under_char_elips::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        under_char_elips *_t = static_cast<under_char_elips *>(_o);
        switch (_id) {
        case 0: _t->attachedCharPosChanges(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData under_char_elips::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject under_char_elips::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_under_char_elips,
      qt_meta_data_under_char_elips, &staticMetaObjectExtraData }
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
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
