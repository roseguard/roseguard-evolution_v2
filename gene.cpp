#include "gene.h"

Gene::Gene()
{

}

Gene::Gene(LifeCell *organism, ActionPointer thisAction, QString thisActionName, QVector<Gene*> caseActionList)
{
    caseActions = caseActionList;
    baseAction = thisAction;
    actionName = thisActionName;
    life = organism;
}

void Gene::changeCaseAction(qint16 index, Gene* action)
{
    if(index < caseActions.length())
    {
        delete caseActions.at(index);
        caseActions.replace(index, action);
    }
}

void Gene::changeBaseAction(ActionPointer action, QString name)
{
    baseAction = action;
    actionName = name;
}

void Gene::appendCase(Gene* action)
{
    caseActions.append(action);
}

void Gene::run()
{
    runGene();
}

int Gene::runGene()
{
//    QFuture<int> future = QtConcurrent::run(baseAction, life);
    if(life->isFinished())
        return 0;
    int value = baseAction(life);
//    future.waitForFinished();
//    int value = future.result();
    if(life->getStamina()<=0 && !life->isFinished())
        life->setFinish();
    if(!life->isFinished())
    {
        if(value < caseActions.length() && value >= 0)
        {
            return caseActions[value]->runGene();
        }
    }
    return value;
}

QVector<Gene*> Gene::getCaseActions()
{
//    QVector<Gene*> temp;
//    for(int i = 0; i < caseActions.length(); i++)
//    {
//        temp.append(caseActions[i]);
//    }
    return caseActions;
}

ActionPointer Gene::getBaseAction()
{
    return baseAction;
}

QString Gene::getActionName()
{
    return actionName;
}

int Gene::runGeneAt(int index)
{
    if(index >= 0 && index < caseActions.length())
    {
        return caseActions[index]->runGene();
    }
    else
    {
        return -1;
    }
}

int Gene::runGeneAtModule(int index)
{
    if(caseActions.length()>0)
    {
        return caseActions[index % caseActions.length()]->runGene();
    }
    else
    {
        return -1;
    }
}
