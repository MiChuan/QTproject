#ifndef USERDAO_H
#define USERDAO_H
#include "user.h"
#include <vector>
#include <QSqlQuery>

using namespace std;

class UserDao
{
public:
    UserDao();
    virtual QString selectUserPermission(QString name,QString pwd) = 0;

    virtual ~UserDao();
};

#endif // USERDAO_H
