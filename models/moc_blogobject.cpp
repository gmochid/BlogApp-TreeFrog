/****************************************************************************
** Meta object code from reading C++ file 'blogobject.h'
**
** Created: Thu Jul 11 11:53:30 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/blogobject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blogobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BlogObject[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      15,   11, 0x02095003,
      26,   18, 0x0a095003,
      35,   18, 0x0a095003,
      41,   18, 0x0a095003,
      63,   53, 0x10095003,
      74,   53, 0x10095003,
      85,   11, 0x02095003,

       0        // eod
};

static const char qt_meta_stringdata_BlogObject[] = {
    "BlogObject\0int\0id\0QString\0username\0"
    "title\0description\0QDateTime\0created_at\0"
    "updated_at\0lock_revision\0"
};

void BlogObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData BlogObject::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BlogObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_BlogObject,
      qt_meta_data_BlogObject, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BlogObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BlogObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BlogObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BlogObject))
        return static_cast<void*>(const_cast< BlogObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< BlogObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int BlogObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getusername(); break;
        case 2: *reinterpret_cast< QString*>(_v) = gettitle(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getdescription(); break;
        case 4: *reinterpret_cast< QDateTime*>(_v) = getcreated_at(); break;
        case 5: *reinterpret_cast< QDateTime*>(_v) = getupdated_at(); break;
        case 6: *reinterpret_cast< int*>(_v) = getlock_revision(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setid(*reinterpret_cast< int*>(_v)); break;
        case 1: setusername(*reinterpret_cast< QString*>(_v)); break;
        case 2: settitle(*reinterpret_cast< QString*>(_v)); break;
        case 3: setdescription(*reinterpret_cast< QString*>(_v)); break;
        case 4: setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 5: setupdated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 6: setlock_revision(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
