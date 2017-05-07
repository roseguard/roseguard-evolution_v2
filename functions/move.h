#include "methodlists.h"
#include "lifecell.h"
#include "worldcontroller.h"

#define randomSide 0
#define randomSideCountLeft 1

int moveDown(LifeCell *life)
{
    if(life->damageStamina(5)<=0)
        life->setFinish();
    QDesktopWidget desk;
    if(life->rect().height()+life->y() < desk.height())
    {
        qreal tempx = life->x()+(life->rect().width()/2);
        qreal tempy = life->y()+(life->rect().height()+1);
        int itemNum = life->getWorld()->itemAt(tempx , tempy, QTransform())->data(itemType).toInt();
        if(itemNum == backgroundItem)
        {
            life->moveBy(0,1);
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

int moveUp(LifeCell *life)
{
    if(life->damageStamina(5)<=0)
        life->setFinish();
    if(life->rect().height()+life->y() > 0)
    {
        qreal tempx = life->x()+(life->rect().width()/2);
        qreal tempy = life->y()-1;
        int itemNum = life->getWorld()->itemAt(tempx , tempy, QTransform())->data(itemType).toInt();
        if(itemNum == backgroundItem)
        {
            life->moveBy(0,-1);
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

int moveLeft(LifeCell *life)
{
    if(life->damageStamina(5)<=0)
        life->setFinish();
    if(life->rect().height()+life->y() > 0)
    {
        qreal tempx = life->x()-1;
        qreal tempy = life->y()+(life->rect().height()/2);
        int itemNum = life->getWorld()->itemAt(tempx , tempy, QTransform())->data(itemType).toInt();
        if(itemNum == backgroundItem)
        {
            life->moveBy(-1,0);
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

int moveRight(LifeCell *life)
{
    if(life->damageStamina(5)<=0)
        life->setFinish();
    QDesktopWidget desk;
    if(life->rect().height()+life->y() < desk.width())
    {
        qreal tempx = life->x()+(life->rect().width())+1;
        qreal tempy = life->y()+(life->rect().height()/2);
        int itemNum = life->getWorld()->itemAt(tempx , tempy, QTransform())->data(itemType).toInt();
        if(itemNum == backgroundItem)
        {
            life->moveBy(1,0);
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

int moveRandom(LifeCell *life)
{
    if(life->damageStamina(1)<=0)
        life->setFinish();
    if(life->memory[randomSide]!=4 && life->memory[randomSideCountLeft]!=0)
    {
        switch(life->memory[randomSide])
        {
        case(0) : moveDown(life);   break;
        case(1) : moveUp(life);     break;
        case(2) : moveLeft(life);   break;
        case(3) : moveRight(life);  break;
        }
        life->memory[randomSideCountLeft]--;
        return 1;
    }
    else
    {
        int randHandler = qrand()%4;
        switch(randHandler)
        {
        case(0) : moveDown(life);   break;
        case(1) : moveUp(life);     break;
        case(2) : moveLeft(life);   break;
        case(3) : moveRight(life);  break;
        }
        life->memory[randomSide] = randHandler;
        life->memory[randomSideCountLeft] = qrand()%50;
        return 0;
    }
}
