#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QMainWindow>

namespace Ui {
class anotherwindow;
}

class anotherwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit anotherwindow(QWidget *parent = nullptr);
    ~anotherwindow();
signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();


    void on_spinBox_valueChanged(const QString &arg1);

private:
    Ui::anotherwindow *ui;
};

#endif // ANOTHERWINDOW_H
