#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QWidget>
#include "mainwindowinteractor.h"

namespace Ui {
class FinalWindow;
}

class FinalWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FinalWindow(QWidget *parent = nullptr);// как сюда передать список??
    ~FinalWindow();
signals:
    void endClicked();

private:
    Ui::FinalWindow *ui;
    MainWindowInteractor* interactor;
private slots:
    void on_changeButton_clicked();
    void on_endButton_clicked();

};

#endif // FINALWINDOW_H
