#include "flour.h"

Flour::Flour() = default;

Flour::Flour(int price, QString name, int colour){
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
    if(!(jsonFlour.value("colour") == QJsonValue::Undefined)){
        colour_ = jsonFlour.value("colour").toInt();
    }
}

int Flour::getPrice(){
    return price_;
}

QString Flour::getName(){
    return name_;
}

int Flour::getColour(){
    return colour_;
}

void Flour::setPrice(int price){
    price_ = price;
}

void Flour::setName(QString name){
    name_ = name;
}

void Flour::setColour(int colour){
    colour_ = colour;
}

bool Flour::operator==(Flour flour){
    return getJsonInfo() == flour.getJsonInfo();
}

bool Flour::operator!=(Flour flour){
    return !(getJsonInfo() == flour.getJsonInfo());
}

QJsonObject Flour::getJsonInfo(){
    return QJsonObject({
                           qMakePair(QString("price"), QJsonValue(price_)),
                           qMakePair(QString("name"), name_),
                           qMakePair(QString("colour"), colour_)
                       });
}
