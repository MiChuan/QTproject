#ifndef LACK_H
#define LACK_H
#include <QString>


class Lack
{
public:
    Lack(const QString &LackId,const QString &outId, const QString &goodsId, const QString &stid,const QString &Lacktime,const QString &Lacknum);
    QString getLackId()const;
    QString getoutId()const;
    QString getgoodsId()const;
    QString getstid()const;
    QString getLacktime()const;
    QString getLacknum()const;

private:
    QString LackId,outId, goodsId, stid, Lacktime, Lacknum;

};

#endif // LACK_H
