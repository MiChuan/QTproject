#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "user.h"
#include "QString"
#include "dialogwarehouse.h"
#include "dialoglack.h"
#include "dialogsale.h"
#include "dialogsupplier.h"
#include "dialogpurchase.h"
#include "dialogpurchaseorder.h"

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

    void on_btn_entrepot_clicked();

    void on_btn_need_clicked();

    void on_pushButton_clicked();

    void on_btn_supplier_clicked();

    void on_btn_purchase_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::login *ui;
    DialogWarehouse *dialogWarehouse;
    DialogSale *dialogSale;
    DialogLack *dialogLack;
    DialogSupplier *dialogSupplier;
//    DialogPurchase *dialogPurchase;
    DialogPurchaseOrder * dialogPurchaseOrder;
};

#endif // LOGIN_H
