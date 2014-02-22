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
    scene = new DiagramScene(itemMenu, this);
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));
    connect(scene, SIGNAL(itemInserted(DiagramItem*)),this, SLOT(itemInserted(DiagramItem*)));
    connect(scene, SIGNAL(textInserted(QGraphicsTextItem*)), this, SLOT(textInserted(QGraphicsTextItem*)));
    connect(scene, SIGNAL(itemSelected(QGraphicsItem*)),this, SLOT(itemSelectionChanged(QGraphicsItem*)));
    createActions();
    createToolBox();
    createMenus();
    createToolbars();
    createStatusBar();


    /**************************** Grid ********************************************/
    view = new QGraphicsView(scene);
    plan = new PlanModel(this);

    setCentralWidget(view);

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
void MainWindow::itemSelectionChanged(QGraphicsItem *item)
{
    DiagramTextItem *textItem = qgraphicsitem_cast<DiagramTextItem *>(item);

    if (item == NULL) {
        statusBar->clearMessage();
        return;
    }


    if (item->type() == QGraphicsItem::UserType + 1){ //Batiment
        BatimentItem *bat = static_cast<BatimentItem*>(item);
        statusBar->showMessage(QString::fromUtf8("Bât. ") + bat->nom() + QString::fromUtf8(" - ") + QString::number(bat->nbEtages()) + QString::fromUtf8(" étage(s)"));
    }
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
    FenetreBat *formulaire = new FenetreBat(scene);
    formulaire->show();
    scene->setMode(DiagramScene::AddBatiment);
}

void MainWindow::ouvrirCouloir(){
    scene->setMode(DiagramScene::AddCouloir);
}

void MainWindow::ouvrirEscalier(){
    EscalierFenetre *formulaire = new EscalierFenetre(scene);
    formulaire->show();
    scene->setMode(DiagramScene::AddEscalier);
}

void MainWindow::ouvrirConnexion(){
    FenetreConnexion *formulaire = new FenetreConnexion(scene);
    formulaire->show();
    scene->setMode(DiagramScene::AddConnexion);
}

void MainWindow::ouvrirPorte(){
    scene->setMode(DiagramScene::AddPorte);
}

void MainWindow::ouvrirCloison(){
    scene->setMode(DiagramScene::AddCloison);
}


void MainWindow::ouvrirAscenseur(){

    scene->setMode(DiagramScene::AddAscenseur);
}



void MainWindow::ouvrirEtage(){
    FenetreEtage *formulaire = new FenetreEtage(scene);
    formulaire->show();
    //plan->setListScene(scene);
    //sauvegarde l autre scene et en créer une nouvelle
    //DiagramScene *scene = new DiagramScene();
}

void MainWindow::createStatusBar()
{
    statusBar = new QStatusBar;
    setStatusBar(statusBar);
}

//! [21]
void MainWindow::createToolBox()
{
    //! [22]
    toolBoxDock = new QDockWidget;
    ChoixConstruction* toolBox = new ChoixConstruction(toolBoxDock);
    toolBox->setMainWindow(this);
    toolBoxDock->setWidget(toolBox);
    addDockWidget(Qt::RightDockWidgetArea, toolBoxDock);
}
//! [22]

//! [23]
void MainWindow::createActions()
{

    /**********************************************************/

    actionNouveau = new QAction("&Nouveau plan", this);
    actionNouveau->setShortcut(tr("Ctrl+N"));
    actionCharger = new QAction("&Charger", this);
    actionSauvegarder = new QAction("&Sauvegarder", this);
    actionSauvegarder->setShortcut(tr("Ctrl+S"));
    connect(actionSauvegarder,SIGNAL(triggered()),this,SLOT(sauvegardePlan()));
    actionPorte = new QAction("&Porte", this);
    connect(actionPorte,SIGNAL(triggered()),this,SLOT(ouvrirPorte()));

    actionCloison = new QAction("&Cloison", this);
    actionEscalier = new QAction("&Escalier", this);
    connect(actionEscalier,SIGNAL(triggered()),this,SLOT(ouvrirEscalier()));
    actionAscenseur = new QAction("&Ascenseur", this);
     connect(actionAscenseur,SIGNAL(triggered()),this,SLOT(ouvrirAscenseur()));
    actionConnexion = new QAction("&Connexion", this);
     connect(actionConnexion,SIGNAL(triggered()),this,SLOT(ouvrirConnexion()));

    actionEtage = new QAction("&Etage", this);
    connect(actionEtage, SIGNAL(triggered()),this, SLOT(ouvrirEtage()));

    actionNouveauBatiment = new QAction("&Nouveau", this);
    connect(actionNouveauBatiment,SIGNAL(triggered()),this,SLOT(ouvrirBatiment()));

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
    menuBatiment = menuEdition->addMenu("&Batiment");
    menuBatiment->addAction(actionNouveauBatiment);
   // menuBatiment->addAction(actionChoisirBatiment);
    menuConstruction = menuEdition->addMenu("&Construction");
    menuConstruction->addAction(actionPorte);
    menuConstruction->addAction(actionCloison);
    menuConstruction->addAction(actionEscalier);
    menuConstruction->addAction(actionAscenseur);
    menuConstruction->addAction(actionConnexion);
    //
    menuEdition->addAction(actionEtage);
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

void MainWindow::sauvegardePlan(){
    plan->setListScene(scene);
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    //exporter au format xml
    //exporter au format png
}
