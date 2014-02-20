#ifndef CONNEXIONITEM_H
#define CONNEXIONITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class ConnexionItem : public QGraphicsPixmapItem
{
public:
    ConnexionItem(DiagramScene *ds);

private:
    DiagramScene* parent;
};

#endif // CONNEXIONITEM_H
