#ifndef BOUQUET_H
#define BOUQUET_H

#include "flour.h"
#include <QString>

class Iterator;

class Bouquet
{
    struct Node{
        Flour* info;
        Node *next= nullptr, *prev= nullptr;
    };
public:
    friend class Iterator;
    Node *head, *tail;
    Iterator begin();
    Iterator end();
    Bouquet();
    Bouquet(const Bouquet &Bouquet);
    Bouquet(QJsonObject jsonBouquet);
    void deleteElement(Flour* info);
    QJsonObject getJsonInfo();
//    void readBouquetFromFile(const QString& fileName);
//    void writeToFile(const QString& fileName);
    void clearBouquet();
    void add(Flour* info);
    int len();
    bool operator==(Bouquet bouquet);
    bool operator!=(Bouquet bouquet);
    Bouquet operator+(Bouquet bouquet);
    ~Bouquet();
};
#endif // BOUQUET_H
