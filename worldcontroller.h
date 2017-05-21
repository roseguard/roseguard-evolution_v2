#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "includes.h"

class WorldController : public QGraphicsScene
{
    Q_OBJECT
public:
    WorldController(qreal x, qreal y, qreal width, qreal height, QObject * parent = 0, MethodLists *list = 0);
    void hit(LifeCell *atacker, qreal side);
    void addLife(LifeCell *life = 0);
    void addFood();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void makeStep();
private:
    QVector<LifeCell*> lifes;

    QDesktopWidget desk;
    MethodLists *methods;
    const qreal lifeWidth = desk.width()*0.05;
    const qreal lifeHeight = desk.height()*0.07;

};

#endif // WORLDCONTROLLER_H
