#include "dnaclass.h"
#include "gene.h"
#include "methodlists.h"
#include "lifecell.h"

DNAClass::DNAClass(LifeCell *organism)
{
    life = organism;
}

DNAClass::DNAClass(LifeCell *organism, QString DNAString)
{
    life = organism;

    QVector<QString> DNACode = DNAString.split('\n').toVector();
    for(int i = 0; i < DNACode.length(); i++)
    {
        DNACode[i].remove('\n');
        DNACode[i].remove('\r');
        QString tempCopy = DNACode.at(i);
        tempCopy.remove('\t');
        if(tempCopy.isEmpty())
        {
            DNACode.removeAt(i);
            i--;
        }
    }

    QVector<quint32> tabsOfCode;
    for(int i = 0; i < DNACode.length(); i++)
    {
        qint16 tabs = 0;
        while(DNACode.at(i).at(tabs)=='\t')
            tabs++;
        tabsOfCode.append(tabs);
        DNACode[i].remove('\t');
    }
    for(quint32 index = 0; index < DNACode.length();)
    {
        QVector<Gene*> tempGens;
        Gene* testGen = new Gene(life, MethodLists::getActionAt(DNACode.at(index)), DNACode.at(index), QVector<Gene*>(0));
        tempGens = createGeneChain(DNACode, tabsOfCode, index);
        for(int i = 0; i < tempGens.length(); i++)
        {
            testGen->appendCase(tempGens.at(i));
        }
        genePool.append(testGen);
    }
}

DNAClass::~DNAClass()
{
    for(int i = 0; i < genePool.length(); i++)
    {
        delete genePool.at(i);
    }
}

QVector<Gene*> DNAClass::createGeneChain(QVector<QString> DNACode, QVector<quint32> tabsLen, quint32 &index)
{
    int currentTab = tabsLen.at(index);
    QVector<Gene*> thisLineGens;
    for(index++;index < DNACode.length();index++)
    {
        if(tabsLen.at(index)<=currentTab || tabsLen.at(index)==0)
        {
            return thisLineGens;
        }
        else
        {
            quint32 thisIndex = index;
            Gene* tempGen = new Gene(life, MethodLists::getActionAt(DNACode.at(thisIndex)), DNACode.at(thisIndex), createGeneChain(DNACode, tabsLen, index));
            thisLineGens.append(tempGen);
            index--;
        }
    }
}

void DNAClass::append(Gene* gene)
{
    genePool.append(gene);
}

void DNAClass::replace(quint32 index, Gene* gene)
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
        if(qrand()%100 < life->getMutationChance())
        {
            /** Loading ptr of whole this dna (recursive) into one vector */
            QVector<Gene*> allGens;
            for(int i = 0; i < genePool.length(); i++)
                allGens.append(genePool.at(i));
            for(int i = 0; i < allGens.length(); i++)
            {
                allGens.append(allGens.at(i)->getCaseActions());
            }
            quint32 geneIndex;
            if(qrand()%100 > 50) /** add one gene if true */
            {
                geneIndex = (qrand()%(allGens.length())+1);
                if(geneIndex==allGens.length()) /**if true - put at the back of main gene pool */
                {
                    quint32 methodIndex = MethodLists::getRandomIndex();
                    ActionPointer method = MethodLists::getActionAt(methodIndex);
                    QString methodName = MethodLists::getActionNameAt(methodIndex);
                    genePool.append(new Gene(life, method, methodName, QVector<Gene*>(0)));
                    return;
                }
                else
                {
                    quint32 methodIndex = MethodLists::getRandomIndex();
                    ActionPointer method = MethodLists::getActionAt(methodIndex);
                    QString methodName = MethodLists::getActionNameAt(methodIndex);
                    allGens.at(geneIndex)->appendCase(new Gene(life, method, methodName, QVector<Gene*>(0)));
                    return;
                }
            }
            else                /** Change or delete gene if false */
            {
                if(qrand()%100 > 50)    // change gene if true
                {
                    geneIndex = (qrand()%(allGens.length()));
                    quint32 methodIndex = MethodLists::getRandomIndex();
                    ActionPointer method = MethodLists::getActionAt(methodIndex);
                    QString methodName = MethodLists::getActionNameAt(methodIndex);
                    allGens.at(geneIndex)->changeBaseAction(method, methodName);
                }
                else                    //delete gene if false
                {
                    if(allGens.length()>3)
                    {
                        geneIndex = 1+(qrand()%(allGens.length()-1));
                        delete allGens.at(geneIndex);
                    }
                }
            }
        }
    }
    else
    {
        quint32 methodIndex = MethodLists::getRandomIndex();
        ActionPointer method = MethodLists::getActionAt(methodIndex);
        QString methodName = MethodLists::getActionNameAt(methodIndex);
        genePool.append(new Gene(life, method, methodName, QVector<Gene*>(0)));
    }
    life->updateCode();
}

void DNAClass::runDNA()
{
    for(int i = 0; i < genePool.length(); i++)
    {
        if(life->getStamina()<=0)
            life->restoreStaminaFromHealth();
        genePool.at(i)->runGene();
    }
    if(!life->isFinished())
        life->setFinish();
}

QString DNAClass::toString()
{
    if(genePool.length()!=0)
    {
        QString out;
        quint32 tablen = 0;
        QVector<Gene*> allGens = genePool;
        for(int i = 0; i < allGens.length(); i++)
        {
            for(int j = 0; j < tablen; j++)
                out.append("\t");
            out.append(allGens.at(i)->getActionName() + "\n");
            out.append(recusiveGetGens(allGens.at(i), tablen+1));
        }
        return out;
    }
}

QString DNAClass::recusiveGetGens(Gene* lastGen, quint32 tablen)
{
    QString out;
    QVector<Gene*> allGens = lastGen->getCaseActions();
    for(int i = 0; i < allGens.length(); i++)
    {
        for(int j = 0; j < tablen; j++)
            out.append("\t");
        out.append(allGens.at(i)->getActionName() + "\n");
        out.append(recusiveGetGens(allGens.at(i), tablen+1));
    }
    return out;
}

QVector<Gene*> DNAClass::getGenePool()
{
    return genePool;
}

QVector<Gene *> DNAClass::getAllGens()
{
    QVector<Gene*> allGens;
    for(int i = 0; i < genePool.length(); i++)
        allGens.append(genePool.at(i));
    for(int i = 0; i < allGens.length(); i++)
    {
        allGens.append(allGens.at(i)->getCaseActions());
    }
    return allGens;
}

void DNAClass::removeGeneFromPool(Gene *gene)
{
    for(int i = 0; i < genePool.length(); i++)
    {
        if(gene==genePool.at(i))
        {
            genePool.removeAt(i);
            return;
        }
    }
}
