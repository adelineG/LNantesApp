#ifndef LABELITEM_H
#define LABELITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class LabelItem : public QGraphicsSimpleTextItem
{
public:
    LabelItem(DiagramScene *ds);

private:
    DiagramScene *parent;
};

#endif // LABELITEM_H
