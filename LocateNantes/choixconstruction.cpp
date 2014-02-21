#include <QtGui>
#include "choixconstruction.h"
#include "fenetrebat.h"
#include "escalierfenetre.h"
#include "fenetreconnexion.h"
#include "fenetreetage.h"
#include "mainwindow.h"
#include "diagramscene.h"

ChoixConstruction::ChoixConstruction(QWidget* parent) : QToolBox(parent)
{
    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);
    connect(buttonGroup, SIGNAL(buttonClicked(int)),this, SIGNAL(selectedConstruction(int)));

    QGridLayout *layout = new QGridLayout;
//! [21]
    /******************************* bouton batiment *******************************************************/
    QToolButton *batimentButton = new QToolButton;
    batimentButton->setCheckable(true);
    buttonGroup->addButton(batimentButton, Construction::Batiment);
    batimentButton->setIcon(QIcon(QPixmap(":/images/rectangle.png") .scaled(60, 60)));
    batimentButton->setIconSize(QSize(50, 50));
    QGridLayout *batimentLayout = new QGridLayout;
    batimentLayout->addWidget(batimentButton, 0, 0, Qt::AlignHCenter);
    batimentLayout->addWidget(new QLabel(tr("Batiment")), 1, 0, Qt::AlignCenter);
    QWidget *batimentWidget = new QWidget;
    batimentWidget->setLayout(batimentLayout);
    layout->addWidget(batimentWidget, 0, 0);

    connect(batimentButton,SIGNAL(clicked()),this,SLOT(ouvrirBatiment()));


   /******************************* bouton batiment *******************************************************/
    /******************************* bouton Couloir *******************************************************/
    QToolButton *couloirButton = new QToolButton;
    couloirButton->setCheckable(true);
    buttonGroup->addButton(couloirButton, Construction::Couloir);
    couloirButton->setIcon(QIcon(QPixmap(":/images/couloir.png") .scaled(60, 60)));
    couloirButton->setIconSize(QSize(50, 50));
    QGridLayout *couloirLayout = new QGridLayout;
    couloirLayout->addWidget(couloirButton, 0, 0, Qt::AlignHCenter);
    couloirLayout->addWidget(new QLabel(tr("Couloir")), 1, 0, Qt::AlignCenter);
    QWidget *couloirWidget = new QWidget;
    couloirWidget->setLayout(couloirLayout);
    layout->addWidget(couloirWidget, 1, 0);
    connect(couloirButton,SIGNAL(clicked()),this,SLOT(ouvrirCouloir()));

   /******************************* bouton Couloir *******************************************************/

    /******************************* bouton porte *******************************************************/
    QToolButton *porteButton = new QToolButton;
    porteButton->setCheckable(true);
    buttonGroup->addButton(porteButton, Construction::Porte);
    porteButton->setIcon(QIcon(QPixmap(":/images/porte.png") .scaled(60, 60)));
    porteButton->setIconSize(QSize(50, 50));
    QGridLayout *porteLayout = new QGridLayout;
    porteLayout->addWidget(porteButton, 0, 0, Qt::AlignHCenter);
    porteLayout->addWidget(new QLabel(tr("Porte")), 1, 0, Qt::AlignCenter);
    QWidget *porteWidget = new QWidget;
    porteWidget->setLayout(porteLayout);
    layout->addWidget(porteWidget, 2, 0);

    connect(porteButton,SIGNAL(clicked()),this,SLOT(ouvrirPorte()));
   /******************************* bouton porte *******************************************************/


    /******************************* bouton Cloison *******************************************************/
    QToolButton *cloisonButton = new QToolButton;
    cloisonButton->setCheckable(true);
    buttonGroup->addButton(cloisonButton, Construction::Cloison);
    cloisonButton->setIcon(QIcon(QPixmap(":/images/Separation.png") .scaled(60, 60)));
    cloisonButton->setIconSize(QSize(50, 50));
    QGridLayout *cloisonLayout = new QGridLayout;
    cloisonLayout->addWidget(cloisonButton, 0, 0, Qt::AlignHCenter);
    cloisonLayout->addWidget(new QLabel(tr("Cloison")), 1, 0, Qt::AlignCenter);
    QWidget *cloisonWidget = new QWidget;
    cloisonWidget->setLayout(cloisonLayout);
    layout->addWidget(cloisonWidget, 3, 0);

    connect(cloisonButton,SIGNAL(clicked()),this,SLOT(ouvrirCloison()));
   /******************************* bouton Cloison *******************************************************/
    layout->setRowStretch(4, 10);
    layout->setColumnStretch(1, 10);

    QWidget *itemWidget = new QWidget;
    itemWidget->setLayout(layout);

    QGridLayout *accesLayout = new QGridLayout;
    /******************************* bouton escalier *******************************************************/
    QToolButton *escalierButton = new QToolButton;
    escalierButton->setCheckable(true);
    buttonGroup->addButton(escalierButton, Construction::Escalier);
    escalierButton->setIcon(QIcon(QPixmap(":/images/escalier.png") .scaled(60, 60)));
    escalierButton->setIconSize(QSize(50, 50));
    QGridLayout *escalierLayout = new QGridLayout;
    escalierLayout->addWidget(escalierButton, 0, 0, Qt::AlignHCenter);
    escalierLayout->addWidget(new QLabel(tr("Escalier")), 1, 0, Qt::AlignCenter);
    QWidget *escalierWidget = new QWidget;
    escalierWidget->setLayout(escalierLayout);
    accesLayout->addWidget(escalierWidget, 0, 0);

     connect(escalierButton,SIGNAL(clicked()),this,SLOT(ouvrirEscalier()));
   /******************************* bouton escalier *******************************************************/

    /******************************* bouton ascenseur *******************************************************/
    QToolButton *ascenseurButton = new QToolButton;
    ascenseurButton->setCheckable(true);
    buttonGroup->addButton(ascenseurButton, Construction::Ascenseur);
    ascenseurButton->setIcon(QIcon(QPixmap(":/images/ascenseur.png") .scaled(60, 60)));
    ascenseurButton->setIconSize(QSize(50, 50));
    QGridLayout *ascenseurLayout = new QGridLayout;
    ascenseurLayout->addWidget(ascenseurButton, 0, 0, Qt::AlignHCenter);
    ascenseurLayout->addWidget(new QLabel(tr("Ascenseur")), 1, 0, Qt::AlignCenter);
    QWidget *ascenseurWidget = new QWidget;
    ascenseurWidget->setLayout(ascenseurLayout);
    accesLayout->addWidget(ascenseurWidget, 1, 0);

      connect(ascenseurButton,SIGNAL(clicked()),this,SLOT(ouvrirAscenseur()));
   /******************************* bouton ascenseur *******************************************************/

    /******************************* bouton connexion *******************************************************/
    QToolButton *connexionButton = new QToolButton;
    connexionButton->setCheckable(true);
    buttonGroup->addButton(connexionButton, Construction::Connexion);
    connexionButton->setIcon(QIcon(QPixmap(":/images/Sortie.png") .scaled(60, 60)));
    connexionButton->setIconSize(QSize(50, 50));
    QGridLayout *connexionLayout = new QGridLayout;
    connexionLayout->addWidget(connexionButton, 0, 0, Qt::AlignHCenter);
    connexionLayout->addWidget(new QLabel(tr("Connexion")),1, 0, Qt::AlignCenter);
    QWidget *connexionWidget = new QWidget;
    connexionWidget->setLayout(connexionLayout);
    accesLayout->addWidget(connexionWidget, 2, 0);

    connect(connexionButton,SIGNAL(clicked()),this,SLOT(ouvrirConnexion()));


   /******************************* bouton connexion *******************************************************/

    /******************************* bouton label *******************************************************/
    QToolButton *textButton = new QToolButton;
    textButton->setCheckable(true);
    buttonGroup->addButton(textButton, Construction::Label);
    textButton->setIcon(QIcon(QPixmap(":/images/label.png") .scaled(60, 60)));
    textButton->setIconSize(QSize(50, 50));
    QGridLayout *textLayout = new QGridLayout;
    textLayout->addWidget(textButton, 0, 0, Qt::AlignHCenter);
    textLayout->addWidget(new QLabel(tr("Label")),1, 0, Qt::AlignCenter);
    QWidget *textWidget = new QWidget;
    textWidget->setLayout(textLayout);
    accesLayout->addWidget(textWidget, 3, 0);
   /******************************* bouton connexion *******************************************************/

    accesLayout->setColumnStretch(1, 10);

    QWidget *backgroundWidget = new QWidget;
    backgroundWidget->setLayout(accesLayout);

    setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
    setMinimumWidth(itemWidget->sizeHint().width());
    addItem(itemWidget, tr("Construction"));
    addItem(backgroundWidget, tr("Acces"));
}

void ChoixConstruction::ouvrirBatiment(){  
    main->getScene()->setMode(DiagramScene::AddBatiment);
    main->getScene()->ouvrirFenetrePopUp();
}

void ChoixConstruction::ouvrirCouloir(){
   main->getScene()->setMode(DiagramScene::AddCouloir);

}

void ChoixConstruction::ouvrirPorte(){
   main->getScene()->setMode(DiagramScene::AddPorte);
}

void ChoixConstruction::ouvrirCloison(){
   main->getScene()->setMode(DiagramScene::AddCloison);
}



void ChoixConstruction::ouvrirEscalier(){

    main->getScene()->setMode(DiagramScene::AddEscalier);
}

void ChoixConstruction::ouvrirAscenseur(){

    main->getScene()->setMode(DiagramScene::AddAscenseur);
}

void ChoixConstruction::ouvrirConnexion(){

    main->getScene()->setMode(DiagramScene::AddConnexion);
}


