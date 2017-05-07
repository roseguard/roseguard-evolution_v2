#include "viewer.h"
#include "methodlists.h"
#include "worldcontroller.h"
#include "lifecell.h"
#include "gene.h"
#include "dnaclass.h"

#include <QFile>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Viewer w;
    qDebug() << "lalalala";

    //////////////////
    //////////////////
    {
//        ActionPointer first = [](LifeCell * curLife){qDebug() << "peaceofshit1"; return 0;};
//        ActionPointer second = [](LifeCell * curLife){qDebug() << "peaceofshit2"; return 0;};
//        ActionPointer third = [](LifeCell * curLife){qDebug() << "peaceofshit3"; return 0;};


//        MethodLists *methods = new MethodLists();
//        methods->append(first, "first");
//        methods->append(second, "second");
//        methods->append(third, "third");

//        LifeCell *life = new LifeCell(w.world, methods);
////        QVector<Gene> tempVect;
////        QVector<Gene> tempVect2;
////        tempVect2.append(Gene(life, third, "third", QVector<Gene>(0)));
////        tempVect.append(Gene(life, second, "second", tempVect2));
////        Gene gene(life, first, "first", tempVect);

//        QFile tf("D:/test2.ros");
//        tf.open(QIODevice::ReadOnly);
//        QString dnaStr = tf.readAll();

//        DNAClass dna(life, dnaStr);
//        dna.randomMutation();

//        QFile f("D:/testsss.ros");
//        f.open(QIODevice::WriteOnly);
//        f.write(dna.toString().toLatin1());
//        f.close();
//        dna.run();

//        f.open(QIODevice::ReadOnly);
////        DNAClass test(life, f.readAll());
////        f.close();
////        qDebug() << test.toString();
////        f.setFileName("D:/test2.ros");
////        f.open(QIODevice::WriteOnly);
////        f.write(test.toString().toLatin1());
////        f.close();
    }
    //////////////////
    //////////////////

    return a.exec();
}
