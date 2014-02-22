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

private:
    DiagramScene *parent;

    QLineEdit *nom;
    QLineEdit *etage;


    QPushButton *valider;
    QPushButton *annuler;

};

#endif // FENETREBAT_H
