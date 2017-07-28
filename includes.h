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

#include <QWidget>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QProgressBar>
#include <QPushButton>
#include <QTextEdit>
#include <QFileSystemModel>
#include <QTreeView>
#include <QLineEdit>

#include <QGraphicsProxyWidget>

#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

class LifeCell;
class MethodLists;
class Gene;
class WorldController;
class DNAClass;
class DNAHotEdit;
class PathChooser;

typedef int (*ActionPointer)(LifeCell*);

#define returnValue -1

#define itemType 0

#define lifeItem        0
#define foodItem        1
#define backgroundItem  2

#define baseHealth      80

#endif // MY_DEFINES_H
