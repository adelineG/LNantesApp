#include "batimentitem.h"



void BatimentItem::draw(const QPointF &lastPoint, const QPointF &endPoint){

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    painter.drawRect(QRectF(lastPoint,endPoint));

}
