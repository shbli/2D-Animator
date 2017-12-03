/****************************************************************************
** Meta object code from reading C++ file 'node.h'
**
** Created: Fri Nov 16 17:45:47 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../GameEngine/GameEngine/Srcs/node.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'node.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Node[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       8,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,    6,    5,    5, 0x05,
      77,   51,    5,    5, 0x05,
     116,  108,    5,    5, 0x05,
     148,  135,    5,    5, 0x05,
     190,  176,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     228,  217,    5,    5, 0x0a,
     254,  248,    5,    5, 0x0a,
     269,    6,    5,    5, 0x0a,
     294,   51,    5,    5, 0x0a,
     329,  321,    5,    5, 0x0a,
     344,  135,    5,    5, 0x0a,
     382,  368,    5,    5, 0x0a,

 // properties: name, type, flags
     411,  405, (QMetaType::QReal << 24) | 0x00095103,
     417,  405, (QMetaType::QReal << 24) | 0x00095103,
     424,  405, (QMetaType::QReal << 24) | 0x00095103,
     431,  405, (QMetaType::QReal << 24) | 0x00095103,
     439,  405, (QMetaType::QReal << 24) | 0x00095003,
     454,  446, 0x1a095103,
     458,  405, (QMetaType::QReal << 24) | 0x00095003,
     476,  446, 0x1a095003,

       0        // eod
};

static const char qt_meta_stringdata_Node[] = {
    "Node\0\0parentX,parentY\0"
    "updateChildsPos(qreal,qreal)\0"
    "parentxScale,parentyScale\0"
    "updateChildsScale(qreal,qreal)\0myRealZ\0"
    "updateChildsZ(int)\0parentRotate\0"
    "updateChildsRotation(qreal)\0myRealOpacity\0"
    "updateChildsOpacity(qreal)\0doneAction\0"
    "actionDone(action*)\0delta\0update(double)\0"
    "updateMyPos(qreal,qreal)\0"
    "updateMyScale(qreal,qreal)\0parentZ\0"
    "updateMyZ(int)\0updateMyRotation(qreal)\0"
    "parentOpacity\0updateMyOpacity(qreal)\0"
    "qreal\0scale\0scaleX\0scaleY\0opacity\0"
    "rotate\0QPointF\0pos\0rotateIneffective\0"
    "posIneffective\0"
};

const QMetaObject Node::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Node,
      qt_meta_data_Node, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Node::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Node::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Node::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Node))
        return static_cast<void*>(const_cast< Node*>(this));
    return QObject::qt_metacast(_clname);
}

int Node::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateChildsPos((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 1: updateChildsScale((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 2: updateChildsZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: updateChildsRotation((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 4: updateChildsOpacity((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: actionDone((*reinterpret_cast< action*(*)>(_a[1]))); break;
        case 6: update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: updateMyPos((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 8: updateMyScale((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 9: updateMyZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: updateMyRotation((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 11: updateMyOpacity((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = scale(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = scaleX(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = scaleY(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = opacity(); break;
        case 4: *reinterpret_cast< qreal*>(_v) = rotation(); break;
        case 5: *reinterpret_cast< QPointF*>(_v) = pos(); break;
        case 6: *reinterpret_cast< qreal*>(_v) = rotation(); break;
        case 7: *reinterpret_cast< QPointF*>(_v) = pos(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setScale(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setScaleX(*reinterpret_cast< qreal*>(_v)); break;
        case 2: setScaleY(*reinterpret_cast< qreal*>(_v)); break;
        case 3: setOpacity(*reinterpret_cast< qreal*>(_v)); break;
        case 4: setRotation(*reinterpret_cast< qreal*>(_v)); break;
        case 5: setPos(*reinterpret_cast< QPointF*>(_v)); break;
        case 6: setIneffectiveRotation(*reinterpret_cast< qreal*>(_v)); break;
        case 7: setIneffectivePos(*reinterpret_cast< QPointF*>(_v)); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Node::updateChildsPos(qreal _t1, qreal _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Node::updateChildsScale(qreal _t1, qreal _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Node::updateChildsZ(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Node::updateChildsRotation(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Node::updateChildsOpacity(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
