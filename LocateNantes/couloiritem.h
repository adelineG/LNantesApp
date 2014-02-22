#ifndef COULOIRITEM_H
#define COULOIRITEM_H
#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class DiagramScene;

class CouloirItem : public QGraphicsLineItem
{
public:
    CouloirItem(DiagramScene*);

    QPointF depart() const { return _depart;}
    QPointF fin() const { return _fin;}
    void setDepart(QPointF p){_depart=p;}
    void setFin(QPointF p){_fin=p;}

private:
    DiagramScene *parent;

    QImage image;
    QPointF _depart;
    QPointF _fin;


};

#endif // COULOIRITEM_H
