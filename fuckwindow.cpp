#include "fuckwindow.h"
#include "ui_fuckwindow.h"
#include "mainwindowinteractor.h"

FuckWindow::FuckWindow(QWidget *parent,QString name) :
    QMainWindow(parent),
    ui(new Ui::FuckWindow)
{
    ui->setupUi(this);
    //ui->comboBox->addItems(list->getFlourColors(name));хз сработает ли оно так, но должно
    QWidget::setFixedSize(700, 360);
}

FuckWindow::~FuckWindow()
{
    delete ui;
}
void FuckWindow::on_anotherFlourButton_clicked(){
    this->close();
//    setEnabled(true);


}
void FuckWindow::on_addButton_clicked(){
    int x = ui->spinBox->value();
    QString color = ui->comboBox->currentText();
    list->addToTemporaryBouquet(name,color,x);
    //Тут надо вывести в listWidget, у меня ругается почти на все
    // По дизайну хуйня, я хз, что можно вставить справа от listWidget, где есть промежуток между кнопками и боксами


}
