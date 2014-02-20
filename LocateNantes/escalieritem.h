#ifndef ESCALIERITEM_H
#define ESCALIERITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class EscalierItem : public QGraphicsPixmapItem
{
public:
    EscalierItem(DiagramScene *ds);
private:
    DiagramScene *parent;
};

#endif // ESCALIERITEM_H
