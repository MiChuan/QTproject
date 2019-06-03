#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include "userdaoimp.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QLineEdit>
#include <QIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    WidgetLogin = new login();
    WidgetLogin->hide();
    QObject::connect(this,SIGNAL(userLogin(const User &)),WidgetLogin,SLOT(onUserLogin(const User &)));
    QObject::connect(WidgetLogin,SIGNAL(userLogout()),this,SLOT(onUserLogout()));
    ui->user_pwd->setEchoMode(QLineEdit::Password);
    this->setWindowTitle("水果订单管理系统");

//    border-image:url(:/myImages/images/fruit_icon.png)
//    this->setObjectName("dialog");    //这句话一定要有，不然，整个界面上的控件背景都跟界面背景一样
//    #MainWindow {border-image:url(:/myImages/images/fruit_icon.png);}
//    this->setStyleSheet("QDialog#dialog{border-image:url(:/myImages/images/fruit_icon.png)}");
    QIcon icon(":/myImages/images/logo.ico");
    this->setWindowIcon(icon);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    if(ui->user_name->text().isEmpty()){
        QMessageBox::critical(this,"警告","用户名不允许为空");
        return;
    }
    if(ui->user_pwd->text().isEmpty()){
        QMessageBox::critical(this,"警告","密码不允许为空");
        return;
    }
    QString name = ui->user_name->text();
    QString pwd = ui->user_pwd->text();

    UserDao *ud = new UserDaoImp();
    QSqlQuery query = ud->selectUserByName(name);

    int size = query.size();
    if(size == 0){
       QMessageBox::critical(this,"警告","用户不存在");
       return;
    }
    QSqlRecord rec = query.record();
    QString password;
    QString permission;
    while(query.next()){
         password = query.value(2).toString();
         permission = query.value(3).toString();
         qDebug() << query.value(2).toString() << query.value(3).toString();
    }
    if(password != pwd){
        qDebug() << password << "|" << pwd;
        QMessageBox::critical(this,"警告","密码错误");
        return;
    }
    User user(name, password, permission);
//    User user("admin", "admin", "admin");
    emit userLogin(user);
    WidgetLogin->show();
    this->hide();
    //    QString permission = ;

    //    User user(name, pwd, permission);
}

void MainWindow::onUserLogout(){
    WidgetLogin->hide();
    this->show();
}
