#ifndef USERDAOIMP_H
#define USERDAOIMP_H
#include "userdao.h"
#include <QSqlQuery>
#include "dbhelper.h"

class UserDaoImp:public UserDao
{
public:
    UserDaoImp();
    QString selectUserPermission(QString name,QString pwd);
};

#endif // USERDAOIMP_H
