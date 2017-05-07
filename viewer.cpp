#include "viewer.h"
#include "lifecell.h"
#include "worldcontroller.h"
#include "methodlists.h"

Viewer::Viewer(MethodLists *list, QWidget *parent)
    : QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    if(list==0)
    {
        list = new MethodLists();
    }
    world = new  WorldController(0,0, desk.width(), desk.height(), this, list);
    setScene(world);
    showFullScreen();
}

Viewer::~Viewer()
{

}
