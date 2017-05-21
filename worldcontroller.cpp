#include "worldcontroller.h"
#include "lifecell.h"
#include "methodlists.h"
#include "dnaclass.h"

WorldController::WorldController(qreal x, qreal y, qreal width, qreal height, QObject * parent, MethodLists *list)
    : QGraphicsScene(x, y, width, height, parent)
{
    QPixmap back = QPixmap(":/img/back.png").scaled(desk.width(), desk.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QGraphicsPixmapItem *backItem = addPixmap(back);
    backItem->setPos(0,0);
    backItem->setData(itemType, backgroundItem);


    methods = list;
    list->initBaseMethods();

    for(int i = 0; i < 10; i++)
    {
        addLife();
        addFood();
    }

    QTimer::singleShot(1, this, SLOT(makeStep()));
}

void WorldController::addLife(LifeCell *life)
{
    if(life==0)
    {
        qreal tempx = qrand()%desk.width();
        qreal tempy = qrand()%desk.height();
        life = new LifeCell(this, methods);
        life->setPos(tempx, tempy);
        addItem(life);
    }
    else
    {
        addItem(life);
    }
    lifes.append(life);
}

void WorldController::addFood()
{
    QGraphicsRectItem *food = new QGraphicsRectItem(0);
    food->setBrush(* new QBrush(Qt::white));
    int rectSize = 20 + qrand()%80;
    food->setRect(0,0,rectSize,rectSize);
    qreal tempx = qrand()%desk.width();
    qreal tempy = qrand()%desk.height();
    food->setPos(tempx, tempy);
    food->setData(itemType, foodItem);
    addItem(food);
}

void WorldController::keyPressEvent(QKeyEvent *event)
{
    if(event->text()=="w")
    {
        makeStep();
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
            lifes.removeAt(i);
            i--;
        }
        else
        {
            while(!lifes.at(i)->isFinished());
            lifes[i]->live();
            if(qrand()%100 > 95)
                addFood();
        }
    }
    QTimer::singleShot(1, this, SLOT(makeStep()));
}
