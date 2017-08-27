#ifndef VIEWER_H
#define VIEWER_H

#include "includes.h"


class Viewer : public QGraphicsView
{
    Q_OBJECT

public:
    Viewer(QWidget *parent = 0);
    ~Viewer();
signals:
    void showMenu();
public:
    WorldController *world;
    QDesktopWidget  desk;
};

#endif // VIEWER_H
