#ifndef VIEWER_H
#define VIEWER_H

#include "includes.h"

class WorldController;

class Viewer : public QGraphicsView
{
    Q_OBJECT

public:
    Viewer(QWidget *parent = 0);
    ~Viewer();

    WorldController *world;
    QDesktopWidget  desk;
};

#endif // VIEWER_H
