#include "lifecell.h"
#include "worldcontroller.h"

LifeCell::LifeCell(WorldController *worldPointer) : QGraphicsRectItem()
{
    setBrush(* new QBrush(Qt::red));
//    setRect(0,0,lifeWidth, lifeHeight);
    setRect(100,100,200,200);
    world = worldPointer;
    world->addLife(this);
}
