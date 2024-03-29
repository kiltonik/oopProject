#include "mainwindowinteractor.h"
#include "database.h"
#include "iterator.h"


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
        p_instance->tempBouquet = Bouquet();
        p_instance->fileName = "DB.json";
        destroyer.initialize( p_instance);
    }
    return *p_instance;
}

QList<QString> MainWindowInteractor::getFlourColors(QString name) const{

    QList<int> ids = this->db.getFloursIds(this->fileName);
    QList<QString> colors;
    for (int t: ids){
        Flour *flour = db.getFlourFromDb(this->fileName, t);
        if (flour != nullptr){
            if (flour->getName() == name) colors.append(flour->getColor());

        }
    }
    return colors;
}

void MainWindowInteractor::addToTemporaryBouquet(QString name,
                                                 QString color, int number){
    QList<int> ids = this->db.getFloursIds(this->fileName);
    for (int t: ids){
        Flour *flour = db.getFlourFromDb(this->fileName, t);
        if (flour != nullptr){
            if (flour->getName() == name && flour->getColor() == color){
                for (int i = 0; i < number; ++i){
                    this->tempBouquet.add(*flour);
                }
            }
        }

    }
}

int MainWindowInteractor::getFlourPrice(QString name, QString color) const{
    QList<int> ids = this->db.getFloursIds(this->fileName);
    for (int t: ids){

        Flour *flour = db.getFlourFromDb(this->fileName, t);
        if(flour != nullptr){
            if (flour->getName() == name && flour->getColor() == color)
                return flour->getPrice();
        }

    }
    return 0;
}

QList<QList<QString>> MainWindowInteractor::getBouquetInfo() const{
    QList<QList<QString>> temp;

    for (Iterator itr = this->tempBouquet.begin();
         itr != this->tempBouquet.end(); ++itr){
        QList<QString> tmp;
        tmp.append({(*itr)->getName(), (*itr)->getColor(),
                    QString::number((*itr)->getPrice())});
        temp.append(tmp);
    }
    return temp;
}

void MainWindowInteractor::clearTempBouquet(){
    this->tempBouquet.clearBouquet();
}

void MainWindowInteractor::deleteFlourInTempBouquet(QString name, QString color){
    QList<int> ids = this->db.getFloursIds(this->fileName);
    for (int t: ids){

        Flour *flour = db.getFlourFromDb(this->fileName, t);
        if (flour != nullptr){
            if (flour->getName() == name && flour->getColor() == color)
                this->tempBouquet.deleteElement(*flour);
        }

    }
}

void MainWindowInteractor::saveBouuetToDb() const{
    db.addBouquetToFile(this->tempBouquet, this->fileName);
}

void MainWindowInteractor::saveBouquetToFIle(QString fileName) const{
    db.addBouquetToFile(this->tempBouquet, fileName);
}

void MainWindowInteractor::setDbFile(QString fileName){
    this->fileName = fileName;
}

int MainWindowInteractor::getTempBouquetPrice() const{
    return this->tempBouquet.price();
}

QString MainWindowInteractor::getFlourPic(QString name, QString color) const{
    QList<int> ids = this->db.getFloursIds(this->fileName);
    QString url;
    for (int t: ids){
        Flour *flour = db.getFlourFromDb(this->fileName, t);
        if (flour != nullptr){
            if (flour->getName() == name && flour->getColor() == color)
                url = flour->getPicUrl();
        }
    }
    return url;
}
