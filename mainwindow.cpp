#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addingflourwindow.h"
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
    ui->roseButton->setIcon(QIcon("pictures\\rose_white.jpg"));
    ui->roseButton->setIconSize(QSize(180,180));
    ui->lilButton->setIcon(QIcon("pictures\\lily_orange.jpg"));
    ui->lilButton->setIconSize(QSize(180,180));
    ui->orchButton->setIcon(QIcon("pictures\\orchid_pink.jpg"));
    ui->orchButton->setIconSize(QSize(180,180));
    ui->zhasButton->setIcon(QIcon("pictures\\jasmine_white.jpg"));
    ui->zhasButton->setIconSize(QSize(180,180));

    ui->chrizButton->setIcon(QIcon("pictures\\chrysanthemum_red_with_white.jpg"));
    ui->chrizButton->setIconSize(QSize(180,180));
    ui->gorButton->setIcon(QIcon("pictures\\hydrangea_blue.jpg"));
    ui->gorButton->setIconSize(QSize(180,180));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_roseButton_clicked()
{
    QString name = "rose";
    this->addingFlourWindow = new AddingFlourWindow(nullptr);


    connect(this, &MainWindow::sendFlourName, addingFlourWindow,
            &AddingFlourWindow::fillData);

    emit sendFlourName(name);

    this->addingFlourWindow->show();

    this->setEnabled(false);
    this->addingFlourWindow->setEnabled(true);


    QObject::connect(this->addingFlourWindow, &AddingFlourWindow::endClicked,
                     this, &MainWindow::enableWindow);

}

void MainWindow::on_lilButton_clicked()
{
    QString name = "lily";
    this->addingFlourWindow = new AddingFlourWindow(nullptr);

    connect(this, &MainWindow::sendFlourName, addingFlourWindow,
            &AddingFlourWindow::fillData);

    emit sendFlourName(name);

    this->addingFlourWindow->show();

    this->setEnabled(false);
    this->addingFlourWindow->setEnabled(true);

    QObject::connect(this->addingFlourWindow, &AddingFlourWindow::endClicked,
                     this, &MainWindow::enableWindow);
}
void MainWindow::on_orchButton_clicked()
{
    QString name = "hydrangea";
    this->addingFlourWindow = new AddingFlourWindow(nullptr);

    connect(this, &MainWindow::sendFlourName, addingFlourWindow,
            &AddingFlourWindow::fillData);

    emit sendFlourName(name);

    this->addingFlourWindow->show();

    this->setEnabled(false);
    this->addingFlourWindow->setEnabled(true);

    QObject::connect(this->addingFlourWindow, &AddingFlourWindow::endClicked,
                     this, &MainWindow::enableWindow);
}
void MainWindow::on_zhasButton_clicked()
{
    QString name = "jasmine";
    this->addingFlourWindow = new AddingFlourWindow(nullptr);

    connect(this, &MainWindow::sendFlourName, addingFlourWindow,
            &AddingFlourWindow::fillData);

    emit sendFlourName(name);

    this->addingFlourWindow->show();

    this->setEnabled(false);
    this->addingFlourWindow->setEnabled(true);

    QObject::connect(this->addingFlourWindow, &AddingFlourWindow::endClicked,
                     this, &MainWindow::enableWindow);
}
void MainWindow::on_chrizButton_clicked()
{
    QString name = "chrysanthemum";
    this->addingFlourWindow = new AddingFlourWindow(nullptr);

    connect(this, &MainWindow::sendFlourName, addingFlourWindow,
            &AddingFlourWindow::fillData);

    emit sendFlourName(name);

    this->addingFlourWindow->show();

    this->setEnabled(false);
    this->addingFlourWindow->setEnabled(true);

    QObject::connect(this->addingFlourWindow, &AddingFlourWindow::endClicked,
                     this, &MainWindow::enableWindow);
}
void MainWindow::on_gorButton_clicked()
{
    QString name = "hydrangea";

    this->addingFlourWindow = new AddingFlourWindow(nullptr);

    connect(this, &MainWindow::sendFlourName, addingFlourWindow,
            &AddingFlourWindow::fillData);

    emit sendFlourName(name);

    this->addingFlourWindow->show();

    this->setEnabled(false);
    this->addingFlourWindow->setEnabled(true);

    QObject::connect(this->addingFlourWindow, &AddingFlourWindow::endClicked,
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
