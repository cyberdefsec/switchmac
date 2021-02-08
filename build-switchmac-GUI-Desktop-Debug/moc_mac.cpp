/****************************************************************************
** Meta object code from reading C++ file 'mac.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../switchmac-GUI/mac.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mac.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mac_t {
    QByteArrayData data[12];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mac_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mac_t qt_meta_stringdata_Mac = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Mac"
QT_MOC_LITERAL(1, 4, 13), // "setMacAddress"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 13), // "nameInetrface"
QT_MOC_LITERAL(4, 33, 7), // "macAddr"
QT_MOC_LITERAL(5, 41, 13), // "getMacAddress"
QT_MOC_LITERAL(6, 55, 13), // "nameInterface"
QT_MOC_LITERAL(7, 69, 12), // "getErrorText"
QT_MOC_LITERAL(8, 82, 8), // "getError"
QT_MOC_LITERAL(9, 91, 8), // "ErrorMac"
QT_MOC_LITERAL(10, 100, 8), // "setError"
QT_MOC_LITERAL(11, 109, 3) // "err"

    },
    "Mac\0setMacAddress\0\0nameInetrface\0"
    "macAddr\0getMacAddress\0nameInterface\0"
    "getErrorText\0getError\0ErrorMac\0setError\0"
    "err"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mac[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x0a /* Public */,
       5,    1,   54,    2, 0x0a /* Public */,
       7,    0,   57,    2, 0x0a /* Public */,
       8,    0,   58,    2, 0x0a /* Public */,
      10,    1,   59,    2, 0x0a /* Public */,
      10,    1,   62,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString,
    0x80000000 | 9,
    QMetaType::Void, 0x80000000 | 9,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

void Mac::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Mac *_t = static_cast<Mac *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setMacAddress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: { QString _r = _t->getMacAddress((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->getErrorText();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { ErrorMac _r = _t->getError();
            if (_a[0]) *reinterpret_cast< ErrorMac*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->setError((*reinterpret_cast< const ErrorMac(*)>(_a[1]))); break;
        case 5: _t->setError((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 6: _t->setError(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mac::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Mac.data,
      qt_meta_data_Mac,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Mac::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mac::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mac.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Mac::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
