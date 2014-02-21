#ifndef PLANMODEL_H
#define PLANMODEL_H

#include "QAbstractItemModel"
#include "mainwindow.h"
#include <QList>

class MainWindow;

class PlanModel : public QAbstractItemModel
{
public:
    PlanModel(MainWindow *m){parent=m;}
    void setListScene(QGraphicsScene* itemScene){listScene->append(itemScene);}

private:
    MainWindow *parent;
    QList<QGraphicsScene> *listScene;
};

#endif // PLANMODEL_H
