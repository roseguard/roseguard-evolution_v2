#include "worldcontroller.h"
#include "lifecell.h"
#include "methodlists.h"
#include "dnaclass.h"
#include "viewer.h"
#include "worldcell.h"

#ifdef _WIN32
#include "windows.h"
#endif

WorldController::WorldController(qreal x, qreal y, qreal width, qreal height, Viewer *parent)
    : QGraphicsScene(x, y, width, height, 0)
{
    if(parent)
        viewer = parent;

    qDebug() << "here";
    MethodLists::init();
    MethodLists::initBaseMethods();
    qDebug() << "there";

    QPixmap back = QPixmap(":/img/back.png").scaled(desk.width(), desk.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QGraphicsPixmapItem *backItem = addPixmap(back);
    backItem->setPos(0,0);
    backItem->setData(itemType, backgroundItem);

    autoSaveTimer = new QTimer(this);
    connect(autoSaveTimer, SIGNAL(timeout()), this, SLOT(autoSave()));
    autoSaveTimer->start(600000);

    speedView = new QGraphicsTextItem;
    speedView->setPlainText(QString::number(speed));
    speedView->show();
    speedView->setScale(2);
    speedView->setDefaultTextColor(QColor(qRgb(255,255,255)));
    speedView->setPos(desk.width()-100, 50);
    addItem(speedView);

    createGround();

#ifdef WIN32
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);

    cores = sysinfo.dwNumberOfProcessors;
#endif
    for(int i = 0; i < cores; i++)
    {
        threads.append(QPair<QThread*, quint8>(new QThread, 0));
    }
    for(int i = 0; i < 10; i++)
    {
        addLife();
        addFood();
    }

    isLoop = false;

//    sceneThread = new QThread;
//    connect(sceneThread, SIGNAL(started()), this, SLOT(makeStep()));

    stepTimer = new QTimer(this);
    stepTimer->setSingleShot(true);
//    connect(stepTimer, SIGNAL(timeout()), this, SLOT(makeThreadStep()));
    connect(stepTimer, SIGNAL(timeout()), this, SLOT(makeStep()));

//    WorldCell *newCell = new WorldCell(QPoint(50,50), WorldCell::Normal, WorldCell::Water, this);
}

WorldController::~WorldController()
{
    isLoop=false;
    delete speedView;
    QList<QGraphicsItem*> itemList;
    for(int i = 0; i < itemList.length(); i++)
    {
        delete itemList.at(i);
    }
    delete sceneThread;
}

void WorldController::createGround()
{
    int sizeX = (desk.width()/50)+1;
    int sizeY = (desk.height()/50)+1;

    int massive[sizeX][sizeY];

    int value;
    QString tempstr = "testmessage";
    for(int i = 0; i < tempstr.length(); i++)
    {
        value += tempstr.at(i).toLatin1();
    }
    value = QTime::currentTime().msec();
    qsrand(value);

    qreal tempt = -2 * 0.5 * 0.5 * 0.5 + 3 * 0.5 * 0.5;
//        qreal tempt = 0.5 * 0.5 * 0.5 * (0.5 * (0.5 * 6 - 15) + 10);
//        qreal tempt = 0.5;
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            massive[x][y]=qrand()%500;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        for(int y = 0; y < sizeY-1; y++)
        {
            for(int x = 0; x < sizeX-1; x++)
            {
                qreal tempx = x + tempt;
                qreal tempy = y + tempt;
                qreal tempUp = massive[x][y] * (tempt - 1) + massive[x+1][y] * tempt;
                qreal tempDown = massive[x][y+1] * (tempt - 1) + massive[x+1][y+1] * tempt;
                massive[x][y] = tempUp + (tempDown - tempUp) * tempt;
            }
        }
    }

    for(int y = 0; y < sizeY-1; y++)
    {
        for(int x = 0; x < sizeX-1; x++)
        {
            if(abs(massive[x][y])<5)
            {
                WorldCell *newCell = new WorldCell(QPoint(x+(x*50), y+(y*50)), WorldCell::Arctic, WorldCell::Water, this);
                worldCells.append(newCell);
            }
            else if(abs(massive[x][y])<10)
            {
                WorldCell *newCell = new WorldCell(QPoint(x+(x*50), y+(y*50)), WorldCell::Arctic, WorldCell::Sand, this);
                worldCells.append(newCell);
            }
            else if(abs(massive[x][y])<30)
            {
                WorldCell *newCell = new WorldCell(QPoint(x+(x*50), y+(y*50)), WorldCell::Arctic, WorldCell::Land, this);
                worldCells.append(newCell);
            }
            else
            {
                WorldCell *newCell = new WorldCell(QPoint(x+(x*50), y+(y*50)), WorldCell::Arctic, WorldCell::Mountains, this);
                worldCells.append(newCell);
            }
        }
    }
}

