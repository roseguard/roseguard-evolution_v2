#ifndef ISLIFE_H
#define ISLIFE_H

#include "methodlists.h"
#include "worldcontroller.h"
#include "lifecell.h"
#include "memdef.h"

int isLifeDown(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    qreal tempx = life->x()+(life->rect().width()/2);
    qreal tempy = life->y()+(life->rect().height()+3);
    QGraphicsItem *itemDown = world->itemAt(tempx , tempy, QTransform());
    if(itemDown)
    {
        if(itemDown->data(itemType).toInt()==lifeItem)
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

int isLifeUp(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    qreal tempx = life->x()+(life->rect().width()/2);
    qreal tempy = life->y()-3;
    QGraphicsItem *itemDown = world->itemAt(tempx , tempy, QTransform());
    if(itemDown)
    {
        if(itemDown->data(itemType).toInt()==lifeItem)
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

int isLifeLeft(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    qreal tempx = life->x()-3;
    qreal tempy = life->y()+(life->rect().height()/2);
    QGraphicsItem *itemDown = world->itemAt(tempx , tempy, QTransform());
    if(itemDown)
    {
        if(itemDown->data(itemType).toInt()==lifeItem)
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

int isLifeRight(LifeCell *life)
{
    life->damageStamina(3);
    WorldController *world = life->getWorld();
    qreal tempx = life->x()+(life->rect().width()+3);
    qreal tempy = life->y()+(life->rect().height()/2);
    QGraphicsItem *itemDown = world->itemAt(tempx , tempy, QTransform());
    if(itemDown)
    {
        if(itemDown->data(itemType).toInt()==lifeItem)
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

#endif // ISLIFE_H
