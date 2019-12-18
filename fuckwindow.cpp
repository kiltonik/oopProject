#include "fuckwindow.h"
#include "ui_fuckwindow.h"

FuckWindow::FuckWindow(QWidget *parent,QString name) :
    QMainWindow(parent),
    ui(new Ui::FuckWindow)
{
    ui->setupUi(this);

}

FuckWindow::~FuckWindow()
{
    delete ui;
}
