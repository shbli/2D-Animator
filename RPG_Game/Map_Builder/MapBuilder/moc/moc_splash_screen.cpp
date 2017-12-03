/****************************************************************************
** Meta object code from reading C++ file 'splash_screen.h'
**
** Created: Fri Nov 16 17:48:00 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../splash_screen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'splash_screen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_splash_screen[] = {

 // content:
       5,       // revision
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

const QMetaObject splash_screen::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_splash_screen,
      qt_meta_data_splash_screen, 0 }
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
        switch (_id) {
        case 0: removeSplashScreen1(); break;
        case 1: removeSplashScreen1Free(); break;
        case 2: replaceWithGameLogo(); break;
        case 3: replaceSceneStep2(); break;
        case 4: replaceWithFreeAd(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
