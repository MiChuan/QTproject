#include "dialogviewstock.h"
#include "ui_dialogviewstock.h"
#include <QSqlQuery>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "goodsdaoimp.h"

DialogViewStock::DialogViewStock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogViewStock)
{
    ui->setupUi(this);
    this->setWindowTitle("查看库存");

    /**二级界面**/
    dialogSelect = new DialogSelect(this);
    /**设置二级界面为模态**/
    dialogSelect->setWindowModality(Qt::ApplicationModal);


    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogViewStock::~DialogViewStock()
{
    delete ui;
}

void DialogViewStock::showAllGoods()
{
    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();

    QSqlQuery query;
    bool ret = query.exec("select * from COMMODITY;");
    while(query.next()){
         qDebug() << query.value(0).toString() << "|"
                  << query.value(1).toString() << "|"
                  << query.value(2).toString() << "|"
                  << query.value(3).toString() << "|"
                  << query.value(4).toString() << "|"   ;
    }
    if(ret){
        qDebug()<<"create tb_goods success";
    } else {
        qDebug()<<query.lastError().text();
    }

    model->setQuery("select CID as '货品号',"
                    "CNAME as '货品名',"
                    "STID as '仓库编号', "
                    "STORE  as '货品库存量',"
                    "MANUFACTURER  as '生产厂家' from COMMODITY;");
    ui->tableView->setModel(model);
}

void DialogViewStock::on_btnflush_clicked()
{
    showAllGoods();
}

void DialogViewStock::on_btnselect_clicked()
{
    dialogSelect->show();
}
