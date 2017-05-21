#ifndef REPLICATE_H
#define REPLICATE_H

#include "methodlists.h"
#include "lifecell.h"
#include "worldcontroller.h"
#include "dnaclass.h"
#include "memdef.h"

int isReadyForReplication(LifeCell *life)
{
    if(life->memory[healthForReplication]==0)
        life->memory[healthForReplication]= 50 + qrand()%150;
    if(life->memory[healthForReplication] < life->getHealth())
        return 1;
    else
        return 0;
}

int replicate(LifeCell *life)
{
    life->damageHealth(life->memory[healthForReplication]/2);
    LifeCell *child = new LifeCell(life->getWorld(), life->getMethods(), life, life->memory[healthForReplication]/2);
    child->setPos(life->x()-qrand()%50+qrand()%100, life->y()-qrand()%50+qrand()%100);
    child->getDNA()->randomMutation();
    life->getWorld()->addLife(child);
    life->setFinish();
}

#endif // REPLICATE_H
