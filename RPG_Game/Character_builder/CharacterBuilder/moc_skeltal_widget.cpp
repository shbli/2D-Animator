/****************************************************************************
** Meta object code from reading C++ file 'skeltal_widget.h'
**
** Created: Thu Jun 14 21:21:51 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "skeltal_widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skeltal_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_skeltal_widget[] = {

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
      40,   28,   16,   15, 0x0a,
      86,   76,   15,   15, 0x0a,
     125,   15,  120,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_skeltal_widget[] = {
    "skeltal_widget\0\0QDomElement\0domDocumnet\0"
    "getSkeltalDomElement(QDomDocument*)\0"
    "jointRoot\0loadFromQDomElement(QDomElement*)\0"
    "bool\0checkAnimationValues()\0"
};

void skeltal_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        skeltal_widget *_t = static_cast<skeltal_widget *>(_o);
        switch (_id) {
        case 0: { QDomElement _r = _t->getSkeltalDomElement((*reinterpret_cast< QDomDocument*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDomElement*>(_a[0]) = _r; }  break;
        case 1: _t->loadFromQDomElement((*reinterpret_cast< QDomElement*(*)>(_a[1]))); break;
        case 2: { bool _r = _t->checkAnimationValues();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData skeltal_widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject skeltal_widget::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_skeltal_widget,
      qt_meta_data_skeltal_widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &skeltal_widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *skeltal_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *skeltal_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_skeltal_widget))
        return static_cast<void*>(const_cast< skeltal_widget*>(this));
    return QObject::qt_metacast(_clname);
}

int skeltal_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
