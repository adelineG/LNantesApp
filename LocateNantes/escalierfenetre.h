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

class EscalierFenetre  : public QWidget
{
     Q_OBJECT

public:
    EscalierFenetre();

public slots:
        void sauvegarder();
        void demandeNom();
        void choixNom();


private:
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
