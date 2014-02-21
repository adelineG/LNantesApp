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

private:
    DiagramScene *parent;
    QString nomSalle;
    QString capacite;
};

#endif // PORTEITEM_H
