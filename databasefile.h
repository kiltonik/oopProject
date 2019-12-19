#ifndef DATABASEFILE_H
#define DATABASEFILE_H

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
    Ui::dataBaseFile *ui;
    void on_dataBaseButton_clicked();
};

#endif // DATABASEFILE_H
