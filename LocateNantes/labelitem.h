#ifndef LABELITEM_H
#define LABELITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class LabelItem : public QGraphicsSimpleTextItem
{
public:
    LabelItem(DiagramScene *ds);
    enum { Type = UserType + 7 };

    int type() const { return Type; }

private:
    DiagramScene *parent;
};

#endif // LABELITEM_H
