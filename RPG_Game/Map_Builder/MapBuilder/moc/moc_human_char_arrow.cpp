/****************************************************************************
** Meta object code from reading C++ file 'human_char_arrow.h'
**
** Created: Fri Nov 16 17:47:10 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../game_controller/human_char_arrow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'human_char_arrow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_human_char_arrow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      43,   17,   17,   17, 0x0a,
      73,   67,   17,   17, 0x0a,
      88,   17,   17,   17, 0x0a,
     110,   17,   17,   17, 0x0a,
     132,   17,   17,   17, 0x0a,
     168,  156,   17,   17, 0x0a,
     188,   17,   17,   17, 0x2a,
     204,   17,   17,   17, 0x0a,
     218,   17,   17,   17, 0x0a,
     239,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_human_char_arrow[] = {
    "human_char_arrow\0\0attachedCharPosChanges()\0"
    "pointedCharPosChanges()\0delta\0"
    "update(double)\0start_bounce_effect()\0"
    "start_circle_effect()\0start_teleport_effect()\0"
    "circle_glow\0glow_in_white(bool)\0"
    "glow_in_white()\0glow_in_red()\0"
    "start_red_teleport()\0start_red_teleport_2()\0"
};

const QMetaObject human_char_arrow::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_human_char_arrow,
      qt_meta_data_human_char_arrow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &human_char_arrow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *human_char_arrow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *human_char_arrow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_human_char_arrow))
        return static_cast<void*>(const_cast< human_char_arrow*>(this));
    return Layer::qt_metacast(_clname);
}

int human_char_arrow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: attachedCharPosChanges(); break;
        case 1: pointedCharPosChanges(); break;
        case 2: update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: start_bounce_effect(); break;
        case 4: start_circle_effect(); break;
        case 5: start_teleport_effect(); break;
        case 6: glow_in_white((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: glow_in_white(); break;
        case 8: glow_in_red(); break;
        case 9: start_red_teleport(); break;
        case 10: start_red_teleport_2(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
