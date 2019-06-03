#include "user.h"

User::User(const QString &name, const QString &pwd, const QString &permission)
    :name(name),pwd(pwd), permission(permission)
{

}
QString User::getName()const
{
    return name;
}

QString User::getPwd()const
{
    return pwd;
}

QString User::getPermission()const
{
    return permission;
}


