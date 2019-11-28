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
    Bouquet* getBouquetFromDb(QString fileName, int id);
    Flour* getFlourFromDb(QString fileName, int id);
    int* getBouquetsIds(QString fileName);
    int* getFloursIds(QString fileName);
    void addFlourToFile(Flour newFlour, QString fileName);
    void addBouquetToFile(Bouquet newBouqet, QString fileName);
    void editBouquetInDb(Bouquet oldBouquet, Bouquet newBouquet, QString fileName);
    void editFlourInDb(Flour oldFLour, Flour newFLour, QString fileName);
    void deleteBouquetFromDb(Bouquet oddBouquet, QString fileName);
    void deleteFlourFromDb(Flour oddFlour, QString fileName);
    ~DataBase() { }
public:
    static DataBase& getInstance();
};

#endif // DATABASE_H
