#ifndef MY_DEFINES_H
#define MY_DEFINES_H

#include <QDesktopWidget>
#include <QSize>
#include <QVector>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QApplication>
#include <QFile>
#include <QThread>
#include <QProgressBar>
#include <QGraphicsProxyWidget>
#include <QKeyEvent>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

class LifeCell;
class MethodLists;
class Gene;
class WorldController;
class DNAClass;

typedef int (*ActionPointer)(LifeCell*);

#define returnValue -1

#define itemType 0

#define lifeItem        0
#define foodItem        1
#define backgroundItem  2

#endif // MY_DEFINES_H
