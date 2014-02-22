#ifndef PARSERXML_H
#define PARSERXML_H

#include "mainwindow.h"


class parserXML
{
public:
    parserXML(MainWindow *mw);
    void sauvegarderXML(QString);
    void ouvrirXML();

private:
    MainWindow* parent;
};

#endif // PARSERXML_H
