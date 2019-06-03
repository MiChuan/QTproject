#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbhelper.h"
#include <QSqlRecord>

DBHelper *helper = DBHelper::getInstance();
QSqlQuery query;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    showAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAll(){
    qDebug()<<"select\n";//debug

    QString item = ui->line_id->text();

    int ret = query.exec(QString("SELECT * FROM test;"));

    qDebug()<<ret;
             if(ret){
                qDebug()<<"readsuccessfully";
                QSqlRecord rec = query.record();
                while(query.next()){
                      rec = query.record();
                      QString id = query.value("TID").toString();
                      qDebug()<<"id:"<<id;
                      QString name = query.value("TNAME").toString();
                      qDebug()<<"name:"<<name;
                      int tint = query.value("TINT").toInt();
                      qDebug()<<"tint:"<<tint;
                }
             }

    model->setQuery("select TID as '编号',"
                    "TNAME as '名称',"
                    "TINT as '数量' from test;");
    ui->tableView->setModel(model);
    qDebug()<<"select return\n"<<endl;//debug
}

void MainWindow::on_btnCnt_clicked()
{
    qDebug()<<"open\n";//debug
    helper->openDatabase();//链接数据库
    qDebug()<<"open return\n"<<endl;//debug
}

void MainWindow::on_btnDcnt_clicked()
{
    qDebug()<<"close\n";//debug

    helper->closeDatabase();//断开连接

    qDebug()<<"close return\n"<<endl;//debug
}

void MainWindow::on_btnAdd_clicked()
{
    qDebug()<<"add\n";//debug

    QString item1 = ui->line_id->text();
    QString item2 = ui->line_name->text();
    QString item3 = ui->line_int->text();

    qDebug()<<"id:"<<item1;
    qDebug()<<"name:"<<item2;
    qDebug()<<"tint:"<<item3;
//    QString item1 = "10376";
//    QString item2 = "测试6";
//    QString item3 = "4";//绑定字符为char，无需转义为int
    int ret = query.exec(QString("INSERT INTO test(TID ,TNAME ,TINT) VALUES('%1','%2',%3);").arg(item1,item2,item3));//绑定方式1

//    query.prepare("INSERT INTO test(TID ,TNAME ,TINT) VALUES(':item1',':item2',:item3);");//绑定方式2
//    query.bindValue(":item1",item1);
//    query.bindValue(":item2",item2);
//    query.bindValue(":item3",item3);
//    int ret = query.exec();

    qDebug()<<ret;
             if(ret){
                qDebug()<<"add successfully";
                while(query.next()){

                      qDebug()<<"id:"<<item1;

                      qDebug()<<"name:"<<item2;

                      qDebug()<<"tint:"<<item3;
                }
             }

    qDebug()<<"add return\n"<<endl;//debug
}

void MainWindow::on_btnDel_clicked()
{
    qDebug()<<"DELETE\n";//debug

    QString item1 = ui->line_id->text();

    qDebug()<<"id:"<<item1;

    int ret = query.exec(QString("DELETE FROM test WHERE TID = '%1'").arg(item1));//绑定方式1


    qDebug()<<ret;
             if(ret){
                qDebug()<<"DELETE successfully";
             }

    qDebug()<<"DELETE return\n"<<endl;//debug
}

void MainWindow::on_btnUpdate_clicked()
{
    qDebug()<<"update\n";//debug

    QString item1 = ui->line_id->text();
    QString item2 = ui->line_name->text();
    QString item3 = ui->line_int->text();
    QString item4 = ui->line_id_old->text();

    qDebug()<<"new id:"<<item1;
    qDebug()<<"name:"<<item2;
    qDebug()<<"tint:"<<item3;
    qDebug()<<"old id:"<<item4;

    int ret = query.exec(QString("update test set TID = '%1',TNAME = '%2',TINT = %3 where TID = '%4';").arg(item1,item2,item3,item4));//绑定方式1

    qDebug()<<ret;
             if(ret){
                qDebug()<<"update successfully";
             }

    qDebug()<<"update return\n"<<endl;//debug
}

void MainWindow::on_btnSelByname_clicked()
{
    qDebug()<<"select by name\n";//debug

    QString item = ui->line_name->text();

    int ret = query.exec(QString("SELECT * FROM test where TNAME = '%1';").arg(item));//绑定方式1

    qDebug()<<ret;
             if(ret){
                qDebug()<<"readsuccessfully";
                QSqlRecord rec = query.record();
                while(query.next()){
                      rec = query.record();
                      QString id = query.value("TID").toString();
                      qDebug()<<"id:"<<id;
                      QString name = query.value("TNAME").toString();
                      qDebug()<<"name:"<<name;
                      int tint = query.value("TINT").toInt();
                      qDebug()<<"tint:"<<tint;
                }
             }

    qDebug()<<"select by name return\n"<<endl;//debug
}

void MainWindow::on_btnSel_clicked()
{
    showAll();
}
