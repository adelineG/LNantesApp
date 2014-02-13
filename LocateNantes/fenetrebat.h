#ifndef FENETREBAT_H
#define FENETREBAT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class FenetreBat : public QWidget
{
    Q_OBJECT
public:
   FenetreBat();


public slots:
    void sauvegarder();

private:
    QLineEdit *nom;
    QLineEdit *etage;

    QPushButton *valider;
    QPushButton *annuler;

};

#endif // FENETREBAT_H
