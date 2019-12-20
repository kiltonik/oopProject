#ifndef ADDINGFLOURWINDOW_H
#define ADDINGFLOURWINDOW_H

#include "mainwindowinteractor.h"
#include <QWidget>

namespace Ui {
class AddingFlourWindow;
}

class AddingFlourWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddingFlourWindow(QWidget *parent = nullptr);
    ~AddingFlourWindow() override;
    void closeEvent(QCloseEvent *event) override;

signals:
    void endClicked();
private:
    Ui::AddingFlourWindow *ui;
    QString name;
    QString color;
    MainWindowInteractor *interactor;
    void paintEvent(QPaintEvent *event) override;
public slots:
    void fillData(QString flourName);
private slots:
    void on_anotherFlourButton_clicked();
    void on_addButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);
};


#endif // ADDINGFLOURWINDOW_H
