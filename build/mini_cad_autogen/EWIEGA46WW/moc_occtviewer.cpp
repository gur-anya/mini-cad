/****************************************************************************
** Meta object code from reading C++ file 'occtviewer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../occtviewer.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'occtviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_OcctViewer_t {
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[10];
    char stringdata2[31];
    char stringdata3[1];
    char stringdata4[2];
    char stringdata5[2];
    char stringdata6[2];
    char stringdata7[13];
    char stringdata8[15];
    char stringdata9[11];
    char stringdata10[12];
    char stringdata11[6];
    char stringdata12[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_OcctViewer_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_OcctViewer_t qt_meta_stringdata_OcctViewer = {
    {
        QT_MOC_LITERAL(0, 10),  // "OcctViewer"
        QT_MOC_LITERAL(11, 9),  // "createBox"
        QT_MOC_LITERAL(21, 30),  // "opencascade::handle<AIS_Shape>"
        QT_MOC_LITERAL(52, 0),  // ""
        QT_MOC_LITERAL(53, 1),  // "w"
        QT_MOC_LITERAL(55, 1),  // "h"
        QT_MOC_LITERAL(57, 1),  // "d"
        QT_MOC_LITERAL(59, 12),  // "createSphere"
        QT_MOC_LITERAL(72, 14),  // "createCylinder"
        QT_MOC_LITERAL(87, 10),  // "exportBrep"
        QT_MOC_LITERAL(98, 11),  // "removeShape"
        QT_MOC_LITERAL(110, 5),  // "shape"
        QT_MOC_LITERAL(116, 10)   // "importBrep"
    },
    "OcctViewer",
    "createBox",
    "opencascade::handle<AIS_Shape>",
    "",
    "w",
    "h",
    "d",
    "createSphere",
    "createCylinder",
    "exportBrep",
    "removeShape",
    "shape",
    "importBrep"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_OcctViewer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   50,    3, 0x0a,    1 /* Public */,
       7,    0,   57,    3, 0x0a,    5 /* Public */,
       8,    0,   58,    3, 0x0a,    6 /* Public */,
       9,    0,   59,    3, 0x0a,    7 /* Public */,
      10,    1,   60,    3, 0x0a,    8 /* Public */,
      12,    0,   63,    3, 0x0a,   10 /* Public */,

 // slots: parameters
    0x80000000 | 2, QMetaType::Double, QMetaType::Double, QMetaType::Double,    4,    5,    6,
    0x80000000 | 2,
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 2,   11,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject OcctViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_OcctViewer.offsetsAndSizes,
    qt_meta_data_OcctViewer,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_OcctViewer_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<OcctViewer, std::true_type>,
        // method 'createBox'
        QtPrivate::TypeAndForceComplete<opencascade::handle<AIS_Shape>, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'createSphere'
        QtPrivate::TypeAndForceComplete<opencascade::handle<AIS_Shape>, std::false_type>,
        // method 'createCylinder'
        QtPrivate::TypeAndForceComplete<opencascade::handle<AIS_Shape>, std::false_type>,
        // method 'exportBrep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeShape'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const opencascade::handle<AIS_Shape> &, std::false_type>,
        // method 'importBrep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void OcctViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OcctViewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { opencascade::handle<AIS_Shape> _r = _t->createBox((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])));
            if (_a[0]) *reinterpret_cast< opencascade::handle<AIS_Shape>*>(_a[0]) = std::move(_r); }  break;
        case 1: { opencascade::handle<AIS_Shape> _r = _t->createSphere();
            if (_a[0]) *reinterpret_cast< opencascade::handle<AIS_Shape>*>(_a[0]) = std::move(_r); }  break;
        case 2: { opencascade::handle<AIS_Shape> _r = _t->createCylinder();
            if (_a[0]) *reinterpret_cast< opencascade::handle<AIS_Shape>*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->exportBrep(); break;
        case 4: _t->removeShape((*reinterpret_cast< std::add_pointer_t<opencascade::handle<AIS_Shape>>>(_a[1]))); break;
        case 5: _t->importBrep(); break;
        default: ;
        }
    }
}

const QMetaObject *OcctViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OcctViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OcctViewer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OcctViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
