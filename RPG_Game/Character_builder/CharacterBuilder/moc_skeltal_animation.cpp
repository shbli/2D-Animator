/****************************************************************************
** Meta object code from reading C++ file 'skeltal_animation.h'
**
** Created: Thu Jun 14 21:21:12 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../skeltal/skeltal_animation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skeltal_animation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_skeltal_animation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   19,   18,   18, 0x0a,
      48,   18,   18,   18, 0x0a,
      65,   18,   18,   18, 0x0a,
      81,   18,   18,   18, 0x0a,
     139,  100,   18,   18, 0x0a,
     213,  186,   18,   18, 0x2a,
     275,  255,   18,   18, 0x2a,
     322,  311,   18,   18, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_skeltal_animation[] = {
    "skeltal_animation\0\0delta\0"
    "advanceOneStep(double)\0startAnimation()\0"
    "stopAnimation()\0restartAnimation()\0"
    "endT,anlge,svgIndex,yvalue,fireW1Value\0"
    "addAnimationStep(float,float,float,float,bool)\0"
    "endT,anlge,svgIndex,yvalue\0"
    "addAnimationStep(float,float,float,float)\0"
    "endT,anlge,svgIndex\0"
    "addAnimationStep(float,float,float)\0"
    "endT,anlge\0addAnimationStep(float,float)\0"
};

void skeltal_animation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        skeltal_animation *_t = static_cast<skeltal_animation *>(_o);
        switch (_id) {
        case 0: _t->advanceOneStep((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->startAnimation(); break;
        case 2: _t->stopAnimation(); break;
        case 3: _t->restartAnimation(); break;
        case 4: _t->addAnimationStep((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 5: _t->addAnimationStep((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 6: _t->addAnimationStep((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 7: _t->addAnimationStep((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData skeltal_animation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject skeltal_animation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_skeltal_animation,
      qt_meta_data_skeltal_animation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &skeltal_animation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *skeltal_animation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *skeltal_animation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_skeltal_animation))
        return static_cast<void*>(const_cast< skeltal_animation*>(this));
    return QObject::qt_metacast(_clname);
}

int skeltal_animation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
