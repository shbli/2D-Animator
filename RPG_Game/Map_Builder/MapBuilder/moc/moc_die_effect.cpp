/****************************************************************************
** Meta object code from reading C++ file 'die_effect.h'
**
** Created: Fri Nov 16 17:46:36 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../character/die_effect.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'die_effect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_die_and_join_effect[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   21,   20,   20, 0x0a,
      63,   20,   20,   20, 0x0a,
      89,   83,   20,   20, 0x0a,
     104,   20,   20,   20, 0x0a,
     127,   20,   20,   20, 0x0a,
     139,   20,   20,   20, 0x0a,
     158,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_die_and_join_effect[] = {
    "die_and_join_effect\0\0character\0"
    "startDieEffect(character_base*)\0"
    "hideDeadCharacter()\0delta\0update(double)\0"
    "deleteSelfFromParent()\0finalStep()\0"
    "startEnterEffect()\0enterEffectShowParentHideEffect()\0"
};

const QMetaObject die_and_join_effect::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_die_and_join_effect,
      qt_meta_data_die_and_join_effect, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &die_and_join_effect::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *die_and_join_effect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *die_and_join_effect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_die_and_join_effect))
        return static_cast<void*>(const_cast< die_and_join_effect*>(this));
    return Layer::qt_metacast(_clname);
}

int die_and_join_effect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startDieEffect((*reinterpret_cast< character_base*(*)>(_a[1]))); break;
        case 1: hideDeadCharacter(); break;
        case 2: update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: deleteSelfFromParent(); break;
        case 4: finalStep(); break;
        case 5: startEnterEffect(); break;
        case 6: enterEffectShowParentHideEffect(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
