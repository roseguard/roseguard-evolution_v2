#include "dnaclass.h"
#include "gene.h"
#include "methodlists.h"
#include "lifecell.h"

DNAClass::DNAClass(LifeCell *organism)
{
    life = organism;
}

void DNAClass::append(Gene gene)
{
    genePool.append(gene);
}

void DNAClass::replace(quint32 index, Gene gene)
{
    if(index < genePool.length())
    {
        genePool.replace(index, gene);
    }
}

void DNAClass::randomMutation()
{
    if(genePool.length() > 0)
    {

    }
    else
    {
//        QVector<Gene> tempVect;
//        Gene temp(life, life->getMethods()->getRandom(), tempVect);
//        genePool.append(temp);
    }
}

void DNAClass::run()
{
    for(int i = 0; i < genePool.length(); i++)
    {
        genePool[i].run();
    }
}
