/****************************************************************************
** Meta object code from reading C++ file 'human_char_arrow.h'
**
** Created: Thu Jun 14 21:21:39 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../game_controller/human_char_arrow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'human_char_arrow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_human_char_arrow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      43,   17,   17,   17, 0x0a,
      73,   67,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_human_char_arrow[] = {
    "human_char_arrow\0\0attachedCharPosChanges()\0"
    "pointedCharPosChanges()\0delta\0"
    "update(double)\0"
};

void human_char_arrow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        human_char_arrow *_t = static_cast<human_char_arrow *>(_o);
        switch (_id) {
        case 0: _t->attachedCharPosChanges(); break;
        case 1: _t->pointedCharPosChanges(); break;
        case 2: _t->update((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData human_char_arrow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject human_char_arrow::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_human_char_arrow,
      qt_meta_data_human_char_arrow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &human_char_arrow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *human_char_arrow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *human_char_arrow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_human_char_arrow))
        return static_cast<void*>(const_cast< human_char_arrow*>(this));
    return Layer::qt_metacast(_clname);
}

int human_char_arrow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
