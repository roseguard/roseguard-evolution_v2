#ifndef DNACLASS_H
#define DNACLASS_H

#include <QVector>

class LifeCell;
class Gene;
typedef int (*ActionPointer)(LifeCell*);

class DNAClass
{
public:
    DNAClass(LifeCell *organism);
    void append(Gene gene);
    void replace(quint32 index, Gene gene);
    void randomMutation();
    void run();
private:
    QVector<Gene> genePool;
    LifeCell      *life;
};

#endif // DNACLASS_H
