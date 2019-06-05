#include "dialogcheckpurchase.h"
#include "ui_dialogcheckpurchase.h"
#include <QSqlQuery>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "purchasedaoimp.h"

DialogCheckPurchase::DialogCheckPurchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCheckPurchase)
{
    ui->setupUi(this);
    this->setWindowTitle("审核进货单");

    /**二级界面**/
    dialogSelectPurchase = new DialogSelectPurchase(this);
    /**设置二级界面为模态**/
    dialogSelectPurchase->setWindowModality(Qt::ApplicationModal);

    dialogPurchaseCheckResult = new DialogPurchaseCheckResult(this);

    dialogPurchaseCheckResult->setWindowModality(Qt::ApplicationModal);

    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogCheckPurchase::~DialogCheckPurchase()
{
    delete ui;
}

void DialogCheckPurchase:: showAllPurchase(){
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

void DialogCheckPurchase::on_btnflush_clicked()
{
    showAllPurchase();
}

void DialogCheckPurchase::on_btnsel_clicked()
{
    dialogSelectPurchase->show();
}

void DialogCheckPurchase::on_btncheck_clicked()
{
    dialogPurchaseCheckResult->show();
}
