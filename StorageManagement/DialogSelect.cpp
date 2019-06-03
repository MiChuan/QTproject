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

    QSqlQuery query;
    if(!ui->le_select_id->text().isEmpty())
    {
        query.prepare("select * from COMMODITY where CID = :CID;");
        query.bindValue(":CID", ui->le_select_id->text());
    } else if(ui->le_select_id->text().isEmpty() && !ui->le_name->text().isEmpty()){
        query.prepare("select * from COMMODITY where CNAME = :CNAME;");
        query.bindValue(":CNAME", ui->le_name->text());
    }

    bool ret = query.exec();
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


    QSqlQuery _query;
    if(!ui->le_select_id->text().isEmpty())
    {
        _query.prepare("select CID as '货品号',"
                       "CNAME as '货品名',"
                       "STID as '仓库号', "
                       "STORE as '数量', "
                       "MANUFACTURER as '生产厂家' from COMMODITY where CID = :_CID;");
        _query.bindValue(":_CID", ui->le_select_id->text());
    } else if(ui->le_select_id->text().isEmpty() && !ui->le_name->text().isEmpty()){
        _query.prepare("select CID as '货品号',"
                       "CNAME as '货品名',"
                       "STID as '仓库号', "
                       "STORE as '数量', "
                       "MANUFACTURER as '生产厂家' from COMMODITY where CNAME = :_CNAME;");
        _query.bindValue(":_CNAME", ui->le_name->text());
    }

    _query.exec();
    model->setQuery(_query);

    ui->tableView->setModel(model);

    helper->closeDatabase();
}
