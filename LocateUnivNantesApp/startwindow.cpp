#include <QWidget>
#include <QGridLayout>
#include "startwindow.h"
#include "mainwindow.h"

StartWindow::StartWindow(): QWidget()
{

    setFixedSize(600, 400);
    setWindowTitle("Bienvenue");


    // Constructions des boutons
    m_boutonNouveau = new QPushButton(" Nouveau", this);
    m_boutonCharger = new QPushButton("Charger Plan", this);

    //message
    message = new QString("Bienvenue dans l applicatiion LocateUniv Nantes");
    QGridLayout *layout = new QGridLayout;


    //layout->addWidget(message, 0, 0, 1, 2);
   // layout->addWidget((QWidget)message,0,0,1,2);
    layout->addWidget(m_boutonNouveau, 1, 1);
    layout->addWidget(m_boutonCharger, 2, 1);

    this->setLayout(layout);

    // Connexion du clic du bouton à la fermeture de l'application
    QObject::connect(m_boutonNouveau, SIGNAL(clicked()), qApp, SLOT(ouvrirMainWindow(this)));
    QObject::connect(m_boutonCharger, SIGNAL(clicked()), qApp, SLOT(ouvrirDialogueChargement()));

}


void ouvrirMainWindow(QWidget* courante){

    MainWindow maMain;
    maMain.show();

    courante->close();
}

 void ouvrirDialogueChargement(){

         QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString());
         QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);
         MainWindow maMain;
         maMain.show();
 }

