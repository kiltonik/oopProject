#include "finalwindow.h"
#include "ui_finalwindow.h"
#include "iostream"
#include"qdebug.h"

#include <QCloseEvent>
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
    ui->price->setText(QString::number(this->interactor->getTempBouquetPrice()));
}

FinalWindow::~FinalWindow()
{
    delete ui;
}
void FinalWindow::on_endButton_clicked(){
    this->interactor->clearTempBouquet();
    emit this->endClicked();
    this->destroy();
}
void FinalWindow::on_changeButton_clicked(){
    emit this->endClicked();
    this->destroy();
}

void FinalWindow::closeEvent(QCloseEvent *event){
    emit this->endClicked();
    event->accept();
}

void FinalWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QStringList text = item->text().split("\n");
    this->interactor->deleteFlourInTempBouquet(text[0].split(" ")[1],
            text[1].split(" ")[1]);
    delete item;
    ui->price->setText(QString::number(this->interactor->getTempBouquetPrice()));
}
