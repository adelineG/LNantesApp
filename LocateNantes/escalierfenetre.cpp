#include "escalierfenetre.h"
#include "QLayout"
#include "QBoxLayout"
#include "QFormLayout"
#include "QGroupBox"
#include "QMessageBox"
#include "QString"
#include "QRadioButton"
#include "QWidget"
#include "escalieritem.h"


EscalierFenetre::EscalierFenetre(DiagramScene *ds)
{
    parent=ds;
    QString name = "";
    actifNouveau= false;
    /*if(parent->listBatiment.isEmpty()){
        name = "";
    }
    else {
        name= parent->listBatiment.front()->nom();
        name += " etage ";
        name += parent->listBatiment.front()->etage();
    }*/


    nom = new QLineEdit;
    etage = new QLineEdit;



    //QGroupBox *groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));

    radio1 = new QRadioButton(tr("&Nouveau"));
    radio2 = new QRadioButton(tr("&Existant"));


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->setAlignment(Qt::AlignLeft);

    /**************************test caché *******************************/
    nom = new QLineEdit;
    definitionLayout = new QFormLayout;
    definitionLayout->addRow("&Vers l'etage :", nom);
    widgetGadget=new QWidget();
    widgetGadget->setLayout(definitionLayout);

    /*
    listeExistant = new QComboBox();
    //if (myEscalier){
        listeExistant->addItem("Escalier1");
        listeExistant->addItem("Escalier3");
   // }*/


    /**************************test caché *******************************/
    vbox->addWidget(radio1);
    vbox->addWidget(widgetGadget);
   // vbox->addWidget(radio2);
  //  vbox->addWidget(listeExistant);

    widgetGadget->hide();
  //  listeExistant->hide();
    vbox->addStretch(0);

    // Layout : boutons du bas (générer, quitter...)
    valider = new QPushButton("&Ok");
    annuler = new QPushButton("&Annuler");

    boutonsLayout = new QHBoxLayout;
    boutonsLayout->setAlignment(Qt::AlignRight);

    boutonsLayout->addWidget(valider);
    boutonsLayout->addWidget(annuler);

    groupDefinition = new QGroupBox(name);
    groupDefinition->setLayout(vbox);

    layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(groupDefinition);
    layoutPrincipal->addLayout(boutonsLayout);

    connect(radio1,SIGNAL(clicked()), this,SLOT(demandeNom()));
    connect(radio2,SIGNAL(clicked()), this,SLOT(choixNom()));
    connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
    connect(valider, SIGNAL(clicked()), this, SLOT(sauvegarder()));

    setLayout(layoutPrincipal);
    setWindowTitle("Definition d'un escalier");
    resize(250, 150);
}

void EscalierFenetre::sauvegarder()
{
    // On vérifie que le nom de la classe n'est pas vide, sinon on arrête
        if (nom->text().isEmpty())
        {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer le nom de l'escalier pour valider");
            return; // Arrêt de la méthode
        }

        if(!nom->text().isEmpty())parent->escalier->setEtage(nom->text());
        this->close();
}

void EscalierFenetre::demandeNom(){

      // listeExistant->hide();
       widgetGadget->show();
       this->update();

}

void EscalierFenetre::choixNom(){

     //  listeExistant->show();
       widgetGadget->hide();
       this->update();
}

