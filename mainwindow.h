#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "finalwindow.h"
#include "fuckwindow.h"
#include "mainwindowinteractor.h"
#include <QIcon>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_roseButton_clicked();
    void on_lilButton_clicked();
    void on_orchButton_clicked();
    void on_zhasButton_clicked();
    void on_chrizButton_clicked();
    void on_gorButton_clicked();
    void on_bouquetButton_clicked();
    void on_dataBaseButton_clicked();

public slots:
    void enableWindow();

private:
    FuckWindow *fuckWindow;
    FinalWindow *finalWindow;
    MainWindowInteractor* interactor;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

