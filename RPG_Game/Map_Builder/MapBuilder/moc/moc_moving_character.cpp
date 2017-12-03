/****************************************************************************
** Meta object code from reading C++ file 'moving_character.h'
**
** Created: Fri Nov 16 17:46:31 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../character/moving_character.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'moving_character.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_moving_character[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   18,   17,   17, 0x0a,
      57,   47,   17,   17, 0x0a,
      91,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_moving_character[] = {
    "moving_character\0\0delta\0move_to_attack(double)\0"
    "character\0aim_to_char_move(character_base*)\0"
    "ckeckAttackingDistance()\0"
};

const QMetaObject moving_character::staticMetaObject = {
    { &character_base::staticMetaObject, qt_meta_stringdata_moving_character,
      qt_meta_data_moving_character, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &moving_character::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *moving_character::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *moving_character::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_moving_character))
        return static_cast<void*>(const_cast< moving_character*>(this));
    return character_base::qt_metacast(_clname);
}

int moving_character::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = character_base::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: move_to_attack((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: aim_to_char_move((*reinterpret_cast< character_base*(*)>(_a[1]))); break;
        case 2: ckeckAttackingDistance(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
