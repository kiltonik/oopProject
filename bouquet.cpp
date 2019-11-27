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


Iterator Bouquet::begin(){
    Iterator *begin = new Iterator(this->head);
    return *begin;
}

Iterator Bouquet::end(){
    Iterator *end(nullptr);
    return *end;
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
        this->add(*itr);
    }
}

void Bouquet::deleteElement(Flour *info){
    Node *cur = this->head;
    while(cur){
        if(cur->info->getInfo() == info->getInfo()){
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

void Bouquet::readBouquetFromFile(const QString& fileName){
    this->clearBouquet();
    QFile file(fileName+".json");
    if (!file.open(QIODevice::ReadOnly)) return;
    QJsonObject temp = QJsonDocument::fromJson(file.readAll()).object();
    for(const auto& i: temp.keys()){
        QJsonObject object = temp.value(i).toObject();
        Flour *thing = new Flour(object.value("price").toInt(), object.value("name").toString(), object.value("colour").toInt());
        this->add(thing);
    }
    file.close();
}

void Bouquet::writeToFile(const QString& fileName){
    QFile file(fileName+".json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return;
    QJsonDocument data;
    int i = 0;
    QJsonObject t;
    for(Iterator itr = Iterator(this->head); itr != this->end(); ++itr){
        t.insert(QString::number(i), (*itr)->getInfo());
        ++i;
    }
    file.write(QJsonDocument(t).toJson(QJsonDocument::Indented));
    file.close();
}

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

void Bouquet::add(Flour* info){
    Node *newNode = new Node;
    newNode->info = info;
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

int Bouquet::len(){
    int len = 0;
    Node *temp;
    temp = head;
    while(temp){
        ++len;
        temp = temp->next;
    }
    return len;
}

bool Bouquet::operator==(Bouquet Bouquet){
    bool flag = true;
    for(Iterator itr = this->begin(), itr2 = Bouquet.begin();itr != Bouquet::end() && itr2 != Bouquet::end(); ++itr, ++itr2){
        if(!(*itr == *itr2)) flag = false;
    }
    return flag;
}

Bouquet::~Bouquet(){
    this->clearBouquet();
    delete head;
    delete tail;
}
