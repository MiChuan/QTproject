#include "dialogselectlack.h"
#include "ui_dialogselectlack.h"
#include "lackdaoimp.h"
#include "DBHelper.h"
#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>
#include <QTextCodec>

DialogSelectLack::DialogSelectLack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSelectLack)
{
    ui->setupUi(this);
    this->setWindowTitle("查询缺货信息");

    model = new QSqlQueryModel(ui->tableView);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogSelectLack::~DialogSelectLack()
{
    delete ui;
}


void DialogSelectLack::on_btnselect_clicked()
{
    if(ui->line_lackid->text().isEmpty() && ui->line_outid->text().isEmpty() && ui->line_goodsid->text().isEmpty()){
            QMessageBox::critical(this,"警告","不允许全为空");
            return;
    }

    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();

    bool ret = 0;
    QSqlQuery query;
    if(!ui->line_lackid->text().isEmpty())
    {
          ret =  query.exec(QString("select * from STOCKOUT where SOID = '%1';").arg(ui->line_lackid->text()));//绑定方式

    } else if(ui->line_lackid->text().isEmpty() && !ui->line_outid->text().isEmpty()){
          ret =  query.exec(QString("select * from STOCKOUT where DID = '%1';").arg(ui->line_outid->text()));

    } else if(ui->line_lackid->text().isEmpty() && ui->line_outid->text().isEmpty() && !ui->line_goodsid->text().isEmpty()){
          ret =  query.exec(QString("select * from STOCKOUT where CID = '%1';").arg(ui->line_goodsid->text()));
    }

    while(query.next()){
         qDebug() << query.value(0).toString() << "|"
                  << query.value(1).toString() << "|"
                  << query.value(2).toString() << "|"
                  << query.value(3).toString() << "|"
                  << query.value(4).toString() << "|"
                  << query.value(5).toString() << "|"   ;
    }
    if(ret){
        qDebug()<<"select from STOCKOUT success";
    } else {
        qDebug()<<query.lastError().text();
    }


    if(!ui->line_lackid->text().isEmpty())
    {
        query.exec(QString("select SOID as '缺货单号',"
                           "DID as '出货单号',"
                           "CID as '货品号',"
                           "STID as '仓库编号', "
                           "SOTIME  as '登记时间',"
                           "SONUM  as '缺货量' from STOCKOUT where SOID = '%1';").arg(ui->line_lackid->text()));
    } else if(ui->line_lackid->text().isEmpty() && !ui->line_outid->text().isEmpty()){
        query.exec(QString("select SOID as '缺货单号',"
                           "DID as '出货单号',"
                           "CID as '货品号',"
                           "STID as '仓库编号', "
                           "SOTIME  as '登记时间',"
                           "SONUM  as '缺货量' from STOCKOUT where DID = '%1';").arg(ui->line_outid->text()));
    } else if(ui->line_lackid->text().isEmpty() && ui->line_outid->text().isEmpty() && !ui->line_goodsid->text().isEmpty()){
        query.exec(QString("select SOID as '缺货单号',"
                           "DID as '出货单号',"
                           "CID as '货品号',"
                           "STID as '仓库编号', "
                           "SOTIME  as '登记时间',"
                           "SONUM  as '缺货量' from STOCKOUT where CID = '%1';").arg(ui->line_goodsid->text()));
    }

    model->setQuery(query);

    ui->tableView->setModel(model);
}
