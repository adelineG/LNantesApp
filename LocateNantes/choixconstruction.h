#include <QtGui>
#include "mainwindow.h"


namespace Construction {
    enum Type { Batiment, Couloir, Porte, Cloison, Escalier, Ascenseur,
	Connexion, Label  };
}

class ChoixConstruction : public QToolBox
{
    Q_OBJECT

    public:
    ChoixConstruction(QWidget* parent = 0);
    MainWindow* main;
    void setMainWindow(MainWindow* m){main=m;}

public slots:
    void ouvrirBatiment();
    void ouvrirEscalier();
    void ouvrirConnexion();
    void ouvrirEtage();
    void ouvrirCouloir();
    void ouvrirPorte();

    private:
    QButtonGroup* buttonGroup;

    signals:
	void selectedConstruction(int construction);
};

