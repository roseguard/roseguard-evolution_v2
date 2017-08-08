#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "includes.h"

class WorldController : public QGraphicsScene
{
    Q_OBJECT
public:
    WorldController(qreal x, qreal y, qreal width, qreal height, QObject * parent = 0);
    ~WorldController();
    void hit(LifeCell *atacker, qreal side);
    void addLife(LifeCell *life = 0, bool isCopy = false);
    void addFood();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void makeStep();
    void autoSave();
private:
    QTimer *stepTimer;
    QTimer *autoSaveTimer;
    QVector<LifeCell*> lifes;
    quint16 speed = 1;
    bool    isLoop = 0;
    qint32  foodCount = 0;

    QGraphicsTextItem   *speedView;
    QDesktopWidget desk;
    const qreal lifeWidth = desk.width()*0.05;
    const qreal lifeHeight = desk.height()*0.07;

};

#endif // WORLDCONTROLLER_H
