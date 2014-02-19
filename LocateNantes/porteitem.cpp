#include "porteitem.h"



void PorteItem::draw(const QPointF &lastPoint, const QPointF &endPoint){

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    QPoint offxh = lastPoint;
    QPoint offxv = lastPoint;
    QPoint offyv = endPoint;
    QPoint offyh = endPoint;
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

    painter.drawLine(QLine(offxh, lastPoint));
    painter.drawLine(QLine(offxv, lastPoint));
    painter.drawLine(QLine(endPoint, offyh));
    painter.drawLine(QLine(endPoint, offyv));
    painter.setPen(QPen(myPenColor, 8, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawEllipse(endPoint,int(distance/3),int(distance/3));
    painter.drawEllipse(lastPoint,int(distance/3),int(distance/3));


}
