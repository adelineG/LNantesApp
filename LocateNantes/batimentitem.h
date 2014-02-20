#ifndef BATIMENTITEM_H
#define BATIMENTITEM_H

#include <QtGui>
#include <QPainter>
#include <diagramscene.h>

class DiagramScene;

class BatimentItem : public QGraphicsRectItem
{
    enum { Type = UserType + 1 };

public:
    BatimentItem(DiagramScene*);
   // void paint(QPainter& ,const QPointF &, const QPointF &)const ;
    QString nom() const { return _nom; }
    int nbEtages() const { return _nbEtages; }
    int type() const { return Type; }

protected:
    DiagramScene *parent;

private:
    QImage image;
    QPainter painter;
    QString _nom;
    int _nbEtages;


};

#endif // BATIMENTITEM_H
