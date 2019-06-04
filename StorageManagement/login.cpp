#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QIcon>
#include "mainwindow.h"
#include "dialogstockmanage.h"
#include "dialogviewstock.h"
#include "dialoglackmanage.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("主界面");
    QIcon icon(":/pictures/images/warehouselogo.ico");
    this->setWindowIcon(icon);

    dialogstockmanage = new DialogStockmanage(this);

    dialogstockmanage->setWindowModality(Qt::ApplicationModal);

    dialogviewStock = new DialogViewStock(this);

    dialogviewStock->setWindowModality(Qt::ApplicationModal);

    dialoglackmanage = new DialogLackManage(this);

    dialoglackmanage->setWindowModality(Qt::ApplicationModal);
}

login::~login()
{
    delete ui;
}
void login::onUserLogin(const User &user){
    qDebug()<<user.getName();
    QString uname = user.getName();
    if(uname == "2019060001") uname = "销售";
    else if(uname == "2019060002") uname = "采购";
    else if(uname == "2019060003") uname = "审核";
    else if(uname == "2019060004") uname = "管理";
    ui->le_username->setText(uname);
    QString permission = user.getPermission();
    if(permission == "Xiao"){
        ui->btn_selstock->show();
        ui->btn_intable->hide();
        ui->btn_incheck->hide();
        ui->btn_selneed->show();
        ui->btn_outable->show();
        ui->btn_outcheck->hide();
        ui->btn_stockmanage->hide();
        ui->btn_need->hide();
    }
    if(permission == "CaiG"){
        ui->btn_selstock->show();
        ui->btn_intable->show();
        ui->btn_incheck->hide();
        ui->btn_selneed->show();
        ui->btn_outable->hide();
        ui->btn_outcheck->hide();
        ui->btn_stockmanage->hide();
        ui->btn_need->hide();
    }
    if(permission == "Shen"){
        ui->btn_selstock->show();
        ui->btn_intable->hide();
        ui->btn_incheck->show();
        ui->btn_selneed->show();
        ui->btn_outable->hide();
        ui->btn_outcheck->show();
        ui->btn_stockmanage->hide();
        ui->btn_need->hide();
    }
    if(permission == "Guan"){
        ui->btn_selstock->hide();
        ui->btn_intable->hide();
        ui->btn_outable->hide();
        ui->btn_selneed->hide();
        ui->btn_stockmanage->show();
        ui->btn_incheck->hide();
        ui->btn_outcheck->hide();
        ui->btn_need->show();
    }
}

void login::on_btn_logout_clicked()
{
    emit userLogout();
}

void login::on_btn_stockmanage_clicked()
{
    dialogstockmanage->show();
}

void login::on_btn_selstock_clicked()
{
    dialogviewStock->show();
}

void login::on_btn_need_clicked()
{
    dialoglackmanage->show();
}