void WorldController::addLife(LifeCell *life, bool isCopy)
{
    if(life==0)
    {
        qreal tempx = qrand()%desk.width();
        qreal tempy = qrand()%desk.height();
        life = new LifeCell(this);
        life->setPos(tempx, tempy);
        addItem(life);
        lifes.append(life);
    }
    else
    {
        if(isCopy)
        {
            addItem(life);
            lifes.append(life);
        }
        else
        {
            qreal tempx = qrand()%desk.width();
            qreal tempy = qrand()%desk.height();
            LifeCell *newlife = new LifeCell(this, life, life->getHealth()/2);
            newlife->setPos(tempx, tempy);
            addItem(newlife);
            lifes.append(newlife);
        }
    }
}

void WorldController::addFood()
{
//    QGraphicsRectItem *food = new QGraphicsRectItem(0);
//    food->setBrush(* new QBrush(Qt::white));
//    int rectSize = 20 + qrand()%80;
//    food->setRect(0,0,rectSize,rectSize);
//    qreal tempx = qrand()%desk.width();
//    qreal tempy = qrand()%desk.height();
//    if(!items(tempx, tempy, rectSize, rectSize, Qt::IntersectsItemBoundingRect, Qt::AscendingOrder, QTransform()).length()>1)
//    {
//        delete food;
//        return;
//    }
//    food->setPos(tempx, tempy);
//    food->setData(itemType, foodItem);
//    addItem(food);
//    foodCount++;
    worldCells.at(qrand()%worldCells.length())->spawnFood();
}

void WorldController::keyPressEvent(QKeyEvent *event)
{
    if(event->text()=="w")
    {
        if(!isLoop)
            makeStep();
    }
    else if(event->text()=="+")
    {
        speed+=10;
        speedView->setPlainText(QString::number(speed));
    }
    else if(event->text()=="-")
    {
        speed-=10;
        speedView->setPlainText(QString::number(speed));
    }
    else if(event->key()==Qt::Key_Space)
    {
        isLoop=!isLoop;
        if(isLoop)
            makeStep();
    }
    else if(event->text()=="f")
    {
        addFood();
    }
    else if(event->text()=="e")
    {
        addLife();
    }
    else if(event->text()=="q")
    {
        QGraphicsItem *lifePtr = itemAt(QCursor().pos(), QTransform());
        if(lifePtr->data(itemType)==lifeItem)
        {
            addLife(new LifeCell(this, (LifeCell*)(lifePtr), baseHealth), true);
        }
    }
    else if(event->text()=="r")
    {
        QGraphicsItem *lifePtr = itemAt(QCursor().pos(), QTransform());
        if(lifePtr->data(itemType)==lifeItem)
        {
            ((LifeCell*)(lifePtr))->getDNA()->randomMutation();
        }
    }
    else if(event->text()=="s")
    {
        autoSave();
    }
    else if(event->key()==Qt::Key_Escape)
    {
        emit viewer->showMenu();
    }
}

void WorldController::makeThreadStep()
{
    moveToThread(sceneThread);
    sceneThread->start();
}

void WorldController::makeStep()
{
    for(int i = 0; i < lifes.length(); i++)
    {
        if(i<0)
            i=0;
        if(lifes.at(i)->isDead())
        {
            removeItem(lifes.at(i));
            delete lifes.at(i);
            lifes[i] = Q_NULLPTR;
            lifes.removeAt(i);
            i--;
        }
        else
        {
            lifes[i]->live();
        }
    }
    if(qrand()%100 > 90)
        addFood();
    int tempLenght = lifes.length();
    while(tempLenght < 1)
    {
        if(qrand()%100>50)
            addLife(lifes.first(), false);
        else
            addLife();
        tempLenght++;
    }
    if(lifes.length()>15)
    {
        for(int i = 0; i < lifes.length(); i++)
        {
            lifes.at(i)->damageHealth(1);
        }
    }
    if(isLoop)
    {
        stepTimer->start(speed);
    }
}

void WorldController::autoSave()
{
    QDir dir(QCoreApplication::applicationDirPath());
    dir.mkdir("saves");
    dir.cd("saves");
    dir.mkdir(QDate::currentDate().toString("dd_MM_yyyy"));
    dir.cd(QDate::currentDate().toString("dd_MM_yyyy"));
    dir.mkdir(QTime::currentTime().toString("hh_mm_ss"));
    dir.cd(QTime::currentTime().toString("hh_mm_ss"));
    QString time = "/%1.dna";
    for(int i = 0; i < lifes.length(); i++)
    {
        QFile newLifeBackup(dir.path()+time.arg(i));
        newLifeBackup.open(QIODevice::WriteOnly);
        newLifeBackup.write(lifes.at(i)->getDNA()->toString().toLatin1());
        newLifeBackup.close();
    }
}
