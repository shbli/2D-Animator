/****************************************************************************
** Meta object code from reading C++ file 'shop.h'
**
** Created: Fri Nov 16 17:47:43 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../map/shop.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_shop[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      31,    5,    5,    5, 0x0a,
      66,    5,    5,    5, 0x0a,
     115,  102,    5,    5, 0x0a,
     140,  102,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_shop[] = {
    "shop\0\0on_back_button_clicked()\0"
    "on_accept_payment_button_clicked()\0"
    "on_confirm_payment_button_clicked()\0"
    "to_be_bought\0buy_weapon(shop_weapon*)\0"
    "buy_item(shop_item*)\0"
};

const QMetaObject shop::staticMetaObject = {
    { &Layer::staticMetaObject, qt_meta_stringdata_shop,
      qt_meta_data_shop, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &shop::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *shop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *shop::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_shop))
        return static_cast<void*>(const_cast< shop*>(this));
    return Layer::qt_metacast(_clname);
}

int shop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_back_button_clicked(); break;
        case 1: on_accept_payment_button_clicked(); break;
        case 2: on_confirm_payment_button_clicked(); break;
        case 3: buy_weapon((*reinterpret_cast< shop_weapon*(*)>(_a[1]))); break;
        case 4: buy_item((*reinterpret_cast< shop_item*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
