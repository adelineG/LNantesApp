#ifndef SORTIEITEM_H
#define SORTIEITEM_H

#include <QtGui>
#include <diagramscene.h>

class DiagramScene;

class SortieItem : public QGraphicsPixmapItem
{

public:
    SortieItem(DiagramScene*);
  //  void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

protected:
    DiagramScene *parent;

private:
    static QPixmap image;
};

#endif // BATIMENTITEM_H
