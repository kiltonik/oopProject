#include "finalwindow.h"
#include "ui_finalwindow.h"
#include "iostream"
FinalWindow::FinalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinalWindow)
{
    ui->setupUi(this);
    QWidget::setFixedSize(580, 350);
    //ui->listWidget->addItems(тут надо лист передать и сразу по дефолту заполнять виджет)
}

FinalWindow::~FinalWindow()
{
    delete ui;
}
void FinalWindow::on_endButton_clicked(){
    emit this->endClicked();
    this->close();
}
void FinalWindow::on_changeButton_clicked(){
    this->close();
    setEnabled(true);
}

