#include "worldcell.h"
#include "worldcontroller.h"

WorldCell::WorldCell(QPoint pos, Climats climateType, Ground groundType, WorldController *cellWorld)
{
    world = cellWorld;
    setPos(pos);
    currentClimate = climateType;
    currentGround = groundType;
    world->addItem(this);

    int defaultSize = 50;

    switch(currentGround)
    {
    case(Water):        groundItem = new QGraphicsPixmapItem(QPixmap(":/img/textures/water.png").scaled(defaultSize,defaultSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation),       this);      break;
    case(Sand):         groundItem = new QGraphicsPixmapItem(QPixmap(":/img/textures/sand.png").scaled(defaultSize,defaultSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation),        this);      break;
    case(Land):         groundItem = new QGraphicsPixmapItem(QPixmap(":/img/textures/land.png").scaled(defaultSize,defaultSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation),        this);      break;
    case(Mountains):    groundItem = new QGraphicsPixmapItem(QPixmap(":/img/textures/mountain.png").scaled(defaultSize,defaultSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation),   this);      break;
    default:            groundItem = new QGraphicsPixmapItem(QPixmap(":/img/textures/water.png").scaled(defaultSize,defaultSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation),       this);      break;
    }

//    switch(currentClimate)
//    {
//    case(Arctic):      climateItem = new QGraphicsPixmapItem(QPixmap(":/img/textsures/arctic.png").scaled(defaultSize,defaultSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);         break;
//    case(Tundra):      climateItem = new QGraphicsPixmapItem(QPixmap(":/img/textsures/tundra.png").scaled(defaultSize,defaultSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);         break;
//    case(Normal):      climateItem = new QGraphicsPixmapItem(QPixmap(":/img/textsures/normal.png").scaled(defaultSize,defaultSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);         break;
//    case(Tropical):    climateItem = new QGraphicsPixmapItem(QPixmap(":/img/textsures/tropical.png").scaled(defaultSize,defaultSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);       break;
//    case(Equatorial):  climateItem = new QGraphicsPixmapItem(QPixmap(":/img/textsures/equatorial.png").scaled(defaultSize,defaultSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);     break;
//    default:           climateItem = new QGraphicsPixmapItem(QPixmap(":/img/textsures/normal.png").scaled(defaultSize,defaultSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation), this);         break;
//    }
    setData(itemType, backgroundItem);
//    climateItem->setData(itemType, backgroundItem);
    groundItem->setData(itemType, backgroundItem);
}

WorldCell::~WorldCell()
{

}

bool WorldCell::spawnFood()
{
    switch(currentGround)
    {
    case(Water) : return false;
    case(Sand):
    {
        if(qrand()%100>80)
        {
            QPixmap foodPix = QPixmap(":/img/textures/food.png").scaled(qrand()%groundItem->pixmap().width(), qrand()%groundItem->pixmap().height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            QGraphicsPixmapItem *newFood = new QGraphicsPixmapItem(foodPix, this);
            newFood->moveBy(qrand()%(groundItem->pixmap().width()-foodPix.width()), qrand()%(groundItem->pixmap().height()-foodPix.height()));
            newFood->setData(itemType, foodItem);
//            world->addItem(newFood);
            return true;
        }
        return false;
    }
    case(Land):
    {
        if(qrand()%100>50)
        {
            QPixmap foodPix = QPixmap(":/img/textures/food.png").scaled(qrand()%groundItem->pixmap().width(), qrand()%groundItem->pixmap().height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            QGraphicsPixmapItem *newFood = new QGraphicsPixmapItem(foodPix, this);
            newFood->moveBy(qrand()%(groundItem->pixmap().width()-foodPix.width()), qrand()%(groundItem->pixmap().height()-foodPix.height()));
            newFood->setData(itemType, foodItem);
//            world->addItem(newFood);
            return true;
        }
        return false;
    }
    case(Mountains):
    {
        if(qrand()%100>90)
        {
            QPixmap foodPix = QPixmap(":/img/textures/food.png").scaled(qrand()%groundItem->pixmap().width(), qrand()%groundItem->pixmap().height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            QGraphicsPixmapItem *newFood = new QGraphicsPixmapItem(foodPix, this);
            newFood->moveBy(qrand()%(groundItem->pixmap().width()-foodPix.width()), qrand()%(groundItem->pixmap().height()-foodPix.height()));
            newFood->setData(itemType, foodItem);
//            world->addItem(newFood);
            return true;
        }
        return false;
    }
    }
}

WorldCell::Climats WorldCell::getClimate()
{
    return currentClimate;
}

WorldCell::Ground WorldCell::getGround()
{
    return currentGround;
}

