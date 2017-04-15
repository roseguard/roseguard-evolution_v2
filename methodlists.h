#ifndef METHODLISTS_H
#define METHODLISTS_H

#include "includes.h"

typedef int (*ActionPointer)(LifeCell*);

typedef int (*ActionPointer)(LifeCell*);

class MethodLists
{
public:
    MethodLists();
    void append(ActionPointer action, QString actionName);
    void removeAt(quint32 index);
    void replace(quint32 index, ActionPointer action, QString actionName);
    quint32 getRandomIndex();
    ActionPointer getActionAt(quint32 index);
    QString getActionNameAt(quint32 index);
    MethodLists* getMethodList();
private:
    QVector<ActionPointer> list;
    QVector<QString>       names;
};

#endif // METHODLISTS_H
