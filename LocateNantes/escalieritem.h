#ifndef ESCALIERITEM_H
#define ESCALIERITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>
#include <QList>

class EscalierItem : public QGraphicsPixmapItem
{
public:
    EscalierItem(DiagramScene *ds);
    void setEtage(QString et){listeEtage.push_front(et);}

private:
    DiagramScene *parent;
    QList<QString> listeEtage;
};

#endif // ESCALIERITEM_H
