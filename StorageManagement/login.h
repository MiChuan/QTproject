#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "user.h"
#include "QString"
#include "dialogstockmanage.h"

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

private:
    Ui::login *ui;
    DialogStockmanage *dialogstockmanage;

};

#endif // LOGIN_H
