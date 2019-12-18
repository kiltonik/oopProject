#ifndef ITERATOR_H
#define ITERATOR_H
#include "bouquet.h"


class Iterator
{
private:
    Bouquet::Node *nodeptr;
public:
    friend class Bouquet;

    Iterator(Bouquet::Node *ptr);
    const Iterator operator++();
    const Iterator operator--();
    Flour* &operator *();
    bool operator==(const Iterator& ptr);
    bool operator!=(const Iterator& ptr);
    Iterator();
};


#endif // ITERATOR_H
