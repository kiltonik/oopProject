#include "bouquet.h"
#include <cassert>
#include "flour.h"
#include <fstream>
#include <iostream>
#include <io.h>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include "iterator.h"


Iterator Bouquet::begin() const{
    return Iterator(this->head);
}

Iterator Bouquet::end() const{
    return Iterator(nullptr);
}
Bouquet::Bouquet()
{
    this->head = nullptr;
    this->tail = nullptr;
}

Bouquet::Bouquet(const Bouquet &Bouquet){
    Iterator itr = Iterator(Bouquet.head);
    this->head = nullptr;
    this->tail = nullptr;
    for(; itr != Bouquet::end(); ++itr){
        this->add(*(*itr));
    }
}

Bouquet::Bouquet(QJsonObject jsonBouquet){
    for(const auto& i: jsonBouquet.keys()){
        QJsonObject object = jsonBouquet.value(i).toObject();
        Flour *thing = new Flour(object);
        this->add(*thing);
    }
}

void Bouquet::deleteElement(Flour& info){
    Node *cur = this->head;
    while(cur){
        if(cur->info->getJsonInfo() == info.getJsonInfo()){
            if(cur == this->head){
                if (this->head == this->tail){
                    delete cur;
                    this->head = nullptr;
                    this->tail = nullptr;
                    return;
                }
                else{
                    cur->next->prev = nullptr;
                    head = cur->next;
                    delete cur;
                    return;
                }
            }
            else{
                if (cur == this->tail){
                    tail = cur->prev;
                    tail->next = nullptr;
                    delete cur;
                    return;
                }
                else{
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    delete cur;
                    return;
                }
            }
        }
        cur = cur->next;
    }
}

QJsonObject Bouquet::getJsonInfo() const{
    QJsonObject data;
    int i = 0;
    for(Iterator itr = Iterator(this->head); itr != this->end(); ++itr){
        data.insert(QString::number(i), (*itr)->getJsonInfo());
        ++i;
    }
    return data;
}

//void Bouquet::readBouquetFromFile(const QString& fileName){
//    this->clearBouquet();
//    QFile file(fileName+".json");
//    if (!file.open(QIODevice::ReadOnly)) return;
//    QJsonObject temp = QJsonDocument::fromJson(file.readAll()).object();
//    for(const auto& i: temp.keys()){
//        QJsonObject object = temp.value(i).toObject();
//        Flour *thing = new Flour(object.value("price").toInt(), object.value("name").toString(), object.value("colour").toInt());
//        this->add(thing);
//    }
//    file.close();
//}

//void Bouquet::writeToFile(const QString& fileName){
//    QFile file(fileName+".json");
//    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return;
//    QJsonDocument data;
//    int i = 0;
//    QJsonObject t;
//    for(Iterator itr = Iterator(this->head); itr != this->end(); ++itr){
//        t.insert(QString::number(i), (*itr)->getInfo());
//        ++i;
//    }
//    file.write(QJsonDocument(t).toJson(QJsonDocument::Indented));
//    file.close();
//}

void Bouquet::clearBouquet(){
    Node *cur = head;
    while(cur){
        Node *next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
    tail = nullptr;
}

void Bouquet::add(Flour& info){
    Node *newNode = new Node;
    newNode->info = &info;
    if(!head){
        newNode->prev = nullptr;
        head = tail = newNode;
    }
    else{
        Node *temp = tail;
        temp = tail;
        tail = newNode;
        temp->next = tail;
        tail->prev = temp;
    }

}

int Bouquet::len() const{
    int len = 0;
    Node *temp;
    temp = head;
    while(temp){
        ++len;
        temp = temp->next;
    }
    return len;
}

bool Bouquet::operator==(Bouquet bouquet) const{
    return this->getJsonInfo() == bouquet.getJsonInfo();
}

bool Bouquet::operator!=(Bouquet bouquet) const{
    return this->getJsonInfo() != bouquet.getJsonInfo();
}

Bouquet Bouquet::operator+(Bouquet bouquet){
    for(Iterator itr = Iterator(bouquet.head); itr != bouquet.tail; ++itr){
        this->add(*(*itr));
    }
    return *this;
}

Bouquet::~Bouquet(){
    this->clearBouquet();
    delete head;
    delete tail;
}
