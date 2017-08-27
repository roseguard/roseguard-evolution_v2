#ifndef EMPTYACTIONS_H
#define EMPTYACTIONS_H

#include "methodlists.h"
#include "lifecell.h"
#include "worldcontroller.h"
#include "memdef.h"

int emptyBase(LifeCell *life)
{
    life->damageStamina(4);
    return 0;
}

int emptyWithFinishing(LifeCell *life)
{
    life->damageStamina(4);
    life->setFinish();
    return 0;
}

int emptyWithReturn(LifeCell *life)
{
    life->damageStamina(4);
    return -1;
}



#endif // EMPTYACTIONS_H
