/****************************************************************************
** Meta object code from reading C++ file 'GEInterfaces.h'
**
** Created: Thu Feb 9 19:14:12 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Srcs/GEInterfaces.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GEInterfaces.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GE__AudioSource[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_GE__AudioSource[] = {
    "GE::AudioSource\0"
};

void GE::AudioSource::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GE::AudioSource::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GE::AudioSource::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GE__AudioSource,
      qt_meta_data_GE__AudioSource, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GE::AudioSource::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GE::AudioSource::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GE::AudioSource::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GE__AudioSource))
        return static_cast<void*>(const_cast< AudioSource*>(this));
    return QObject::qt_metacast(_clname);
}

int GE::AudioSource::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
