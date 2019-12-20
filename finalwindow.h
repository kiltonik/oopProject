#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QWidget>
#include <qlistwidget.h>
#include "mainwindowinteractor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FinalWindow; }
QT_END_NAMESPACE

class FinalWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FinalWindow(QWidget *parent = nullptr);// как сюда передать список??
    ~FinalWindow() override;
    void closeEvent(QCloseEvent *event) override;
signals:
    void endClicked();

private:
    Ui::FinalWindow *ui;
    MainWindowInteractor* interactor;
private slots:
    void on_changeButton_clicked();
    void on_endButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
};

#endif // FINALWINDOW_H
