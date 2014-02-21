#include "fenetreetage.h"
#include "QMessageBox"
#include ""


FenetreEtage::FenetreEtage (DiagramScene *ds)
{

    QString name= "Batiment 1 ";

    parent=ds;
    etage = new QLineEdit;

    radio1 = new QRadioButton(tr("&Inferieur"));
    radio2 = new QRadioButton(tr("&Superieur"));


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->setAlignment(Qt::AlignLeft);

    /**************************test caché *******************************/

    definitionLayout = new QFormLayout;
    definitionLayout->addRow("&Nom :", etage);
    widgetGadget=new QWidget();
    widgetGadget->setLayout(definitionLayout);

    /**************************test caché *******************************/
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(widgetGadget);
    radio2->setChecked(true);
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

    connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
    connect(valider, SIGNAL(clicked()), this, SLOT(sauvegarder()));

    setLayout(layoutPrincipal);
    setWindowTitle("Definition d'un etage");
    resize(250, 150);
}

//il faut créer une nouvelle scene car une nouvelle scene == un nouvel etage d un batiment
void FenetreEtage::sauvegarder()
{
    // On vérifie que le nom de la classe n'est pas vide, sinon on arrête
        if (etage->text().isEmpty())
        {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer le nom de l'etage a creer pour valider");
            return; // Arrêt de la méthode
        }

        this->close();
}



