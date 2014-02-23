#include "parserxml.h"
#include "escalieritem.h"
#include "batimentitem.h"
#include "couloiritem.h"
#include "ascenseuritem.h"
#include "diagramscene.h"
#include "porteitem.h"
#include "QList"

parserXML::parserXML(MainWindow *mw) { parent=mw; }
void parserXML::sauvegarderXML(QString fileName){

    BatimentItem *bat; CouloirItem *c; EscalierItem *es; AscenseurItem *as; PorteItem *po;

    QFile file( fileName ); if ( !file.open( QIODevice::WriteOnly ) ) { //showMessage( QString("Failed to write to '%1'").arg(filename) ); return; }

        QXmlStreamWriter xmlWriter( &file ); xmlWriter.setAutoFormatting( true ); xmlWriter.writeStartDocument(); xmlWriter.writeStartElement("Plan");

        foreach( QGraphicsItem* item, parent->scene->items()) { switch (item->type()) {

            case BatimentItem::Type: bat= (BatimentItem*)item;

                xmlWriter.writeStartElement("Batiment"); xmlWriter.writeAttribute("nom",bat->nom()); xmlWriter.writeAttribute("etage",bat->etage());

                // position du batiment en elem ************ xmlWriter.writeStartElement("Debut");
                xmlWriter.writeAttribute("x",QString::number(bat->scenePos().x()));
                xmlWriter.writeAttribute("y",QString::number(bat->scenePos().y()));


                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("Fin");


                xmlWriter.writeAttribute("x",QString::number(bat->rect().bottomRight().x()));
                xmlWriter.writeAttribute("y",QString::number(bat->rect().bottomRight().y()));
                xmlWriter.writeEndElement(); xmlWriter.writeEndElement();

                break; case CouloirItem::Type: c = (CouloirItem*) item;

                xmlWriter.writeStartElement("Couloir"); xmlWriter.writeStartElement("Debut");
                xmlWriter.writeAttribute("x",QString::number(c->scenePos().x()));
                xmlWriter.writeAttribute("y",QString::number(c->scenePos().y()));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("Fin");
                xmlWriter.writeAttribute("x",QString::number(c->line().x2()));
                xmlWriter.writeAttribute("y",QString::number(c->line().y2()));
                xmlWriter.writeEndElement(); xmlWriter.writeEndElement();

                break; case EscalierItem::Type: es= (EscalierItem*) item;

                xmlWriter.writeStartElement("Escalier"); xmlWriter.writeStartElement("Position");
                xmlWriter.writeAttribute("x",QString::number(es->scenePos().x()));
                xmlWriter.writeAttribute("y",QString::number(es->scenePos().y()));
                xmlWriter.writeEndElement(); xmlWriter.writeEndElement();

                break; case AscenseurItem::Type: as= (AscenseurItem*)item;

                xmlWriter.writeStartElement("Ascenseur"); xmlWriter.writeStartElement("Position");
                xmlWriter.writeAttribute("x",QString::number(as->scenePos().x()));
                xmlWriter.writeAttribute("y",QString::number(as->scenePos().y()));
                xmlWriter.writeEndElement(); xmlWriter.writeEndElement();

                break; case PorteItem::Type: po=(PorteItem*)item;

                xmlWriter.writeStartElement("Porte"); xmlWriter.writeStartElement("Salle"); xmlWriter.writeAttribute("nom",po->nomSalle()); xmlWriter.writeAttribute("capacite",po->capacite()); xmlWriter.writeEndElement();

                xmlWriter.writeStartElement("Debut");
                xmlWriter.writeAttribute("x",QString::number(po->scenePos().x()));
                xmlWriter.writeAttribute("y",QString::number(po->scenePos().y()));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("Fin");
                xmlWriter.writeAttribute("x",QString::number(po->rect().bottomRight().x()));
                xmlWriter.writeAttribute("y",QString::number(po->rect().bottomRight().y()));
                xmlWriter.writeEndElement(); xmlWriter.writeEndElement();

                break;

            default: break; }

        }

        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
        file.close();

}
}
