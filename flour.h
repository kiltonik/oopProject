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
    int getPrice() const;
    QString getName() const;
    QString getColor() const;
    void setPrice(int price);
    void setName(QString name);
    void setColour(QString colour);
    bool operator==(Flour flour) const;
    bool operator!=(Flour flour) const;
    QJsonObject getJsonInfo() const;
    QString getPicUrl() const;
};

#endif // FLOUR_H
