/****************************************************************************
** Meta object code from reading C++ file 'adminobject.h'
**
** Created: Thu Jul 11 14:20:35 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/adminobject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdminObject[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      20,   12, 0x0a095003,
      29,   12, 0x0a095003,
      48,   38, 0x10095003,
      59,   38, 0x10095003,
      74,   70, 0x02095003,

       0        // eod
};

static const char qt_meta_stringdata_AdminObject[] = {
    "AdminObject\0QString\0username\0password\0"
    "QDateTime\0created_at\0updated_at\0int\0"
    "lock_revision\0"
};

void AdminObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AdminObject::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AdminObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_AdminObject,
      qt_meta_data_AdminObject, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdminObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdminObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdminObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdminObject))
        return static_cast<void*>(const_cast< AdminObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< AdminObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int AdminObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getusername(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getpassword(); break;
        case 2: *reinterpret_cast< QDateTime*>(_v) = getcreated_at(); break;
        case 3: *reinterpret_cast< QDateTime*>(_v) = getupdated_at(); break;
        case 4: *reinterpret_cast< int*>(_v) = getlock_revision(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setusername(*reinterpret_cast< QString*>(_v)); break;
        case 1: setpassword(*reinterpret_cast< QString*>(_v)); break;
        case 2: setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 3: setupdated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 4: setlock_revision(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
