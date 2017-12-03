/****************************************************************************
** Meta object code from reading C++ file 'director.h'
**
** Created: Fri Mar 30 17:30:58 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GameEngine/GameEngine/Srcs/director.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'director.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Director[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,    9,    9,    9, 0x0a,
      56,    9,    9,    9, 0x0a,
      80,    9,    9,    9, 0x0a,
     116,  110,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Director[] = {
    "Director\0\0deltams\0update(double)\0"
    "refreshAndroidScreen()\0updatedEveryFrameRate()\0"
    "updatedEveryFrameRateOpenGL()\0scene\0"
    "transitionDone(Scene*)\0"
};

void Director::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Director *_t = static_cast<Director *>(_o);
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->refreshAndroidScreen(); break;
        case 2: _t->updatedEveryFrameRate(); break;
        case 3: _t->updatedEveryFrameRateOpenGL(); break;
        case 4: _t->transitionDone((*reinterpret_cast< Scene*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Director::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Director::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Director,
      qt_meta_data_Director, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Director::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Director::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Director::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Director))
        return static_cast<void*>(const_cast< Director*>(this));
    return QObject::qt_metacast(_clname);
}

int Director::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Director::update(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
