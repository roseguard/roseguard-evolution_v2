#include "gene.h"
#include "dnaclass.h"

Gene::Gene()
{

}

Gene::Gene(LifeCell *organism, ActionPointer thisAction, QString thisActionName, QVector<Gene*> caseActionList)
{
    upperGene = 0;
    caseActions = caseActionList;
    baseAction = thisAction;
    actionName = thisActionName;
    life = organism;
    for(int i = 0; i < caseActions.length(); i++)
    {
        caseActions.at(i)->setUpperGene(this);
    }
}

Gene::Gene(LifeCell *organism, Gene *copyGene)
{
    upperGene = 0;
    life = organism;
    baseAction = copyGene->baseAction;
    actionName = copyGene->actionName;
    for(int i = 0; i < copyGene->getCaseActions().length(); i++)
    {
        caseActions.append(new Gene(organism, copyGene->getCaseActions().at(i)));
    }
} 

Gene::~Gene()
{
    QVector<Gene*> tempVector = caseActions;
    for(int i = 0; i < tempVector.length(); i++)    // delete all child gens
        delete tempVector.at(i);
    if(upperGene!=0)                                // inform father gen if have, to delete this one from pool
    {
        upperGene->removeCaseFromPool(this);
    }
    else
    {
        life->getDNA()->removeGeneFromPool(this);
    }
}

void Gene::changeCaseAction(qint16 index, Gene* action)
{
    if(index < caseActions.length())
    {
        action->setUpperGene(this);
        Gene *temp = caseActions.at(index);
        caseActions.replace(index, action);
        delete temp;
    }
}

void Gene::changeBaseAction(ActionPointer action, QString name)
{
    baseAction = action;
    actionName = name;
}

void Gene::setUpperGene(Gene *upper)
{
    upperGene = upper;
}

void Gene::appendCase(Gene* action)
{
    caseActions.append(action);
    action->setUpperGene(this);
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

void Gene::removeCaseAt(qint16 index)
{
    delete caseActions.at(index);
}

void Gene::removeCaseFromPool(Gene *caseGen)
{
    for(int i = 0; i<caseActions.length(); i++)
    {
        if(caseActions.at(i)==caseGen)
        {
            caseActions.removeAt(i);
        }
    }
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
