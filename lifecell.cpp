#include "lifecell.h"
#include "worldcontroller.h"

LifeCell::LifeCell(WorldController *worldPointer, MethodLists *allMethods) : QGraphicsRectItem()
{
    setBrush(* new QBrush(Qt::red));
//    setRect(0,0,lifeWidth, lifeHeight);
    setRect(100,100,200,200);
    world = worldPointer;
    world->addLife(this);
    wholeMethods = allMethods;
}

qint32 LifeCell::getHealth()
{
    return health;
}

qint32 LifeCell::getStamina()
{
    return stamina;
}

qint8  LifeCell::getMutationChance()
{
    return mutationChance;
}

qint32 LifeCell::damageHealth(qint32 value)
{
    health-=value;
    if(health<=0)
    {

    }
    return health;
}

qint32 LifeCell::damageStamina(qint32 value)
{
    stamina-=value;
    return stamina;
}

WorldController* LifeCell::getWorld()
{
    return world;
}

MethodLists*     LifeCell::getMethods()
{
    return wholeMethods;
}
