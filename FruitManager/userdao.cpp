#include "userdao.h"
#include <QDebug>
UserDao::UserDao()
{

}

UserDao::~UserDao()
{
    qDebug()<<"虚析构";
}
