#include <QtGui>

namespace Construction {
    enum Type { Batiment, Couloir, Porte, Cloison, Escalier, Ascenseur,
	Connexion, Label  };
}

class ChoixConstruction : public QToolBox
{
    Q_OBJECT

    public:
	ChoixConstruction(QWidget* parent = 0);

private slots:
    void ouvrirBatiment();
    void ouvrirEscalier();
    void ouvrirConnexion();
    void ouvrirEtage();

    private:
	QButtonGroup* buttonGroup;

    signals:
	void selectedConstruction(int construction);
};

