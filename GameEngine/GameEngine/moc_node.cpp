/****************************************************************************
** Meta object code from reading C++ file 'node.h'
**
** Created: Thu Feb 9 19:14:26 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Srcs/node.h"
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
       4,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      24,    5,    5,    5, 0x05,
      44,    5,    5,    5, 0x05,
      60,    5,    5,    5, 0x05,
      83,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     116,  105,    5,    5, 0x0a,
     142,  136,    5,    5, 0x0a,
     157,    5,    5,    5, 0x0a,
     171,    5,    5,    5, 0x0a,
     187,    5,    5,    5, 0x0a,
     199,    5,    5,    5, 0x0a,
     218,    5,    5,    5, 0x0a,

 // properties: name, type, flags
     242,  236, ((uint)QMetaType::QReal << 24) | 0x00095103,
     248,  236, ((uint)QMetaType::QReal << 24) | 0x00095103,
     256,  236, ((uint)QMetaType::QReal << 24) | 0x00095003,
     271,  263, 0x1a095103,

       0        // eod
};

static const char qt_meta_stringdata_Node[] = {
    "Node\0\0updateChildsPos()\0updateChildsScale()\0"
    "updateChildsZ()\0updateChildsRotation()\0"
    "updateChildsOpacity()\0doneAction\0"
    "actionDone(action*)\0delta\0update(double)\0"
    "updateMyPos()\0updateMyScale()\0updateMyZ()\0"
    "updateMyRotation()\0updateMyOpacity()\0"
    "qreal\0scale\0opacity\0rotate\0QPointF\0"
    "pos\0"
};

void Node::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Node *_t = static_cast<Node *>(_o);
        switch (_id) {
        case 0: _t->updateChildsPos(); break;
        case 1: _t->updateChildsScale(); break;
        case 2: _t->updateChildsZ(); break;
        case 3: _t->updateChildsRotation(); break;
        case 4: _t->updateChildsOpacity(); break;
        case 5: _t->actionDone((*reinterpret_cast< action*(*)>(_a[1]))); break;
        case 6: _t->update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->updateMyPos(); break;
        case 8: _t->updateMyScale(); break;
        case 9: _t->updateMyZ(); break;
        case 10: _t->updateMyRotation(); break;
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
        case 1: *reinterpret_cast< qreal*>(_v) = opacity(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = rotation(); break;
        case 3: *reinterpret_cast< QPointF*>(_v) = pos(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setScale(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setOpacity(*reinterpret_cast< qreal*>(_v)); break;
        case 2: setRotation(*reinterpret_cast< qreal*>(_v)); break;
        case 3: setPos(*reinterpret_cast< QPointF*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Node::updateChildsPos()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
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
void Node::updateChildsRotation()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Node::updateChildsOpacity()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
