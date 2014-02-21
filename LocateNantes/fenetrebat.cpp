#include "fenetrebat.h"
#include "QLayout"
#include "QBoxLayout"
#include "QFormLayout"
#include "QGroupBox"
#include "QMessageBox"


FenetreBat::FenetreBat(DiagramScene *ds)
{

    nom = new QLineEdit;
    etage = new QLineEdit;

    QFormLayout *definitionLayout = new QFormLayout;
    definitionLayout->addRow("&Nom :", nom);
    definitionLayout->addRow("&Etage :", etage);

    // Layout : boutons du bas (générer, quitter...)
    valider = new QPushButton("&Ok");
    annuler = new QPushButton("&Annuler");

    QHBoxLayout *boutonsLayout = new QHBoxLayout;
    boutonsLayout->setAlignment(Qt::AlignRight);

    boutonsLayout->addWidget(valider);
    boutonsLayout->addWidget(annuler);

    QGroupBox *groupDefinition = new QGroupBox("Definition d'un nouveau batiment avec etage courant :");
    groupDefinition->setLayout(definitionLayout);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(groupDefinition);
    layoutPrincipal->addLayout(boutonsLayout);


    connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
    connect(valider, SIGNAL(clicked()), this, SLOT(sauvegarder()));

    setLayout(layoutPrincipal);
    setWindowTitle("Batiment");
    resize(200, 150);
}

void FenetreBat::sauvegarder()
{
    // On vérifie que le nom de la classe n'est pas vide, sinon on arrête
        if (nom->text().isEmpty())
        {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer le nom du batiment");
            return; // Arrêt de la méthode
        }
        parent->bat->setNom(nom->text());
        if(!etage->text().isEmpty()) parent->bat->setEtage(etage->text());
        this->close();
}
