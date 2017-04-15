#ifndef LIFECELL_H
#define LIFECELL_H

#include "includes.h"

typedef int (*ActionPointer)(LifeCell*);

class LifeCell : public QGraphicsRectItem
{
public:
    LifeCell(WorldController *worldPointer, MethodLists *allMethods);
    qint32 getHealth();
    qint32 getStamina();
    qint8  getMutationChance();
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
    qint8                   mutationChance;
    WorldController         *world;
    MethodLists             *wholeMethods;

};

#endif // LIFECELL_H
