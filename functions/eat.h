#ifndef EAT_H
#define EAT_H

#include "methodlists.h"
#include "lifecell.h"
#include "worldcontroller.h"
#include "memdef.h"

int eatDown(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    QGraphicsItem *item = world->itemAt(life->x()+(life->rect().width()/2), life->y()+life->rect().height()+1, QTransform());
    if(item)
    {
        if(item->data(itemType)==foodItem)
        {
            life->feedLife(5);
            delete item;
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

int eatUp(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    QGraphicsItem *item = world->itemAt(life->x()+(life->rect().width()/2), life->y()-1, QTransform());
    if(item)
    {
        if(item->data(itemType)==foodItem)
        {
            life->feedLife(5);
            delete item;
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

int eatLeft(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    QGraphicsItem *item = world->itemAt(life->x()-1, life->y()+life->rect().height()/2, QTransform());
    if(item)
    {
        if(item->data(itemType)==foodItem)
        {
            life->feedLife(5);
            delete item;
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

int eatRight(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    QGraphicsItem *item= world->itemAt(life->x()+(life->rect().width()+1), life->y()+life->rect().height()/2, QTransform());
    if(item)
    {
        if(item->data(itemType)==foodItem)
        {
            life->feedLife(5);
            delete item;
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

#endif
