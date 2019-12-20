#include "flour.h"

Flour::Flour() = default;

Flour::Flour(int price, QString name, QString colour){
    price_ = price;
    name_ = name;
    colour_ = colour;
}

Flour::Flour(const Flour &flour){
    price_ = flour.price_;
    name_ = flour.name_;
    colour_ = flour.colour_;
    
}

Flour::Flour(QJsonObject jsonFlour):Flour(){
    if(!(jsonFlour.value("price") == QJsonValue::Undefined)){
        price_ = jsonFlour.value("price").toInt();
    }
    if(!(jsonFlour.value("name") == QJsonValue::Undefined)){
        name_ = jsonFlour.value("name").toString();
    }
    if(!(jsonFlour.value("color") == QJsonValue::Undefined)){
        colour_ = jsonFlour.value("color").toString();
    }
}

int Flour::getPrice() const{
    return price_;
}

QString Flour::getName() const{
    return name_;
}

QString Flour::getColor() const{
    return colour_;
}

void Flour::setPrice(int price){
    price_ = price;
}

void Flour::setName(QString name){
    name_ = name;
}

void Flour::setColour(QString colour){
    colour_ = colour;
}

bool Flour::operator==(Flour flour) const{
    return getJsonInfo() == flour.getJsonInfo();
}

bool Flour::operator!=(Flour flour) const{
    return !(getJsonInfo() == flour.getJsonInfo());
}

QJsonObject Flour::getJsonInfo() const{
    return QJsonObject({
                           qMakePair(QString("price"), QJsonValue(price_)),
                           qMakePair(QString("name"), name_),
                           qMakePair(QString("colour"), colour_)
                       });
}

QString Flour::getPicUrl() const{
    return QString("pictures\\") + this->getName()
            + QString("_") + this->getColor() + QString(".jpg");
}
