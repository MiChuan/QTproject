#ifndef PURCHASEDAO_H
#define PURCHASEDAO_H
#include "purchase.h"
#include <vector>
#include <QString>
#include <QSqlQuery>
using namespace std;

class PurchaseDao
{
public:
    PurchaseDao();

    virtual bool insertPurchase(const Purchase &Purchases) = 0;
    virtual bool deletePurchase(const QString &Purchaseid) = 0;
    virtual bool updatePurchase(const Purchase &Purchases, const QString & oldid) = 0;
    virtual bool purcheckresult(const QString &id,const QString &checkresult) = 0;
    virtual ~PurchaseDao();
};

#endif // PURCHASEDAO_H
