#include "worldcontroller.h"
#include "lifecell.h"

WorldController::WorldController(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    : QGraphicsScene(x, y, width, height, parent)
{
    QPixmap back = QPixmap(":/img/back.png").scaled(desk.width(), desk.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    addPixmap(back)->setPos(0,0);
}

void WorldController::addLife(LifeCell *life)
{
    lifes.append(life);
    {
        qreal tempx = qrand()%desk.width();
        qreal tempy = qrand()%desk.height();
        this->addItem(life);
    }
}
