#ifndef VIEWER_H
#define VIEWER_H

#include "includes.h"

class Viewer : public QGraphicsView
{
    Q_OBJECT

public:
    Viewer(MethodLists *list = 0, QWidget *parent = 0);
    ~Viewer();

    WorldController *world;
    QDesktopWidget  desk;
};

#endif // VIEWER_H
