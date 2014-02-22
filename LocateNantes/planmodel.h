#ifndef PLANMODEL_H
#define PLANMODEL_H

#include "QAbstractItemModel"
#include "mainwindow.h"
#include "diagramscene.h"
#include <QList>

class MainWindow;

class PlanModel
{
public:
    PlanModel(MainWindow *m);
    void setListScene(DiagramScene* itemScene){listScene->append(itemScene);}
    bool hasMoreOneScene(){
      return  listScene->size()>1;
    }

    QList<DiagramScene*> *listScene;


private:
    MainWindow *parent;

};

#endif // PLANMODEL_H
