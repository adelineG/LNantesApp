#ifndef PORTEITEM_H
#define PORTEITEM_H
#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class PorteItem : public QGraphicsEllipseItem
{
public:
    PorteItem(DiagramScene *ds);


private:
    DiagramScene *parent;
};

#endif // PORTEITEM_H
