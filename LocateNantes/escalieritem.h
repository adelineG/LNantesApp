#ifndef ESCALIERITEM_H
#define ESCALIERITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>
#include <QList>

class EscalierItem : public QGraphicsPixmapItem
{
public:

     enum { Type = UserType + 5 };

    EscalierItem(DiagramScene *ds);
    void setEtage(QString et){listeEtage.append(et);}
    QPointF position;

      int type() const { return Type; }

private:
    DiagramScene *parent;
    QList<QString> listeEtage;
};

#endif // ESCALIERITEM_H
