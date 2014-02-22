#ifndef ASCENSEURITEM_H
#define ASCENSEURITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class AscenseurItem : public QGraphicsPixmapItem
{
public:
    AscenseurItem(DiagramScene *ds);
    QPointF position;

private:
    DiagramScene *parent;
};

#endif // ASCENSEURITEM_H
