#ifndef METHODLISTS_H
#define METHODLISTS_H

#include "includes.h"

class LifeCell;
class MethodLists;

typedef int (*ActionPointer)(LifeCell*);

class MethodLists
{
public:
    MethodLists();
    void append(ActionPointer action, QString actionName);
    void removeAt(quint32 index);
    void replace(quint32 index, ActionPointer action, QString actionName);
    quint32 getRandomIndex();
    QAction getActionAt(quint32 index);
    QString getActionNameAt(quint32 index);
    MethodLists* getMethodList();
private:
    QVector<ActionPointer> list;
    QVector<QString>       names;
};

#endif // METHODLISTS_H
