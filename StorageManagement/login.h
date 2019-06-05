#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "user.h"
#include "QString"
#include "dialogstockmanage.h"
#include "dialogviewstock.h"
#include "dialoglackmanage.h"
#include "dialogviewlack.h"
#include "dialogpurchasemanage.h"
#include "dialogcheckpurchase.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);

    ~login();
signals:
    void userLogout();

private slots:
    void onUserLogin(const User &user);

    void on_btn_logout_clicked();

    void on_btn_stockmanage_clicked();

    void on_btn_selstock_clicked();

    void on_btn_need_clicked();

    void on_btn_selneed_clicked();

    void on_btn_outable_clicked();

    void on_btn_incheck_clicked();

private:
    Ui::login *ui;
    DialogStockmanage *dialogstockmanage;
    DialogViewStock *dialogviewStock;
    DialogLackManage *dialoglackmanage;
    DialogViewLack * dialogviewLack;
    DialogPurchaseManage *dialogpurchasemanage;
    DialogCheckPurchase * dialogCheckPurchase;
};

#endif // LOGIN_H
