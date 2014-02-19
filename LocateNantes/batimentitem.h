#ifndef BATIMENTITEM_H
#define BATIMENTITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class BatimentItem : public QGraphicsItem
{
public:
    BatimentItem(DiagramScene *ds){
        parent = ds;
    }


private:
    DiagramScene *parent;

    QImage image;

    QPainter painter;

    void draw(const QPointF &, const QPointF &);
};

#endif // BATIMENTITEM_H
