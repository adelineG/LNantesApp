#ifndef FENETRECONNEXION_H
#define FENETRECONNEXION_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QComboBox>

class FenetreConnexion : public QWidget
{

    Q_OBJECT

public:
    FenetreConnexion();

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

};

#endif // FENETRECONNEXION_H
