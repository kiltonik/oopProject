#ifndef DATABASE_H
#define DATABASE_H

#include "bouquet.h"
#include "flour.h"
#include <QVector>


class DataBase;

class DataBaseDestroyer
{
private:
    DataBase* p_instance;
public:
    ~DataBaseDestroyer();
    void initialize( DataBase* p );
};

class DataBase
{
private:
    static DataBase* p_instance;
    static DataBaseDestroyer destroyer;
protected:
    friend class DataBaseDestroyer;
    DataBase() { }
    DataBase( const DataBase& );
    DataBase& operator=( DataBase& );
    QVector<Bouquet> getBouquetsFromDb(QString fileName);
    QVector<Flour> getFloursFromDb(QString fileName);
    bool addFlourToFile(Flour newFlour);
    bool addBouquetToFile(Bouquet newBouqet);
    bool editBouquetInDb(Bouquet oldBouquet, Bouquet newBouquet);
    bool editFlourInDb(Flour oldFLour, Flour newFLour);
    bool deleteBouquetFromDb(Bouquet oddBouquet);
    bool deleteFlourFromDb(Flour oddFlour);
    ~DataBase() { }
public:
    static DataBase& getInstance();
};

#endif // DATABASE_H
