#include "lifecell.h"
#include "worldcontroller.h"
#include "dnaclass.h"

LifeCell::LifeCell(WorldController *worldPointer, MethodLists *allMethods) : QGraphicsRectItem()
{
    setBrush(* new QBrush(Qt::red));
//    setRect(0,0,lifeWidth, lifeHeight);
    setRect(0,0,50,50);
    world = worldPointer;
    methods = allMethods;
    setData(itemType, lifeItem);

//    QFile file("D:\\dna.ros");
//    file.open(QIODevice::ReadOnly);
//    QString code = file.readAll();

//    DNA = new DNAClass(this, code);

//    file.close();
//    file.open(QIODevice::WriteOnly);
//    file.write(DNA->toString().toLatin1());
//    file.close();

    DNA = new DNAClass(this);
    for(int i = 0; i < 1; i++)
    {
        DNA->randomMutation();
    }

    for(int i = 0; i < 16; i++)
        memory[i] = 0;

    health = 100;
    stamina = 500;
    healthView = new QGraphicsTextItem(QString::number(health), this);
    staminaView = new QGraphicsTextItem(QString::number(stamina), this);
    staminaView->moveBy(0, 30);
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

MethodLists*     LifeCell::getMethods()
{
    return methods;
}

void LifeCell::live()
{
    finished = false;
    DNA->run();
    qDebug() << "pos down " << x()+(rect().width()/2);
    qDebug() << "pos down " << y()+(rect().height()+1);
    qDebug() << pos();
    qDebug() << "";
}

bool LifeCell::isFinished()
{
    return finished;
}

void LifeCell::setFinish()
{
    finished = true;
}

bool LifeCell::isDead()
{
    return dead;
}
