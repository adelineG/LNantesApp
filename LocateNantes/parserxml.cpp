#include "parserxml.h"
#include "escalieritem.h"
#include "batimentitem.h"
#include "couloiritem.h"
#include "ascenseuritem.h"
#include "diagramscene.h"
#include "QList"

parserXML::parserXML(MainWindow *mw)
{
    parent=mw;
}


void parserXML::sauvegarderXML(QString fileName){

    DiagramScene *scene;
    BatimentItem *bat;
    CouloirItem *c;
    EscalierItem *es;
    AscenseurItem *as;
    PorteItem *po;

    QXmlStreamWriter xmlWriter( &fileName );
    xmlWriter.setAutoFormatting( true );


    xmlWriter.writeStartDocument();



    xmlWriter.writeStartElement("Plan");
    qDebug()<< parent->plan->listScene;

    /*foreach (scene, parent->plan->listScene) {
        if(!(scene->listBatiment.isEmpty())){

            foreach (bat, scene->listBatiment) {

                //ouvrir Batiment
                xmlWriter.writeStartElement("Batiment");
                xmlWriter.writeAttribute("nom",bat->nom());
                xmlWriter.writeAttribute("etage",bat->etage());

                // position du batiment en elem ************
                xmlWriter.writeStartElement("Debut");
                xmlWriter.writeAttribute("x",QString(bat->depart().x());
                xmlWriter.writeAttribute("y",QString(bat->depart().y()));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("Fin");
                xmlWriter.writeAttribute("x",QString(bat->fin().x());
                xmlWriter.writeAttribute("y",QString(bat->fin().y()));
                xmlWriter.writeEndElement();
            }

            foreach (c, scene->listeCouloir) {
                // ouvrir couloir ---------------------------------
                xmlWriter.writeStartElement("Couloir");
                xmlWriter.writeStartElement("Debut");
                xmlWriter.writeAttribute("x",QString(c->depart().x());
                        xmlWriter.writeAttribute("y",QString(c->depart().y()));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("Fin");
                xmlWriter.writeAttribute("x",QString(c->fin().x());
                        xmlWriter.writeAttribute("y",QString(c->fin().y()));
                xmlWriter.writeEndElement();
                xmlWriter.writeEndElement();
                //fermer couloir
            }

            foreach (es, scene->listeEscalier) {
                // ouvrir escalier -----------------------------------
                xmlWriter.writeStartElement("Escalier");
                    xmlWriter.writeStartElement("Position");
                    xmlWriter.writeAttribute("x",QString(es->position.x()));
                    xmlWriter.writeAttribute("y",QString(es->position.y()));
                    xmlWriter.writeEndElement();
                xmlWriter.writeEndElement();
                //fermer escalier
            }

            foreach (as, scene->listeAscenseur) {
                // ouvrir ascenseur -----------------------------------
                xmlWriter.writeStartElement("Ascenseur");
                    xmlWriter.writeStartElement("Position");
                    xmlWriter.writeAttribute("x",QString(as->position.x()));
                    xmlWriter.writeAttribute("y",QString(as->position.y()));
                    xmlWriter.writeEndElement();
                xmlWriter.writeEndElement();
                //fermer ascenseur
            }


            foreach (po, scene->listePorte) {

                xmlWriter.writeStartElement("Porte");
                    xmlWriter.writeStartElement("Salle");
                    xmlWriter.writeAttribute("nom",po->nomSalle);
                    xmlWriter.writeAttribute("capacite",po->capacite);
                    xmlWriter.writeEndElement();

                    xmlWriter.writeStartElement("Debut");
                    xmlWriter.writeAttribute("x",QString(po->depart().x());
                    xmlWriter.writeAttribute("y",QString(po->depart().y()));
                    xmlWriter.writeEndElement();
                    xmlWriter.writeStartElement("Fin");
                    xmlWriter.writeAttribute("x",QString(po->fin().x());
                    xmlWriter.writeAttribute("y",QString(po->fin().y()));
                    xmlWriter.writeEndElement();
                xmlWriter.writeEndElement();
            }


            xmlWriter.writeEndElement();



        }

    }*/

    xmlWriter.writeEndElement();

    xmlWriter.writeEndDocument();

}
