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
    qsrand(QTime::currentTime().msec());
    Viewer w;

//    {
//        MethodLists::baseInit();
//        MethodLists::initBaseMethods();

//        WorldController *world = new WorldController(0,0,500,500, 0);
//        LifeCell *mother = new LifeCell(world);
//        LifeCell *father = new LifeCell(world);
//        LifeCell *child = new LifeCell(world, father, mother);

//        QFile fatherFile("D:\\test\\father.ros");
//        QFile motherFile("D:\\test\\mother.ros");
//        QFile childFile("D:\\test\\child.ros");

//        fatherFile.open(QIODevice::WriteOnly);
//        motherFile.open(QIODevice::WriteOnly);
//        childFile.open(QIODevice::WriteOnly);

//        fatherFile.write(father->getDNA()->toString().toLatin1());
//        motherFile.write(mother->getDNA()->toString().toLatin1());
//        childFile.write(child->getDNA()->toString().toLatin1());

//        fatherFile.close();
//        motherFile.close();
//        childFile.close();

//        return 1;
//    }
    return a.exec();
}
