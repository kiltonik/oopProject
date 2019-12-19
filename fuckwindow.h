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
    MainWindowInteractor *interactor;
signals:
    void endClicked();
private:
    Ui::FuckWindow *ui;
    QString name;
private slots:
    void on_anotherFlourButton_clicked();
    void on_addButton_clicked();

};

#endif // FUCKWINDOW_H
