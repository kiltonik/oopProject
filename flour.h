#ifndef FLOUR_H
#define FLOUR_H

#include <QString>
#include <QJsonObject>


class Flour
{
private:
    int price_;
    QString name_;
    QString colour_;
public:
    Flour();
    Flour(int price, QString name, QString colour);
    Flour(const Flour &flour);
    Flour(QJsonObject jsonFlour);
    int getPrice();
    QString getName();
    QString getColour();
    void setPrice(int price);
    void setName(QString name);
    void setColour(QString colour);
    bool operator==(Flour flour);
    bool operator!=(Flour flour);
    QJsonObject getJsonInfo();
};

#endif // FLOUR_H
