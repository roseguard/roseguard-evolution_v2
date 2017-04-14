#include "methodlists.h"
#include "QTime"

MethodLists::MethodLists()
{
    qsrand(QTime::currentTime().msec());
}

void MethodLists::append(ActionPointer action, QString actionName)
{
    list.append(action);
}

quint32 MethodLists::getRandomIndex()
{
    return qrand()%list.length();
}

QAction MethodLists::getActionAt(quint32 index)
{
    return list.at(index);
}

QString MethodLists::getActionNameAt(quint32 index)
{
    return names.at(index);
}

void MethodLists::removeAt(quint32 index)
{
    if(index < list.length())
    {
        list.removeAt(index);
        names.removeAt(index);
    }
}

void MethodLists::replace(quint32 index, ActionPointer action, QString actionName)
{
    if(index < list.length())
    {
        list.replace(index, action);
        names.replace(index, actionName);
    }
}
