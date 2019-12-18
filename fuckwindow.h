#ifndef FUCKWINDOW_H
#define FUCKWINDOW_H

#include <QMainWindow>

namespace Ui {
class FuckWindow;
}

class FuckWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FuckWindow(QWidget *parent = nullptr,QString name = "");
    ~FuckWindow();

private:
    Ui::FuckWindow *ui;
};

#endif // FUCKWINDOW_H
