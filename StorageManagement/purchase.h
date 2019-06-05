#ifndef PURCHASE_H
#define PURCHASE_H
#include <QString>

class Purchase
{
public:
    Purchase(const QString &PId, const QString &GoodsId, const QString &Stid, const QString &GoodsName, const QString &PNum, const QString &PTime, const QString &PMa, const QString &Check);
    QString getPId()const;
    QString getGoodsId()const;
    QString getStid()const;
    QString getGoodsName()const;
    QString getPNum()const;
    QString getPTime()const;
    QString getPMa()const;
    QString getCheck()const;

private:
    QString PId,GoodsId,Stid, GoodsName,PNum, PTime, PMa, Check;
};

#endif // PURCHASE_H
