#ifndef GOODS_H
#define GOODS_H
#include<QString>

class Goods
{
public:
    Goods(const QString &goodsId,const QString &goodsName, const QString &goodsStid, const int &goodsNum,const QString &goodsMa);
    QString getGoodsName()const;
    QString getGoodsId()const;
    QString getGoodsStid()const;
    int getGoodsNum()const;
    QString getGoodsMa()const;

private:
    QString goodsName;
    QString goodsId;
    QString goodsStid;
    int goodsNum;
    QString goodsMa;
};

#endif //GOODS_H
