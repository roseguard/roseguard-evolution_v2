#ifndef FUNCTIONSFILE_H
#define FUNCTIONSFILE_H

#include <QTime>
#include "functions/eat.h"
#include "functions/isFood.h"
#include "functions/move.h"
#include "functions/replicate.h"

void writeFunctions(MethodLists *list)
{
    qsrand(QTime::currentTime().msec());
//    list->append(&testFunc, "testFunc");
//    list->append(&testFunc2, "testFunc2");

    list->append(&isFoodDown, "isFoodDown");
    list->append(&isFoodUp, "isFoodUp");
    list->append(&isFoodLeft, "isFoodLeft");
    list->append(&isFoodRight, "isFoodRight");

    list->append(&moveDown, "moveDown");
    list->append(&moveUp, "moveUp");
    list->append(&moveLeft, "moveLeft");
    list->append(&moveRight, "moveRight");
    list->append(&moveRandom, "moveRandom");

    list->append(&eatDown, "eatDown");
    list->append(&eatUp, "eatUp");
    list->append(&eatLeft, "eatLeft");
    list->append(&eatRight, "eatRight");

    list->append(&isReadyForReplication, "isReadyForReplication");
    list->append(&replicate, "replicate");
}

#endif // FUNCTIONSFILE_H
