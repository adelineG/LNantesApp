#ifndef CLOISONITEM_H
#define CLOISONITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class CloisonItem : public QGraphicsLineItem
{
public:
    CloisonItem(DiagramScene *ds);

private:
    DiagramScene *parent;
};

#endif // CLOISONITEM_H
