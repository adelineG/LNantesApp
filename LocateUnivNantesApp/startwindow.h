#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QString>


class StartWindow : public QWidget
{
public:
    StartWindow();
public slots:
    void ouvrirMainWindow();
    void ouvrirDialogueChargement();

private:
QPushButton *m_boutonNouveau;
QPushButton *m_boutonCharger;
QString *message;

};

#endif // STARTWINDOW_H
