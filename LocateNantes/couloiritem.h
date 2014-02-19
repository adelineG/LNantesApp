#ifndef COULOIRITEM_H
#define COULOIRITEM_H
#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class CouloirItem : public QGraphicsLineItem
{
public:
    CouloirItem(DiagramScene *ds){
        parent = ds;
    }



private:
    DiagramScene *parent;

    QImage image;

    QPainter painter;
    void paint(const QPointF&, const QPointF&);
};

#endif // COULOIRITEM_H
