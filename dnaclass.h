#ifndef DNACLASS_H
#define DNACLASS_H

#include "includes.h"

typedef int (*ActionPointer)(LifeCell*);

class DNAClass
{
public:
    DNAClass(LifeCell *organism);
    DNAClass(LifeCell *organism, QString DNAString);
    QVector<Gene> createGeneChain(QVector<QString> DNACode, QVector<quint32> tabsLen, quint32 &index);
    void append(Gene gene);
    void replace(quint32 index, Gene gene);
    void randomMutation();
    QString toString();
    QString recusiveGetGens(Gene* lastGen, quint32 tablen);
    void run();
private:
    QVector<Gene> genePool;
    LifeCell      *life;
};

#endif // DNACLASS_H
