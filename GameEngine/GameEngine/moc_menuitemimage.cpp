/****************************************************************************
** Meta object code from reading C++ file 'menuitemimage.h'
**
** Created: Thu Feb 9 19:14:35 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Srcs/menuitemimage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menuitemimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MenuItemImage[] = {

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
      21,   15,   14,   14, 0x0a,
      59,   15,   14,   14, 0x0a,
      96,   15,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MenuItemImage[] = {
    "MenuItemImage\0\0event\0"
    "touchBegin(QGraphicsSceneMouseEvent*)\0"
    "touchMove(QGraphicsSceneMouseEvent*)\0"
    "touchEnd(QGraphicsSceneMouseEvent*)\0"
};

void MenuItemImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MenuItemImage *_t = static_cast<MenuItemImage *>(_o);
        switch (_id) {
        case 0: _t->touchBegin((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->touchMove((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->touchEnd((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MenuItemImage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MenuItemImage::staticMetaObject = {
    { &MenuItem::staticMetaObject, qt_meta_stringdata_MenuItemImage,
      qt_meta_data_MenuItemImage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MenuItemImage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MenuItemImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MenuItemImage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuItemImage))
        return static_cast<void*>(const_cast< MenuItemImage*>(this));
    return MenuItem::qt_metacast(_clname);
}

int MenuItemImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MenuItem::qt_metacall(_c, _id, _a);
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
