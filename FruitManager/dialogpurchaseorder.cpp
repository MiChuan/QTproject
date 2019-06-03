#include "dialogpurchaseorder.h"
#include "ui_dialogpurchaseorder.h"

#include <QModelIndex>
#include <QDebug>
#include <QString>
#include "dbhelper.h"

DialogPurchaseOrder::DialogPurchaseOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPurchaseOrder)
{
    ui->setupUi(this);

    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
//    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    showAllPurchaseOrder();

//    dialogPurchase = new DialogPurchase();
//    dialogPurchase->show();
}

DialogPurchaseOrder::~DialogPurchaseOrder()
{
    delete ui;
}

void DialogPurchaseOrder::showAllPurchaseOrder(){
    DBHelper *helper =  DBHelper::getInstance();
        helper->connectDatabase();

//        QSqlQuery query;
//        bool ret = query.exec("select fruitName, fruitNum, fruitPrice, limited_number from om_entrepot;");
//        while(query.next()){
//             qDebug() << query.value(0).toString() << "|"
//                      << query.value(1).toString() << "|"
//                      << query.value(2).toString() << "|"
//                      << query.value(3).toString();
//        }
//        if(ret){
//            qDebug()<<"create tb_fruit success";
//        } else {
//            qDebug()<<query.lastError().text();
//        }

        model->setQuery("select fruit_name as '水果名',"
                        "supplier_name as '供应商',"
                        "number as '数量/kg',"
                        "price as '最新单价￥/500g', "
                        "date as '日期' from om_purchase_order;");
        ui->tableView->setModel(model);

        helper->disconnectDatabase();
}

void DialogPurchaseOrder::on_btn_flush_clicked()
{
    showAllPurchaseOrder();
}
