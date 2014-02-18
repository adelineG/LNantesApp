#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QtGui/QWidget>
#include<QMouseEvent>
#include<QGraphicsLineItem>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsItem>
#include<QHBoxLayout>
#include <QPixmap>

class Rectangle : public QWidget
{
    Q_OBJECT

public:
    Rectangle(QWidget *parent = 0);

private:



    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

public slots:
    void clearImage();
    void print();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified;
    bool scribbling;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
};

#endif // RECTANGLE_H
