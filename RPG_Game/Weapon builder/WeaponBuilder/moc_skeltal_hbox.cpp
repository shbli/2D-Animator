/****************************************************************************
** Meta object code from reading C++ file 'skeltal_hbox.h'
**
** Created: Fri Mar 30 17:31:15 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "skeltal_hbox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skeltal_hbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_skeltal_hbox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      32,   13,   13,   13, 0x0a,
      55,   13,   50,   13, 0x0a,
     102,   90,   78,   13, 0x0a,
     132,   13,   13,   13, 0x0a,
     152,   13,   13,   13, 0x0a,
     170,   13,   13,   13, 0x0a,
     197,  191,   13,   13, 0x0a,
     224,   13,   13,   13, 0x0a,
     264,  251,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_skeltal_hbox[] = {
    "skeltal_hbox\0\0hideAllElements()\0"
    "showAllElements()\0bool\0checkAnimationValues()\0"
    "QDomElement\0domDocumnet\0"
    "partDomElement(QDomDocument*)\0"
    "addMovementsForms()\0addJoint_button()\0"
    "removeJoint_button()\0child\0"
    "removeChild(skeltal_hbox*)\0"
    "addSVGBoxForJoint_button()\0jointElement\0"
    "loadFromQDomElement(QDomElement*)\0"
};

void skeltal_hbox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        skeltal_hbox *_t = static_cast<skeltal_hbox *>(_o);
        switch (_id) {
        case 0: _t->hideAllElements(); break;
        case 1: _t->showAllElements(); break;
        case 2: { bool _r = _t->checkAnimationValues();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { QDomElement _r = _t->partDomElement((*reinterpret_cast< QDomDocument*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDomElement*>(_a[0]) = _r; }  break;
        case 4: _t->addMovementsForms(); break;
        case 5: _t->addJoint_button(); break;
        case 6: _t->removeJoint_button(); break;
        case 7: _t->removeChild((*reinterpret_cast< skeltal_hbox*(*)>(_a[1]))); break;
        case 8: _t->addSVGBoxForJoint_button(); break;
        case 9: _t->loadFromQDomElement((*reinterpret_cast< QDomElement*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData skeltal_hbox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject skeltal_hbox::staticMetaObject = {
    { &QVBoxLayout::staticMetaObject, qt_meta_stringdata_skeltal_hbox,
      qt_meta_data_skeltal_hbox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &skeltal_hbox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *skeltal_hbox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *skeltal_hbox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_skeltal_hbox))
        return static_cast<void*>(const_cast< skeltal_hbox*>(this));
    return QVBoxLayout::qt_metacast(_clname);
}

int skeltal_hbox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVBoxLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
