#ifndef FRUITDAOIMP_H
#define FRUITDAOIMP_H
#include "FruitDao.h"
#include <QString>
#include <QSqlQuery>
#include <dbhelper.h>
#include <QSqlError>
#include <QDebug>
#include <dbhelper.h>


class FruitDaoImp:public FruitDao
{
public:
    FruitDaoImp();
    QSqlQuery selectFruits();
    QSqlQuery selectFruitByName(QString fruitName);
    QSqlQuery selectFruitByPrice(double fruitPrice);
    QSqlQuery selectFruitByNum(double fruitNum);

    bool insertFruit(const Fruit &fruit) ;
    bool deleteFruit(const QString &fruitName) ;
    bool updateFruit(const Fruit &fruit, const QString & oldname) ;
};

#endif // FRUITDAOIMP_H
