#include "userdaoimp.h"
#include <QDebug>

UserDaoImp::UserDaoImp()
{

}

QSqlQuery UserDaoImp::selectUserByName( QString name)
{
    DBHelper *helper = DBHelper::getInstance();
    QSqlQuery query;
    helper->connectDatabase();//链接数据库


    query.prepare("select * from om_user where username = :name;");
    query.bindValue(":name",name);

    query.exec();

    helper->disconnectDatabase();
    return query;
}
