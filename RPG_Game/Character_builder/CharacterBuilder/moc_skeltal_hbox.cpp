/****************************************************************************
** Meta object code from reading C++ file 'skeltal_hbox.h'
**
** Created: Thu Jun 7 19:50:23 2012
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
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      40,   13,   13,   13, 0x0a,
      67,   13,   13,   13, 0x0a,
      83,   13,   13,   13, 0x0a,
     100,   13,   13,   13, 0x0a,
     118,   13,   13,   13, 0x0a,
     141,   13,  136,   13, 0x0a,
     188,  176,  164,   13, 0x0a,
     218,   13,   13,   13, 0x0a,
     238,   13,   13,   13, 0x0a,
     256,   13,   13,   13, 0x0a,
     283,  277,   13,   13, 0x0a,
     310,   13,   13,   13, 0x0a,
     350,  337,   13,   13, 0x0a,
     403,  384,   13,   13, 0x0a,
     438,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_skeltal_hbox[] = {
    "skeltal_hbox\0\0setAsDragandDropElement()\0"
    "setAsDragandDropElement2()\0setPartValues()\0"
    "setPartValues2()\0hideAllElements()\0"
    "showAllElements()\0bool\0checkAnimationValues()\0"
    "QDomElement\0domDocumnet\0"
    "partDomElement(QDomDocument*)\0"
    "addMovementsForms()\0addJoint_button()\0"
    "removeJoint_button()\0child\0"
    "removeChild(skeltal_hbox*)\0"
    "addSVGBoxForJoint_button()\0jointElement\0"
    "loadFromQDomElement(QDomElement*)\0"
    "animationName,time\0"
    "hightlightAnimation(QString,float)\0"
    "showEveryAnimation()\0"
};

void skeltal_hbox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        skeltal_hbox *_t = static_cast<skeltal_hbox *>(_o);
        switch (_id) {
        case 0: _t->setAsDragandDropElement(); break;
        case 1: _t->setAsDragandDropElement2(); break;
        case 2: _t->setPartValues(); break;
        case 3: _t->setPartValues2(); break;
        case 4: _t->hideAllElements(); break;
        case 5: _t->showAllElements(); break;
        case 6: { bool _r = _t->checkAnimationValues();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { QDomElement _r = _t->partDomElement((*reinterpret_cast< QDomDocument*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDomElement*>(_a[0]) = _r; }  break;
        case 8: _t->addMovementsForms(); break;
        case 9: _t->addJoint_button(); break;
        case 10: _t->removeJoint_button(); break;
        case 11: _t->removeChild((*reinterpret_cast< skeltal_hbox*(*)>(_a[1]))); break;
        case 12: _t->addSVGBoxForJoint_button(); break;
        case 13: _t->loadFromQDomElement((*reinterpret_cast< QDomElement*(*)>(_a[1]))); break;
        case 14: _t->hightlightAnimation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 15: _t->showEveryAnimation(); break;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
