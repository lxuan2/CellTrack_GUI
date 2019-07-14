/****************************************************************************
** Meta object code from reading C++ file 'video_groupbox.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../video_groupbox.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video_groupbox.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoGroupBox_t {
    QByteArrayData data[15];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoGroupBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoGroupBox_t qt_meta_stringdata_VideoGroupBox = {
    {
QT_MOC_LITERAL(0, 0, 13), // "VideoGroupBox"
QT_MOC_LITERAL(1, 14, 4), // "play"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "changeVolume"
QT_MOC_LITERAL(4, 33, 6), // "volume"
QT_MOC_LITERAL(5, 40, 14), // "changePosition"
QT_MOC_LITERAL(6, 55, 8), // "position"
QT_MOC_LITERAL(7, 64, 10), // "changeFile"
QT_MOC_LITERAL(8, 75, 4), // "file"
QT_MOC_LITERAL(9, 80, 9), // "setVolume"
QT_MOC_LITERAL(10, 90, 11), // "setPosition"
QT_MOC_LITERAL(11, 102, 11), // "playClicked"
QT_MOC_LITERAL(12, 114, 6), // "browse"
QT_MOC_LITERAL(13, 121, 12), // "loadOriginal"
QT_MOC_LITERAL(14, 134, 10) // "loadResult"

    },
    "VideoGroupBox\0play\0\0changeVolume\0"
    "volume\0changePosition\0position\0"
    "changeFile\0file\0setVolume\0setPosition\0"
    "playClicked\0browse\0loadOriginal\0"
    "loadResult"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoGroupBox[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,
       7,    1,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   74,    2, 0x0a /* Public */,
      10,    1,   77,    2, 0x0a /* Public */,
      11,    0,   80,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,
      13,    0,   82,    2, 0x0a /* Public */,
      14,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VideoGroupBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoGroupBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->play(); break;
        case 1: _t->changeVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changePosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->playClicked(); break;
        case 7: _t->browse(); break;
        case 8: _t->loadOriginal(); break;
        case 9: _t->loadResult(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoGroupBox::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoGroupBox::play)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoGroupBox::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoGroupBox::changeVolume)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VideoGroupBox::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoGroupBox::changePosition)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VideoGroupBox::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoGroupBox::changeFile)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VideoGroupBox::staticMetaObject = { {
    &QGroupBox::staticMetaObject,
    qt_meta_stringdata_VideoGroupBox.data,
    qt_meta_data_VideoGroupBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VideoGroupBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoGroupBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoGroupBox.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int VideoGroupBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void VideoGroupBox::play()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VideoGroupBox::changeVolume(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoGroupBox::changePosition(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VideoGroupBox::changeFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
