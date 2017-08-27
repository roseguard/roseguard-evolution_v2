#ifndef ISFOOD_H
#define ISFOOD_H

#include "methodlists.h"
#include "lifecell.h"
#include "worldcontroller.h"
#include "memdef.h"

int isFoodDown(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    qreal tempx = life->x()+(life->rect().width()/2);
    qreal tempy = life->y()+(life->rect().height()+3);
    QGraphicsItem *itemDown = world->itemAt(tempx , tempy, QTransform());
    if(itemDown)
    {
        if(itemDown->data(itemType).toInt()==foodItem)
        {
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

int isFoodUp(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    qreal tempx = life->x()+(life->rect().width()/2);
    qreal tempy = life->y()-3;
    QGraphicsItem *itemDown = world->itemAt(tempx , tempy, QTransform());
    if(itemDown)
    {
        if(itemDown->data(itemType).toInt()==foodItem)
        {
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

int isFoodLeft(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    qreal tempx = life->x()-3;
    qreal tempy = life->y()+(life->rect().height()/2);
    QGraphicsItem *itemDown = world->itemAt(tempx , tempy, QTransform());
    if(itemDown)
    {
        if(itemDown->data(itemType).toInt()==foodItem)
        {
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

int isFoodRight(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    qreal tempx = life->x()+(life->rect().width()+3);
    qreal tempy = life->y()+(life->rect().height()/2);
    QGraphicsItem *itemDown = world->itemAt(tempx , tempy, QTransform());
    if(itemDown)
    {
        if(itemDown->data(itemType).toInt()==foodItem)
        {
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
