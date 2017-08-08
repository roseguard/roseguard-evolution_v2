#include "dnahotedit.h"
#include "lifecell.h"
#include "dnaclass.h"
#include "pathchooser.h"

DNAHotEdit::DNAHotEdit(LifeCell *parent)
{
    lay = new QVBoxLayout(this);

    code = new QTextEdit(this);
    code->setEnabled(true);
    code->setPlainText(parent->getDNA()->toString());
    code->setTabStopWidth(10);

    change = new QPushButton(tr("Change"), this);
    connect(change, SIGNAL(clicked(bool)), this, SLOT(changeDNA()));

    save = new QPushButton(tr("Save"), this);
    connect(save, SIGNAL(clicked(bool)), this, SLOT(saveDNA()));

    load = new QPushButton(tr("Load"), this);
    connect(load, SIGNAL(clicked(bool)), this, SLOT(loadDNA()));

    lay->addWidget(code);
    lay->addWidget(change);
    lay->addWidget(save);
    lay->addWidget(load);

    life = parent;

    chooser = Q_NULLPTR;
}

DNAHotEdit::~DNAHotEdit()
{
}

void DNAHotEdit::plainNewDNA()
{
    code->setPlainText(life->getDNA()->toString());
}

void DNAHotEdit::changeDNA()
{
    if(life)
    {
        life->changeDNA(new DNAClass(life, code->toPlainText()));
    }
    if(chooser)
        delete chooser;
}

void DNAHotEdit::saveDNA()
{
    if(chooser)
        delete chooser;
    chooser = new PathChooser(this);
    connect(chooser, SIGNAL(choosedPath(QString)), this, SLOT(startSaving(QString)));
    connect(chooser, SIGNAL(destroyed(QObject*)), this, SLOT(endChooser()));
}

void DNAHotEdit::loadDNA()
{
    if(chooser)
        delete chooser;
    chooser = new PathChooser(this);
    connect(chooser, SIGNAL(choosedPath(QString)), this, SLOT(startLoading(QString)));
    connect(chooser, SIGNAL(destroyed(QObject*)), this, SLOT(endChooser()));
}

void DNAHotEdit::startSaving(QString path)
{
    delete chooser;
    chooser = Q_NULLPTR;
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    if(!file.write(code->toPlainText().toLatin1()))
    {
        file.close();
        return;
    }
    file.close();
}

void DNAHotEdit::startLoading(QString path)
{
    delete chooser;
    chooser = Q_NULLPTR;
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    code->setText(file.readAll());
    file.close();
}

void DNAHotEdit::endChooser()
{
    chooser = Q_NULLPTR;
}
