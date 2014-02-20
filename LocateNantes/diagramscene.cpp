/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>

#include "diagramscene.h"
#include "arrow.h"
#include "batimentitem.h"
#include "couloiritem.h"
#include "porteitem.h"
#include <QPainter>

static const int GRID_STEP = 30;

inline qreal round(qreal val, int step) {
    int tmp = int(val) + step /2;
    tmp -= tmp % step;
    return qreal(tmp);
}

//! [0]
DiagramScene::DiagramScene(QMenu *itemMenu, QObject *parent)
    : QGraphicsScene(parent)
{
    myItemMenu = itemMenu;
    myMode = MoveItem;
    myItemType = DiagramItem::Step;
    line = 0;
    textItem = 0;

}
//! [0]


void DiagramScene::setMode(Mode mode)
{
    myMode = mode;
}

void DiagramScene::setItemType(DiagramItem::DiagramType type)
{
    myItemType = type;
}

//! [5]
void DiagramScene::editorLostFocus(DiagramTextItem *item)
{
    QTextCursor cursor = item->textCursor();
    cursor.clearSelection();
    item->setTextCursor(cursor);

    if (item->toPlainText().isEmpty()) {
        removeItem(item);
        item->deleteLater();
    }
}
//! [5]

//! [6]
void DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;
    QGraphicsScene::mousePressEvent(mouseEvent);

    startPoint = mouseEvent->scenePos();

}
//! [9]

//! [10]
void DiagramScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (myMode == InsertLine && line != 0) {
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    } else if (myMode == MoveItem) {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
}
//! [10]

//! [11]
void DiagramScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{


    if (line != 0 && myMode == InsertLine) {
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();

        removeItem(line);
        delete line;
        //! [11] //! [12]

        if (startItems.count() > 0 && endItems.count() > 0 &&
                startItems.first()->type() == DiagramItem::Type &&
                endItems.first()->type() == DiagramItem::Type &&
                startItems.first() != endItems.first()) {
            DiagramItem *startItem =
                    qgraphicsitem_cast<DiagramItem *>(startItems.first());
            DiagramItem *endItem =
                    qgraphicsitem_cast<DiagramItem *>(endItems.first());
            Arrow *arrow = new Arrow(startItem, endItem);
            startItem->addArrow(arrow);
            endItem->addArrow(arrow);
            arrow->setZValue(-1000.0);
            addItem(arrow);
            arrow->updatePosition();
        }
    }
    //! [12] //! [13]




    /*************************************************************************************************/
    if (myMode==AddBatiment){

        bat = new BatimentItem(this);
        bat->setPen(QPen(Qt::black,3,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
        bat->setRect(QRectF(QPointF(0,0),mouseEvent->scenePos()-startPoint));
        bat->setPos(startPoint);
        addItem(bat);
    }

    /*************************************************************************************************/
    if(myMode == AddCouloir){
        QPointF offx = startPoint;
        QPointF offy = mouseEvent->scenePos();
        int testx = abs(offy.x()-offx.x());
        int testy = abs(offy.y()-offx.y());

        if( testx <= testy ){

            offx += QPointF(40,0);
            offy += QPointF(40,0);
        }
        else if(testx > testy)
        {

            offx += QPointF(0,40);
            offy += QPointF(0,40);
        }

        /*
        coulS = new CouloirItem(this);
        coulI = new CouloirItem(this);
        coulS->setLine(QLineF(QPointF(0,0),mouseEvent->scenePos()-startPoint));
        coulI->setLine(QLineF(QPointF(0,0),offy-offx));
        coulS->setPen(QPen(Qt::blue,5,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
        coulI->setPen(QPen(Qt::blue,5,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
        coulS->setPos(startPoint);
        coulI->setPos(offx);
        addItem(coulS);
        addItem(coulI);*/
        coulI = new CouloirItem(this);
        coulI->setLine(QLineF(QPointF(0,0),mouseEvent->scenePos()-startPoint));
         coulI->setPen(QPen(Qt::blue,20,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
         coulI->setPos(startPoint);
         addItem(coulI);
    }

    if(myMode == AddPorte){


        QPointF offxh = startPoint;
        QPointF offxv = startPoint;
        QPointF offyv = mouseEvent->scenePos();
        QPointF offyh = mouseEvent->scenePos();
        int testx = abs(mouseEvent->scenePos().x()-startPoint.x());
        int testy = abs(mouseEvent->scenePos().y()-startPoint.y());
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

        porteG = new PorteItem(this);
        porteD = new PorteItem(this);
        porteG->setRect(QRectF(QPointF(0,0),QSizeF(10,10)));
        porteG->setPos(startPoint);
        porteG->setBrush(QBrush(Qt::green));
        porteD->setRect(QRectF(QPointF(0,0),QSizeF(10,10)));
        porteD->setBrush(QBrush(Qt::green));
        porteD->setPos(mouseEvent->scenePos());
        addItem(porteG);
        addItem(porteD);


    }
    /***************************************************************************************/





}
//! [13]

//! [14]
bool DiagramScene::isItemChange(int type)
{
    foreach (QGraphicsItem *item, selectedItems()) {
        if (item->type() == type)
            return true;
    }
    return false;
}
//! [14]
void DiagramScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    int step = GRID_STEP;
    painter->setPen(QPen(QColor(200, 200, 255, 125)));
    // draw horizontal grid
    qreal start = round(rect.top(), step);
    if (start > rect.top()) {
        start -= step;
    }
    for (qreal y = start - step; y < rect.bottom(); ) {
        y += step;
        painter->drawLine(rect.left(), y, rect.right(), y);
    }
    // now draw vertical grid
    start = round(rect.left(), step);
    if (start > rect.left()) {
        start -= step;
    }
    for (qreal x = start - step; x < rect.right(); ) {
        x += step;
        painter->drawLine(x, rect.top(), x, rect.bottom());
    }
}


void DiagramScene::paintEvent(QPaintEvent *event)
//! [13] //! [14]
{
    //QPainter *painter(this);
    QRect dirtyRect = event->rect();
    //bat->paint(painter,event,mouseEvent->pos());
}
