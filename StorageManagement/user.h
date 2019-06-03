#ifndef USER_H
#define USER_H

#include <QString>
class User
{
public:
    User(const QString &name,const QString &pwd,const QString &permission);
    QString getName()const;
    QString getPwd()const;
    QString getPermission()const;

private:
    QString name;
    QString pwd;
    QString permission;
};

#endif // USER_H
