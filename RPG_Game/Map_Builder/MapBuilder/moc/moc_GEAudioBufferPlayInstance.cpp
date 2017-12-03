/****************************************************************************
** Meta object code from reading C++ file 'GEAudioBufferPlayInstance.h'
**
** Created: Fri Nov 16 17:45:35 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../GameEngine/GameEngine/Srcs/GEAudioBufferPlayInstance.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GEAudioBufferPlayInstance.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GE__AudioBufferPlayInstance[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   40,   28,   28, 0x0a,
      93,   86,   28,   28, 0x2a,
     148,  118,   28,   28, 0x0a,
     209,  189,   28,   28, 0x2a,
     246,   28,   28,   28, 0x0a,
     259,  253,   28,   28, 0x0a,
     283,  277,   28,   28, 0x0a,
     306,  299,   28,   28, 0x0a,
     327,  299,   28,   28, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GE__AudioBufferPlayInstance[] = {
    "GE::AudioBufferPlayInstance\0\0finished()\0"
    "buffer,loopCount\0playBuffer(AudioBuffer*,int)\0"
    "buffer\0playBuffer(AudioBuffer*)\0"
    "buffer,volume,speed,loopCount\0"
    "playBuffer(AudioBuffer*,float,float,int)\0"
    "buffer,volume,speed\0"
    "playBuffer(AudioBuffer*,float,float)\0"
    "stop()\0count\0setLoopCount(int)\0speed\0"
    "setSpeed(float)\0volume\0setLeftVolume(float)\0"
    "setRightVolume(float)\0"
};

const QMetaObject GE::AudioBufferPlayInstance::staticMetaObject = {
    { &AudioSource::staticMetaObject, qt_meta_stringdata_GE__AudioBufferPlayInstance,
      qt_meta_data_GE__AudioBufferPlayInstance, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GE::AudioBufferPlayInstance::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GE::AudioBufferPlayInstance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GE::AudioBufferPlayInstance::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GE__AudioBufferPlayInstance))
        return static_cast<void*>(const_cast< AudioBufferPlayInstance*>(this));
    return AudioSource::qt_metacast(_clname);
}

int GE::AudioBufferPlayInstance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AudioSource::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: finished(); break;
        case 1: playBuffer((*reinterpret_cast< AudioBuffer*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: playBuffer((*reinterpret_cast< AudioBuffer*(*)>(_a[1]))); break;
        case 3: playBuffer((*reinterpret_cast< AudioBuffer*(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: playBuffer((*reinterpret_cast< AudioBuffer*(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 5: stop(); break;
        case 6: setLoopCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: setSpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 8: setLeftVolume((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: setRightVolume((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void GE::AudioBufferPlayInstance::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
