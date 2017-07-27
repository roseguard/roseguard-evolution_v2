#ifndef METHODLISTS_H
#define METHODLISTS_H

#include "includes.h"

class MethodLists
{
public:
    static void init();
    static void append(ActionPointer action, QString actionName);
    static void removeAt(qint32 index);
    static void replace(qint32 index, ActionPointer action, QString actionName);
    static quint32 getRandomIndex();
    static ActionPointer getActionAt(quint32 index);
    static ActionPointer getActionAt(QString name);
    static QString getActionNameAt(quint32 index);
    static MethodLists* getMethodList();
    static void initBaseMethods();
private:
    MethodLists();
    ~MethodLists();
    QVector<ActionPointer> list;
    QVector<QString>       names;
    static MethodLists *singleList;
};

#endif // METHODLISTS_H
