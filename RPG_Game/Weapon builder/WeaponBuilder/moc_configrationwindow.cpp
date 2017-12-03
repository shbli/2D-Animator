/****************************************************************************
** Meta object code from reading C++ file 'configrationwindow.h'
**
** Created: Fri Mar 30 17:31:04 2012
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
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      41,   19,   19,   19, 0x0a,
      75,   62,   19,   19, 0x0a,
     107,   19,   19,   19, 0x0a,
     122,   19,  117,   19, 0x0a,
     145,   19,   19,   19, 0x08,
     177,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConfigrationWindow[] = {
    "ConfigrationWindow\0\0on_refresh_clicked()\0"
    "on_SaveXML_clicked()\0newTimeValue\0"
    "changeCurrentAnimationTime(int)\0"
    "loadXML()\0bool\0checkAnimationValues()\0"
    "on_runAnimationButton_clicked()\0"
    "on_stopAnimationButton_clicked()\0"
};

void ConfigrationWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConfigrationWindow *_t = static_cast<ConfigrationWindow *>(_o);
        switch (_id) {
        case 0: _t->on_refresh_clicked(); break;
        case 1: _t->on_SaveXML_clicked(); break;
        case 2: _t->changeCurrentAnimationTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->loadXML(); break;
        case 4: { bool _r = _t->checkAnimationValues();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->on_runAnimationButton_clicked(); break;
        case 6: _t->on_stopAnimationButton_clicked(); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
