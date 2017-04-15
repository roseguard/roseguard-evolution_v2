#include "dnaclass.h"
#include "gene.h"
#include "methodlists.h"
#include "lifecell.h"

DNAClass::DNAClass(LifeCell *organism)
{
    life = organism;
    qsrand(QTime::currentTime().msec());
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
        if(qrand()%100 > life->getMutationChance())
        {
            /** Loading ptr of whole this dna (recursive) into one vector */
            QVector<Gene*> allGens;
            for(int i = 0; i < genePool.length(); i++)
                allGens.append(&genePool[i]);
            for(int i = 0; i < allGens.length(); i++)
            {
                allGens.append(allGens[i]->getCaseActions());
            }

            /** Just for debag*/
            for(int i = 0; i < allGens.length(); i++)
            {
                qDebug() << allGens.at(i)->getActionName();
            }
            quint32 geneIndex = (qrand()%(allGens.length())+1);
            if(qrand()%100 > 30) /** add one gene if true */
            {
                if(geneIndex==allGens.length())
                {
                    quint32 methodIndex = life->getMethods()->getRandomIndex();
                    ActionPointer method = life->getMethods()->getActionAt(methodIndex);
                    QString methodName = life->getMethods()->getActionNameAt(methodIndex);
                    genePool.append(Gene(life, method, methodName, QVector<Gene>(0)));
                    return;
                }
                else
                {
                    quint32 methodIndex = life->getMethods()->getRandomIndex();
                    ActionPointer method = life->getMethods()->getActionAt(methodIndex);
                    QString methodName = life->getMethods()->getActionNameAt(methodIndex);
                    allGens[geneIndex]->appendCase(Gene(life, method, methodName, QVector<Gene>(0)));
                    return;
                }
            }
            else                /** Change gene if false */
            {
                quint32 methodIndex = life->getMethods()->getRandomIndex();
                ActionPointer method = life->getMethods()->getActionAt(methodIndex);
                QString methodName = life->getMethods()->getActionNameAt(methodIndex);
                allGens[geneIndex]->changeBaseAction(method, methodName);
            }
        }
    }
    else
    {
        quint32 methodIndex = life->getMethods()->getRandomIndex();
        ActionPointer method = life->getMethods()->getActionAt(methodIndex);
        QString methodName = life->getMethods()->getActionNameAt(methodIndex);
        genePool.append(Gene(life, method, methodName, QVector<Gene>(0)));
    }
}

void DNAClass::run()
{
    for(int i = 0; i < genePool.length(); i++)
    {
        genePool[i].run();
    }
}

QString DNAClass::toString()
{
    if(genePool.length()!=0)
    {
        QString out;
        quint32 tablen = 0;
        QVector<Gene> allGens = genePool;
        for(int i = 0; i < allGens.length(); i++)
        {
            for(int j = 0; j < tablen; j++)
                out.append("\t");
            out.append(allGens[i].getActionName() + "\n");
            out.append(recusiveGetGens(&allGens[i], tablen+1));
        }
        qDebug() << out;
        return out;
    }
}

QString DNAClass::recusiveGetGens(Gene *lastGen, quint32 tablen)
{
    QString out;
    QVector<Gene*> allGens = lastGen->getCaseActions();
    for(int i = 0; i < allGens.length(); i++)
    {
        for(int j = 0; j < tablen; j++)
            out.append("\t");
        out.append(allGens[i]->getActionName() + "\n");
        out.append(recusiveGetGens(allGens[i], tablen+1));
    }
    return out;
}
