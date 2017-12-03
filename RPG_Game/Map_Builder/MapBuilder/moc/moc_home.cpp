/****************************************************************************
** Meta object code from reading C++ file 'home.h'
**
** Created: Fri Nov 16 17:47:23 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../map/home.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'home.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_home[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      31,    5,    5,    5, 0x0a,
      78,   61,    5,    5, 0x0a,
     107,    5,    5,    5, 0x2a,
     133,    5,    5,    5, 0x0a,
     159,    5,    5,    5, 0x0a,
     182,    5,    5,    5, 0x0a,
     222,  207,    5,    5, 0x0a,
     255,  242,    5,    5, 0x0a,
     273,    5,    5,    5, 0x0a,
     304,  298,    5,    5, 0x0a,
     342,  298,    5,    5, 0x0a,
     379,  298,    5,    5, 0x0a,
     415,    5,    5,    5, 0x0a,
     451,  442,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_home[] = {
    "home\0\0on_back_button_clicked()\0"
    "on_change_character_clicked()\0"
    "defaultSelection\0on_change_wepon_clicked(int)\0"
    "on_change_wepon_clicked()\0"
    "on_change_items_clicked()\0"
    "on_up_button_clicked()\0on_down_button_clicked()\0"
    "weaponSequence\0weaponSoldSlot(int)\0"
    "itemSequence\0itemSoldSlot(int)\0"
    "refreshWeaponsSequence()\0event\0"
    "touchBegin(QGraphicsSceneMouseEvent*)\0"
    "touchMove(QGraphicsSceneMouseEvent*)\0"
    "touchEnd(QGraphicsSceneMouseEvent*)\0"
    "onExitTransitionDidStart()\0weaponID\0"
    "enable_drag_drop_for_weapon(int)\0"
};

const QMetaObject home::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_home,
      qt_meta_data_home, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &home::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *home::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *home::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_home))
        return static_cast<void*>(const_cast< home*>(this));
    return Layer::qt_metacast(_clname);
}

int home::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_back_button_clicked(); break;
        case 1: on_change_character_clicked(); break;
        case 2: on_change_wepon_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_change_wepon_clicked(); break;
        case 4: on_change_items_clicked(); break;
        case 5: on_up_button_clicked(); break;
        case 6: on_down_button_clicked(); break;
        case 7: weaponSoldSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: itemSoldSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: refreshWeaponsSequence(); break;
        case 10: touchBegin((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 11: touchMove((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 12: touchEnd((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 13: onExitTransitionDidStart(); break;
        case 14: enable_drag_drop_for_weapon((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
