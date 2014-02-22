#ifndef CLOISONITEM_H
#define CLOISONITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class CloisonItem : public QGraphicsLineItem
{
public:
    CloisonItem(DiagramScene *ds);
    QPointF depart() const { return _depart;}
    QPointF fin() const { return _fin;}

private:
    DiagramScene *parent;
    QPointF _depart;
    QPointF _fin;
};

#endif // CLOISONITEM_H
