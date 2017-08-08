#ifndef DNACLASS_H
#define DNACLASS_H

#include "includes.h"
#include "gene.h"

class DNAClass
{
public:
    DNAClass(LifeCell *organism);
    DNAClass(LifeCell *organism, QString DNAString);
    ~DNAClass();
    QVector<Gene*> createGeneChain(QVector<QString> DNACode, QVector<quint32> tabsLen, quint32 &index);
    void append(Gene* gene);
    void replace(quint32 index, Gene* gene);
    void randomMutation();
    QVector<Gene*> getGenePool();
    QVector<Gene*> getAllGens();
    void           removeGeneFromPool(Gene *gene);
    QString toString();
    QString recusiveGetGens(Gene *lastGen, quint32 tablen);
    void runDNA();
private:
    QVector<Gene*> genePool;
    LifeCell      *life;
};

#endif // DNACLASS_H
