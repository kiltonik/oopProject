#include "anotherwindow.h"
#include "ui_anotherwindow.h"

anotherwindow::anotherwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::anotherwindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Р–РµР»С‚С‹Р№");
    ui->comboBox->addItem("РЎРёРЅРёР№");
    ui->comboBox->addItem("РљСЂР°СЃРЅС‹Р№");
    ui->comboBox->addItem("Р‘РµР»С‹Р№");
    ui->comboBox->addItem("Р¤РёРѕР»РµС‚РѕРІС‹Р№");
}

anotherwindow::~anotherwindow()
{
    delete ui;
}
void anotherwindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void anotherwindow::on_spinBox_valueChanged(const QString &arg1)
{
    int x = ui->spinBox->value();
    int y = 10;
    x = x*y;
    ui->label_2->setText(QString::number(x));

}
