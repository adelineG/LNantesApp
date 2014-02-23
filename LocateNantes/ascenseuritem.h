#ifndef ASCENSEURITEM_H
#define ASCENSEURITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class AscenseurItem : public QGraphicsPixmapItem
{
public:

     enum { Type = UserType + 2};

    AscenseurItem(DiagramScene *ds);
    QPointF position;

    int type() const{ return Type;}

private:
    DiagramScene *parent;
};

#endif // ASCENSEURITEM_H
