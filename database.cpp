#include "database.h"


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

