

#include <QtGui>

#include "diagramscene.h"
#include "arrow.h"
#include "batimentitem.h"
#include "couloiritem.h"
#include "porteitem.h"
#include "escalieritem.h"
#include "ascenseuritem.h"
#include "connexionitem.h"
#include "escalierfenetre.h"
#include "fenetreconnexion.h"
#include "fenetreetage.h"
#include "cloisonitem.h"
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

    if (myMode == MoveItem) {
	itemEnDeplacement = this->itemAt(startPoint);
	if (itemEnDeplacement != NULL) {
	    offsetPointer = startPoint - itemEnDeplacement->pos();
	}
	emit itemSelected(itemEnDeplacement);
    }

    if (myMode==AddBatiment){
        bat = new BatimentItem(this);
        bat->setPen(QPen(Qt::black,3,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
        bat->setRect(QRectF(QPointF(0,0),mouseEvent->scenePos()-startPoint).normalized());
        bat->setPos(startPoint);
	addItem(bat);
    }

    if (myMode == AddEscalier){
        EscalierFenetre *formulaire = new EscalierFenetre();
        formulaire->show();
        escalier = new EscalierItem(this);
        escalier->setPixmap(QPixmap(":/images/escalier.png").scaled(30,30));
        escalier->setPos(mouseEvent->scenePos());
        addItem(escalier);
    }
    if (myMode == AddAscenseur){

        escalier = new EscalierItem(this);
        escalier->setPixmap(QPixmap(":/images/ascenseur.png").scaled(30,30));
        escalier->setPos(mouseEvent->scenePos());
        addItem(escalier);
    }
    if (myMode == AddConnexion){
        FenetreConnexion *formulaire = new FenetreConnexion();
        formulaire->show();
        escalier = new EscalierItem(this);
        escalier->setPixmap(QPixmap(":/images/Sortie.png").scaled(30,30));
        escalier->setPos(mouseEvent->scenePos());
        addItem(escalier);
    }

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

    if(myMode == AddCloison){
        cloison = new CloisonItem(this);
        cloison->setLine(QLineF(QPointF(0,0),mouseEvent->scenePos()-startPoint));
        cloison->setPen(QPen(Qt::black,5,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
        cloison->setPos(startPoint);
        addItem(cloison);
    }
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
	if (itemEnDeplacement != NULL)
	    itemEnDeplacement->setPos(mouseEvent->scenePos()-offsetPointer);
    }

    if (myMode==AddBatiment){
        bat->setPen(QPen(Qt::black,3,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
        bat->setRect(QRectF(QPointF(0,0),mouseEvent->scenePos()-startPoint).normalized());
        bat->setPos(startPoint);
    }
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
        coulI->setLine(QLineF(QPointF(0,0),mouseEvent->scenePos()-startPoint));
        coulI->setPen(QPen(Qt::blue,20,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
        coulI->setPos(startPoint);
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
        porteG->setRect(QRectF(QPointF(0,0),QSizeF(10,10)));
        porteG->setPos(startPoint);
        porteG->setBrush(QBrush(Qt::green));
        porteD->setRect(QRectF(QPointF(0,0),QSizeF(10,10)));
        porteD->setBrush(QBrush(Qt::green));
        porteD->setPos(mouseEvent->scenePos());
    }

    if(myMode == AddCloison){
        cloison->setLine(QLineF(QPointF(0,0),mouseEvent->scenePos()-startPoint));
        cloison->setPen(QPen(Qt::black,5,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
        cloison->setPos(startPoint);
    }
}
//! [10]

//! [11]
void DiagramScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if (myMode == MoveItem)
	itemEnDeplacement = NULL;

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
    // si on est en mode bâtiment, il n'y a rien à faire, sinon, changer de mode
    myMode = MoveItem;
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
