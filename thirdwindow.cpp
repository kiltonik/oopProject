#include "thirdwindow.h"
#include "ui_thirdwindow.h"

thirdwindow::thirdwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::thirdwindow)
{
    ui->setupUi(this);
}

thirdwindow::~thirdwindow()
{
    delete ui;
}
void thirdwindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}
