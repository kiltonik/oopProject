#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QMainWindow>

namespace Ui {
class FinalWindow;
}

class FinalWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FinalWindow(QWidget *parent = nullptr);
    ~FinalWindow();

private:
    Ui::FinalWindow *ui;
};

#endif // FINALWINDOW_H
