#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include "includes.h"

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
    MenuWidget(QWidget * parent = 0);
    ~MenuWidget();

public slots:
    void startPressed();
    void configPressed();
    void helpPressed();
    void exitPressed();
signals:
    void closeApp();
    void showEvolution();
private:

    QVBoxLayout     *lay;

    QPushButton     *startButt;
    QPushButton     *configButt;
    QPushButton     *helpButt;
    QPushButton     *exitButt;
};

#endif // MENUWIDGET_H
