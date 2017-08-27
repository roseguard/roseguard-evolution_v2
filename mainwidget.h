#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "includes.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
public slots:
    void showScene();
    void showMenu();
private:
    QVBoxLayout *lay;
    Viewer      *evolution;
    MenuWidget  *menu;
};

#endif // MAINWIDGET_H
