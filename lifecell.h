#ifndef LIFECELL_H
#define LIFECELL_H

#include "includes.h"

class LifeCell : public QGraphicsRectItem
{
public:
    LifeCell(WorldController *worldPointer);
    LifeCell(WorldController *worldPointer, LifeCell *monoparent, qint32 healthValue);
    LifeCell(WorldController *worldPointer, LifeCell *father, LifeCell *mother);
    ~LifeCell();
    qint32 getHealth();
    qint32 getStamina();
    qint8  getMutationChance();
    qint32 damageHealth(qint32 value);
    qint32 damageStamina(qint32 value);
    void   feedLife(qint32 value);
    void   restoreStaminaFromHealth();
    WorldController* getWorld();
    DNAClass*        getDNA();
    bool    isDead();
    void    live();
    int     memory[16];

    bool    isFinished();
    void    setFinish();

//    void mousePressEvent(QMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QDesktopWidget desk;
    const qreal lifeWidth = desk.width()*0.05;
    const qreal lifeHeight = desk.height()*0.07;

    QGraphicsTextItem       *healthView;
    QGraphicsTextItem       *staminaView;

    QGraphicsTextItem       *DNACode;

    qint32                  health;
    qint32                  stamina;
    qint8                   mutationChance;
    DNAClass                *DNA;
    WorldController         *world;
    bool                    finished = true;
    bool                    dead = false;
};

#endif // LIFECELL_H
