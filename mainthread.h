#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include "includes.h"

class MainThread : public QObject
{
    Q_OBJECT
public:
    MainThread(WorldController *worldPointer, MethodLists *list);
private:
    WorldController *world;
    MethodLists     *methods;

public slots:
    void startFunction(LifeCell *life, Gene &gen);
signals:
    void functionEnded(LifeCell *life, int value);
};

#endif // MAINTHREAD_H
