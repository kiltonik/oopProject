#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fuckwindow.h"
#include "finalwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    FuckWindow *window = new FuckWindow(this,name);
    window->show();
    this->setEnabled(false);
    window->setEnabled(true);


}

void MainWindow::on_lilButton_clicked()
{
    QString name = "Lilia";
    FuckWindow *window = new FuckWindow(this,name);
    window->show();
    this->setEnabled(false);
    window->setEnabled(true);
}
void MainWindow::on_orchButton_clicked()
{
    QString name = "Orchideya";
    FuckWindow *window = new FuckWindow(this, name);
    window->show();
    this->setEnabled(false);
    window->setEnabled(true);
}
void MainWindow::on_zhasButton_clicked()
{
    QString name = "Zhasmin";
    FuckWindow *window = new FuckWindow(this, name);
    window->show();
    this->setEnabled(false);
    window->setEnabled(true);
}
void MainWindow::on_chrizButton_clicked()
{
    QString name = "Chrizantema";
    FuckWindow *window = new FuckWindow(this, name);
    window->show();
    this->setEnabled(false);
    window->setEnabled(true);
}
void MainWindow::on_gorButton_clicked()
{
    QString name = "Gortensiya";
    FuckWindow *window = new FuckWindow(this, name);
    window->show();
    this->setEnabled(false);
    window->setEnabled(true);
}
void MainWindow::on_bouquetButton_clicked()
{
    FinalWindow *window = new FinalWindow(this);
    this->setEnabled(false);
    window->setEnabled(true);
}
