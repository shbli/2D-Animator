/****************************************************************************
** Meta object code from reading C++ file 'png_scene.h'
**
** Created: Fri Nov 16 17:47:56 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../png_scene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'png_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_png_scene[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   11,   10,   10, 0x0a,
      55,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_png_scene[] = {
    "png_scene\0\0xml_file_name\0"
    "loadCharacterFromXML(QString)\0"
    "stopAllAnimatedCharacters()\0"
};

const QMetaObject png_scene::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_png_scene,
      qt_meta_data_png_scene, 0 }
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
        switch (_id) {
        case 0: loadCharacterFromXML((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: stopAllAnimatedCharacters(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
