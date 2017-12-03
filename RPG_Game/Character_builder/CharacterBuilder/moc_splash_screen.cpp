/****************************************************************************
** Meta object code from reading C++ file 'splash_screen.h'
**
** Created: Thu Jun 7 19:50:27 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "splash_screen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'splash_screen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_splash_screen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      37,   14,   14,   14, 0x0a,
      63,   14,   14,   14, 0x0a,
      85,   14,   14,   14, 0x0a,
     105,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_splash_screen[] = {
    "splash_screen\0\0removeSplashScreen1()\0"
    "removeSplashScreen1Free()\0"
    "replaceWithGameLogo()\0replaceSceneStep2()\0"
    "replaceWithFreeAd()\0"
};

void splash_screen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        splash_screen *_t = static_cast<splash_screen *>(_o);
        switch (_id) {
        case 0: _t->removeSplashScreen1(); break;
        case 1: _t->removeSplashScreen1Free(); break;
        case 2: _t->replaceWithGameLogo(); break;
        case 3: _t->replaceSceneStep2(); break;
        case 4: _t->replaceWithFreeAd(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData splash_screen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject splash_screen::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_splash_screen,
      qt_meta_data_splash_screen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &splash_screen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *splash_screen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *splash_screen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_splash_screen))
        return static_cast<void*>(const_cast< splash_screen*>(this));
    return Layer::qt_metacast(_clname);
}

int splash_screen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
