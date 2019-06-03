#include "dialogsale.h"
#include "ui_dialogsale.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

DialogSale::DialogSale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSale)
{
    ui->setupUi(this);

    dialogSaleItem = new DialogSaleItem();

    dialogSaleItem->setWindowModality(Qt::ApplicationModal);

    model = new QSqlQueryModel(ui->tableView);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    flush();
}

DialogSale::~DialogSale()
{
    delete ui;
}

void DialogSale::on_btn_add_clicked()
{
    dialogSaleItem->show();
}

void DialogSale::on_btn_flush_clicked()
{
    flush();
    qDebug() << "dialogsale->fluhs()";
}

void DialogSale::flush()
{
    DBHelper *helper =  DBHelper::getInstance();
    helper->connectDatabase();

    QSqlQuery query;
    bool ret = query.exec("select (id, fruit_name, number, price, date) from om_sale_order;");
    while(query.next()){
         qDebug() << query.value(0).toString() << "|"
                  << query.value(1).toString() << "|"
                  << query.value(2).toString() << "|"
                  << query.value(3).toString() << "|"
                  << query.value(4).toString();
    }
    if(ret){
        qDebug()<<"select sale order success";
    } else {
        qDebug()<<query.lastError().text();
    }

    model->setQuery("select id as '订单编号', "
                    "fruit_name as '水果名',"
                    "number as '售出数量/kg',"
                    "price as '售出单价￥/500g', "
                    "date as '日期' from om_sale_order;");
    ui->tableView->setModel(model);

    helper->disconnectDatabase();
}

