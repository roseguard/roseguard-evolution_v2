#ifndef BREATHE_H
#define BREATHE_H

#include "methodlists.h"
#include "lifecell.h"
#include "worldcontroller.h"
#include "dnaclass.h"
#include "memdef.h"

int catBreathe(LifeCell *life)
{
    life->damageStamina(5);
    if(life->memory[breatheDelay]==0)
        return 1;
    else
        return 0;
}

int breathe(LifeCell *life)
{
    life->damageStamina(10);
    if(life->memory[breatheDelay]==0)
    {
        life->memory[breatheDelay]=10;
        life->restoreSomeStamina(150);
    }
    else
    {
        life->memory[breatheDelay]--;
        return 0;
    }
}

#endif // BREATHE_H
