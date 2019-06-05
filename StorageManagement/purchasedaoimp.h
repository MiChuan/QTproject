#ifndef PURCHASEDAOIMP_H
#define PURCHASEDAOIMP_H
#include "purchasedao.h"
#include <QString>
#include <QSqlQuery>
#include <dbhelper.h>
#include <QSqlError>
#include <QDebug>

class PurchaseDaoImp:public PurchaseDao //注意声明成员Dao
{
public:
    PurchaseDaoImp();

    bool insertPurchase(const Purchase &Purchases);
    bool deletePurchase(const QString &Purchaseid);
    bool updatePurchase(const Purchase &Purchases, const QString & oldid);
    bool purcheckresult(const QString &id,const QString &checkresult);
};

#endif // PURCHASEDAOIMP_H
