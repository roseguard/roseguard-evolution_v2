#ifndef DNACELL_H
#define DNACELL_H

#include "includes.h"
#include "lifecell.h"

class LifeCell;

class Gene
{
public:
    Gene();
    Gene(LifeCell* organism, ActionPointer thisAction, QString thisActionName, QVector<Gene> caseActionList);
    void changeCaseAction(qint16 index, Gene action);
    void appendCase(Gene action);
    void changeBaseAction(ActionPointer action, QString name);
    QVector<Gene*> getCaseActions();
    ActionPointer getBaseAction();
    QString getActionName();
    int  run();
    int runGeneAt(int index);
    int runGeneAtModule(int index);
public:
    LifeCell                *life;
    QVector<Gene>           caseActions;
    ActionPointer           baseAction;
    QString                 actionName;
};

#endif // DNACELL_H
