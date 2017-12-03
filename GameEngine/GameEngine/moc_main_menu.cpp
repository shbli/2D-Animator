/****************************************************************************
** Meta object code from reading C++ file 'main_menu.h'
**
** Created: Thu Feb 9 19:14:14 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_menu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_main_menu[] = {

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
      17,   11,   10,   10, 0x0a,
      32,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_main_menu[] = {
    "main_menu\0\0delta\0update(double)\0"
    "animation()\0"
};

void main_menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        main_menu *_t = static_cast<main_menu *>(_o);
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->animation(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData main_menu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject main_menu::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_main_menu,
      qt_meta_data_main_menu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &main_menu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *main_menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *main_menu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_main_menu))
        return static_cast<void*>(const_cast< main_menu*>(this));
    return Layer::qt_metacast(_clname);
}

int main_menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
