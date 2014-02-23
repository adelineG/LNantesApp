/****************************************************************************
** Meta object code from reading C++ file 'fenetrebat.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LocateNantes/fenetrebat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetrebat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FenetreBat[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      26,   11,   11,   11, 0x0a,
      42,   11,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      74,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FenetreBat[] = {
    "FenetreBat\0\0sauvegarder()\0demandeNomBat()\0"
    "choixNomBat()\0demandeNomEtage()\0"
    "choixNomEtage()\0"
};

void FenetreBat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FenetreBat *_t = static_cast<FenetreBat *>(_o);
        switch (_id) {
        case 0: _t->sauvegarder(); break;
        case 1: _t->demandeNomBat(); break;
        case 2: _t->choixNomBat(); break;
        case 3: _t->demandeNomEtage(); break;
        case 4: _t->choixNomEtage(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FenetreBat::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FenetreBat::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FenetreBat,
      qt_meta_data_FenetreBat, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FenetreBat::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FenetreBat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FenetreBat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FenetreBat))
        return static_cast<void*>(const_cast< FenetreBat*>(this));
    return QWidget::qt_metacast(_clname);
}

int FenetreBat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
