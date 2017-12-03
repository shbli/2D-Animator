/****************************************************************************
** Meta object code from reading C++ file 'svg_scene.h'
**
** Created: Fri Mar 30 17:31:08 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "svg_scene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'svg_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_svg_scene[] = {

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
      33,   11,   10,   10, 0x0a,
      86,   10,   10,   10, 0x0a,
     112,   10,   10,   10, 0x0a,
     145,  139,   10,   10, 0x0a,
     160,   10,   10,   10, 0x0a,
     172,   10,   10,   10, 0x0a,
     205,   10,   10,   10, 0x0a,
     237,  223,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_svg_scene[] = {
    "svg_scene\0\0newAnimationName,time\0"
    "setXMLTestCharacterCurrentAnimationTime(QString,int)\0"
    "runAnimationOnCharacter()\0"
    "stopAnimationOnCharacter()\0delta\0"
    "update(double)\0animation()\0"
    "performanceRandomAnimationTest()\0"
    "loadSVGasPixmap()\0xml_file_name\0"
    "loadCharacterFromXML(QString)\0"
};

void svg_scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        svg_scene *_t = static_cast<svg_scene *>(_o);
        switch (_id) {
        case 0: _t->setXMLTestCharacterCurrentAnimationTime((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->runAnimationOnCharacter(); break;
        case 2: _t->stopAnimationOnCharacter(); break;
        case 3: _t->update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->animation(); break;
        case 5: _t->performanceRandomAnimationTest(); break;
        case 6: _t->loadSVGasPixmap(); break;
        case 7: _t->loadCharacterFromXML((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData svg_scene::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject svg_scene::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_svg_scene,
      qt_meta_data_svg_scene, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &svg_scene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *svg_scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *svg_scene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_svg_scene))
        return static_cast<void*>(const_cast< svg_scene*>(this));
    return Layer::qt_metacast(_clname);
}

int svg_scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
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
