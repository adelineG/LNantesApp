#ifndef CONNEXIONITEM_H
#define CONNEXIONITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>
#include <QList>

class ConnexionItem : public QGraphicsPixmapItem
{
public:
    enum { Type = UserType + 6 };

    ConnexionItem(DiagramScene *ds);
    void setConnect(QString a){
            connect=a;
    }
    bool exist(){return true;}

    int type() const { return Type; }

private:
    DiagramScene* parent;
    QString connect;

};

#endif // CONNEXIONITEM_H
