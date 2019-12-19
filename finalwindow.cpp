#include "finalwindow.h"
#include "ui_finalwindow.h"
#include "iostream"
FinalWindow::FinalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinalWindow)
{
    ui->setupUi(this);
    QWidget::setFixedSize(580, 350);
    this->interactor = &(MainWindowInteractor::getInstance());
    QList<QList<QString>> tmp = interactor->getBouquetInfo();
    foreach (auto i, tmp){
        ui->listWidget->addItem(QString("Flour: ") + i[0] + QString("\nColor: ")
                + i[1] + QString("\nPrice: ") + i[2]);
    }
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

