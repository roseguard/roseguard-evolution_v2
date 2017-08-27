#include "mainwidget.h"
#include "menuwidget.h"
#include "viewer.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    lay = new QVBoxLayout(this);
    lay->setMargin(0);
    menu = new MenuWidget(this);
    connect(menu, SIGNAL(closeApp()), this, SLOT(close()));
    connect(menu, SIGNAL(showEvolution()), this, SLOT(showScene()));
    evolution = new Viewer(this);
    evolution->hide();
    connect(evolution, SIGNAL(showMenu()), this, SLOT(showMenu()));
    lay->addWidget(menu);

    showFullScreen();
}

MainWidget::~MainWidget()
{

}

void MainWidget::showScene()
{
    lay->removeWidget(menu);
    lay->addWidget(evolution);
    evolution->show();
    evolution->setFocus();
}

void MainWidget::showMenu()
{
    lay->removeWidget(evolution);
    lay->addWidget(menu);
    evolution->hide();
}
