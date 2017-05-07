#include "methodlists.h"
#include "functionsfile.h"

MethodLists::MethodLists()
{
    qsrand(QTime::currentTime().msec());
}

void MethodLists::append(ActionPointer action, QString actionName)
{
    list.append(action);
    names.append(actionName);
}

quint32 MethodLists::getRandomIndex()
{
    return qrand()%list.length();
}

ActionPointer MethodLists::getActionAt(quint32 index)
{
    return list.at(index);
}

ActionPointer MethodLists::getActionAt(QString name)
{
    for(int i = 0; i < names.length(); i++)
    {
        if(names.at(i)==name)
        {
            return list.at(i);
        }
    }
    return nullptr;
}

QString MethodLists::getActionNameAt(quint32 index)
{
    return names.at(index);
}

void MethodLists::removeAt(qint32 index)
{
    if(index < list.length())
    {
        list.removeAt(index);
        names.removeAt(index);
    }
}

void MethodLists::replace(qint32 index, ActionPointer action, QString actionName)
{
    if(index < list.length())
    {
        list.replace(index, action);
        names.replace(index, actionName);
    }
}

void MethodLists::initBaseMethods()
{
    writeFunctions(this);
}
