#include "sortieitem.h"
#include "diagramscene.h"

QPixmap SortieImage::image;


SortieItem::SortieItem(DiagramScene *ds) : parent(ds)
{
    if (image.isNull) {
	// initialiser l'image
    }
}


