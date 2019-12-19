#include "databasefile.h"
#include "ui_databasefile.h"
dataBaseFile::dataBaseFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dataBaseFile)
{
    ui->setupUi(this);
}

dataBaseFile::~dataBaseFile()
{
    delete ui;
}
void dataBaseFile::on_dataBaseButton_clicked(){
    QString file = ui->lineEdit->text();
    this->close();
}
