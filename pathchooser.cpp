#include "pathchooser.h"

PathChooser::PathChooser(DNAHotEdit *parent)
{
    lay = new QVBoxLayout(this);

    fsModel = new QFileSystemModel(this);
    fsModel->setRootPath(QDir::rootPath());
    fsTree = new QTreeView(this);
    fsTree->setModel(fsModel);
    fsTree->setCurrentIndex(fsModel->index(""));
    connect(fsTree, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(choosing(QModelIndex)));

    nameLine = new QLineEdit("New dir or file", this);

    createDir = new QPushButton(tr("Create dir"), this);
    connect(createDir, SIGNAL(clicked(bool)), this, SLOT(creatingDir()));

    createFile = new QPushButton(tr("Create file"), this);
    connect(createFile, SIGNAL(clicked(bool)), this, SLOT(creatingFile()));

    lay->addWidget(fsTree);
    lay->addWidget(nameLine);
    lay->addWidget(createDir);
    lay->addWidget(createFile);

    show();
}

PathChooser::~PathChooser()
{

}

void PathChooser::choosing(QModelIndex index)
{
    if(QFile(fsModel->filePath(index)).exists())
        emit choosedPath(fsModel->filePath(index));
}

void PathChooser::creatingDir()
{
    if(!QDir(fsModel->filePath(fsTree->currentIndex())+"/"+nameLine->text()).exists())
    {
        QDir(fsModel->filePath(fsTree->currentIndex())).mkdir(nameLine->text());
    }
}

void PathChooser::creatingFile()
{
    QFile file(fsModel->filePath(fsTree->currentIndex())+"/"+nameLine->text());
    if(!file.exists())
    {
        file.open(QIODevice::WriteOnly);
        file.close();
    }
}
