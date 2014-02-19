#ifndef COULOIRITEM_H
#define COULOIRITEM_H
#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class DiagramScene;

class CouloirItem : public QGraphicsLineItem
{
public:
    CouloirItem(DiagramScene*);



private:
    DiagramScene *parent;

    QImage image;


};

#endif // COULOIRITEM_H
