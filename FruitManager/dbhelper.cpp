#include "dbhelper.h"
#include <QDebug>
DBHelper *DBHelper::instance = NULL;

DBHelper::DBHelper()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("dboms");
    db.setUserName("root");
    db.setPassword("123456");
}
void DBHelper::connectDatabase()
{
    qDebug()<<"true";
    bool ret = db.open();
    if(ret){qDebug()<<"open db success";}
    else{qDebug()<<"open db failed";}
}

void DBHelper::disconnectDatabase()
{
    db.close();
    db.removeDatabase("dbmos");
}


//开门
DBHelper *DBHelper::getInstance()
{
    if(instance == NULL)
    {
        instance = new DBHelper();
    }
    return instance;
}
