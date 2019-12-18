#include "mainwindowinteractor.h"
#include "database.h"


MainWindowInteractor * MainWindowInteractor::p_instance = nullptr;
MainWindowInteractorDestroyer MainWindowInteractor::destroyer;

MainWindowInteractorDestroyer::~MainWindowInteractorDestroyer() {
    delete p_instance;
}

void MainWindowInteractorDestroyer::initialize( MainWindowInteractor* p ) {
    p_instance = p;
}

MainWindowInteractor& MainWindowInteractor::getInstance() {
    if(!p_instance)     {
        p_instance = new MainWindowInteractor(DataBase::getInstance());
        destroyer.initialize( p_instance);
    }
    return *p_instance;
}

QList<QString> MainWindowInteractor::getFlourColors(QString name){
    QList<int> ids = this->db.getFloursIds(fileName);
    QList<QString> colors;
    for (int t: ids){
        if (db.getFlourFromDb(fileName, t)){

        }
    }
    return colors;
}
