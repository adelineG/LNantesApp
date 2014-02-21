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

#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QGraphicsScene>
#include "diagramitem.h"
#include "diagramtextitem.h"
#include "batimentitem.h"
#include "couloiritem.h"
#include "porteitem.h"
#include "labelitem.h"
#include "connexionitem.h"
#include "escalierfenetre.h"
#include <QList>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
class MainWindow;
class BatimentItem;
class CouloirItem;
class PorteItem;
class EscalierItem;
class ConnexionItem;
class AscenseurItem;
class CloisonItem;
class LabelItem;
QT_END_NAMESPACE



//! [0]
class DiagramScene : public QGraphicsScene
{
    Q_OBJECT

public:
    enum Mode { InsertItem, InsertLine, InsertText, MoveItem, AddBatiment, AddCouloir , AddPorte, AddEscalier, AddAscenseur, AddConnexion, AddCloison};
    QString nom;
    DiagramScene(QMenu *itemMenu , QObject *parent = 0);
    LabelItem* label;
    BatimentItem *bat;
    CouloirItem *coulS;
    CouloirItem *coulI;
    PorteItem *porteG;
    PorteItem *porteD;
    EscalierItem* escalier;
    AscenseurItem* ascenseur;
    ConnexionItem* connexion;
    CloisonItem* cloison;
    QList <BatimentItem*> listBatiment;
    QList <CouloirItem*> listeCouloir;
    QList <PorteItem*> listePorte;
    QList <EscalierItem*> listeEscalier;
    QList <ConnexionItem*> listeConnexion;
    QList <AscenseurItem*> listeAscenseur;
    QList <CloisonItem*> listeCloison;
    QList <LabelItem*> listeLabel;

    void ouvrirFenetrePopUp();


public slots:
    void setMode(Mode mode);
    Mode getMode (){return myMode;}
    void setItemType(DiagramItem::DiagramType type);
    void editorLostFocus(DiagramTextItem *item);


signals:
    void itemInserted(DiagramItem *item);
    void textInserted(QGraphicsTextItem *item);
    void itemSelected(QGraphicsItem *item);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void drawBackground(QPainter * painter, const QRectF & rect );
    void paintEvent(QPaintEvent*);


    QGraphicsSimpleTextItem *texteExemple;
    QGraphicsItem* itemEnDeplacement;



private:
    bool isItemChange(int type);

    DiagramItem::DiagramType myItemType;
    QMenu *myItemMenu;
    Mode myMode;
    bool leftButtonDown;
    QPointF startPoint;
    QGraphicsLineItem *line;
    DiagramTextItem *textItem;
    QPainter painter;
    QPointF offsetPointer;

};
//! [0]

#endif
