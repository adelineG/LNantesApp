#ifndef BATIMENTITEM_H
#define BATIMENTITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class DiagramScene;

class BatimentItem : public QGraphicsRectItem
{


public:

     enum { Type = UserType + 1 };

    BatimentItem(DiagramScene*);
   // void paint(QPainter& ,const QPointF &, const QPointF &)const ;
    void setNom(QString n) {_nom=n;}
    void setEtage(QString i){etage_cur=i;}
    QString nom() const { return _nom; }
    QString etage() const { return etage_cur;}
    int nbEtages() const { return _nbEtages; }
    int type() const { return Type; }
    QPointF depart() const { return _depart;}
    QPointF fin() const { return _fin;}
    void setDepart(QPointF p){_depart=p;}
    void setFin(QPointF p){_fin=p;}



protected:
    DiagramScene *parent;

private:
    QImage image;
    QPainter painter;
    QString etage_cur;
    QString _nom;
    QPointF _depart;
    QPointF _fin;
    int _nbEtages;


};

#endif // BATIMENTITEM_H
