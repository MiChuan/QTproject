#ifndef DBHELPER_H
#define DBHELPER_H
#include <QSqlDatabase>

class DBHelper
{
public:
    static DBHelper *getInstance();
    bool openDatabase();
    bool closeDatabase();
 //   bool selectDatabase();
private:
    static DBHelper *instance;
    DBHelper();
    QSqlDatabase db;
};
#endif // DBHELPER_H
