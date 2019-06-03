#include "dialogpurchase.h"
#include "ui_dialogpurchase.h"
#include <dbhelper.h>
#include <QComboBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include <QStringList>
#include <QModelIndex>
#include "fruit.h"
#include "fruitdaoimp.h"
#include "fruitdao.h"

DialogPurchase::DialogPurchase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogPurchase)
{
    ui->setupUi(this);
    model = new QSqlQueryModel(ui->tableView);
    helper =DBHelper::getInstance();

}

DialogPurchase::~DialogPurchase()
{
    delete ui;
}

void DialogPurchase::on_le_fruit_name_textChanged(const QString &arg1)
{
    ui->cb_supplier->clear();
    ui->le_price->clear();
    ui->le_address->clear();
}

void DialogPurchase::on_cb_supplier_activated(const QString &arg1)
{
//    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    QString supplier = ui->cb_supplier->currentText();
    query.prepare("select price, address from om_supplier where name = :supplier;");
    query.bindValue(":supplier", supplier);
    query.exec();

    while(query.next()){
        ui->le_price->setText(query.value(0).toString());
        ui->le_address->setText(query.value(1).toString());
    }


    helper->disconnectDatabase();
}

void DialogPurchase::on_le_fruit_name_editingFinished()
{
//    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();

    QString fruitName ;
    fruitName = ui->le_fruit_name->text();

    QSqlQuery query;
    query.prepare("select name from om_supplier where fruitName = :fruitName;");
    query.bindValue(":fruitName", fruitName);
    query.exec();

    if(query.size() == 0){
        QMessageBox::information(this,"警告"," 该水果没有供应商供应");
        return ;
    }

    while(query.next()){
        ui->cb_supplier->addItem(query.value(0).toString());
    }
//    QStringList strList;
//    strList <<"香蕉"<<"水果";
//    ui->cb_supplier->addItems(strList);
    helper->disconnectDatabase();
}

void DialogPurchase::on_pushButton_clicked()
{
    int fruitId;
    QString fruitName;
    int supplierId;
    QString supplierName;
    QString address;
    double price;
    double num;
    QString date;
    int is_update = 0;


    if(ui->cb_supplier->currentText().isEmpty()||
            ui->le_fruit_name->text().isEmpty() ||
            ui->le_num->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","请完善信息");
        return;
    }

//    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;

    query.exec("START TRANSACTION");


    supplierName = ui->cb_supplier->currentText();
    fruitName = ui->le_fruit_name->text();
    address = ui->le_address->text();
    price = ui->le_price->text().toDouble();
    num = ui->le_num->text().toDouble();
    QDateTime current_date_time = QDateTime::currentDateTime();
    date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
//    qDebug()<<supplierName;

    //获取水果id
    query.prepare("select id from om_entrepot where fruitName = :fruitName;");
    query.bindValue(":fruitName", fruitName);
    query.exec();
    while(query.next()){
        fruitId = query.value(0).toString().toInt();
    }

    //获取供应商id
    query.prepare("select id from om_supplier where name = :supplierName;");
    query.bindValue(":supplierName", supplierName);
    query.exec();
    while(query.next()){
        supplierId = query.value(0).toString().toInt();
    }


    //执行采购单插入
    query.prepare("insert into om_purchase_order(fruit_id,fruit_name,number, price,supplier_id,supplier_name,date,is_update)"
                  "values(:fruitId, :fruitName, :num, :price, :supplierId, :supplierName, :date, :is_update);");
    query.bindValue(":fruitId", fruitId);
    query.bindValue(":fruitName", fruitName);
    query.bindValue(":num", num);
    query.bindValue(":price", price);
    query.bindValue(":supplierId", supplierId);
    query.bindValue(":supplierName", supplierName);
    query.bindValue(":date", date);
    query.bindValue(":is_update", is_update);

    bool ret = query.exec();

    if(ret){
        qDebug()<<"添加采购记录成功";
    }
    else{
        qDebug()<<"添加采购记录失败"<<query.lastError().text();
    }

    // 将采购的水果加入库存
    double fruitNum;
    double fruitPrice;
    double limited_number;
    query.prepare("select * from om_entrepot where fruitName = :fruitName;");
    query.bindValue(":fruitName", fruitName);
    query.exec();

    if(query.size() == 0){
        fruitNum = num;
        fruitPrice = price;
        limited_number = 0;
        query.prepare("insert into om_entrepot(fruitName,fruitPrice,fruitNum)"
                      "values(:fruitName,:fruitPrice,:fruitNum);");
        query.bindValue(":fruitName",fruitName);
        query.bindValue(":fruitPrice",fruitPrice);
        query.bindValue(":fruitNum",fruitNum);
        ret = query.exec();
        if(ret)
        {
            qDebug()<<"插入成功";
        }
        else
        {
            qDebug()<<"插入失败";
        }
    } else {
        while(query.next()){
            fruitNum = query.value(2).toString().toDouble() + num;
            fruitPrice = query.value(3).toString().toDouble();
            limited_number = query.value(4).toString().toDouble();

            query.prepare("update om_entrepot "
                          "set fruitName = :fruitName, "
                          "fruitPrice = :fruitPrice, "
                          "fruitNum = :fruitNum, "
                          "limited_number = :limitedNum "
                          "where fruitName = :oldname");
            query.bindValue(":fruitName",fruitName);
            query.bindValue(":fruitPrice",fruitPrice);
            query.bindValue(":fruitNum",fruitNum);
            query.bindValue(":limitedNum",limited_number);
            query.bindValue(":oldname",fruitName);
            ret = query.exec();
            if(ret)
            {
                qDebug()<<"修改成功";
            }
            else
            {
                qDebug()<<"修改失败";
            }
        }
    }
//    helper->disconnectDatabase();
//    helper->connectDatabase();
    model->setQuery("select fruit_name as '水果名',"
                    "supplier_name as '供应商',"
                    "number as '数量/kg',"
                    "price as '最新单价￥/500g', "
                    "date as '日期' from om_purchase_order;");
    ui->tableView->setModel(model);
    commit_flag = true;

//    query.exec("COMMIT");

//    helper->disconnectDatabase();
//    this->close();

}

void DialogPurchase::on_btn_commit_clicked()
{
//    DBHelper *helper = DBHelper::getInstance();
//    helper->connectDatabase();
    if(!commit_flag){
        QMessageBox::critical(this,"警告","请先进行采购");
        return;
    }
    QSqlQuery query;
    query.exec("COMMIT");
    commit_flag = false;
    helper->disconnectDatabase();
}
