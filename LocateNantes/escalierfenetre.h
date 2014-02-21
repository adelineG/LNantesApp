#ifndef ESCALIERFENETRE_H
#define ESCALIERFENETRE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QComboBox>
#include "diagramscene.h"

class EscalierFenetre  : public QWidget
{
     Q_OBJECT

public:
    EscalierFenetre(DiagramScene *ds);

public slots:
        void sauvegarder();
        void demandeNom();
        void choixNom();


private:
        DiagramScene *parent;
        QLineEdit *nom;
        QLineEdit *etage;
        QRadioButton *radio1;
        QRadioButton *radio2;
        QPushButton *valider;
        QPushButton *annuler;
        QVBoxLayout *layoutPrincipal;
        QGroupBox *groupDefinition;
        QHBoxLayout *boutonsLayout;
        QFormLayout *definitionLayout;
        QWidget *widgetGadget;
        QComboBox *listeExistant;
        bool actifNouveau;
};

#endif // ESCALIERFENETRE_H
