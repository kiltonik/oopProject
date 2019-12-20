#include "addingflourwindow.h"
#include "ui_addingflourwindow.h"

#include <QCloseEvent>
#include <QPainter>
#include <QPicture>
#include <qdebug.h>

AddingFlourWindow::AddingFlourWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddingFlourWindow)
{
    this->interactor = &(MainWindowInteractor::getInstance());
    ui->setupUi(this);
    QWidget::setFixedSize(700, 360);
}

AddingFlourWindow::~AddingFlourWindow()
{
    delete ui;
}
void AddingFlourWindow::on_anotherFlourButton_clicked(){
    emit this->endClicked();
    this->destroy();
}
void AddingFlourWindow::on_addButton_clicked(){
    int x = ui->spinBox->value();
    QString color = ui->comboBox->currentText();
    interactor->addToTemporaryBouquet(this->name,color,x);
    emit this->endClicked();
    this->close();
}

void AddingFlourWindow::fillData(QString flourName){
    this->name = flourName;
    QList<QString> t;
    this->interactor->getFlourColors(flourName);
    QStringList tmp = QStringList(this->
                                  interactor->getFlourColors(this->name));
    ui->price->setText(QString::number(this->
                                       interactor->getFlourPrice(flourName, tmp[0])));
    ui->comboBox->addItems(QStringList(this->
                                       interactor->getFlourColors(this->name)));
}

void AddingFlourWindow::closeEvent(QCloseEvent *event){
    emit this->endClicked();
    event->accept();
}

void AddingFlourWindow::paintEvent(QPaintEvent *event){
    QImage tmp(this->interactor->getFlourPic(this->name, this->color));
    QPainter painter(this);
    painter.drawImage(20,20,tmp.scaled(351,311));
}

void AddingFlourWindow::on_comboBox_currentTextChanged(const QString &color)
{
    this->color = color;
    ui->price->setText(QString::number(this->
                                       interactor->getFlourPrice(this->name, color)));

    this->update();
}
