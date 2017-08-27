#include "lifecell.h"
#include "worldcontroller.h"
#include "dnaclass.h"
#include "methodlists.h"
#include "dnahotedit.h"

LifeCell::LifeCell(WorldController *worldPointer)
{
    DNACode = Q_NULLPTR;
    DNAEditor = Q_NULLPTR;
    setBrush(* new QBrush(Qt::red));
//    setRect(0,0,lifeWidth, lifeHeight);
    setRect(0,0,desk.width()*0.02,desk.height()*0.035);
    world = worldPointer;
    setData(itemType, lifeItem);

//    QFile readCode("D:\\test\\dna2.ros");
//    readCode.open(QIODevice::ReadOnly);
//    QString codeHandler = readCode.readAll();

//    DNA = new DNAClass(this, codeHandler);

    DNA = new DNAClass(this);
    for(int i = 0; i < 10; i++)
    {
        DNA->randomMutation();
    }

    for(int i = 0; i < 16; i++)
        memory[i] = 0;

    health = 100;
    stamina = 500;
    healthView = new QGraphicsTextItem(QString::number(health), this);
//    healthView->setScale();
    staminaView = new QGraphicsTextItem(QString::number(stamina), this);
//    staminaView->setScale(0.7);
    staminaView->moveBy(0, 15);

    DNACode = new QGraphicsTextItem(this);
    DNACode->setDefaultTextColor(QColor(qRgb(0,255,0)));
    DNACode->setPlainText(DNA->toString());
    DNACode->moveBy(rect().width(), 0);
    DNACode->hide();

    DNAEditor = Q_NULLPTR;

}

LifeCell::LifeCell(WorldController *worldPointer, LifeCell *monoparent, qint32 healthValue)
{
    DNACode = Q_NULLPTR;
    DNAEditor = Q_NULLPTR;
    setBrush(* new QBrush(Qt::red));
//    setRect(0,0,lifeWidth, lifeHeight);
    setRect(0,0,desk.width()*0.02,desk.height()*0.035);
    world = worldPointer;
    setData(itemType, lifeItem);

    DNA = new DNAClass(this, monoparent->getDNA()->toString());

    for(int i = 0; i < 16; i++)
        memory[i] = 0;

    if(qrand()%100>50)
    {
        DNA->randomMutation();
    }

    health = healthValue;
    stamina = 500;
    healthView = new QGraphicsTextItem(QString::number(health), this);
//    healthView->setScale(0.7);
    staminaView = new QGraphicsTextItem(QString::number(stamina), this);
//    staminaView->setScale(0.7);
    staminaView->moveBy(0, 15);

    DNACode = new QGraphicsTextItem(this);
    DNACode->setDefaultTextColor(QColor(qRgb(0,255,0)));
    DNACode->setPlainText(DNA->toString());
    DNACode->moveBy(rect().width(), 0);
    DNACode->hide();

    DNAEditor = Q_NULLPTR;
}

LifeCell::LifeCell(WorldController *worldPointer, LifeCell *father, LifeCell *mother)
{
    DNACode = Q_NULLPTR;
    DNAEditor = Q_NULLPTR;
    setBrush(* new QBrush(Qt::red));
//    setRect(0,0,lifeWidth, lifeHeight);
    setRect(0,0,desk.width()*0.02,desk.height()*0.035);
    world = worldPointer;
    setData(itemType, lifeItem);

    DNA = new DNAClass(this, mother->getDNA()->toString());
    QVector<Gene*> motherGens = DNA->getAllGens();
    QVector<Gene*> fatherGens = father->getDNA()->getAllGens();
    for(int i = 0; i < motherGens.length(); i++)
    {
        if(qrand()%100>50)
        {
//            motherGens.replace(i, new Gene(this, fatherGens->at(i%fatherGens.length())));
            motherGens.at(i)->changeBaseAction(fatherGens.at(i%fatherGens.length())->getBaseAction(), fatherGens.at(i%fatherGens.length())->getActionName());
        }
    }


    for(int i = 0; i < 16; i++)
        memory[i] = 0;

//    if(qrand()%100>50)
//    {
//        DNA->randomMutation();
//    }

    health = mother->getHealth()/3;
    stamina = 500;
    healthView = new QGraphicsTextItem(QString::number(health), this);
//    healthView->setScale(0.7);
    staminaView = new QGraphicsTextItem(QString::number(stamina), this);
//    staminaView->setScale(0.7);
    staminaView->moveBy(0, 15);

    DNACode = new QGraphicsTextItem(this);
    DNACode->setDefaultTextColor(QColor(qRgb(0,255,0)));
    DNACode->setPlainText(DNA->toString());
    DNACode->moveBy(rect().width(), 0);
    DNACode->hide();

    DNAEditor = Q_NULLPTR;
}

LifeCell::~LifeCell()
{
    delete DNA;
    delete DNACode;
    if(DNAEditor)
        delete DNAEditor;
}

void LifeCell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        if(DNACode->isVisible())
        {
            DNACode->hide();
        }
        else
        {
            DNACode->setPlainText(DNA->toString());
            DNACode->show();
        }
    }
    else if(event->button()==Qt::RightButton)
    {
        feedLife(10);
    }
    else if(event->buttons()==Qt::MiddleButton)
    {
        damageHealth(10);
    }
}

void LifeCell::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        if(!DNAEditor)
        {
            DNAEditor = new DNAHotEdit(this);
        }
        if(DNAEditor->isHidden())
        {
            DNAEditor->plainNewDNA();
            DNAEditor->show();
        }
        else
            DNAEditor->hide();
    }
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
    if(health<=0)
    {
        dead = true;
    }
    return health;
}

qint32 LifeCell::damageStamina(qint32 value)
{
    stamina-=value;
    return stamina;
}

void LifeCell::updateCode()
{
    if(DNACode!=Q_NULLPTR)
    {
        if(DNACode->isVisible())
            DNACode->setPlainText(DNA->toString());
    }
    if(DNAEditor!=Q_NULLPTR)
    {
        if(!DNAEditor->isHidden())
            DNAEditor->plainNewDNA();
    }
}

void LifeCell::updateText()
{
    healthView->setPlainText(QString::number(health));
    staminaView->setPlainText(QString::number(stamina));
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
        stamina+=1000;
    }
}

void LifeCell::restoreSomeStamina(qint32 value)
{
    stamina+=value;
    if(stamina>1000)
        stamina = 1000;
}

WorldController* LifeCell::getWorld()
{
    return world;
}

void LifeCell::live()
{
    finished = false;
    DNA->runDNA();
    updateText();
}

bool LifeCell::wasFinished()
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

DNAClass* LifeCell::getDNA()
{
    return DNA;
}

void LifeCell::changeDNA(DNAClass *newDNA)
{
    delete DNA;
    DNA = newDNA;
    DNACode->setPlainText(DNA->toString());
}
