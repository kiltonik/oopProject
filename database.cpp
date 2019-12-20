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
    if(!file.open(QIODevice::ReadOnly)) return nullptr;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    for(const auto& i: t.keys()){
        if (i == id){
            Bouquet *bouquet = new Bouquet(t.value(i).toObject());
            return bouquet;
        }
    }

    return nullptr;
}

Flour* DataBase::getFlourFromDb(QString fileName, int id){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) return nullptr;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    for(const auto& i: t.keys()){
        if (i == QString::number(id)){
            QJsonObject c = t.value(i).toObject();
            Flour *flour = new Flour(t.value(i).toObject());
            return flour;
        }
    }
    return nullptr;
}

QList<int> DataBase::getBouquetsIds(QString fileName){
    QList<int> temp;

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) return temp;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    for(const auto& i: t.keys()){
        temp.append(i.toInt());
    }
    return temp;
}

QList<int> DataBase::getFloursIds(QString fileName){
    QList<int> temp;

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) return temp;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    for(const auto& i: t.keys()){
        temp.append(i.toInt());
    }
    return temp;
}

void DataBase::addBouquetToFile(Bouquet newBouqet, QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) return;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return;

    if (t.keys().isEmpty()) t.insert(QString("0"), newBouqet.getJsonInfo());

    else t.insert(QString::number(t.keys().last().toInt()+1), newBouqet
                  .getJsonInfo());
    file.write(QJsonDocument(t).toJson(QJsonDocument::Indented));
    file.close();
}

void DataBase::addFlourToFile(Flour newFlour, QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) return;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return;

    if (t.keys().isEmpty()) t.insert(QString("0"), newFlour.getJsonInfo());
    else t.insert(QString::number(t.keys().last().toInt()+1), newFlour
                  .getJsonInfo());

    file.write(QJsonDocument(t).toJson(QJsonDocument::Indented));
    file.close();
}

void DataBase::editFlourInDb(Flour oldFLour, Flour newFLour, QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) return;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return;

    for(const auto& i: t.keys()){
        if (t.value(i).toObject() == oldFLour.getJsonInfo()){
            t.remove(i);
            t.insert(i, newFLour.getJsonInfo());
        }
    }

    file.write(QJsonDocument(t).toJson(QJsonDocument::Indented));
    file.close();
}

void DataBase::editBouquetInDb(Bouquet oldBouquet, Bouquet newBouquet,
                               QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) return;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return;

    for(const auto& i: t.keys()){
        if (t.value(i).toObject() == oldBouquet.getJsonInfo()){
            t.remove(i);
            t.insert(i, newBouquet.getJsonInfo());
        }
    }

    file.write(QJsonDocument(t).toJson(QJsonDocument::Indented));
    file.close();
}

void DataBase::deleteFlourFromDb(Flour oddFlour, QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) return;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return;

    for(const auto& i: t.keys()){
        if (t.value(i).toObject() == oddFlour.getJsonInfo()){
            t.remove(i);
        }
    }

    file.write(QJsonDocument(t).toJson(QJsonDocument::Indented));
    file.close();
}

void DataBase::deleteBouquetFromDb(Bouquet oddBouquet, QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) return;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return;

    for(const auto& i: t.keys()){
        if (t.value(i).toObject() == oddBouquet.getJsonInfo()){
            t.remove(i);
        }
    }

    file.write(QJsonDocument(t).toJson(QJsonDocument::Indented));
    file.close();
}
