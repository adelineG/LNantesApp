#ifndef FENETREBAT_H
#define FENETREBAT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "diagramscene.h"
#include "mainwindow.h"

class FenetreBat : public QWidget
{
    Q_OBJECT
public:
   FenetreBat(DiagramScene *ds);


public slots:
    void sauvegarder();
    void demandeNomBat();
    void choixNomBat();
    void demandeNomEtage();
    void choixNomEtage();

private:
    DiagramScene *parent;

    QLineEdit *nom;
    QLineEdit *etage;

    QRadioButton *radio1;
    QRadioButton *radio2;
    QRadioButton *radio3;
    QRadioButton *radio4;
    bool actifNouveauBat;
    bool actifNouveauEtage;
    QPushButton *valider;
    QPushButton *annuler;
    QWidget *widgetGadgetBat;
    QWidget *widgetGadgetEtage;
    QComboBox *sceneScaleComboBat;
    QComboBox *sceneScaleComboEtage;
    QGroupBox *groupDefinition;

};

#endif // FENETREBAT_H
