/****************************************************************************
** Meta object code from reading C++ file 'png_scene.h'
**
** Created: Fri Mar 30 17:31:11 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "png_scene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'png_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_png_scene[] = {

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
      17,   11,   10,   10, 0x0a,
      32,   10,   10,   10, 0x0a,
      44,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_png_scene[] = {
    "png_scene\0\0delta\0update(double)\0"
    "animation()\0performanceRandomAnimationTest()\0"
};

void png_scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        png_scene *_t = static_cast<png_scene *>(_o);
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->animation(); break;
        case 2: _t->performanceRandomAnimationTest(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData png_scene::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject png_scene::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_png_scene,
      qt_meta_data_png_scene, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &png_scene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *png_scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *png_scene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_png_scene))
        return static_cast<void*>(const_cast< png_scene*>(this));
    return Layer::qt_metacast(_clname);
}

int png_scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
