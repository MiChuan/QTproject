#ifndef USERDAOIMP_H
#define USERDAOIMP_H
#include "userdao.h"
#include <QSqlQuery>
#include "dbhelper.h"

class UserDaoImp:public UserDao
{
public:
    UserDaoImp();
    QSqlQuery selectUserByName(QString name);
};

#endif // USERDAOIMP_H
