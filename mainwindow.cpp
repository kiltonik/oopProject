#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::ui->pushButton->setIcon(QIcon("rose.jpg"));
    MainWindow::ui->pushButton->setIconSize(QSize(180,180));
    MainWindow::ui->pushButton_2->setIcon(QIcon("lil.jpg"));
    MainWindow::ui->pushButton_2->setIconSize(QSize(180,180));
    MainWindow::ui->pushButton_3->setIcon(QIcon("orh.jpg"));
    MainWindow::ui->pushButton_3->setIconSize(QSize(220,170));
    MainWindow::ui->pushButton_4->setIcon(QIcon("zha.jpg"));
    MainWindow::ui->pushButton_4->setIconSize(QSize(180,180));
    MainWindow::ui->pushButton_5->setIcon(QIcon("chr.jpg"));
    MainWindow::ui->pushButton_5->setIconSize(QSize(180,180));
    MainWindow::ui->pushButton_6->setIcon(QIcon("gor.jpg"));
    MainWindow::ui->pushButton_6->setIconSize(QSize(180,180));
    sWindow = new anotherwindow();
        // РїРѕРґРєР»СЋС‡Р°РµРј Рє СЃР»РѕС‚Сѓ Р·Р°РїСѓСЃРєР° РіР»Р°РІРЅРѕРіРѕ РѕРєРЅР° РїРѕ РєРЅРѕРїРєРµ РІРѕ РІС‚РѕСЂРѕРј РѕРєРЅРµ
    connect(sWindow, &anotherwindow::firstWindow, this, &MainWindow::show);

        // РРЅРёС†РёР°Р»РёР·РёСЂСѓРµРј С‚СЂРµС‚СЊРµ РѕРєРЅРѕ
    thirdWindow = new thirdwindow();
        // РїРѕРґРєР»СЋС‡Р°РµРј Рє СЃР»РѕС‚Сѓ Р·Р°РїСѓСЃРєР° РіР»Р°РІРЅРѕРіРѕ РѕРєРЅР° РїРѕ РєРЅРѕРїРєРµ РІ С‚СЂРµС‚СЊРµРј РѕРєРЅРµ
    connect(thirdWindow, &thirdwindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    anotherwindow *tmp = new anotherwindow(this);
    tmp->show();
    tmp->setFocus();
//    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    sWindow->show();
    this->close();
}
void MainWindow::on_pushButton_3_clicked()
{
    sWindow->show();
    this->close();
}
void MainWindow::on_pushButton_4_clicked()
{
    sWindow->show();
    this->close();
}
void MainWindow::on_pushButton_5_clicked()
{

    sWindow->show();
    this->close();
}
void MainWindow::on_pushButton_6_clicked()
{
    sWindow->show();
    this->close();
}
void MainWindow::on_pushButton_7_clicked()
{

    thirdWindow->show();
    this->close();
}
