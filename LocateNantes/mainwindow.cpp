/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>
#include <QLabel>

#include "mainwindow.h"
#include "diagramitem.h"
#include "diagramscene.h"
#include "diagramtextitem.h"
#include "arrow.h"
#include "fenetrebat.h"
#include "escalierfenetre.h"
#include "fenetreconnexion.h"
#include "fenetreetage.h"
#include "choixconstruction.h"


//! [0]
MainWindow::MainWindow()
{
    createActions();
    createToolBox();
    createMenus();

    scene = new DiagramScene(itemMenu, this);
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));
    connect(scene, SIGNAL(itemInserted(DiagramItem*)),this, SLOT(itemInserted(DiagramItem*)));
    connect(scene, SIGNAL(textInserted(QGraphicsTextItem*)), this, SLOT(textInserted(QGraphicsTextItem*)));
    connect(scene, SIGNAL(itemSelected(QGraphicsItem*)),this, SLOT(itemSelected(QGraphicsItem*)));
    createToolbars();


    /**************************** Grid ********************************************/
    view = new QGraphicsView(scene);


    setCentralWidget(view);
    addDockWidget(Qt::RightDockWidgetArea, toolBoxDock);

    setWindowTitle(tr("LocateUnivNantes"));
    setUnifiedTitleAndToolBarOnMac(true);
}
//! [0]



//! [3]
void MainWindow::deleteItem()
{
    foreach (QGraphicsItem *item, scene->selectedItems()) {
        if (item->type() == Arrow::Type) {
            scene->removeItem(item);
            Arrow *arrow = qgraphicsitem_cast<Arrow *>(item);
            arrow->startItem()->removeArrow(arrow);
            arrow->endItem()->removeArrow(arrow);
            delete item;
        }
    }

    foreach (QGraphicsItem *item, scene->selectedItems()) {
         if (item->type() == DiagramItem::Type) {
             qgraphicsitem_cast<DiagramItem *>(item)->removeArrows();
         }
         scene->removeItem(item);
         delete item;
     }
}
//! [3]

//! [4]
void MainWindow::pointerGroupClicked(int)
{
    scene->setMode(DiagramScene::Mode(pointerTypeGroup->checkedId()));
}
//! [4]

//! [5]
void MainWindow::bringToFront()
{
    if (scene->selectedItems().isEmpty())
        return;

    QGraphicsItem *selectedItem = scene->selectedItems().first();
    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() >= zValue &&
            item->type() == DiagramItem::Type)
            zValue = item->zValue() + 0.1;
    }
    selectedItem->setZValue(zValue);
}
//! [5]

//! [6]
void MainWindow::sendToBack()
{
    if (scene->selectedItems().isEmpty())
        return;

    QGraphicsItem *selectedItem = scene->selectedItems().first();
    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() <= zValue &&
            item->type() == DiagramItem::Type)
            zValue = item->zValue() - 0.1;
    }
    selectedItem->setZValue(zValue);
}
//! [6]

//! [7]
void MainWindow::itemInserted(DiagramItem *item)
{
    pointerTypeGroup->button(int(DiagramScene::MoveItem))->setChecked(true);
    scene->setMode(DiagramScene::Mode(pointerTypeGroup->checkedId()));
 //   buttonGroup->button(int(item->diagramType()))->setChecked(false);
}
//! [7]

//! [8]
void MainWindow::textInserted(QGraphicsTextItem *)
{
  //  buttonGroup->button(InsertTextButton)->setChecked(false);
    scene->setMode(DiagramScene::Mode(pointerTypeGroup->checkedId()));
}
//! [8]


//! [11]
void MainWindow::sceneScaleChanged(const QString &scale)
{
    double newScale = scale.left(scale.indexOf(tr("%"))).toDouble() / 100.0;
    QMatrix oldMatrix = view->matrix();
    view->resetMatrix();
    view->translate(oldMatrix.dx(), oldMatrix.dy());
    view->scale(newScale, newScale);
}
//! [11]

//! [19]
void MainWindow::itemSelected(QGraphicsItem *item)
{
    DiagramTextItem *textItem =
    qgraphicsitem_cast<DiagramTextItem *>(item);
    //
}
//! [19]

//! [20]
void MainWindow::about()
{
    QMessageBox::about(this, tr("About Locate Univ Nantes"),
                       tr("Cette application vous permet de construire les plans des batiments de l'Université de Nantes"));
}
//! [20]
void MainWindow::ouvrirBatiment(){
    FenetreBat *formulaire = new FenetreBat();
    formulaire->show();
}

void MainWindow::ouvrirEscalier(){
    EscalierFenetre *formulaire = new EscalierFenetre();
    formulaire->show();
}

void MainWindow::ouvrirConnexion(){
    FenetreConnexion *formulaire = new FenetreConnexion();
    formulaire->show();
}

void MainWindow::ouvrirEtage(){
    FenetreEtage *formulaire = new FenetreEtage();
    formulaire->show();
}


