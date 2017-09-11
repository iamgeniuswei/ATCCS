/****************************************************************************
** Meta object code from reading C++ file 'ATCTitleBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ATCTitleBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ATCTitleBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ATCTitleBar_t {
    QByteArrayData data[6];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ATCTitleBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ATCTitleBar_t qt_meta_stringdata_ATCTitleBar = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ATCTitleBar"
QT_MOC_LITERAL(1, 12, 14), // "settingClicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "minClicked"
QT_MOC_LITERAL(4, 39, 10), // "maxClicked"
QT_MOC_LITERAL(5, 50, 12) // "closeClicked"

    },
    "ATCTitleBar\0settingClicked\0\0minClicked\0"
    "maxClicked\0closeClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ATCTitleBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ATCTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ATCTitleBar *_t = static_cast<ATCTitleBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->settingClicked(); break;
        case 1: _t->minClicked(); break;
        case 2: _t->maxClicked(); break;
        case 3: _t->closeClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ATCTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ATCTitleBar::settingClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ATCTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ATCTitleBar::minClicked)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ATCTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ATCTitleBar::maxClicked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ATCTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ATCTitleBar::closeClicked)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ATCTitleBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ATCTitleBar.data,
      qt_meta_data_ATCTitleBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ATCTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ATCTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ATCTitleBar.stringdata0))
        return static_cast<void*>(const_cast< ATCTitleBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int ATCTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ATCTitleBar::settingClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ATCTitleBar::minClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ATCTitleBar::maxClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ATCTitleBar::closeClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
