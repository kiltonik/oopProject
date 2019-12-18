#ifndef MAINWINDOWINTERACTOR_H
#define MAINWINDOWINTERACTOR_H

#include "database.h"


class MainWindowInteractor;

class MainWindowInteractorDestroyer
{
private:
    MainWindowInteractor* p_instance;
public:
    ~MainWindowInteractorDestroyer();
    void initialize( MainWindowInteractor* p );
};

class MainWindowInteractor
{
private:
    QString fileName;
    static MainWindowInteractor* p_instance;
    static MainWindowInteractorDestroyer destroyer;
    DataBase& db;
protected:
    friend class MainWindowInteractorDestroyer;
    MainWindowInteractor(DataBase& db) : db(db) { }
    MainWindowInteractor( const MainWindowInteractor& );
    MainWindowInteractor& operator=( MainWindowInteractor& );
    ~MainWindowInteractor() { }
public:
    static MainWindowInteractor& getInstance();
    QList<QString> getFlourColors(QString name);
};

#endif // MAINWINDOWINTERACTOR_H
