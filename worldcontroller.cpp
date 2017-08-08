#include "worldcontroller.h"
#include "lifecell.h"
#include "methodlists.h"
#include "dnaclass.h"

WorldController::WorldController(qreal x, qreal y, qreal width, qreal height, QObject * parent)
    : QGraphicsScene(x, y, width, height, parent)
{
    qDebug() << "here";
    MethodLists::init();
    MethodLists::initBaseMethods();
    qDebug() << "there";

    QPixmap back = QPixmap(":/img/back.png").scaled(desk.width(), desk.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QGraphicsPixmapItem *backItem = addPixmap(back);
    backItem->setPos(0,0);
    backItem->setData(itemType, backgroundItem);
    stepTimer = new QTimer(this);
    stepTimer->setSingleShot(true);
    connect(stepTimer, SIGNAL(timeout()), this, SLOT(makeStep()));

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

    for(int i = 0; i < 1; i++)
    {
        addLife();
        addFood();
    }
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
    QGraphicsRectItem *food = new QGraphicsRectItem(0);
    food->setBrush(* new QBrush(Qt::white));
    int rectSize = 20 + qrand()%80;
    food->setRect(0,0,rectSize,rectSize);
    qreal tempx = qrand()%desk.width();
    qreal tempy = qrand()%desk.height();
    if(!items(tempx, tempy, rectSize, rectSize, Qt::IntersectsItemBoundingRect, Qt::AscendingOrder, QTransform()).length()>1)
    {
        delete food;
        return;
    }
    food->setPos(tempx, tempy);
    food->setData(itemType, foodItem);
    addItem(food);
    foodCount++;
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
}

void WorldController::makeStep()
{
    for(int i = 0; i < lifes.length(); i++)
    {
        while(!lifes.at(i)->isFinished());
    }
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
            while(!lifes.at(i)->isFinished());
            lifes[i]->live();
        }
    }
    if(qrand()%100 > 92+lifes.length())
        addFood();
    int tempLenght = lifes.length();
    while(tempLenght < 5)
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
