/****************************************************************************
** Meta object code from reading C++ file 'node.h'
**
** Created: Fri Mar 30 17:30:44 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GameEngine/GameEngine/Srcs/node.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'node.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Node[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       6,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,    6,    5,    5, 0x05,
      51,    5,    5,    5, 0x05,
      71,    5,    5,    5, 0x05,
     100,   87,    5,    5, 0x05,
     128,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     161,  150,    5,    5, 0x0a,
     187,  181,    5,    5, 0x0a,
     202,    6,    5,    5, 0x0a,
     227,    5,    5,    5, 0x0a,
     243,    5,    5,    5, 0x0a,
     255,   87,    5,    5, 0x0a,
     279,    5,    5,    5, 0x0a,

 // properties: name, type, flags
     303,  297, ((uint)QMetaType::QReal << 24) | 0x00095103,
     309,  297, ((uint)QMetaType::QReal << 24) | 0x00095103,
     316,  297, ((uint)QMetaType::QReal << 24) | 0x00095103,
     323,  297, ((uint)QMetaType::QReal << 24) | 0x00095103,
     331,  297, ((uint)QMetaType::QReal << 24) | 0x00095003,
     346,  338, 0x1a095103,

       0        // eod
};

static const char qt_meta_stringdata_Node[] = {
    "Node\0\0parentX,parentY\0"
    "updateChildsPos(qreal,qreal)\0"
    "updateChildsScale()\0updateChildsZ()\0"
    "parentRotate\0updateChildsRotation(qreal)\0"
    "updateChildsOpacity()\0doneAction\0"
    "actionDone(action*)\0delta\0update(double)\0"
    "updateMyPos(qreal,qreal)\0updateMyScale()\0"
    "updateMyZ()\0updateMyRotation(qreal)\0"
    "updateMyOpacity()\0qreal\0scale\0scaleX\0"
    "scaleY\0opacity\0rotate\0QPointF\0pos\0"
};

void Node::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Node *_t = static_cast<Node *>(_o);
        switch (_id) {
        case 0: _t->updateChildsPos((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 1: _t->updateChildsScale(); break;
        case 2: _t->updateChildsZ(); break;
        case 3: _t->updateChildsRotation((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 4: _t->updateChildsOpacity(); break;
        case 5: _t->actionDone((*reinterpret_cast< action*(*)>(_a[1]))); break;
        case 6: _t->update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->updateMyPos((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 8: _t->updateMyScale(); break;
        case 9: _t->updateMyZ(); break;
        case 10: _t->updateMyRotation((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 11: _t->updateMyOpacity(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Node::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Node::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Node,
      qt_meta_data_Node, &staticMetaObjectExtraData }
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
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
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setScale(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setScaleX(*reinterpret_cast< qreal*>(_v)); break;
        case 2: setScaleY(*reinterpret_cast< qreal*>(_v)); break;
        case 3: setOpacity(*reinterpret_cast< qreal*>(_v)); break;
        case 4: setRotation(*reinterpret_cast< qreal*>(_v)); break;
        case 5: setPos(*reinterpret_cast< QPointF*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
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
void Node::updateChildsScale()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Node::updateChildsZ()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Node::updateChildsRotation(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Node::updateChildsOpacity()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
