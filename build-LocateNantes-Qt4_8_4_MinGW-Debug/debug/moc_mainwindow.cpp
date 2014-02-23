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
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      28,   25,   11,   11, 0x08,
      53,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      86,   81,   11,   11, 0x08,
     113,   81,   11,   11, 0x08,
     152,  146,   11,   11, 0x08,
     179,   81,   11,   11, 0x08,
     216,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,
     241,   11,   11,   11, 0x08,
     258,   11,   11,   11, 0x08,
     276,   11,   11,   11, 0x08,
     292,   11,   11,   11, 0x08,
     310,   11,   11,   11, 0x08,
     326,   11,   11,   11, 0x08,
     340,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0deleteItem()\0id\0"
    "pointerGroupClicked(int)\0bringToFront()\0"
    "sendToBack()\0item\0itemInserted(DiagramItem*)\0"
    "textInserted(QGraphicsTextItem*)\0scale\0"
    "sceneScaleChanged(QString)\0"
    "itemSelectionChanged(QGraphicsItem*)\0"
    "about()\0ouvrirBatiment()\0ouvrirEscalier()\0"
    "ouvrirConnexion()\0ouvrirCouloir()\0"
    "ouvrirAscenseur()\0ouvrirCloison()\0"
    "ouvrirPorte()\0sauvegardePlan()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->deleteItem(); break;
        case 1: _t->pointerGroupClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->bringToFront(); break;
        case 3: _t->sendToBack(); break;
        case 4: _t->itemInserted((*reinterpret_cast< DiagramItem*(*)>(_a[1]))); break;
        case 5: _t->textInserted((*reinterpret_cast< QGraphicsTextItem*(*)>(_a[1]))); break;
        case 6: _t->sceneScaleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->itemSelectionChanged((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 8: _t->about(); break;
        case 9: _t->ouvrirBatiment(); break;
        case 10: _t->ouvrirEscalier(); break;
        case 11: _t->ouvrirConnexion(); break;
        case 12: _t->ouvrirCouloir(); break;
        case 13: _t->ouvrirAscenseur(); break;
        case 14: _t->ouvrirCloison(); break;
        case 15: _t->ouvrirPorte(); break;
        case 16: _t->sauvegardePlan(); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
