#include "menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent) : QWidget(parent)
{
    lay = new QVBoxLayout(this);

    startButt = new QPushButton(tr("start"), this);
    startButt->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    connect(startButt, SIGNAL(clicked(bool)), this, SLOT(startPressed()));
    lay->addWidget(startButt);

    configButt = new QPushButton(tr("config"), this);
    connect(configButt, SIGNAL(clicked(bool)), this, SLOT(configPressed()));
    lay->addWidget(configButt);
    configButt->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    helpButt = new QPushButton(tr("help"), this);
    helpButt->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    connect(helpButt, SIGNAL(clicked(bool)), this, SLOT(helpPressed()));
    lay->addWidget(helpButt);

    exitButt = new QPushButton(tr("exit"), this);
    exitButt->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    connect(exitButt, SIGNAL(clicked(bool)), this, SLOT(exitPressed()));
    lay->addWidget(exitButt);

    setStyleSheet(
                  "color: white;"
                  "background-color: rgb(0, 125, 196);"
                  "selection-color: white;"
                  "selection-background-color: blue;"
                  "border-style: outset;"
                  "border-width: 10px;"
                  "border-color: black;"
                  "font: 100px;");
//    menu->setStyleSheet("border-style: outset;"
//                        "border-width: 2px;"
//                        "border-color: white;");
//    languageMenu->setStyleSheet("border-style: outset;"
//                                      "border-width: 2px;"
//                                      "border-color: white;");
}

MenuWidget::~MenuWidget()
{

}

void MenuWidget::startPressed()
{
    emit showEvolution();
}

void MenuWidget::configPressed()
{

}

void MenuWidget::helpPressed()
{

}

void MenuWidget::exitPressed()
{
    emit closeApp();
}


