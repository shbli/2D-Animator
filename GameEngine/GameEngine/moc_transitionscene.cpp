/****************************************************************************
** Meta object code from reading C++ file 'transitionscene.h'
**
** Created: Thu Feb 9 19:14:18 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Srcs/transitionscene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transitionscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_transitionScene[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   16,   16,   16, 0x0a,
      79,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_transitionScene[] = {
    "transitionScene\0\0scene\0"
    "transitionDoneSignal(Scene*)\0"
    "FadeTransition_half_done()\0transition_done()\0"
};

void transitionScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        transitionScene *_t = static_cast<transitionScene *>(_o);
        switch (_id) {
        case 0: _t->transitionDoneSignal((*reinterpret_cast< Scene*(*)>(_a[1]))); break;
        case 1: _t->FadeTransition_half_done(); break;
        case 2: _t->transition_done(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData transitionScene::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject transitionScene::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_transitionScene,
      qt_meta_data_transitionScene, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &transitionScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *transitionScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *transitionScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_transitionScene))
        return static_cast<void*>(const_cast< transitionScene*>(this));
    return QObject::qt_metacast(_clname);
}

int transitionScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void transitionScene::transitionDoneSignal(Scene * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE