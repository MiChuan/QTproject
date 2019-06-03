#ifndef SUPPLIERDAO_H
#define SUPPLIERDAO_H
#include "supplier.h"
#include <vector>
#include <QString>
#include <QSqlQuery>
using namespace std;

class SupplierDao
{
public:
    SupplierDao();
    virtual QSqlQuery selectSuppliers() = 0;
    virtual QSqlQuery selectSupplierByFruitName(QString fruitName) = 0;
//    virtual QSqlQuery selectFruitByPrice(double fruitPrice) = 0;
//    virtual QSqlQuery selectFruitByNum(double fruitNum) = 0;

//    virtual bool insertFruit(const Fruit &fruit) = 0;
//    virtual bool deleteFruit(const QString &name) = 0;
//    virtual bool updateFruit(const Fruit &fruit, const QString & oldname) = 0;
    virtual ~SupplierDao();
};

#endif // SUPPLIERDAO_H
