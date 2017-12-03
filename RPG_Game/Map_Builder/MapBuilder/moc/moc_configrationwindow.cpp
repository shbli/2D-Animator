/****************************************************************************
** Meta object code from reading C++ file 'configrationwindow.h'
**
** Created: Fri Nov 16 17:47:48 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../configrationwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configrationwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConfigrationWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      41,   19,   19,   19, 0x0a,
      62,   19,   19,   19, 0x0a,
      72,   19,   19,   19, 0x0a,
      92,   19,   19,   19, 0x0a,
     120,   19,   19,   19, 0x0a,
     141,   19,   19,   19, 0x0a,
     170,  162,   19,   19, 0x0a,
     223,  205,   19,   19, 0x0a,
     264,   19,   19,   19, 0x08,
     295,   19,   19,   19, 0x08,
     329,   19,   19,   19, 0x08,
     366,   19,   19,   19, 0x08,
     406,   19,   19,   19, 0x08,
     446,   19,   19,   19, 0x08,
     501,  493,   19,   19, 0x08,
     525,   19,   19,   19, 0x28,
     554,  546,   19,   19, 0x08,
     585,   19,   19,   19, 0x08,
     617,   19,   19,   19, 0x08,
     652,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConfigrationWindow[] = {
    "ConfigrationWindow\0\0on_refresh_clicked()\0"
    "on_SaveXML_clicked()\0loadXML()\0"
    "submitPrevChanges()\0submit_prev_enemy_changes()\0"
    "enemy_list_changed()\0listElementChanged()\0"
    "chagedR\0on_rotation_element_changed(float)\0"
    "changedX,changedY\0"
    "on_position_element_changed(float,float)\0"
    "on_loadXMLpushButton_clicked()\0"
    "on_AddElementpushButton_clicked()\0"
    "on_DeleteElementPushButton_clicked()\0"
    "on_ElementXDragDroppushButton_clicked()\0"
    "on_ElementYDragDroppushButton_clicked()\0"
    "on_ElementRotationDragDroppushButton_clicked()\0"
    "elemtid\0print_all_elements(int)\0"
    "print_all_elements()\0checked\0"
    "on_EnemycheckBox_toggled(bool)\0"
    "on_EnemyAddpushButton_clicked()\0"
    "on_EnemyDeletepushButton_clicked()\0"
    "on_slowAnimationPushButton_clicked()\0"
};

const QMetaObject ConfigrationWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ConfigrationWindow,
      qt_meta_data_ConfigrationWindow, 0 }
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
        switch (_id) {
        case 0: on_refresh_clicked(); break;
        case 1: on_SaveXML_clicked(); break;
        case 2: loadXML(); break;
        case 3: submitPrevChanges(); break;
        case 4: submit_prev_enemy_changes(); break;
        case 5: enemy_list_changed(); break;
        case 6: listElementChanged(); break;
        case 7: on_rotation_element_changed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 8: on_position_element_changed((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 9: on_loadXMLpushButton_clicked(); break;
        case 10: on_AddElementpushButton_clicked(); break;
        case 11: on_DeleteElementPushButton_clicked(); break;
        case 12: on_ElementXDragDroppushButton_clicked(); break;
        case 13: on_ElementYDragDroppushButton_clicked(); break;
        case 14: on_ElementRotationDragDroppushButton_clicked(); break;
        case 15: print_all_elements((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: print_all_elements(); break;
        case 17: on_EnemycheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: on_EnemyAddpushButton_clicked(); break;
        case 19: on_EnemyDeletepushButton_clicked(); break;
        case 20: on_slowAnimationPushButton_clicked(); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
