#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "includes.h"

typedef int (*ActionPointer)(LifeCell*);

class WorldController : public QGraphicsScene
{
public:
    WorldController(qreal x, qreal y, qreal width, qreal height, QObject * parent = 0);
    void hit(LifeCell *atacker, qreal side);
    void addLife(LifeCell *life);

private:
    QVector<LifeCell*> lifes;

    QDesktopWidget desk;
    const qreal lifeWidth = desk.width()*0.05;
    const qreal lifeHeight = desk.height()*0.07;
};

#endif // WORLDCONTROLLER_H
