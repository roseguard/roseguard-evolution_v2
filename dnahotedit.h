#ifndef DNAHOTEDIT_H
#define DNAHOTEDIT_H

#include "includes.h"

class LifeCell;

class DNAHotEdit : public QWidget
{
    Q_OBJECT
public:
    DNAHotEdit(LifeCell *parent);
    ~DNAHotEdit();
public slots:
    void changeDNA();
    void saveDNA();
    void loadDNA();
    void startSaving(QString path);
    void startLoading(QString path);
    void endChooser();
private:
    QVBoxLayout     *lay;
    QTextEdit       *code;
    QPushButton     *change;
    QPushButton     *save;
    QPushButton     *load;

    LifeCell        *life;

    PathChooser     *chooser;
};

#endif // DNAHOTEDIT_H
