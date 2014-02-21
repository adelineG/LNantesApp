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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include "diagramitem.h"
#include "planmodel.h"




QT_BEGIN_NAMESPACE
class QAction;
class QToolBox;
class QSpinBox;
class QComboBox;
class QFontComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QToolButton;
class QAbstractButton;
class QGraphicsView;
class DiagramScene;
class PlanModel;
QT_END_NAMESPACE

//! [0]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   MainWindow();
   DiagramScene* getScene() const {return scene;}
   void setScene(DiagramScene* sc){scene=sc;}
   DiagramScene *scene;
   PlanModel *plan;

private slots:
    //void backgroundButtonGroupClicked(QAbstractButton *button);
    void deleteItem();
    void pointerGroupClicked(int id);
    void bringToFront();
    void sendToBack();
    void itemInserted(DiagramItem *item);
    void textInserted(QGraphicsTextItem *item);
    void sceneScaleChanged(const QString &scale);
    void itemSelectionChanged(QGraphicsItem *item);
    void about();
    void ouvrirBatiment();
    void ouvrirEscalier();
    void ouvrirConnexion();
    void ouvrirEtage();
    void ouvrirCouloir();
    void ouvrirAscenseur();
    void ouvrirCloison();
    void ouvrirPorte();

private:
    void createToolBox();
    void createActions();
    void createMenus();
    void createToolbars();
    void createStatusBar();
    void sauvegardePlan();
    
    QMenu *createColorMenu(const char *slot, QColor defaultColor);
    QIcon createColorToolButtonIcon(const QString &image, QColor color);
    QIcon createColorIcon(QColor color);


    QGraphicsView *view;


    QAction *actionQuitter;
    QAction *addAction;
    QAction *deleteAction;
    QAction *exitAction;


    QAction *toFrontAction;
    QAction *sendBackAction;
    QAction *aboutAction;

    QAction *actionNouveau;
    QAction *actionCharger;
    QAction *actionSauvegarder;

    QAction *actionPorte;
    QAction *actionCloison;
    QAction *actionEscalier;
    QAction *actionAscenseur;
    QAction *actionConnexion;
    QAction *actionEtage;
    QAction *actionNouveauBatiment;
    QAction *actionEchelle;
    QAction *actionVueEnsemble;


    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuConstruction;
    QMenu *menuBatiment;
    QMenu *menuAffichage;
    QMenu *aboutMenu;
    QMenu *itemMenu;
    QMenu *itemFile;
    QMenu *fileMenu;

    QToolBar *textToolBar;
    QToolBar *editToolBar;
    QToolBar *pointerToolbar;

    QComboBox *sceneScaleCombo;
    QComboBox *itemColorCombo;
    QComboBox *textColorCombo;

    QDockWidget *toolBoxDock;
    QButtonGroup *pointerTypeGroup;
    QButtonGroup *backgroundButtonGroup;

    QStatusBar *statusBar;
};
//! [0]

#endif
