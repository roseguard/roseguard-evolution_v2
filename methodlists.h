#ifndef METHODLISTS_H
#define METHODLISTS_H

#include "includes.h"

class MethodLists
{
public:
    MethodLists();
    void append(ActionPointer action, QString actionName);
    void removeAt(qint32 index);
    void replace(qint32 index, ActionPointer action, QString actionName);
    quint32 getRandomIndex();
    ActionPointer getActionAt(quint32 index);
    ActionPointer getActionAt(QString name);
    QString getActionNameAt(quint32 index);
    MethodLists* getMethodList();
    void initBaseMethods();
private:
    QVector<ActionPointer> list;
    QVector<QString>       names;
};

#endif // METHODLISTS_H
