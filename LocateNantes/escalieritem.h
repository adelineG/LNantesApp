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
    void setEtage(QString et){listeEtage.append(et);}

private:
    DiagramScene *parent;
    QList<QString> listeEtage;
};

#endif // ESCALIERITEM_H
