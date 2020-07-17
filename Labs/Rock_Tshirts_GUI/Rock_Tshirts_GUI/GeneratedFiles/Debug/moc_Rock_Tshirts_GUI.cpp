/****************************************************************************
** Meta object code from reading C++ file 'Rock_Tshirts_GUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Rock_Tshirts_GUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Rock_Tshirts_GUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Rock_Tshirts_GUI_t {
    QByteArrayData data[11];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Rock_Tshirts_GUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Rock_Tshirts_GUI_t qt_meta_stringdata_Rock_Tshirts_GUI = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Rock_Tshirts_GUI"
QT_MOC_LITERAL(1, 17, 25), // "connect_signals_and_slots"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 10), // "add_new_rt"
QT_MOC_LITERAL(4, 55, 9), // "delete_rt"
QT_MOC_LITERAL(5, 65, 9), // "update_rt"
QT_MOC_LITERAL(6, 75, 6), // "upd_rt"
QT_MOC_LITERAL(7, 82, 6), // "add_rt"
QT_MOC_LITERAL(8, 89, 10), // "display_rt"
QT_MOC_LITERAL(9, 100, 11), // "undo_action"
QT_MOC_LITERAL(10, 112, 11) // "redo_action"

    },
    "Rock_Tshirts_GUI\0connect_signals_and_slots\0"
    "\0add_new_rt\0delete_rt\0update_rt\0upd_rt\0"
    "add_rt\0display_rt\0undo_action\0redo_action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rock_Tshirts_GUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Rock_Tshirts_GUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Rock_Tshirts_GUI *_t = static_cast<Rock_Tshirts_GUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connect_signals_and_slots(); break;
        case 1: _t->add_new_rt(); break;
        case 2: _t->delete_rt(); break;
        case 3: _t->update_rt(); break;
        case 4: _t->upd_rt(); break;
        case 5: _t->add_rt(); break;
        case 6: _t->display_rt(); break;
        case 7: _t->undo_action(); break;
        case 8: _t->redo_action(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Rock_Tshirts_GUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Rock_Tshirts_GUI.data,
      qt_meta_data_Rock_Tshirts_GUI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Rock_Tshirts_GUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Rock_Tshirts_GUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Rock_Tshirts_GUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Rock_Tshirts_GUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
