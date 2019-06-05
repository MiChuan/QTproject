#ifndef DIALOGPURCHASEMANAGE_H
#define DIALOGPURCHASEMANAGE_H

#include <QDialog>
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QHeaderView>
#include <QThread>
#include <QDateTime>
#include <QTimer>

#include "dbhelper.h"
#include "purchasedaoimp.h"
#include "dialogdeletepurchase.h"
#include "dialogselectpurchase.h"
#include "dialogupdatepurchase.h"

namespace Ui {
class DialogPurchaseManage;
}

class DialogPurchaseManage : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPurchaseManage(QWidget *parent = 0);
    void showAllPurchase();
    ~DialogPurchaseManage();

private slots:
    void on_btndel_clicked();

    void on_btnflush_clicked();

    void on_btnupdate_clicked();

    void on_btnadd_clicked();

    void on_btnsel_clicked();

private:
    Ui::DialogPurchaseManage *ui;
    QSqlQueryModel *model;

    DialogDeletePurchase *dialogDeletePurchase;
    DialogSelectPurchase *dialogSelectPurchase;
    DialogUpdatePurchase *dialogUpdatePurchase;
};

#endif // DIALOGPURCHASEMANAGE_H
