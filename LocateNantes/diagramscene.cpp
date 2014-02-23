#include <QtGui>
#include "diagramtextitem.h"
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
#include "fenetrebat.h"
#include "cloisonitem.h"
#include "fenetreporte.h"
#include "labelitem.h"
#include "mainwindow.h"
#include "QMessageBox"
#include <QPainter>
#include <QGraphicsItemGroup>


static const int GRID_STEP = 30;

inline qreal round(qreal val, int step) {
    int tmp = int(val) + step /2;
    tmp -= tmp % step;
    return qreal(tmp);
}

//! [0]
DiagramScene::DiagramScene(QMenu *itemMenu, MainWindow *mw)
    : QGraphicsScene(mw)
{
    myItemMenu = itemMenu;
    myMode = MoveItem;
    myItemType = DiagramItem::Step;
    line = 0;
    textItem = 0;
    parent = mw;


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

    switch (myMode) {
    case MoveItem:
    {
        itemEnDeplacement = this->itemAt(startPoint);
        if (itemEnDeplacement != NULL) {
            offsetPointer = startPoint - itemEnDeplacement->pos();
        }
        emit itemSelected(itemEnDeplacement);
    }
        break;
    case AddBatiment:
    {


        bat->setDepart(startPoint);
        bat->setFin(mouseEvent->scenePos());
        bat->setRect(QRectF(QPointF(0,0),mouseEvent->scenePos()-startPoint).normalized());
        bat->setPos(startPoint);

        monGroupe = new QGraphicsItemGroup(NULL, this);
        monGroupe->addToGroup(bat);


    }
        break;
    case AddEscalier:
    {
        if(monGroupe==NULL )
        {
            myMode = MoveItem;
            break;
        }
        escalier = new EscalierItem(this);
        escalier->setPixmap(QPixmap(":/images/escalier.png").scaled(30,30));
        escalier->setPos(mouseEvent->scenePos());
        escalier->position=mouseEvent->scenePos();
        EscalierFenetre *formulaire = new EscalierFenetre(this);
        formulaire->show();

        monGroupe->addToGroup(escalier);
    }
        break;

    case AddAscenseur:
    {
        if(monGroupe == NULL)
        {

            myMode = MoveItem;
            break ;
        }

        ascenseur = new AscenseurItem(this);
        ascenseur->setPixmap(QPixmap(":/images/ascenseur.png").scaled(30,30));
        ascenseur->setPos(mouseEvent->scenePos());
        ascenseur->position=mouseEvent->scenePos();

        monGroupe->addToGroup(ascenseur);
    }
        break ;

    case AddConnexion:
    {
        if(monGroupe == NULL)
        {

            myMode = MoveItem;
            break ;
        }
        connexion = new ConnexionItem(this);
        connexion->setPixmap(QPixmap(":/images/Sortie.png").scaled(30,30));
        connexion->setPos(mouseEvent->scenePos());

        FenetreConnexion *formulaire = new FenetreConnexion(this);

        formulaire->show();

        monGroupe->addToGroup(connexion);
    }
        break;

    case AddCouloir:
    {
        if(monGroupe == NULL)
        {
            myMode = MoveItem;
            break ;
        }
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
        coulI->setDepart(startPoint);
        coulI->setFin(mouseEvent->scenePos());
        coulI->setPos(startPoint);

        monGroupe->addToGroup(coulI);
    }
        break;
    case AddPorte:
    {
        if(monGroupe == NULL)
        {

            myMode = MoveItem;
        }
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
        porteG->setRect(QRectF(QPointF(0,0),QSizeF(15,15)));
        porteG->setPos(startPoint);
        porteG->setBrush(QBrush(Qt::green));
        porteD->setRect(QRectF(QPointF(0,0),QSizeF(15,15)));
        porteD->setBrush(QBrush(Qt::green));
        porteD->setPos(mouseEvent->scenePos());
        porteD->setDepart(startPoint);
        porteD->setFin(mouseEvent->scenePos());

        monGroupe->addToGroup(porteG);
        monGroupe->addToGroup(porteD);
    }
        break;

    case AddCloison:
    {
        if(monGroupe == NULL)
        {

            break;
        }
        cloison = new CloisonItem(this);
        cloison->setLine(QLineF(QPointF(0,0),mouseEvent->scenePos()-startPoint));
        cloison->setPen(QPen(Qt::blue,5,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
        cloison->setPos(startPoint);

        monGroupe->addToGroup(cloison);
    }
        break;

    case InsertText :
    {

        textItem = new DiagramTextItem();
        textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
        textItem->setZValue(1000.0);
        connect(textItem, SIGNAL(lostFocus(DiagramTextItem*)),
                this, SLOT(editorLostFocus(DiagramTextItem*)));
        connect(textItem, SIGNAL(selectedChange(QGraphicsItem*)),
                this, SIGNAL(itemSelected(QGraphicsItem*)));
        monGroupe->addToGroup(textItem);
        textItem->setPos(mouseEvent->scenePos());
        emit textInserted(textItem);
        break;
    }
    default:
        break;
    }
}


void DiagramScene::ouvrirFenetrePopUp(){


    if(myMode==AddBatiment) {
        bat = new BatimentItem(this);
        bat->setPen(QPen(Qt::black,3,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
        FenetreBat *formulaire = new FenetreBat(this);
        formulaire->show();
    }
    else {
        myMode=MoveItem;
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

        bat->setDepart(startPoint);
        bat->setFin(mouseEvent->scenePos());
        bat->setPen(QPen(Qt::black,3,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
        bat->setRect(QRectF(QPointF(0,0),mouseEvent->scenePos()-startPoint).normalized());
        bat->setPos(startPoint);

    }
    if(myMode == AddCouloir){
        if(monGroupe!=NULL){


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

            coulI->setDepart(startPoint);
            coulI->setFin(mouseEvent->scenePos());
            coulI->setLine(QLineF(QPointF(0,0),mouseEvent->scenePos()-startPoint));
            coulI->setPen(QPen(Qt::gray,20,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
            coulI->setPos(startPoint);
        }
    }

    if(myMode == AddPorte){

        if(monGroupe!=NULL){


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
    }

    if(myMode == AddCloison){
        if(monGroupe!=NULL){
            cloison->setLine(QLineF(QPointF(0,0),mouseEvent->scenePos()-startPoint));
            cloison->setPen(QPen(Qt::black,5,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
            cloison->setPos(startPoint);
        }
    }
}
//! [10]

//! [11]
void DiagramScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if(myMode==AddPorte && monGroupe!=NULL){

        label= new LabelItem(this);
        FenetrePorte *fen = new FenetrePorte(this);
        fen->show();
        label->setBrush(Qt::blue);
        label->setPos(QPointF(mouseEvent->scenePos().x()+20,mouseEvent->scenePos().y()-20));
        monGroupe->addToGroup(label);



    }


    if (myMode == MoveItem)
        itemEnDeplacement = NULL;

    //! [12] //! [13]

    /*************************************************************************************************/
    // si on est en mode construction, il n'y a rien à faire, à part changer de mode
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

    QRect dirtyRect = event->rect();

}
