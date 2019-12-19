#ifndef DATABASEFILE_H
#define DATABASEFILE_H

#include "mainwindowinteractor.h"

#include <QDialog>

namespace Ui {
class dataBaseFile;
}

class dataBaseFile : public QDialog
{
    Q_OBJECT

public:
    explicit dataBaseFile(QWidget *parent = nullptr);
    ~dataBaseFile();

private:
    MainWindowInteractor* interactor;
    Ui::dataBaseFile *ui;
private slots:
    void on_dataBaseButton_clicked();
};

#endif // DATABASEFILE_H
