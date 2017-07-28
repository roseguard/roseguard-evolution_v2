#ifndef PATHCHOOSER_H
#define PATHCHOOSER_H

#include "includes.h"

class PathChooser : public QWidget
{
    Q_OBJECT
public:
    PathChooser(DNAHotEdit* parent);
    ~PathChooser();
private:
    QVBoxLayout      *lay;

    QFileSystemModel *fsModel;
    QTreeView        *fsTree;

    QLineEdit        *nameLine;
    QPushButton      *createDir;
    QPushButton      *createFile;

public slots:
    void creatingDir();
    void creatingFile();
    void choosing(QModelIndex index);
signals:
    void choosedPath(QString path);
};

#endif // PATHCHOOSER_H
