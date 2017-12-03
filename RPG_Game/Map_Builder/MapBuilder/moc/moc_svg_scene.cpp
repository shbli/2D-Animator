/****************************************************************************
** Meta object code from reading C++ file 'svg_scene.h'
**
** Created: Fri Nov 16 17:47:52 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../svg_scene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'svg_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_svg_scene[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x05,
      49,   47,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      76,   10,   10,   10, 0x0a,
     118,   96,   10,   10, 0x0a,
     171,   10,   10,   10, 0x0a,
     197,   10,   10,   10, 0x0a,
     230,  224,   10,   10, 0x0a,
     245,   10,   10,   10, 0x0a,
     257,   10,   10,   10, 0x0a,
     290,   10,   10,   10, 0x0a,
     322,  308,   10,   10, 0x0a,
     352,  308,   10,   10, 0x0a,
     376,   10,   10,   10, 0x0a,
     392,   10,   10,   10, 0x0a,
     426,  420,   10,   10, 0x0a,
     464,  420,   10,   10, 0x0a,
     501,  420,   10,   10, 0x0a,
     537,   10,   10,   10, 0x0a,
     560,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_svg_scene[] = {
    "svg_scene\0\0x,y\0signal_new_postion(float,float)\0"
    "r\0signal_new_rotation(float)\0"
    "decreaseHealthBar()\0newAnimationName,time\0"
    "setXMLTestCharacterCurrentAnimationTime(QString,int)\0"
    "runAnimationOnCharacter()\0"
    "stopAnimationOnCharacter()\0delta\0"
    "update(double)\0animation()\0"
    "performanceRandomAnimationTest()\0"
    "loadSVGasPixmap()\0xml_file_name\0"
    "loadCharacterFromXML(QString)\0"
    "loadMapFromXML(QString)\0testHealthBar()\0"
    "stopAllAnimatedCharacters()\0event\0"
    "touchBegin(QGraphicsSceneMouseEvent*)\0"
    "touchMove(QGraphicsSceneMouseEvent*)\0"
    "touchEnd(QGraphicsSceneMouseEvent*)\0"
    "updateJointSelection()\0hideLine()\0"
};

const QMetaObject svg_scene::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_svg_scene,
      qt_meta_data_svg_scene, 0 }
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
        switch (_id) {
        case 0: signal_new_postion((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: signal_new_rotation((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: decreaseHealthBar(); break;
        case 3: setXMLTestCharacterCurrentAnimationTime((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: runAnimationOnCharacter(); break;
        case 5: stopAnimationOnCharacter(); break;
        case 6: update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: animation(); break;
        case 8: performanceRandomAnimationTest(); break;
        case 9: loadSVGasPixmap(); break;
        case 10: loadCharacterFromXML((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: loadMapFromXML((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: testHealthBar(); break;
        case 13: stopAllAnimatedCharacters(); break;
        case 14: touchBegin((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 15: touchMove((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 16: touchEnd((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 17: updateJointSelection(); break;
        case 18: hideLine(); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void svg_scene::signal_new_postion(float _t1, float _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void svg_scene::signal_new_rotation(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
