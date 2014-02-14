#ifndef FENETREETAGE_H
#define FENETREETAGE_H


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QComboBox>

class FenetreEtage : public QWidget
{
    Q_OBJECT
public:
   FenetreEtage();

public slots:
        void sauvegarder();



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

#endif // FENETREETAGE_H
