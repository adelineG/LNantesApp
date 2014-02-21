#ifndef CONNEXIONITEM_H
#define CONNEXIONITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>
#include <QList>

class ConnexionItem : public QGraphicsPixmapItem
{
public:
    ConnexionItem(DiagramScene *ds);
    void setConnect(QString cur, QString a){connect->push_front(cur);connect->push_front(a);}
    QList <QString> *connect;
private:
    DiagramScene* parent;


};

#endif // CONNEXIONITEM_H