//! [21]
void MainWindow::createToolBox()
{
//! [22]
    toolBoxDock = new QDockWidget;
    ChoixConstruction* toolBox = new ChoixConstruction(toolBoxDock);
    toolBoxDock->setWidget(toolBox);
}
//! [22]

//! [23]
void MainWindow::createActions()
{

    /**********************************************************/

    actionNouveau = new QAction("&Nouveau plan", this);
    actionCharger = new QAction("&Charger", this);
    actionSauvegarder = new QAction("&Sauvegarder", this);


    actionPorte = new QAction("&Porte", this);
    actionContour = new QAction("&Contour", this);
    actionMur = new QAction("&Mur", this);
    actionEscalier = new QAction("&Escalier", this);
    actionAscenseur = new QAction("&Ascenseur", this);
    actionConnexion = new QAction("&Connexion", this);

     actionEtage = new QAction("&Etage", this);
     connect(actionEtage, SIGNAL(triggered()),this, SLOT(ouvrirEtage()));

     actionNouveauBatiment = new QAction("&Nouveau", this);
     actionChoisirBatiment = new QAction("&Choisir", this);

     actionVueEnsemble = new QAction("&Vue d'ensemble", this);
    /**********************************************************/

     toFrontAction = new QAction(QIcon(":/images/bringtofront.png"),
                                 tr("Bring to &Front"), this);
     toFrontAction->setShortcut(tr("Ctrl+F"));
     toFrontAction->setStatusTip(tr("Bring item to front"));
     connect(toFrontAction, SIGNAL(triggered()),
             this, SLOT(bringToFront()));
 //! [23]


    sendBackAction = new QAction(QIcon(":/images/sendtoback.png"),
                                 tr("Send to &Back"), this);
    sendBackAction->setShortcut(tr("Ctrl+B"));
    sendBackAction->setStatusTip(tr("Send item to back"));
    connect(sendBackAction, SIGNAL(triggered()),
        this, SLOT(sendToBack()));

    deleteAction = new QAction(QIcon(":/images/delete.png"),
                               tr("&Delete"), this);
    deleteAction->setShortcut(tr("Delete"));
    deleteAction->setStatusTip(tr("Delete item from diagram"));
    connect(deleteAction, SIGNAL(triggered()),
        this, SLOT(deleteItem()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Quit Scenediagram example"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    aboutAction = new QAction(tr("A&bout"), this);
    aboutAction->setShortcut(tr("Ctrl+B"));
    connect(aboutAction, SIGNAL(triggered()),
            this, SLOT(about()));
}

//! [24]
void MainWindow::createMenus()
{

    //menu fichier
    menuFichier = menuBar()->addMenu("&Fichier");
    menuFichier->addAction(actionNouveau);
    menuFichier->addAction(actionCharger);
    menuFichier->addAction(actionSauvegarder);
    menuFichier->addAction(exitAction);


    //menu edition
    menuEdition = menuBar()->addMenu("&Edition");
    menuConstruction = menuEdition->addMenu("&Construction");
    menuConstruction->addAction(actionPorte);
    menuConstruction->addAction(actionContour);
    menuConstruction->addAction(actionMur);
    menuConstruction->addAction(actionEscalier);
    menuConstruction->addAction(actionAscenseur);
    menuConstruction->addAction(actionConnexion);
    //

    menuEdition->addAction(actionEtage);
    //
    menuBatiment = menuEdition->addMenu("&Batiment");

    menuBatiment->addAction(actionNouveauBatiment);
    menuBatiment->addAction(actionChoisirBatiment);

    // menu affichage
    menuAffichage = menuBar()->addMenu("&Affichage");

    menuAffichage->addAction(actionVueEnsemble);
}
//! [24]

//! [25]
void MainWindow::createToolbars()
{
//! [25]
    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(deleteAction);
    editToolBar->addAction(toFrontAction);
    editToolBar->addAction(sendBackAction);

    QToolButton *pointerButton = new QToolButton;
    pointerButton->setCheckable(true);
    pointerButton->setChecked(true);
    pointerButton->setIcon(QIcon(":/images/pointer.png"));
    QToolButton *linePointerButton = new QToolButton;
    linePointerButton->setCheckable(true);
    linePointerButton->setIcon(QIcon(":/images/linepointer.png"));

    pointerTypeGroup = new QButtonGroup(this);
    pointerTypeGroup->addButton(pointerButton, int(DiagramScene::MoveItem));
    pointerTypeGroup->addButton(linePointerButton,
                                int(DiagramScene::InsertLine));
    connect(pointerTypeGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(pointerGroupClicked(int)));

    sceneScaleCombo = new QComboBox;
    QStringList scales;
    scales << tr("50%") << tr("75%") << tr("100%") << tr("125%") << tr("150%");
    sceneScaleCombo->addItems(scales);
    sceneScaleCombo->setCurrentIndex(2);
    connect(sceneScaleCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(sceneScaleChanged(QString)));

    pointerToolbar = addToolBar(tr("Pointer type"));
    pointerToolbar->addWidget(pointerButton);
    pointerToolbar->addWidget(linePointerButton);
    pointerToolbar->addWidget(sceneScaleCombo);
//! [27]
}
//! [27]

