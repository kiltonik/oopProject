#ifndef FUCKWINDOW_H
#define FUCKWINDOW_H

#include <QMainWindow>
#include "bouquet.h"
#include "mainwindowinteractor.h"

namespace Ui {
class FuckWindow;
}

class FuckWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FuckWindow(QWidget *parent = nullptr,QString name1 = "");
    ~FuckWindow();
    MainWindowInteractor *list;

private:
    Ui::FuckWindow *ui;
    void on_anotherFlourButton_clicked();
    void on_addButton_clicked();
    QString name;

};

#endif // FUCKWINDOW_H
