#ifndef PORTEITEM_H
#define PORTEITEM_H
#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class PorteItem : public QGraphicsEllipseItem
{
public:

    enum { Type = UserType + 8 };


    PorteItem(DiagramScene *ds);
    QString nomSalle(){return _nomSalle;}
    QString capacite(){return _capacite;}
    void getNomSalle(QString s){_nomSalle=s;}
    void getCapaSalle(QString s){_capacite=s;}
    QPointF depart() const { return _depart;}
    QPointF fin() const { return _fin;}
    void setDepart(QPointF p){_depart=p;}
    void setFin(QPointF p){_fin=p;}

    int type() const { return Type; }

private:
    DiagramScene *parent;
    QString _nomSalle;
    QString _capacite;
    QPointF _depart;
    QPointF _fin;
};

#endif // PORTEITEM_H
