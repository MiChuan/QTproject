#ifndef GOODSDAO_H
#define GOODSDAO_H
#include "Goods.h"
#include <vector>
#include <QString>
#include <QSqlQuery>
using namespace std;

class GoodsDao
{
public:
    GoodsDao();

    virtual bool insertGoods(const Goods &goods) = 0;
    virtual bool deleteGoods(const QString &name) = 0;
    virtual bool updateGoods(const Goods &goods, const QString & oldname) = 0;
    virtual ~GoodsDao();
};

#endif // GOODSDAO_H
