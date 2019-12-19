#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QMainWindow>
#include "mainwindowinteractor.h"

namespace Ui {
class FinalWindow;
}

class FinalWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FinalWindow(QWidget *parent = nullptr);// как сюда передать список??
    ~FinalWindow();

private:
    Ui::FinalWindow *ui;
    void on_changeButton_clicked();
    void on_endButton_clicked();
};

#endif // FINALWINDOW_H
