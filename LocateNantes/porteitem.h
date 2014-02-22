#ifndef PORTEITEM_H
#define PORTEITEM_H
#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class PorteItem : public QGraphicsEllipseItem
{
public:
    PorteItem(DiagramScene *ds);
    void getNomSalle(QString s){nomSalle=s;}
    void getCapaSalle(QString s){capacite=s;}
    QPointF depart() const { return _depart;}
    QPointF fin() const { return _fin;}
    void setDepart(QPointF p){_depart=p;}
    void setFin(QPointF p){_fin=p;}

private:
    DiagramScene *parent;
    QString nomSalle;
    QString capacite;
    QPointF _depart;
    QPointF _fin;
};

#endif // PORTEITEM_H
