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
    file.close();

    for(const auto& i: t.keys()){
        if (i == id){
            Bouquet *bouquet = new Bouquet(t.value(i).toObject());
            return bouquet;
        }
    }

    file.close();
    throw 1;
}

Flour* DataBase::getFlourFromDb(QString fileName, int id){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    for(const auto& i: t.keys()){
        if (i == id){
            Flour *flour = new Flour(t.value(i).toObject());
            return flour;
        }
    }

    throw 2;
}

QList<int> DataBase::getBouquetsIds(QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    QList<int> temp;
    for(const auto& i: t.keys()){
        temp.append(i.toInt());
    }
    return temp;
}

QList<int> DataBase::getFloursIds(QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    QList<int> temp;
    for(const auto& i: t.keys()){
        temp.append(i.toInt());
    }
    return temp;
}

void DataBase::addBouquetToFile(Bouquet newBouqet, QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) throw 1;

    if (t.keys().isEmpty()) t.insert(QString("0"), newBouqet.getJsonInfo());

    else t.insert(QString::number(t.keys().last().toInt()+1), newBouqet
                  .getJsonInfo());
    file.write(QJsonDocument(t).toJson(QJsonDocument::Indented));
    file.close();
}

void DataBase::addFlourToFile(Flour newFlour, QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) throw 1;

    if (t.keys().isEmpty()) t.insert(QString("0"), newFlour.getJsonInfo());
    else t.insert(QString::number(t.keys().last().toInt()+1), newFlour
                  .getJsonInfo());

    file.write(QJsonDocument(t).toJson(QJsonDocument::Indented));
    file.close();
}

void DataBase::editFlourInDb(Flour oldFLour, Flour newFLour, QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) throw 1;

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
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) throw 1;

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
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) throw 1;

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
    if(!file.open(QIODevice::ReadOnly)) throw 1;
    QJsonObject t = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) throw 1;

    for(const auto& i: t.keys()){
        if (t.value(i).toObject() == oddBouquet.getJsonInfo()){
            t.remove(i);
        }
    }

    file.write(QJsonDocument(t).toJson(QJsonDocument::Indented));
    file.close();
}

QString DataBase::getDbFIleName(){
    QFile file(QString("settings.txt"));
    if(!file.open(QIODevice::ReadOnly)) throw 1;

}
