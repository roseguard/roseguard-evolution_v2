#ifndef LIFECELL_H
#define LIFECELL_H

#include "includes.h"

class MethodLists;
class LifeCell;
class WorldController;

typedef int (*ActionPointer)(LifeCell*);

class LifeCell : public QGraphicsRectItem
{
public:
    LifeCell(WorldController *worldPointer);
    qint32 getHealth();
    qint32 getStamina();
    qint32 damageHealth(qint32 value);
    qint32 damageStamina(qint32 value);
    WorldController* getWorld();
    MethodLists*     getMethods();

private:
    QDesktopWidget desk;
    const qreal lifeWidth = desk.width()*0.05;
    const qreal lifeHeight = desk.height()*0.07;

    qint32                  health;
    qint32                  stamina;
    WorldController         *world;
    MethodLists             *listArea;

};

#endif // LIFECELL_H
