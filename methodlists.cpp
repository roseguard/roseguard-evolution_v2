#include "methodlists.h"
#include "functionsfile.h"


MethodLists* MethodLists::singleList;

MethodLists::MethodLists()
{
}

MethodLists::~MethodLists()
{

}

void MethodLists::init()
{
    singleList = new MethodLists;
}

void MethodLists::append(ActionPointer action, QString actionName)
{
    singleList->list.append(action);
    singleList->names.append(actionName);
}

quint32 MethodLists::getRandomIndex()
{
    return qrand()%singleList->list.length();
}

ActionPointer MethodLists::getActionAt(quint32 index)
{
    return singleList->list.at(index);
}

ActionPointer MethodLists::getActionAt(QString name)
{
    for(int i = 0; i < singleList->names.length(); i++)
    {
        if(singleList->names.at(i)==name)
        {
            return singleList->list.at(i);
        }
    }
    return nullptr;
}

QString MethodLists::getActionNameAt(quint32 index)
{
    return singleList->names.at(index);
}

void MethodLists::removeAt(qint32 index)
{
    if(index < singleList->list.length())
    {
        singleList->list.removeAt(index);
        singleList->names.removeAt(index);
    }
}

void MethodLists::replace(qint32 index, ActionPointer action, QString actionName)
{
    if(index < singleList->list.length())
    {
        singleList->list.replace(index, action);
        singleList->names.replace(index, actionName);
    }
}

void MethodLists::initBaseMethods()
{
    writeFunctions();
}
