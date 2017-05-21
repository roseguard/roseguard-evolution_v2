#include "lifecell.h"
#include "worldcontroller.h"
#include "dnaclass.h"
#include "methodlists.h"

LifeCell::LifeCell(WorldController *worldPointer, MethodLists *allMethods)
{
    setBrush(* new QBrush(Qt::red));
//    setRect(0,0,lifeWidth, lifeHeight);
    setRect(0,0,50,50);
    world = worldPointer;
    methods = allMethods;
    setData(itemType, lifeItem);

    QFile readCode("D:\\dna.ros");
    readCode.open(QIODevice::ReadOnly);
    QString codeHandler = readCode.readAll();

    DNA = new DNAClass(this, codeHandler);

//    DNA = new DNAClass(this);
//    for(int i = 0; i < 10; i++)
//    {
//        DNA->randomMutation();
//    }

    for(int i = 0; i < 16; i++)
        memory[i] = 0;

    health = 100;
    stamina = 500;
    healthView = new QGraphicsTextItem(QString::number(health), this);
    staminaView = new QGraphicsTextItem(QString::number(stamina), this);
    staminaView->moveBy(0, 30);

}

LifeCell::LifeCell(WorldController *worldPointer, MethodLists *allMethods, LifeCell *monoparent, qint32 healthValue) : QGraphicsRectItem()
{
    setBrush(* new QBrush(Qt::red));
//    setRect(0,0,lifeWidth, lifeHeight);
    setRect(0,0,50,50);
    world = worldPointer;
    methods = allMethods;
    setData(itemType, lifeItem);

    DNA = new DNAClass(this, monoparent->getDNA()->toString());

    for(int i = 0; i < 16; i++)
        memory[i] = 0;

    health = healthValue;
    stamina = 500;
    healthView = new QGraphicsTextItem(QString::number(health), this);
    staminaView = new QGraphicsTextItem(QString::number(stamina), this);
    staminaView->moveBy(0, 30);
}

LifeCell::LifeCell(WorldController *worldPointer, MethodLists *allMethods, LifeCell *father, LifeCell *mother) : QGraphicsRectItem()
{

}

qint32 LifeCell::getHealth()
{
    return health;
}

qint32 LifeCell::getStamina()
{
    return stamina;
}

qint8  LifeCell::getMutationChance()
{
    return mutationChance;
}

qint32 LifeCell::damageHealth(qint32 value)
{
    health-=value;
    healthView->setPlainText(QString::number(health));
    if(health<=0)
    {
        dead = true;
    }
    return health;
}

qint32 LifeCell::damageStamina(qint32 value)
{
    stamina-=value;
    staminaView->setPlainText(QString::number(stamina));
    return stamina;
}

void LifeCell::feedLife(qint32 value)
{
    health+=value;
    healthView->setPlainText(QString::number(health));
}

void LifeCell::restoreStaminaFromHealth()
{
//    if(health>=5)
    {
        damageHealth(1);
        stamina+=500;
    }
}

WorldController* LifeCell::getWorld()
{
    return world;
}

MethodLists* LifeCell::getMethods()
{
    return methods;
}

void LifeCell::live()
{
    finished = false;
    world->removeItem(this);
    DNA->runDNA();
}

bool LifeCell::isFinished()
{
    return finished;
}

void LifeCell::setFinish()
{
    world->addItem(this);
    finished = true;
}

bool LifeCell::isDead()
{
    return dead;
}

DNAClass* LifeCell::getDNA()
{
    return DNA;
}
