/****************************************************************************
** Meta object code from reading C++ file 'DBMAT60TablePanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/DBMAT60TablePanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DBMAT60TablePanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBMAT60TablePanel_t {
    QByteArrayData data[8];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBMAT60TablePanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBMAT60TablePanel_t qt_meta_stringdata_DBMAT60TablePanel = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DBMAT60TablePanel"
QT_MOC_LITERAL(1, 18, 20), // "initializeDBFinished"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 3), // "ret"
QT_MOC_LITERAL(4, 44, 3), // "msg"
QT_MOC_LITERAL(5, 48, 9), // "selectAll"
QT_MOC_LITERAL(6, 58, 10), // "selectNone"
QT_MOC_LITERAL(7, 69, 18) // "initializeDatabase"

    },
    "DBMAT60TablePanel\0initializeDBFinished\0"
    "\0ret\0msg\0selectAll\0selectNone\0"
    "initializeDatabase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBMAT60TablePanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       1,    1,   44,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DBMAT60TablePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DBMAT60TablePanel *_t = static_cast<DBMAT60TablePanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initializeDBFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->initializeDBFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->selectAll(); break;
        case 3: _t->selectNone(); break;
        case 4: _t->initializeDatabase(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DBMAT60TablePanel::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBMAT60TablePanel::initializeDBFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DBMAT60TablePanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DBMAT60TablePanel.data,
      qt_meta_data_DBMAT60TablePanel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DBMAT60TablePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBMAT60TablePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBMAT60TablePanel.stringdata0))
        return static_cast<void*>(const_cast< DBMAT60TablePanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int DBMAT60TablePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DBMAT60TablePanel::initializeDBFinished(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
