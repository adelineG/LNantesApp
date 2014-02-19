#ifndef BATIMENTITEM_H
#define BATIMENTITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class DiagramScene;

class BatimentItem : public QGraphicsRectItem
{
    Q_OBJECT
public:
    BatimentItem(DiagramScene*);
    void draw(QPainter ,const QPointF &, const QPointF &)const ;

protected:
    DiagramScene *parent;

private:

    QImage image;
    QPainter painter;


};

#endif // BATIMENTITEM_H
