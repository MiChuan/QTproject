#include "dialogselectpurchase.h"
#include "ui_dialogselectpurchase.h"
#include "purchasedaoimp.h"
#include "DBHelper.h"
#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>
#include <QTextCodec>

DialogSelectPurchase::DialogSelectPurchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSelectPurchase)
{
    ui->setupUi(this);
    this->setWindowTitle("查询进货单信息");

    model = new QSqlQueryModel(ui->tableView);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogSelectPurchase::~DialogSelectPurchase()
{
    delete ui;
}


void DialogSelectPurchase::on_btnsel_clicked()
{
    if(ui->line_pid->text().isEmpty()  && ui->line_goodsid->text().isEmpty()){
            QMessageBox::critical(this,"警告","不允许全为空");
            return;
    }

    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();

    bool ret = 0;
    QSqlQuery query;
    if(!ui->line_pid->text().isEmpty())
    {
          ret =  query.exec(QString("select * from STOCK where IID = '%1';").arg(ui->line_pid->text()));//绑定方式

    } else if(ui->line_pid->text().isEmpty() && !ui->line_goodsid->text().isEmpty()){
          ret =  query.exec(QString("select * from STOCK where CID = '%1';").arg(ui->line_goodsid->text()));

    }

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


    if(!ui->line_pid->text().isEmpty())
    {
        query.exec(QString("select IID as '进货单号',"
                           "CID as '货品号',"
                           "STID as '仓库编号', "
                           "CNAME as '货品名',"
                           "SNUM as '进货量',"
                           "STIME  as '进货时间',"
                           "MANUFACTURER as '生产厂家',"
                           "CHECKRESULT  as '审核意见' from STOCK where IID = '%1';").arg(ui->line_pid->text()));
    } else if(ui->line_pid->text().isEmpty() && !ui->line_goodsid->text().isEmpty()){
        query.exec(QString("select IID as '进货单号',"
                           "CID as '货品号',"
                           "STID as '仓库编号', "
                           "CNAME as '货品名',"
                           "SNUM as '进货量',"
                           "STIME  as '进货时间',"
                           "MANUFACTURER as '生产厂家',"
                           "CHECKRESULT  as '审核意见' from STOCK where CID = '%1';").arg(ui->line_goodsid->text()));
    }

    model->setQuery(query);

    ui->tableView->setModel(model);
}
