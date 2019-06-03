#ifndef GOODSDAOIMP_H
#define GOODSDAOIMP_H
#include "GoodsDao.h"
#include <QString>
#include <QSqlQuery>
#include <dbhelper.h>
#include <QSqlError>
#include <QDebug>
#include <dbhelper.h>


class GoodsDaoImp:public GoodsDao
{
public:
    GoodsDaoImp();
    QSqlQuery selectGoods();
    QSqlQuery selectGoodsByName(QString GoodsName);
    QSqlQuery selectGoodsById(QString goodsId);
    QSqlQuery selectGoodsByStid(QString goodsStid);
    QSqlQuery selectGoodsByMa(QString goodsMa);
    QSqlQuery selectGoodsByNum(int goodsNum);


    bool insertGoods(const Goods &goods) ;
    bool deleteGoods(const QString &goodsId) ;
    bool updateGoods(const Goods &goods, const QString & oldid) ;
};

#endif // GOODSDAOIMP_H
