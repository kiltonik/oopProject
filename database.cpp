#include "database.h"

#include <QFile>
#include <QJsonDocument>


DataBase * DataBase::p_instance = nullptr;
DataBaseDestroyer DataBase::destroyer;

DataBaseDestroyer::~DataBaseDestroyer() {
    delete p_instance;
}

void DataBaseDestroyer::initialize( DataBase* p ) {
    p_instance = p;
}

DataBase& DataBase::getInstance() {
    if(!p_instance)     {
        p_instance = new DataBase();
        destroyer.initialize( p_instance);
    }
    return *p_instance;
}

Bouquet* DataBase::getBouquetFromDb(QString fileName, int id){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    for(const auto& i: t.keys()){
        if (i == id){
            Bouquet *bouquet = new Bouquet(t.value(i).toObject());
            return bouquet;
        }
    }
    file.close();
    throw 2;
}

Flour* DataBase::getFlourFromDb(QString fileName, int id){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    for(const auto& i: t.keys()){
        if (i == id){
            Flour *flour = new Flour(t.value(i).toObject());
            return flour;
        }
    }
    file.close();
    throw 2;
}

int* DataBase::getBouquetsIds(QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    QVector<int> temp;
    for(const auto& i: t.keys()){
        temp.append(i.toInt());
    }
    if(temp.size() != 0){
        int *arr = new int[size_t(temp.size())];
        for(int i = 0; i < temp.size(); ++i){
            arr[i] = temp[i];
        }
        return arr;
    }
    throw 2;
}

int* DataBase::getFloursIds(QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    QVector<int> temp;
    for(const auto& i: t.keys()){
        temp.append(i.toInt());
    }
    if(temp.size() != 0){
        int *arr = new int[size_t(temp.size())];
        for(int i = 0; i < temp.size(); ++i){
            arr[i] = temp[i];
        }
        return arr;
    }
    throw 2;
}

void DataBase::addBouquetToFile(Bouquet newBouqet, QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) throw 1;
    if (t.keys().isEmpty()) throw 2;
    t.insert(QString::number(t.keys().last().toInt()+1), newBouqet.getJsonInfo());
}

void DataBase::addFlourToFile(Flour newFlour, QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) throw 1;
    if (t.keys().isEmpty()) throw 2;
    t.insert(QString::number(t.keys().last().toInt()+1), newFlour.getJsonInfo());
}
