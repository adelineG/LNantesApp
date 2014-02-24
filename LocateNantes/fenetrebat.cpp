#include "fenetrebat.h"
#include "QLayout"
#include "QBoxLayout"
#include "QFormLayout"
#include "QGroupBox"
#include "QMessageBox"


FenetreBat::FenetreBat(DiagramScene *ds)
{

    parent=ds;
    nom = new QLineEdit;
    etage = new QLineEdit;
    actifNouveauBat= false;
    actifNouveauEtage= false;

    sceneScaleComboBat = new QComboBox;
    sceneScaleComboBat->addItems(parent->listBat);

    sceneScaleComboEtage = new QComboBox;
    sceneScaleComboEtage->addItems(parent->listEtage);


    radio1 = new QRadioButton(tr("&Nouveau"));
    radio2 = new QRadioButton(tr("&Existant"));
    radio3 = new QRadioButton(tr("&Nouveau"));
    radio4 = new QRadioButton(tr("&Existant"));


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->setAlignment(Qt::AlignLeft);
    /****************partie * Batiment****************************/
    QFormLayout *definitionLayoutBat = new QFormLayout;
    definitionLayoutBat->addRow("&Nouveau Batiment :", nom);
    QFormLayout *definitionLayoutEtage = new QFormLayout;
    definitionLayoutEtage->addRow("&Nouvel etage :", etage);

    widgetGadgetBat=new QWidget();
    widgetGadgetBat->setLayout(definitionLayoutBat);

    widgetGadgetEtage=new QWidget();
    widgetGadgetEtage->setLayout(definitionLayoutEtage);





    /*********************************************/


    vbox->addWidget(radio1);
    vbox->addWidget(widgetGadgetBat);
    vbox->addWidget(radio2);
    vbox->addWidget(sceneScaleComboBat);

    vbox->addWidget(radio3);
    vbox->addWidget(widgetGadgetEtage);
    vbox->addWidget(radio4);
    vbox->addWidget(sceneScaleComboEtage);

    radio1->click();
    radio3->click();
    widgetGadgetBat->show();
    widgetGadgetEtage->show();
    sceneScaleComboBat->hide();
    sceneScaleComboEtage->hide();
    vbox->addStretch(0);



    // Layout : boutons du bas (générer, quitter...)
    valider = new QPushButton("&Ok");
    annuler = new QPushButton("&Annuler");

    QHBoxLayout *boutonsLayout = new QHBoxLayout;
    boutonsLayout->setAlignment(Qt::AlignRight);

    boutonsLayout->addWidget(valider);
    boutonsLayout->addWidget(annuler);

    QGroupBox *groupDefinition = new QGroupBox("Definition d'un nouveau batiment avec etage courant :");
    groupDefinition->setLayout(vbox);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(groupDefinition);
    layoutPrincipal->addLayout(boutonsLayout);

    connect(radio1,SIGNAL(clicked()), this,SLOT(demandeNomBat()));
    connect(radio2,SIGNAL(clicked()), this,SLOT(choixNomBat()));
    connect(radio3,SIGNAL(clicked()), this,SLOT(demandeNomEtage()));
    connect(radio4,SIGNAL(clicked()), this,SLOT(choixNomEtage()));
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

    if ( nom->text()!= ""){
        parent->bat->setNom(nom->text());
         parent->listBat.append(nom->text());
    }
    else
    {
        parent->bat->setNom(sceneScaleComboBat->currentText());
        parent->listBat.append(sceneScaleComboBat->currentText());
    }
    if (etage->text()!= ""){
        parent->bat->setEtage(etage->text());
        parent->listEtage.append(etage->text());
    }
    else {
        parent->bat->setEtage(sceneScaleComboEtage->currentText());
        parent->listEtage.append(sceneScaleComboEtage->currentText());
    }




    this->close();
}

void FenetreBat::demandeNomBat(){

    sceneScaleComboBat->hide();
    widgetGadgetBat->show();
    sceneScaleComboEtage->hide();
    widgetGadgetEtage->hide();
    this->update();

}

void FenetreBat::choixNomBat(){

    sceneScaleComboBat->show();
    widgetGadgetBat->hide();
    sceneScaleComboEtage->hide();
    widgetGadgetEtage->hide();
    this->update();
}

void FenetreBat::demandeNomEtage(){

    sceneScaleComboEtage->hide();
    widgetGadgetEtage->show();
    sceneScaleComboBat->hide();
    widgetGadgetBat->hide();
    this->update();

}

void FenetreBat::choixNomEtage(){

    sceneScaleComboEtage->show();
    widgetGadgetEtage->hide();
    sceneScaleComboBat->hide();
    widgetGadgetBat->hide();
    this->update();
}
