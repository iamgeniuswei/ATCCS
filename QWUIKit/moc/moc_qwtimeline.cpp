/****************************************************************************
** Meta object code from reading C++ file 'qwtimeline.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qwtimeline.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwtimeline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QWTimeLine_t {
    QByteArrayData data[10];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QWTimeLine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QWTimeLine_t qt_meta_stringdata_QWTimeLine = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QWTimeLine"
QT_MOC_LITERAL(1, 11, 11), // "itemClicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "index"
QT_MOC_LITERAL(4, 30, 15), // "itemClickedSlot"
QT_MOC_LITERAL(5, 46, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 63, 4), // "item"
QT_MOC_LITERAL(7, 68, 22), // "currentItemChangedSlot"
QT_MOC_LITERAL(8, 91, 7), // "current"
QT_MOC_LITERAL(9, 99, 8) // "previous"

    },
    "QWTimeLine\0itemClicked\0\0index\0"
    "itemClickedSlot\0QListWidgetItem*\0item\0"
    "currentItemChangedSlot\0current\0previous"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QWTimeLine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       7,    2,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    8,    9,

       0        // eod
};

void QWTimeLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QWTimeLine *_t = static_cast<QWTimeLine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->itemClicked((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->itemClickedSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->currentItemChangedSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QWTimeLine::*_t)(unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QWTimeLine::itemClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QWTimeLine::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_QWTimeLine.data,
      qt_meta_data_QWTimeLine,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QWTimeLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWTimeLine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QWTimeLine.stringdata0))
        return static_cast<void*>(const_cast< QWTimeLine*>(this));
    return QListWidget::qt_metacast(_clname);
}

int QWTimeLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QWTimeLine::itemClicked(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
