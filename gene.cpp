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

void Gene::changeBaseAction(ActionPointer action, QString name)
{
    baseAction = action;
    actionName = name;
}

void Gene::appendCase(Gene action)
{
    caseActions.append(action);
}

int Gene::run()
{
    qDebug() << "runned " << actionName;
    qDebug() << life->pos();
    int value = baseAction(life);
    if(life->getStamina()<=0)
        life->setFinish();
    if(!life->isFinished())
    {
        if(value < caseActions.length() && value >= 0)
        {
            return caseActions[value].run();
        }
    }
    return value;
}

QVector<Gene*> Gene::getCaseActions()
{
    QVector<Gene*> temp;
    for(int i = 0; i < caseActions.length(); i++)
    {
        temp.append(&caseActions[i]);
    }
    return temp;
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
        return caseActions[index].run();
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
        return caseActions[index%caseActions.length()].run();
    }
    else
    {
        return -1;
    }
}
