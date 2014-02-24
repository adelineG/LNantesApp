#include "fenetreconnexion.h"
#include "QLayout"
#include "QBoxLayout"
#include "QFormLayout"
#include "QGroupBox"
#include "QMessageBox"
#include "QString"
#include "QRadioButton"
#include "QWidget"


FenetreConnexion::FenetreConnexion(DiagramScene *ds)
{


    parent=ds;
    QString name = "Batiment ";
    name += parent->bat->nom();
    name += " etage ";
    name += parent->bat->etage();
    nom = new QLineEdit;
    etage = new QLineEdit;

    radio1 = new QRadioButton(tr("&Nouvelle"));
    radio2 = new QRadioButton(tr("&Avec le batiment : "));


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->setAlignment(Qt::AlignLeft);

    /**************************test caché *******************************/
    nom = new QLineEdit;
    definitionLayout = new QFormLayout;
    definitionLayout->addRow("&Nom :", nom);
    widgetGadget=new QWidget();
    widgetGadget->setLayout(definitionLayout);

    listeExistant = new QComboBox();
    listeExistant->addItems(parent->listBat);



    /**************************test caché *******************************/
    vbox->addWidget(radio1);
    vbox->addWidget(widgetGadget);
    vbox->addWidget(radio2);
    vbox->addWidget(listeExistant);

    widgetGadget->hide();
    listeExistant->hide();
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
    setWindowTitle("Definition d'une connexion");
    resize(250, 150);
}

void FenetreConnexion::sauvegarder()
{
    // On vérifie que le nom
    if (nom->text().isEmpty() && !radio2->isChecked())
    {
        QMessageBox::critical(this, "Erreur", "Vous n'avez renseigne aucun champs");
        return; // Arrêt de la méthode
    }

    if(!(nom->text().isEmpty())){
        parent->connexion->setConnect(nom->text());
    }
     else {
        parent->connexion->setConnect(listeExistant->currentText());
    }
    this->close();
}

void FenetreConnexion::demandeNom(){

    listeExistant->hide();
    widgetGadget->show();
    this->update();

}

void FenetreConnexion::choixNom(){

    listeExistant->show();
    widgetGadget->hide();
    this->update();

}


