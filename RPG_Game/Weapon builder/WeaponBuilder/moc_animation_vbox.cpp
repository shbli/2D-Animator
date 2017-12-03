/****************************************************************************
** Meta object code from reading C++ file 'animation_vbox.h'
**
** Created: Fri Mar 30 17:31:16 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "animation_vbox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animation_vbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_animation_vbox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      29,   15,   15,   15, 0x0a,
      39,   15,   15,   15, 0x0a,
      61,   49,   15,   15, 0x0a,
     111,   97,   15,   15, 0x0a,
     165,  153,  141,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_animation_vbox[] = {
    "animation_vbox\0\0addNewStep()\0hideAll()\0"
    "showAll()\0toBeDeleted\0"
    "deleteAnimationStep(animationStep*)\0"
    "animationNode\0loadFromDomNode(QDomElement*)\0"
    "QDomElement\0domDocumnet\0"
    "animationsDomElement(QDomDocument*)\0"
};

void animation_vbox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        animation_vbox *_t = static_cast<animation_vbox *>(_o);
        switch (_id) {
        case 0: _t->addNewStep(); break;
        case 1: _t->hideAll(); break;
        case 2: _t->showAll(); break;
        case 3: _t->deleteAnimationStep((*reinterpret_cast< animationStep*(*)>(_a[1]))); break;
        case 4: _t->loadFromDomNode((*reinterpret_cast< QDomElement*(*)>(_a[1]))); break;
        case 5: { QDomElement _r = _t->animationsDomElement((*reinterpret_cast< QDomDocument*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDomElement*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData animation_vbox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject animation_vbox::staticMetaObject = {
    { &QVBoxLayout::staticMetaObject, qt_meta_stringdata_animation_vbox,
      qt_meta_data_animation_vbox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &animation_vbox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *animation_vbox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *animation_vbox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_animation_vbox))
        return static_cast<void*>(const_cast< animation_vbox*>(this));
    return QVBoxLayout::qt_metacast(_clname);
}

int animation_vbox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVBoxLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
