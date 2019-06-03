#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QLineEdit>
#include <QIcon>
#include "userdaoimp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("仓储管理系统");
    QIcon icon(":/pictures/images/warehouselogo.ico");
    this->setWindowIcon(icon);
    WidgetLogin = new login();
    WidgetLogin->hide();
    QObject::connect(this,SIGNAL(userLogin(const User &)),WidgetLogin,SLOT(onUserLogin(const User &)));
    QObject::connect(WidgetLogin,SIGNAL(userLogout()),this,SLOT(onUserLogout()));
    ui->user_pwd->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*登录*/
void MainWindow::on_login_clicked()
{
    /*用户名密码不为空*/
    if(ui->user_name->text().isEmpty()){
        QMessageBox::critical(this,"警告","请输入用户名后再登录");
        return;
    }
    if(ui->user_pwd->text().isEmpty()){
        QMessageBox::critical(this,"警告","请输入密码后再登录");
        return;
    }
    QString name = ui->user_name->text();
    QString pwd = ui->user_pwd->text();

    /*用户存在*/
    UserDao *ud = new UserDaoImp();
    QString permission = ud->selectUserPermission(name,pwd);
    if(permission == "nouser"){
        QMessageBox::critical(this,"警告","用户不存在");
        return;
    }

    /*检查密码*/
    if(permission == "pwderror"){
         QMessageBox::critical(this,"警告","密码错误");
         return;
    }

    if(permission != "pwderror" && permission != "nouser"){
        User user(name, pwd, permission);
        emit userLogin(user);
        WidgetLogin->show();
        this->hide();
    }
}

void MainWindow::onUserLogout(){
    WidgetLogin->hide();
    this->show();
}
