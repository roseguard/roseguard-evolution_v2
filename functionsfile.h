#ifndef FUNCTIONSFILE_H
#define FUNCTIONSFILE_H

#include <QTime>
#include "functions/eat.h"
#include "functions/isFood.h"
#include "functions/move.h"
#include "functions/replicate.h"
#include "functions/islife.h"
#include "functions/bite.h"
#include "functions/emptyactions.h"

void writeFunctions()
{
//    list->append(&testFunc, "testFunc");
//    list->append(&testFunc2, "testFunc2");

    MethodLists::append(&isFoodDown,   "isFoodDown");
    MethodLists::append(&isFoodUp,     "isFoodUp");
    MethodLists::append(&isFoodLeft,   "isFoodLeft");
    MethodLists::append(&isFoodRight,  "isFoodRight");

    MethodLists::append(&moveDown,     "moveDown");
    MethodLists::append(&moveUp,       "moveUp");
    MethodLists::append(&moveLeft,     "moveLeft");
    MethodLists::append(&moveRight,    "moveRight");
    MethodLists::append(&moveRandom,   "moveRandom");

    MethodLists::append(&eatDown,  "eatDown");
    MethodLists::append(&eatUp,    "eatUp");
    MethodLists::append(&eatLeft,  "eatLeft");
    MethodLists::append(&eatRight, "eatRight");

    MethodLists::append(&isReadyForReplication, "isReadyForReplication");
    MethodLists::append(&replicate, "replicate");

    MethodLists::append(&isLifeDown,   "isLifeDown");
    MethodLists::append(&isLifeUp,     "isLifeUp");
    MethodLists::append(&isLifeLeft,   "isLifeLeft");
    MethodLists::append(&isLifeRight,  "isLifeRight");

    MethodLists::append(&biteDown,  "biteDown");
    MethodLists::append(&biteUp,    "biteUp");
    MethodLists::append(&biteLeft,  "biteLeft");
    MethodLists::append(&biteRight, "biteRight");

    MethodLists::append(&rapeDown,  "rapeDown");
    MethodLists::append(&rapeUp,    "rapeUp");
    MethodLists::append(&rapeLeft,  "rapeLeft");
    MethodLists::append(&rapeRight, "rapeRight");

    MethodLists::append(&emptyBase,             "emptyBase");
    MethodLists::append(&emptyWithFinishing,    "emptyWithFinishing");
    MethodLists::append(&emptyWithReturn,       "emptyWithReturn");
}

#endif // FUNCTIONSFILE_H
