#include "finalwindow.h"
#include "ui_finalwindow.h"

FinalWindow::FinalWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FinalWindow)
{
    ui->setupUi(this);
    //ui->listWidget->addItems(тут надо лист передать и сразу по дефолту заполнять виджет)
}

FinalWindow::~FinalWindow()
{
    delete ui;
}
void FinalWindow::on_endButton_clicked(){
    this->close();
}
void FinalWindow::on_changeButton_clicked(){
    this->close();
    setEnabled(true);
}
