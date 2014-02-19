#include "couloiritem.h"
#include <QPainter>


void CouloirItem::paint( const QPointF &lastPoint, const QPointF &endPoint){

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    /*************************dessin couloir*****************************/
    QPointF offx = lastPoint;
    QPointF offy = endPoint;
    int testx = endPoint.x()-lastPoint.x();
    int testy = endPoint.y()-lastPoint.y();

    if( testx <= testy ){

        offx += QPointF(50,0);

        offy += QPointF(50,0);
    }
    else
    {

        offx += QPointF(0,50);

        offy += QPointF(0,50);
    }
    painter.drawLine(QLineF(lastPoint, endPoint));
    painter.drawLine(QLineF(offx, offy));
}
