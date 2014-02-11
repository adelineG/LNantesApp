#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
     //---------------------------Menu-----------------------------------//
    //menu fichier
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionNouveau = new QAction("&Nouveau plan", this);
    QAction *actionCharger = new QAction("&Charger", this);
    QAction *actionSauvegarder = new QAction("&Sauvegarder", this);
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionNouveau);
    menuFichier->addAction(actionCharger);
    menuFichier->addAction(actionSauvegarder);
    menuFichier->addAction(actionQuitter);


    //menu edition
    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    QMenu *menuConstruction = menuEdition->addMenu("&Construction");
    QAction *actionPorte = new QAction("&Porte", this);
    QAction *actionContour = new QAction("&Contour", this);
    QAction *actionMur = new QAction("&Mur", this);
    QAction *actionEscalier = new QAction("&Escalier", this);
    QAction *actionAscenseur = new QAction("&Ascenseur", this);
    QAction *actionConnexion = new QAction("&Connexion", this);
    menuConstruction->addAction(actionPorte);
    menuConstruction->addAction(actionContour);
    menuConstruction->addAction(actionMur);
    menuConstruction->addAction(actionEscalier);
    menuConstruction->addAction(actionAscenseur);
    menuConstruction->addAction(actionConnexion);
    //
    QAction *actionEtage = new QAction("&Etage", this);
    menuEdition->addAction(actionEtage);
    //
    QMenu *menuBatiment = menuEdition->addMenu("&Batiment");
    QAction *actionNouveauBatiment = new QAction("&Nouveau", this);
    QAction *actionChoisirBatiment = new QAction("&Choisir", this);
    menuBatiment->addAction(actionNouveauBatiment);
    menuBatiment->addAction(actionChoisirBatiment);

    // menu affichage
    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");
    QAction *actionEchelle = new QAction("&Echelle", this);
    QAction *actionVueEnsemble = new QAction("&Vue d'ensemble", this);
    menuAffichage->addAction(actionEchelle);
    menuAffichage->addAction(actionVueEnsemble);

    //--------------------------------Menu Fin----------------------------------------//

    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);


}

