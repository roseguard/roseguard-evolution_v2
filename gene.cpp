#include "gene.h"

Gene::Gene()
{

}

Gene::Gene(LifeCell *organism, ActionPointer thisAction, QString thisActionName, QVector<Gene> caseActionList)
{
    caseActions = caseActionList;
    baseAction = thisAction;
    actionName = thisActionName;
    life = organism;
}

void Gene::changeCaseAction(qint16 index, Gene action)
{
    if(index < caseActions.length())
    {
        caseActions.replace(index, action);
    }
}

void Gene::appendCase(Gene action)
{
    caseActions.append(action);
}

int Gene::run()
{
    int value = baseAction(life);
    if(value < caseActions.length() && value >= 0)
    {
        return caseActions[value].run();
    }
    return value;
}
