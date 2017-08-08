#ifndef DNACELL_H
#define DNACELL_H

#include "includes.h"
#include "lifecell.h"

class LifeCell;

class Gene
{
public:
    Gene();
    Gene(LifeCell* organism, ActionPointer thisAction, QString thisActionName, QVector<Gene*> caseActionList);
    Gene(LifeCell* organism, Gene* copyGene);
    ~Gene();
    void changeCaseAction(qint16 index, Gene* action);
    void appendCase(Gene* action);
    void removeCaseAt(qint16 index);
    void removeCaseFromPool(Gene *caseGen);
    void changeBaseAction(ActionPointer action, QString name);
    void setUpperGene(Gene *upper);
    QVector<Gene*> getCaseActions();
    ActionPointer getBaseAction();
    QString getActionName();
    int runGene();
    int runGeneAt(int index);
    int runGeneAtModule(int index);
private:
    LifeCell                *life;
    Gene*                   upperGene;
    QVector<Gene*>          caseActions;
    ActionPointer           baseAction;
    QString                 actionName;
};

#endif // DNACELL_H
