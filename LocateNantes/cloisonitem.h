#ifndef CLOISONITEM_H
#define CLOISONITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class CloisonItem : public QGraphicsLineItem
{
public:

     enum { Type = UserType + 3 };

    CloisonItem(DiagramScene *ds);
    QPointF depart() const { return _depart;}
    QPointF fin() const { return _fin;}

     int type() const { return Type; }

private:
    DiagramScene *parent;
    QPointF _depart;
    QPointF _fin;
};

#endif // CLOISONITEM_H
