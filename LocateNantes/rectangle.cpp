#include <QtGui>

#include "Rectangle.h"
#include "fenetrebat.h"

//! [0]
Rectangle::Rectangle(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    scribbling = false;
    myPenWidth = 3;
    myPenColor = Qt::black;
}


//! [9]
void Rectangle::clearImage()
//! [9] //! [10]
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}
//! [10]

//! [11]
void Rectangle::mousePressEvent(QMouseEvent *event)
//! [11] //! [12]
{
    if (event->button() == Qt::LeftButton) {

        lastPoint = event->pos();
        scribbling = true;
    }
}

void Rectangle::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling) ;
    //drawLineTo(event->pos());
}

void Rectangle::mouseReleaseEvent(QMouseEvent *event)
{
    FenetreBat *fen = new FenetreBat();
    fen->show();

    if (event->button() == Qt::LeftButton && scribbling) {

        drawLineTo(event->pos());
        scribbling = false;
    }
}

//! [12] //! [13]
void Rectangle::paintEvent(QPaintEvent *event)
//! [13] //! [14]
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}
//! [14]

//! [15]
void Rectangle::resizeEvent(QResizeEvent *event)
//! [15] //! [16]
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}
//! [16]

//! [17]
void Rectangle::drawLineTo(const QPoint &endPoint)
//! [17] //! [18]
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    /*************************dessin couloir*****************************/
    /*QPoint offx = lastPoint;
    QPoint offy = endPoint;
    int testx = endPoint.x()-lastPoint.rx();

    int testy = endPoint.y()-lastPoint.ry();

    if( testx <= testy ){

        offx += QPoint(50,0);

        offy += QPoint(50,0);
    }
    else
    {

        offx += QPoint(0,50);

        offy += QPoint(0,50);
    }
    painter.drawLine(QLine(lastPoint, endPoint));
    painter.drawLine(QLine(offx, offy));*/
    /*************************dessin couloir*****************************/
    /*************************dessin batiment*****************************/
    //painter.drawRect(QRect(lastPoint,endPoint));
    /*************************dessin batiment*****************************/

    /*************************dessin porte*****************************/

    QPoint offxh = lastPoint;
    QPoint offxv = lastPoint;
    QPoint offyv = endPoint;
    QPoint offyh = endPoint;
    int testx = endPoint.x()-lastPoint.rx();
    int testy = endPoint.y()-lastPoint.ry();
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



    /*************************dessin porte*****************************/

    modified = true;

    update();
    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}
//! [18]

//! [19]
void Rectangle::resizeImage(QImage *image, const QSize &newSize)
//! [19] //! [20]
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}
//! [20]

//! [21]
void Rectangle::print()
{
#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::HighResolution);

    QPrintDialog *printDialog = new QPrintDialog(&printer, this);
    //! [21] //! [22]
    if (printDialog->exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(image.rect());
        painter.drawImage(0, 0, image);
    }
#endif // QT_NO_PRINTER
}
//! [22]
