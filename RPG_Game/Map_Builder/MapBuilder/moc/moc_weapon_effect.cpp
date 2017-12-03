/****************************************************************************
** Meta object code from reading C++ file 'weapon_effect.h'
**
** Created: Fri Nov 16 17:46:44 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../weapon/weapon_effect.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weapon_effect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_weapon_effect[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   30,   14,   14, 0x0a,
      98,   14,   14,   14, 0x0a,
     112,   14,   14,   14, 0x0a,
     130,   14,   14,   14, 0x0a,
     147,   14,   14,   14, 0x0a,
     164,   14,   14,   14, 0x0a,
     180,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_weapon_effect[] = {
    "weapon_effect\0\0signalEffect()\0"
    "effectElement,screenScale\0"
    "loadeffectsDomElement(QDomElement*,float)\0"
    "startEffect()\0runMOVAnimation()\0"
    "runSXAnimation()\0runSYAnimation()\0"
    "runRAnimation()\0runOAnimation()\0"
};

const QMetaObject weapon_effect::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_weapon_effect,
      qt_meta_data_weapon_effect, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &weapon_effect::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *weapon_effect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *weapon_effect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_weapon_effect))
        return static_cast<void*>(const_cast< weapon_effect*>(this));
    return Layer::qt_metacast(_clname);
}

int weapon_effect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalEffect(); break;
        case 1: loadeffectsDomElement((*reinterpret_cast< QDomElement*(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 2: startEffect(); break;
        case 3: runMOVAnimation(); break;
        case 4: runSXAnimation(); break;
        case 5: runSYAnimation(); break;
        case 6: runRAnimation(); break;
        case 7: runOAnimation(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void weapon_effect::signalEffect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
