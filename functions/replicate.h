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
    if(isReadyForReplication(life))
    {
        life->damageHealth(life->memory[healthForReplication]/2);
        LifeCell *child = new LifeCell(life->getWorld(), life, life->memory[healthForReplication]/2);
        child->setPos(life->x()-qrand()%50+qrand()%100, life->y()-qrand()%50+qrand()%100);
        child->getDNA()->randomMutation();
        life->getWorld()->addLife(child);
        life->setFinish();
        return 1;
    }
    return 0;
}

int rapeDown(LifeCell *life)
{
    life->damageStamina(3);
    if(++life->memory[rapeDelay]<5)
    {
        return 0;
    }
    else
    {
        life->memory[rapeDelay]=0;
    }
    WorldController *world = life->getWorld();
    QGraphicsItem *item = world->itemAt(life->x()+(life->rect().width()/2), life->y()+life->rect().height()+1, QTransform());
    if(item)
    {
        if(item->data(itemType)==lifeItem)
        {
            life->damageHealth(1);
            ((LifeCell*)item)->damageHealth(((LifeCell*)item)->getHealth()/3);
            LifeCell *child = new LifeCell(life->getWorld(), life, (LifeCell*)item);
            child->setPos(item->x()-qrand()%50+qrand()%100, item->y()-qrand()%50+qrand()%100);
            life->getWorld()->addLife(child);
            life->setFinish();
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

int rapeUp(LifeCell *life)
{
    life->damageStamina(3);
    if(++life->memory[rapeDelay]<5)
    {
        return 0;
    }
    else
    {
        life->memory[rapeDelay]=0;
    }
    WorldController *world = life->getWorld();
    QGraphicsItem *item = world->itemAt(life->x()+(life->rect().width()/2), life->y()-1, QTransform());
    if(item)
    {
        if(item->data(itemType)==lifeItem)
        {
            life->damageHealth(1);
            ((LifeCell*)item)->damageHealth(((LifeCell*)item)->getHealth()/3);
            LifeCell *child = new LifeCell(life->getWorld(), life, (LifeCell*)item);
            child->setPos(item->x()-qrand()%50+qrand()%100, item->y()-qrand()%50+qrand()%100);
            life->getWorld()->addLife(child);
            life->setFinish();
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

int rapeLeft(LifeCell *life)
{
    life->damageStamina(3);
    if(++life->memory[rapeDelay]<5)
    {
        return 0;
    }
    else
    {
        life->memory[rapeDelay]=0;
    }
    WorldController *world = life->getWorld();
    QGraphicsItem *item = world->itemAt(life->x()-1, life->y()+life->rect().height()/2, QTransform());
    if(item)
    {
        if(item->data(itemType)==lifeItem)
        {
            life->damageHealth(1);
            ((LifeCell*)item)->damageHealth(((LifeCell*)item)->getHealth()/3);
            LifeCell *child = new LifeCell(life->getWorld(), life, (LifeCell*)item);
            child->setPos(item->x()-qrand()%50+qrand()%100, item->y()-qrand()%50+qrand()%100);
            life->getWorld()->addLife(child);
            life->setFinish();
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

int rapeRight(LifeCell *life)
{
    life->damageStamina(3);
    if(++life->memory[rapeDelay]<5)
    {
        return 0;
    }
    else
    {
        life->memory[rapeDelay]=0;
    }
    WorldController *world = life->getWorld();
    QGraphicsItem *item= world->itemAt(life->x()+(life->rect().width()+1), life->y()+life->rect().height()/2, QTransform());
    if(item)
    {
        if(item->data(itemType)==lifeItem)
        {
            life->damageHealth(1);
            ((LifeCell*)item)->damageHealth(((LifeCell*)item)->getHealth()/3);
            LifeCell *child = new LifeCell(life->getWorld(), life, (LifeCell*)item);
            child->setPos(item->x()-qrand()%50+qrand()%100, item->y()-qrand()%50+qrand()%100);
            life->getWorld()->addLife(child);
            life->setFinish();
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

#endif // REPLICATE_H
