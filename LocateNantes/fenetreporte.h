#ifndef FENETREPORTE_H
#define FENETREPORTE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "mainwindow.h"
#include "diagramscene.h"

class FenetrePorte : public QWidget
{
    Q_OBJECT
public:
    FenetrePorte(DiagramScene *ds);

    void setNomSalle(QString n){nomSalle=n;}
    void setCapaciteSalle(QString c){cap=c;}
    QString getNomSalle(){return nomSalle;}
    QString getCapaciteSalle(){return cap;}

private:
    DiagramScene *parent;

    QLineEdit *nom;
    QLineEdit *capacite;
    QString nomSalle;
    QString cap;
    QPushButton *valider;
    QPushButton *annuler;

public slots:
    void sauvegarder();

};

#endif // FENETREPORTE_H
