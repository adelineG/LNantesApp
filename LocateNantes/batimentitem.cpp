#include "batimentitem.h"
#include "diagramscene.h"

BatimentItem::BatimentItem(DiagramScene *ds) : parent(ds){

}

/*void BatimentItem::paint(QPainter& painter,const QPointF &lastPoint, const QPointF &endPoint) const{

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    painter.drawRect(QRectF(lastPoint,endPoint));

    qDebug()<< lastPoint << "---------------" <<endPoint;

}*/
