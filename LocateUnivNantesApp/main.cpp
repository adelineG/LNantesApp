#include <QApplication>
#include <QtGui>
#include "mainwindow.h"
#include "startwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    StartWindow fenetre ;
    fenetre.show();

    return app.exec();
}
