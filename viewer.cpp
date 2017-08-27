#include "viewer.h"
#include "lifecell.h"
#include "worldcontroller.h"
#include "methodlists.h"
#ifdef WIN32
#include "windows.h"
#endif

Viewer::Viewer(QWidget *parent)
    : QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    world = new WorldController(0,0, desk.width(), desk.height(), this);
    setScene(world);
}

Viewer::~Viewer()
{

}
