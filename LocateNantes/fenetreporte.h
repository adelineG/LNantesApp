#ifndef FENETREPORTE_H
#define FENETREPORTE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class FenetrePorte : public QWidget
{
    Q_OBJECT
public:
    FenetrePorte();


private:
    QLineEdit *nom;
    QLineEdit *capacite;

    QPushButton *valider;
    QPushButton *annuler;

public slots:
    void sauvegarder();

};

#endif // FENETREPORTE_H
