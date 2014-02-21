#include "fenetreporte.h"
#include "QLayout"
#include "QBoxLayout"
#include "QFormLayout"
#include "QGroupBox"
#include "QMessageBox"
#include <QDebug>

FenetrePorte::FenetrePorte(DiagramScene *ds)

{
    parent=ds;
    nom = new QLineEdit;
    capacite = new QLineEdit;

    QFormLayout *definitionLayout = new QFormLayout;
    definitionLayout->addRow("&Nom :", nom);
    definitionLayout->addRow("&Capacite :", capacite);

    // Layout : boutons du bas (générer, quitter...)
    valider = new QPushButton("&Ok");
    annuler = new QPushButton("&Annuler");

    QHBoxLayout *boutonsLayout = new QHBoxLayout;
    boutonsLayout->setAlignment(Qt::AlignRight);

    boutonsLayout->addWidget(valider);
    boutonsLayout->addWidget(annuler);

    QGroupBox *groupDefinition = new QGroupBox("Definition d'une nouvelle salle :");
    groupDefinition->setLayout(definitionLayout);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(groupDefinition);
    layoutPrincipal->addLayout(boutonsLayout);


    connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
    connect(valider, SIGNAL(clicked()), this, SLOT(sauvegarder()));

    setLayout(layoutPrincipal);
    setWindowTitle("Salle");
    resize(200, 150);
}

void FenetrePorte::sauvegarder()
{
    // On vérifie que le nom de la classe n'est pas vide, sinon on arrête
        if (nom->text().isEmpty())
        {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer le nom de la salle");
            return; // Arrêt de la méthode
        }


        parent->label->setText(nomSalle);
        parent->porteD->getNomSalle(nom->text());
        parent->porteD->getCapaSalle(capacite->text());

        this->close();
}
