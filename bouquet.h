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
private:
    Node *head, *tail;
public:
    friend class Iterator;
    Iterator begin() const;
    Iterator end() const;
    Bouquet();
    Bouquet(const Bouquet &Bouquet);
    Bouquet(QJsonObject jsonBouquet);
    void deleteElement(Flour& info);
    QJsonObject getJsonInfo() const;
    void clearBouquet();
    void add(Flour& info);
    int len() const;
    int price() const;
    bool operator==(Bouquet bouquet) const;
    bool operator!=(Bouquet bouquet) const;
    Bouquet operator+(Bouquet bouquet);
    ~Bouquet();
};
#endif // BOUQUET_H
