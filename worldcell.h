#ifndef WORLDCELL_H
#define WORLDCELL_H

#include "includes.h"

class WorldCell : public QGraphicsRectItem
{
public:
    enum Climats
    {
        Arctic,     // no food,     good air
        Tundra,     // less food,   normal air
        Normal,     // normal food, normal air
        Tropical,   // lot of food, less air
        Equatorial, // less food,   less air
        ClimatsCount
    };
    enum Ground
    {
        Water,      // normal food, least air
        Sand,       // no food,     good air
        Land,       // normal food, normal air
        Mountains,  // no food,     less air
        GroundCount
    };
public:
    WorldCell(QPoint pos, Climats climateType, Ground groundType, WorldController *cellWorld);
    ~WorldCell();
    bool spawnFood();
    Climats getClimate();
    Ground getGround();

private:
    Climats currentClimate;
    Ground  currentGround;
    WorldController     *world;
    QGraphicsPixmapItem *climateItem;
    QGraphicsPixmapItem *groundItem;
};

#endif // WORLDCELL_H
