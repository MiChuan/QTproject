#ifndef LACKDAO_H
#define LACKDAO_H
#include "lack.h"
#include <vector>
#include <QString>
#include <QSqlQuery>
using namespace std;

class LackDao
{
public:
    LackDao();

    virtual bool insertLack(const Lack &lacks) = 0;
    virtual bool deleteLack(const QString &lackid) = 0;
    virtual bool updateLack(const Lack &lacks, const QString & oldid) = 0;
    virtual ~LackDao();
};

#endif // LACKDAO_H
