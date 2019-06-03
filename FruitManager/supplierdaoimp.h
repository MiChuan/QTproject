#ifndef SUPPLIERDAOIMP_H
#define SUPPLIERDAOIMP_H
#include"supplierdao.h"
#include <QString>
#include <QSqlQuery>
#include <dbhelper.h>
#include <QSqlError>
#include <QDebug>
#include <dbhelper.h>


class SupplierDaoImp:public SupplierDao
{
public:
    SupplierDaoImp();
    QSqlQuery selectSuppliers();
    QSqlQuery selectSupplierByFruitName(QString fruitName);
};

#endif // SUPPLIERDAOIMP_H
