#include "planmodel.h"

PlanModel::PlanModel(MainWindow *m)
{
    parent=m;
    listScene = new QList<DiagramScene*>;
}
