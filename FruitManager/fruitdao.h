#ifndef FRUITDAO_H
#define FRUITDAO_H
#include "Fruit.h"
#include <vector>
#include <QString>
#include <QSqlQuery>
using namespace std;

class FruitDao
{
public:
    FruitDao();
    virtual QSqlQuery selectFruits() = 0;
    virtual QSqlQuery selectFruitByName(QString fruitName) = 0;
    virtual QSqlQuery selectFruitByPrice(double fruitPrice) = 0;
    virtual QSqlQuery selectFruitByNum(double fruitNum) = 0;

    virtual bool insertFruit(const Fruit &fruit) = 0;
    virtual bool deleteFruit(const QString &name) = 0;
    virtual bool updateFruit(const Fruit &fruit, const QString & oldname) = 0;
    virtual ~FruitDao();
};

#endif // FRUITDAO_H
