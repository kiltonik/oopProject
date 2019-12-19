#include "fuckwindow.h"
#include "ui_fuckwindow.h"
#include "mainwindowinteractor.h"
#include "mainwindow.h"
#include <iostream>
using namespace std;
FuckWindow::FuckWindow(QWidget *parent, QString name1) :
    QMainWindow(parent),
    ui(new Ui::FuckWindow)
{
    ui->lineEdit->setText(name1);
    connect(parent, SIGNAL(sendFlourName(QString)), this, SLOT(fillData(QString)));
    this->interactor = &(MainWindowInteractor::getInstance());
    ui->setupUi(this);
    QWidget::setFixedSize(700, 360);

}

FuckWindow::~FuckWindow()
{
    delete ui;
}
void FuckWindow::on_anotherFlourButton_clicked(){
    emit this->endClicked();
    this->close();
}
void FuckWindow::on_addButton_clicked(){
    int x = ui->spinBox->value();
    QString color = ui->comboBox->currentText();
    interactor->addToTemporaryBouquet(name,color,x);
    //Тут надо вывести в listWidget, у меня ругается почти на все
    // По дизайну хуйня, я хз, что можно вставить справа от listWidget, где есть промежуток между кнопками и боксами
}

void FuckWindow::fillData(QString flourName){
    this->name = flourName;
    QStringList tmp = QStringList(this->interactor->getFlourColors(this->name));
    ui->comboBox->addItems(QStringList(this->interactor->getFlourColors(this->name)));
}
