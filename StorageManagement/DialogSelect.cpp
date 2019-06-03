#include "DialogSelect.h"
#include "ui_DialogSelect.h"
#include "goodsdaoimp.h"
#include "DBHelper.h"
#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>
#include <QTextCodec>
DialogSelect::DialogSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSelect)
{
    ui->setupUi(this);
    this->setWindowTitle("查询货品信息");

    model = new QSqlQueryModel(ui->tableView);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogSelect::~DialogSelect()
{
    delete ui;
}


void DialogSelect::on_btn_select_clicked()
{
    if(ui->le_select_id->text().isEmpty() && ui->le_name->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许全为空");
        return;
    }

    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();

    bool ret = 0;
    QSqlQuery query;
    if(!ui->le_select_id->text().isEmpty())
    {
          ret =  query.exec(QString("select * from COMMODITY where CID = '%1';").arg(ui->le_select_id->text()));//绑定方式

    } else if(ui->le_select_id->text().isEmpty() && !ui->le_name->text().isEmpty()){
          ret =  query.exec(QString("select * from COMMODITY where CNAME = '%1';").arg(ui->le_name->text()));

    }

    while(query.next()){
         qDebug() << query.value(0).toString() << "|"
                  << query.value(1).toString() << "|"
                  << query.value(2).toString() << "|"
                  << query.value(3).toString() << "|"
                  << query.value(4).toString() << "|";
    }
    if(ret){
        qDebug()<<"select from COMMODITY success";
    } else {
        qDebug()<<query.lastError().text();
    }

    if(!ui->le_select_id->text().isEmpty())
    {
        query.exec(QString("select CID as '货品号',"
                           "CNAME as '货品名',"
                           "STID as '仓库号', "
                           "STORE as '数量', "
                           "MANUFACTURER as '生产厂家' from COMMODITY where CID = '%1';").arg(ui->le_select_id->text()));
    } else if(ui->le_select_id->text().isEmpty() && !ui->le_name->text().isEmpty()){
        query.exec(QString("select CID as '货品号',"
                           "CNAME as '货品名',"
                           "STID as '仓库号', "
                           "STORE as '数量', "
                           "MANUFACTURER as '生产厂家' from COMMODITY where CNAME = '%1';").arg(ui->le_name->text()));
    }

    model->setQuery(query);

    ui->tableView->setModel(model);
}
