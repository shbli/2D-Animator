/****************************************************************************
** Meta object code from reading C++ file 'svg_scene.h'
**
** Created: Thu Jun 14 21:21:48 2012
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
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      53,   31,   10,   10, 0x0a,
     106,   10,   10,   10, 0x0a,
     132,   10,   10,   10, 0x0a,
     165,  159,   10,   10, 0x0a,
     180,   10,   10,   10, 0x0a,
     192,   10,   10,   10, 0x0a,
     225,   10,   10,   10, 0x0a,
     262,  243,   10,   10, 0x0a,
     320,  306,   10,   10, 0x2a,
     350,   10,   10,   10, 0x0a,
     366,   10,   10,   10, 0x0a,
     400,  394,   10,   10, 0x0a,
     438,  394,   10,   10, 0x0a,
     475,  394,   10,   10, 0x0a,
     511,   10,   10,   10, 0x0a,
     534,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_svg_scene[] = {
    "svg_scene\0\0decreaseHealthBar()\0"
    "newAnimationName,time\0"
    "setXMLTestCharacterCurrentAnimationTime(QString,int)\0"
    "runAnimationOnCharacter()\0"
    "stopAnimationOnCharacter()\0delta\0"
    "update(double)\0animation()\0"
    "performanceRandomAnimationTest()\0"
    "loadSVGasPixmap()\0xml_file_name,root\0"
    "loadCharacterFromXML(QString,skeltal_hbox*)\0"
    "xml_file_name\0loadCharacterFromXML(QString)\0"
    "testHealthBar()\0stopAllAnimatedCharacters()\0"
    "event\0touchBegin(QGraphicsSceneMouseEvent*)\0"
    "touchMove(QGraphicsSceneMouseEvent*)\0"
    "touchEnd(QGraphicsSceneMouseEvent*)\0"
    "updateJointSelection()\0hideLine()\0"
};

void svg_scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        svg_scene *_t = static_cast<svg_scene *>(_o);
        switch (_id) {
        case 0: _t->decreaseHealthBar(); break;
        case 1: _t->setXMLTestCharacterCurrentAnimationTime((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->runAnimationOnCharacter(); break;
        case 3: _t->stopAnimationOnCharacter(); break;
        case 4: _t->update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->animation(); break;
        case 6: _t->performanceRandomAnimationTest(); break;
        case 7: _t->loadSVGasPixmap(); break;
        case 8: _t->loadCharacterFromXML((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< skeltal_hbox*(*)>(_a[2]))); break;
        case 9: _t->loadCharacterFromXML((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->testHealthBar(); break;
        case 11: _t->stopAllAnimatedCharacters(); break;
        case 12: _t->touchBegin((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 13: _t->touchMove((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 14: _t->touchEnd((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 15: _t->updateJointSelection(); break;
        case 16: _t->hideLine(); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
