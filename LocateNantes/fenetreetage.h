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
#include "mainwindow.h"
#include "diagramscene.h"

class FenetreEtage : public QWidget
{
    Q_OBJECT
public:
   FenetreEtage(DiagramScene *ds);


public slots:
        void sauvegarder();



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

};

#endif // FENETREETAGE_H
