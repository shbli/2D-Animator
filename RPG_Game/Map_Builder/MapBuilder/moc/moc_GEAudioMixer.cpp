/****************************************************************************
** Meta object code from reading C++ file 'GEAudioMixer.h'
**
** Created: Fri Nov 16 17:45:34 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../GameEngine/GameEngine/Srcs/GEAudioMixer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GEAudioMixer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GE__AudioMixer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   16,   15,   15, 0x05,
      52,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      80,   16,   15,   15, 0x0a,
     105,   16,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GE__AudioMixer[] = {
    "GE::AudioMixer\0\0volume\0"
    "absoluteVolumeChanged(float)\0"
    "generalVolumeChanged(float)\0"
    "setAbsoluteVolume(float)\0"
    "setGeneralVolume(float)\0"
};

const QMetaObject GE::AudioMixer::staticMetaObject = {
    { &AudioSource::staticMetaObject, qt_meta_stringdata_GE__AudioMixer,
      qt_meta_data_GE__AudioMixer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GE::AudioMixer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GE::AudioMixer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GE::AudioMixer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GE__AudioMixer))
        return static_cast<void*>(const_cast< AudioMixer*>(this));
    return AudioSource::qt_metacast(_clname);
}

int GE::AudioMixer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AudioSource::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: absoluteVolumeChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: generalVolumeChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: setAbsoluteVolume((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: setGeneralVolume((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GE::AudioMixer::absoluteVolumeChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GE::AudioMixer::generalVolumeChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
