/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LocateNantes/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      28,   11,   11,   11, 0x08,
      44,   41,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      84,   11,   11,   11, 0x08,
     102,   97,   11,   11, 0x08,
     129,   97,   11,   11, 0x08,
     168,  162,   11,   11, 0x08,
     195,   97,   11,   11, 0x08,
     232,   11,   11,   11, 0x08,
     240,   11,   11,   11, 0x08,
     257,   11,   11,   11, 0x08,
     274,   11,   11,   11, 0x08,
     292,   11,   11,   11, 0x08,
     306,   11,   11,   11, 0x08,
     322,   11,   11,   11, 0x08,
     340,   11,   11,   11, 0x08,
     356,   11,   11,   11, 0x08,
     370,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0changerVue(int)\0deleteItem()\0"
    "id\0pointerGroupClicked(int)\0bringToFront()\0"
    "sendToBack()\0item\0itemInserted(DiagramItem*)\0"
    "textInserted(QGraphicsTextItem*)\0scale\0"
    "sceneScaleChanged(QString)\0"
    "itemSelectionChanged(QGraphicsItem*)\0"
    "about()\0ouvrirBatiment()\0ouvrirEscalier()\0"
    "ouvrirConnexion()\0ouvrirEtage()\0"
    "ouvrirCouloir()\0ouvrirAscenseur()\0"
    "ouvrirCloison()\0ouvrirPorte()\0"
    "sauvegardePlan()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->changerVue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->deleteItem(); break;
        case 2: _t->pointerGroupClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->bringToFront(); break;
        case 4: _t->sendToBack(); break;
        case 5: _t->itemInserted((*reinterpret_cast< DiagramItem*(*)>(_a[1]))); break;
        case 6: _t->textInserted((*reinterpret_cast< QGraphicsTextItem*(*)>(_a[1]))); break;
        case 7: _t->sceneScaleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->itemSelectionChanged((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 9: _t->about(); break;
        case 10: _t->ouvrirBatiment(); break;
        case 11: _t->ouvrirEscalier(); break;
        case 12: _t->ouvrirConnexion(); break;
        case 13: _t->ouvrirEtage(); break;
        case 14: _t->ouvrirCouloir(); break;
        case 15: _t->ouvrirAscenseur(); break;
        case 16: _t->ouvrirCloison(); break;
        case 17: _t->ouvrirPorte(); break;
        case 18: _t->sauvegardePlan(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
