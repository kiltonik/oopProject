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
    Bouquet tempBouquet;
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
    // Возвращает список всех цветов для цветка по имени
    QList<QString> getFlourColors(QString name) const;
    // возвращает цену цветка по имени и цвету
    int getFlourPrice(QString name, QString color) const;
    // Функция возвращает информацию о создаваемом букете
    // в виде двусвязного списка строк
    // Второй список имеет вид [name, color, price]
    QList<QList<QString>> getBouquetInfo() const;
    // Добавляет указанное количество необходимого цветка необходимого цвета
    void addToTemporaryBouquet(QString name, QString color, int number);
    // Очищает букет создаваемый пользователем
    void clearTempBouquet();
    // Удаляет цветок необходимого цвета из создаваемого букета
    // при его отсутсвтвии просто ничего не делает
    void deleteFlourInTempBouquet(QString name, QString color);
    // Сохраняет создаваемый букет в бд
    void saveBouuetToDb() const;
    // Сохраняет создаваемый букет в выбранный файл
    void saveBouquetToFIle(QString fileName) const;
    void setDbFile(QString fileName);
    int getTempBouquetPrice() const;
    QString getFlourPic(QString name, QString color) const;
};

#endif // MAINWINDOWINTERACTOR_H
