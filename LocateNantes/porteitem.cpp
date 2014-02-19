#include "porteitem.h"


PorteItem::PorteItem(DiagramScene *ds) : parent(ds)
{
   /* QPainterPath path;

    QPointF offxh = lastPoint;
    QPointF offxv = lastPoint;
    QPointF offyv = endPoint;
    QPointF offyh = endPoint;
    int testx = endPoint.x()-lastPoint.x();
    int testy = endPoint.y()-lastPoint.y();
    int distance = (sqrt((testx*testx)+(testy*testy)))*0.25;


    if( testx <= testy ){
        offxh -= QPoint(distance,0);
        offxv += QPoint(distance,0);
        offyh -= QPoint(distance,0);
        offyv += QPoint(distance,0);
    }
    else
    {
        offxh -= QPoint(0,distance);
        offxv += QPoint(0,distance);
        offyh -= QPoint(0,distance);
        offyv += QPoint(0,distance);
    }

    path.addLine(QLine(offxh.x(), offxh.y(), lastPoint.x(), lastPoint.y()));
    path.addLine(QLine(offxv.x(), offxv.y(), lastPoint.x(), lastPoint.y()));
    path.addLine(QLine(endPoint.x(), endPoint.y(), offyh.x(), offyh.y()));
    path.addLine(QLine(endPoint.x(), endPoint.y(), offyh.x(), offyh.y()));
    path.addEllipse(endPoint,int(distance/3),int(distance/3));
    path.addEllipse(lastPoint,int(distance/3),int(distance/3));

    setPath(path);*/
}
