#include "dialoginputstock.h"
#include "ui_dialoginputstock.h"
#include <QSqlQuery>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "purchasedaoimp.h"

DialogInputStock::DialogInputStock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInputStock)
{
    ui->setupUi(this);
    this->setWindowTitle("入库管理");

    /**二级界面**/
    dialogDeletePurchase = new DialogDeletePurchase(this);
    dialogSelectPurchase = new DialogSelectPurchase(this);
    /**设置二级界面为模态**/
    dialogDeletePurchase->setWindowModality(Qt::ApplicationModal);
    dialogSelectPurchase->setWindowModality(Qt::ApplicationModal);

    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogInputStock::~DialogInputStock()
{
    delete ui;
}

void DialogInputStock:: showAllPurchase(){
    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();

    QSqlQuery query;
    bool ret = query.exec("select * from STOCK;");
    while(query.next()){
         qDebug() << query.value(0).toString() << "|"
                  << query.value(1).toString() << "|"
                  << query.value(2).toString() << "|"
                  << query.value(3).toString() << "|"
                  << query.value(4).toString() << "|"
                  << query.value(5).toString() << "|"
                  << query.value(6).toString() << "|"
                  << query.value(7).toString() << "|"   ;
    }
    if(ret){
        qDebug()<<"select from STOCK success";
    } else {
        qDebug()<<query.lastError().text();
    }

    model->setQuery("select IID as '进货单号',"
                    "CID as '货品号',"
                    "STID as '仓库编号', "
                    "CNAME as '货品名',"
                    "SNUM as '进货量',"
                    "STIME  as '进货时间',"
                    "MANUFACTURER as '生产厂家',"
                    "CHECKRESULT  as '审核意见' from STOCK;");
    ui->tableView->setModel(model);
}

void DialogInputStock::on_btnflush_clicked()
{
    showAllPurchase();
}


void DialogInputStock::on_btnsel_clicked()
{
    dialogSelectPurchase->show();
}


void DialogInputStock::on_btndel_clicked()
{
    dialogDeletePurchase->show();
}
