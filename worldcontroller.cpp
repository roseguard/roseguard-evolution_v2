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

    speedView = new QGraphicsTextItem;
    speedView->setPlainText(QString::number(speed));
    speedView->show();
    speedView->setScale(2);
    speedView->setDefaultTextColor(QColor(qRgb(255,255,255)));
    speedView->setPos(desk.width()-100, 50);
    addItem(speedView);

    for(int i = 0; i < 5; i++)
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
}

void WorldController::makeStep()
{
    qDebug() << lifes.length();
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
            lifes.removeAt(i);
            i--;
        }
        else
        {
            while(!lifes.at(i)->isFinished());
            lifes[i]->live();
        }
    }
    if(qrand()%100 > 80+lifes.length())
        addFood();
    int tempLenght = lifes.length();
    while(tempLenght < 5)
    {
        addLife(lifes.first(), false);
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
