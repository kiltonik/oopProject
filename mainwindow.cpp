#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fuckwindow.h"
#include "finalwindow.h"
#include "databasefile.h"
#include "mainwindowinteractor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->interactor = &(MainWindowInteractor::getInstance());
    ui->setupUi(this);
    QWidget::setFixedSize(730, 550);
    MainWindow::ui->roseButton->setIcon(QIcon("rose.jpg"));
    MainWindow::ui->roseButton->setIconSize(QSize(180,180));
    MainWindow::ui->lilButton->setIcon(QIcon("lil.jpg"));
    MainWindow::ui->lilButton->setIconSize(QSize(180,180));
    MainWindow::ui->orchButton->setIcon(QIcon("orh.jpg"));
    MainWindow::ui->orchButton->setIconSize(QSize(220,170));
    MainWindow::ui->zhasButton->setIcon(QIcon("zha.jpg"));
    MainWindow::ui->zhasButton->setIconSize(QSize(180,180));
    MainWindow::ui->chrizButton->setIcon(QIcon("chr.jpg"));
    MainWindow::ui->chrizButton->setIconSize(QSize(180,180));
    MainWindow::ui->gorButton->setIcon(QIcon("gor.jpg"));
    MainWindow::ui->gorButton->setIconSize(QSize(180,180));
 }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_roseButton_clicked()
{
    QString name = "Rose";
    this->fuckWindow = new FuckWindow(nullptr);

    emit sendFlourName(name);

    this->fuckWindow->show();

    this->setEnabled(false);
    this->fuckWindow->setEnabled(true);


    QObject::connect(this->fuckWindow, &FuckWindow::endClicked,
                     this, &MainWindow::enableWindow);

}

void MainWindow::on_lilButton_clicked()
{
    QString name = "Lilia";
    this->fuckWindow = new FuckWindow(nullptr);

    this->fuckWindow->show();

    this->setEnabled(false);
    this->fuckWindow->setEnabled(true);

    QObject::connect(this->fuckWindow, &FuckWindow::endClicked,
                     this, &MainWindow::enableWindow);
}
void MainWindow::on_orchButton_clicked()
{
    QString name = "Orchideya";
    this->fuckWindow = new FuckWindow(nullptr);

    this->fuckWindow->show();

    this->setEnabled(false);
    this->fuckWindow->setEnabled(true);

    QObject::connect(this->fuckWindow, &FuckWindow::endClicked,
                     this, &MainWindow::enableWindow);
}
void MainWindow::on_zhasButton_clicked()
{
    QString name = "Zhasmin";
    this->fuckWindow = new FuckWindow(nullptr);

    this->fuckWindow->show();

    this->setEnabled(false);
    this->fuckWindow->setEnabled(true);

    QObject::connect(this->fuckWindow, &FuckWindow::endClicked,
                     this, &MainWindow::enableWindow);
}
void MainWindow::on_chrizButton_clicked()
{
    QString name = "Chrizantema";
    this->fuckWindow = new FuckWindow(nullptr);

    this->fuckWindow->show();

    this->setEnabled(false);
    this->fuckWindow->setEnabled(true);

    QObject::connect(this->fuckWindow, &FuckWindow::endClicked,
                     this, &MainWindow::enableWindow);
}
void MainWindow::on_gorButton_clicked()
{
    QString name = "Gortensiya";

    this->fuckWindow = new FuckWindow(nullptr);

    this->fuckWindow->show();

    this->setEnabled(false);
    this->fuckWindow->setEnabled(true);

    QObject::connect(this->fuckWindow, &FuckWindow::endClicked,
                     this, &MainWindow::enableWindow);
}
void MainWindow::on_bouquetButton_clicked()
{
    this->finalWindow = new FinalWindow(nullptr);

    this->finalWindow->show();

    this->setEnabled(false);
    this->finalWindow->setEnabled(true);

    QObject::connect(this->finalWindow, &FinalWindow::endClicked,
                     this, &MainWindow::enableWindow);
}
void MainWindow::on_dataBaseButton_clicked(){
    dataBaseFile window;
    window.setModal(true);
    window.exec();
}

void MainWindow::enableWindow(){
    this->setEnabled(true);
}

//QString MainWindow::sendFlourName(QString flourName){
//    return flourName;
//}
