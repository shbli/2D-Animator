/****************************************************************************
** Meta object code from reading C++ file 'configrationwindow.h'
**
** Created: Thu Jun 14 21:21:45 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "configrationwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configrationwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConfigrationWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   20,   19,   19, 0x0a,
      62,   19,   19,   19, 0x0a,
      83,   19,   19,   19, 0x0a,
     117,  104,   19,   19, 0x0a,
     149,   19,   19,   19, 0x0a,
     164,   19,  159,   19, 0x0a,
     187,   19,   19,   19, 0x0a,
     215,   19,   19,   19, 0x0a,
     247,   19,   19,   19, 0x0a,
     267,   19,   19,   19, 0x0a,
     296,   19,   19,   19, 0x0a,
     319,   19,   19,   19, 0x08,
     351,   19,   19,   19, 0x08,
     384,   19,   19,   19, 0x08,
     417,   19,   19,   19, 0x08,
     458,   19,   19,   19, 0x08,
     502,   19,   19,   19, 0x08,
     534,   19,   19,   19, 0x08,
     569,   19,   19,   19, 0x08,
     607,   19,   19,   19, 0x08,
     652,   19,   19,   19, 0x08,
     694,   19,   19,   19, 0x08,
     736,   19,   19,   19, 0x08,
     778,   19,   19,   19, 0x08,
     816,   19,   19,   19, 0x08,
     853,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConfigrationWindow[] = {
    "ConfigrationWindow\0\0hBox\0"
    "setDragAndDropElement(skeltal_hbox*)\0"
    "on_refresh_clicked()\0on_SaveXML_clicked()\0"
    "newTimeValue\0changeCurrentAnimationTime(int)\0"
    "loadXML()\0bool\0checkAnimationValues()\0"
    "JointTreeSelectionChanged()\0"
    "AnimationTreeSelectionChanged()\0"
    "submitPrevChanges()\0submitPrevAnimationChanges()\0"
    "refreshAnimationTree()\0"
    "on_runAnimationButton_clicked()\0"
    "on_stopAnimationButton_clicked()\0"
    "on_setValuesPushButton_clicked()\0"
    "on_AddAnimationPointpushButton_clicked()\0"
    "on_RemoveAnimationPointpushButton_clicked()\0"
    "on_AddJointpushButton_clicked()\0"
    "on_DeleteJointpushButton_clicked()\0"
    "on_JointYDragDroppushButton_clicked()\0"
    "on_JointRotationDragDroppushButton_clicked()\0"
    "on_AnimationRDragDroppushButton_clicked()\0"
    "on_AnimationYDragDroppushButton_clicked()\0"
    "on_AnimationSetValuespushButton_clicked()\0"
    "on_JointXDragDroppushButton_clicked()\0"
    "on_slowAnimationPushButton_clicked()\0"
    "on_ChangeAnimationPointpushButton_clicked()\0"
};

void ConfigrationWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConfigrationWindow *_t = static_cast<ConfigrationWindow *>(_o);
        switch (_id) {
        case 0: _t->setDragAndDropElement((*reinterpret_cast< skeltal_hbox*(*)>(_a[1]))); break;
        case 1: _t->on_refresh_clicked(); break;
        case 2: _t->on_SaveXML_clicked(); break;
        case 3: _t->changeCurrentAnimationTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->loadXML(); break;
        case 5: { bool _r = _t->checkAnimationValues();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->JointTreeSelectionChanged(); break;
        case 7: _t->AnimationTreeSelectionChanged(); break;
        case 8: _t->submitPrevChanges(); break;
        case 9: _t->submitPrevAnimationChanges(); break;
        case 10: _t->refreshAnimationTree(); break;
        case 11: _t->on_runAnimationButton_clicked(); break;
        case 12: _t->on_stopAnimationButton_clicked(); break;
        case 13: _t->on_setValuesPushButton_clicked(); break;
        case 14: _t->on_AddAnimationPointpushButton_clicked(); break;
        case 15: _t->on_RemoveAnimationPointpushButton_clicked(); break;
        case 16: _t->on_AddJointpushButton_clicked(); break;
        case 17: _t->on_DeleteJointpushButton_clicked(); break;
        case 18: _t->on_JointYDragDroppushButton_clicked(); break;
        case 19: _t->on_JointRotationDragDroppushButton_clicked(); break;
        case 20: _t->on_AnimationRDragDroppushButton_clicked(); break;
        case 21: _t->on_AnimationYDragDroppushButton_clicked(); break;
        case 22: _t->on_AnimationSetValuespushButton_clicked(); break;
        case 23: _t->on_JointXDragDroppushButton_clicked(); break;
        case 24: _t->on_slowAnimationPushButton_clicked(); break;
        case 25: _t->on_ChangeAnimationPointpushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConfigrationWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConfigrationWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ConfigrationWindow,
      qt_meta_data_ConfigrationWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConfigrationWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConfigrationWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConfigrationWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigrationWindow))
        return static_cast<void*>(const_cast< ConfigrationWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ConfigrationWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
