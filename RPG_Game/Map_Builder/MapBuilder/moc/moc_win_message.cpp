/****************************************************************************
** Meta object code from reading C++ file 'win_message.h'
**
** Created: Fri Nov 16 17:47:39 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../map/win_message.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'win_message.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_win_message[] = {

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
      13,   12,   12,   12, 0x0a,
      40,   12,   12,   12, 0x0a,
      53,   12,   12,   12, 0x0a,
      70,   12,   12,   12, 0x0a,
      91,   12,   12,   12, 0x0a,
     112,   12,   12,   12, 0x0a,
     131,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_win_message[] = {
    "win_message\0\0on_message_board_clicked()\0"
    "xp_updates()\0silver_updates()\0"
    "bonus_time_updates()\0bonus_gold_updates()\0"
    "bonus_xp_updates()\0final_step()\0"
};

const QMetaObject win_message::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_win_message,
      qt_meta_data_win_message, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &win_message::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *win_message::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *win_message::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_win_message))
        return static_cast<void*>(const_cast< win_message*>(this));
    return Layer::qt_metacast(_clname);
}

int win_message::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_message_board_clicked(); break;
        case 1: xp_updates(); break;
        case 2: silver_updates(); break;
        case 3: bonus_time_updates(); break;
        case 4: bonus_gold_updates(); break;
        case 5: bonus_xp_updates(); break;
        case 6: final_step(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
