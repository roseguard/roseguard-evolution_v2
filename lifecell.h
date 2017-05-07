#ifndef LIFECELL_H
#define LIFECELL_H

#include "includes.h"

class LifeCell : public QGraphicsRectItem
{
public:
    LifeCell(WorldController *worldPointer, MethodLists *allMethods);
    qint32 getHealth();
    qint32 getStamina();
    qint8  getMutationChance();
    qint32 damageHealth(qint32 value);
    qint32 damageStamina(qint32 value);
    void   feedLife(qint32 value);
    void   restoreStaminaFromHealth();
    WorldController* getWorld();
    MethodLists*     getMethods();
    bool    isDead();
    void    live();
    int     memory[16];

    bool    isFinished();
    void    setFinish();

private:
    QDesktopWidget desk;
    const qreal lifeWidth = desk.width()*0.05;
    const qreal lifeHeight = desk.height()*0.07;

    QGraphicsTextItem       *healthView;
    QGraphicsTextItem       *staminaView;

    qint32                  health;
    qint32                  stamina;
    qint8                   mutationChance;
    DNAClass                *DNA;
    WorldController         *world;
    MethodLists             *methods;
    bool                    finished = true;
    bool                    dead = false;
};

#endif // LIFECELL_H
