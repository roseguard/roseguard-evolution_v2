#ifndef BITE_H
#define BITE_H

#include "methodlists.h"
#include "lifecell.h"
#include "worldcontroller.h"
#include "memdef.h"

int biteDown(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    QGraphicsItem *item = world->itemAt(life->x()+(life->rect().width()/2), life->y()+life->rect().height()+1, QTransform());
    if(item)
    {
        if(item->data(itemType)==lifeItem)
        {
            life->feedLife(5);
            ((LifeCell*)item)->damageHealth(5);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int biteUp(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    QGraphicsItem *item = world->itemAt(life->x()+(life->rect().width()/2), life->y()-1, QTransform());
    if(item)
    {
        if(item->data(itemType)==lifeItem)
        {
            life->feedLife(5);
            ((LifeCell*)item)->damageHealth(5);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int biteLeft(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    QGraphicsItem *item = world->itemAt(life->x()-1, life->y()+life->rect().height()/2, QTransform());
    if(item)
    {
        if(item->data(itemType)==lifeItem)
        {
            life->feedLife(5);
            ((LifeCell*)item)->damageHealth(5);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int biteRight(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    QGraphicsItem *item= world->itemAt(life->x()+(life->rect().width()+1), life->y()+life->rect().height()/2, QTransform());
    if(item)
    {
        if(item->data(itemType)==lifeItem)
        {
            life->feedLife(5);
            ((LifeCell*)item)->damageHealth(10);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

#endif // BITE_H
