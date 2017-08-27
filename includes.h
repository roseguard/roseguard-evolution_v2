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
#include <QThreadPool>

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
#include <QShortcut>
#include <QShortcutEvent>
#include "QtConcurrent/QtConcurrent"

class LifeCell;
class MethodLists;
class Gene;
class WorldController;
class DNAClass;
class DNAHotEdit;
class PathChooser;
class MenuWidget;
class MainWidget;
class Viewer;
class WorldCell;

typedef int (*ActionPointer)(LifeCell*);

#define returnValue -1

#define itemType 0

#define lifeItem        0
#define foodItem        1
#define backgroundItem  2

#define baseHealth      80

#endif // MY_DEFINES_H
