/****************************************************************************
** Meta object code from reading C++ file 'DBMPublicTablePanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/DBMPublicTablePanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DBMPublicTablePanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBMPublicTablePanel_t {
    QByteArrayData data[8];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBMPublicTablePanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBMPublicTablePanel_t qt_meta_stringdata_DBMPublicTablePanel = {
    {
QT_MOC_LITERAL(0, 0, 19), // "DBMPublicTablePanel"
QT_MOC_LITERAL(1, 20, 20), // "initializeDBFinished"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 3), // "ret"
QT_MOC_LITERAL(4, 46, 3), // "msg"
QT_MOC_LITERAL(5, 50, 9), // "selectAll"
QT_MOC_LITERAL(6, 60, 10), // "selectNone"
QT_MOC_LITERAL(7, 71, 18) // "initializeDatabase"

    },
    "DBMPublicTablePanel\0initializeDBFinished\0"
    "\0ret\0msg\0selectAll\0selectNone\0"
    "initializeDatabase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBMPublicTablePanel[] = {

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

void DBMPublicTablePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DBMPublicTablePanel *_t = static_cast<DBMPublicTablePanel *>(_o);
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
            typedef void (DBMPublicTablePanel::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBMPublicTablePanel::initializeDBFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DBMPublicTablePanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DBMPublicTablePanel.data,
      qt_meta_data_DBMPublicTablePanel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DBMPublicTablePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBMPublicTablePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBMPublicTablePanel.stringdata0))
        return static_cast<void*>(const_cast< DBMPublicTablePanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int DBMPublicTablePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DBMPublicTablePanel::initializeDBFinished(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
