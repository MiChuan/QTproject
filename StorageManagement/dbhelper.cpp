#include "dbhelper.h"
#include <QDebug>
#include <QApplication>
DBHelper *DBHelper::instance = NULL;

DBHelper::DBHelper()
{
    db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    QString dsn = QString::fromLocal8Bit("QTDSN");      //数据源名称
    db.setHostName("localhost");                        //选择本地主机，127.0.1.1
    db.setDatabaseName(dsn);                            //设置数据源名称
    db.setUserName("sa");                               //登录用户
    db.setPassword("512013");                              //密码
}

bool DBHelper:: openDatabase()
{
   if(!db.open())                                      //打开数据库
    {
        qDebug()<<"database open fail!";
        return false;                                   //打开失败
    }
    else
    {
        qDebug()<<"database open success!";
    }return true;
}

bool DBHelper:: closeDatabase(){
    db.close();
    db.removeDatabase("QTDSN");

    qDebug()<<"database close success!\n";
    return true;
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
