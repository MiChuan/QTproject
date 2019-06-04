#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "user.h"
#include "QString"
#include "dialogstockmanage.h"
#include "dialogviewstock.h"
#include "dialoglackmanage.h"

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

private:
    Ui::login *ui;
    DialogStockmanage *dialogstockmanage;
    DialogViewStock *dialogviewStock;
    DialogLackManage *dialoglackmanage;
};

#endif // LOGIN_H
