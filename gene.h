#ifndef DNACELL_H
#define DNACELL_H

#include <QVector>
#include "includes.h"
#include "lifecell.h"

class LifeCell;
typedef int (*ActionPointer)(LifeCell*);

class Gene
{
public:
    Gene();
    Gene(LifeCell* organism, ActionPointer thisAction, QString thisActionName, QVector<Gene> caseActionList);
    void changeCaseAction(qint16 index, Gene action);
    void appendCase(Gene action);
    int  run();
private:
    LifeCell                *life;
    QVector<Gene>           caseActions;
    ActionPointer           baseAction;
    QString                 actionName;
};

#endif // DNACELL_H
