#ifndef PORTEITEM_H
#define PORTEITEM_H
#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class PorteItem : public QGraphicsPathItem
{
public:
    PorteItem(DiagramScene *ds){
        parent = ds;
    }


private:
    DiagramScene *parent;
    QImage image;
    QPainter *painter;

    void draw(QPointF,QPointF);
};

#endif // PORTEITEM_H
