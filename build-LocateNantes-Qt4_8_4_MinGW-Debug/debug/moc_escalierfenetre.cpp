/****************************************************************************
** Meta object code from reading C++ file 'escalierfenetre.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LocateNantes/escalierfenetre.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'escalierfenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EscalierFenetre[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      31,   16,   16,   16, 0x0a,
      44,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EscalierFenetre[] = {
    "EscalierFenetre\0\0sauvegarder()\0"
    "demandeNom()\0choixNom()\0"
};

void EscalierFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EscalierFenetre *_t = static_cast<EscalierFenetre *>(_o);
        switch (_id) {
        case 0: _t->sauvegarder(); break;
        case 1: _t->demandeNom(); break;
        case 2: _t->choixNom(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData EscalierFenetre::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EscalierFenetre::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EscalierFenetre,
      qt_meta_data_EscalierFenetre, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EscalierFenetre::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EscalierFenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EscalierFenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EscalierFenetre))
        return static_cast<void*>(const_cast< EscalierFenetre*>(this));
    return QWidget::qt_metacast(_clname);
}

int EscalierFenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
