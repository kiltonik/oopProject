#include "databasefile.h"
#include "ui_databasefile.h"
dataBaseFile::dataBaseFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dataBaseFile)
{
    this->interactor = &(MainWindowInteractor::getInstance());
    ui->setupUi(this);
}

dataBaseFile::~dataBaseFile()
{
    delete ui;
}
void dataBaseFile::on_dataBaseButton_clicked(){
    this->interactor->setDbFile(ui->lineEdit->text());
    this->close();
}
