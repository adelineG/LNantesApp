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

    private:
	QButtonGroup* buttonGroup;

    signals:
	void selectedConstruction(Construction::Type construction);
};

