#include "finalwindow.h"
#include "ui_finalwindow.h"

FinalWindow::FinalWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FinalWindow)
{
    ui->setupUi(this);
}

FinalWindow::~FinalWindow()
{
    delete ui;
}
