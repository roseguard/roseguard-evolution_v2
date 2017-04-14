#include <QApplication>
#include <QDebug>

#include "viewer.h"
#include "methodlists.h"
#include "worldcontroller.h"
#include "lifecell.h"
#include "gene.h"
#include "dnaclass.h"

typedef int (*ActionPointer)(LifeCell*);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Viewer w;

    //////////////////
    //////////////////

    ActionPointer first = [](LifeCell * curLife){qDebug() << "peaceofshit1"; return 0;};
    ActionPointer second = [](LifeCell * curLife){qDebug() << "peaceofshit2"; return 0;};
    ActionPointer third = [](LifeCell * curLife){qDebug() << "peaceofshit3"; return 0;};


    MethodLists *methods = new MethodLists();
    methods->append(first, "first");
    methods->append(second, "second");
    methods->append(third, "third");

    LifeCell *life = new LifeCell(w.world);
    QVector<Gene> tempVect;
    QVector<Gene> tempVect2;
    tempVect2.append(Gene(life, third, "thid", QVector<Gene>(0)));
    tempVect.append(Gene(life, second, "second", tempVect2));
    Gene gene(life, first, "first", tempVect);

    DNAClass dna(life);
    dna.append(gene);
    dna.append(Gene(life, second, "second", tempVect2));
    dna.run();


    //////////////////
    //////////////////
    return a.exec();
}
