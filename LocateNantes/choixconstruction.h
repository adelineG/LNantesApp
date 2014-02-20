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
    ChoixConstruction(MainWindow const*,QWidget* parent = 0);

private slots:
    void ouvrirBatiment(const MainWindow *);
    void ouvrirEscalier();
    void ouvrirConnexion();
    void ouvrirEtage();
    void ouvrirCouloir();

    private:
    QButtonGroup* buttonGroup;

    signals:
	void selectedConstruction(int construction);
};

