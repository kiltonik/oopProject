#ifndef FLOUR_H
#define FLOUR_H

#include <QString>
#include <QJsonObject>


class Flour
{
private:
    int price_;
    QString name_;
    int colour_;
public:
    Flour();
    Flour(int price, QString name, int colour);
    Flour(const Flour &flour);
    Flour(QJsonObject jsonFlour);
    int getPrice();
    QString getName();
    int getColour();
    void setPrice(int price);
    void setName(QString name);
    void setColour(int colour);
    bool operator==(Flour flour);
    bool operator!=(Flour flour);
    QJsonObject getJsonInfo();
};

#endif // FLOUR_H
