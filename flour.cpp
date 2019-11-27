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
    return getInfo() == flour.getInfo();
}

bool Flour::operator!=(Flour flour){
    return !(getInfo() == flour.getInfo());
}

QJsonObject Flour::getInfo(){
    return QJsonObject({
                           qMakePair(QString("price"), QJsonValue(price_)),
                           qMakePair(QString("name"), name_),
                           qMakePair(QString("colour"), colour_)
                       });
}
