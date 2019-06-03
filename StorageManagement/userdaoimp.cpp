#include "userdaoimp.h"
#include <QDebug>

UserDaoImp::UserDaoImp()
{

}

QString UserDaoImp::selectUserPermission(QString name,QString pwd){
    DBHelper *helper = DBHelper::getInstance();
    QSqlQuery query;
    helper->openDatabase();//链接数据库

    query.prepare("select * from DB_USER;");
    query.exec();

    while(query.next()){
          QString id = query.value("DB_USER_NAME").toString();
          qDebug()<<"name:"<<id;
          if(id == name){
              QString password = query.value("DB_PASSWORD").toString();
              qDebug()<<"password:"<<password;
              if(pwd == password){
                  QString permission = query.value("PERMISSION").toString();
                  qDebug()<<"permission:"<<permission;
                  helper->closeDatabase();
                  return permission;
              }
              helper->closeDatabase();
              return "pwderror";
          }
    }
    helper->closeDatabase();
    return "nouser";
}
