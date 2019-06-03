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
    virtual QSqlQuery selectGoods() = 0;
    virtual QSqlQuery selectGoodsById(QString goodsId) = 0;
    virtual QSqlQuery selectGoodsByName(QString goodsName) = 0;
    virtual QSqlQuery selectGoodsByStid(QString goodsStid) = 0;
    virtual QSqlQuery selectGoodsByMa(QString goodsMa) = 0;
    virtual QSqlQuery selectGoodsByNum(int goodsNum) = 0;

    virtual bool insertGoods(const Goods &goods) = 0;
    virtual bool deleteGoods(const QString &name) = 0;
    virtual bool updateGoods(const Goods &goods, const QString & oldname) = 0;
    virtual ~GoodsDao();
};

#endif // GOODSDAO_H
