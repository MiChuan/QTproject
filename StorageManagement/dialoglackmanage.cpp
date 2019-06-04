#include "dialoglackmanage.h"
#include "ui_dialoglackmanage.h"
#include <QSqlQuery>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "lackdaoimp.h"

DialogLackManage::DialogLackManage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLackManage)
{
    ui->setupUi(this);
    this->setWindowTitle("缺货处理");

    /**二级界面**/
    dialogDeleteLack = new DialogDeleteLack(this);
    dialogUpdateLack = new DialogUpdateLack(this);
    dialogSelectLack = new DialogSelectLack(this);

    /**设置二级界面为模态**/
    dialogDeleteLack->setWindowModality(Qt::ApplicationModal);
    dialogUpdateLack->setWindowModality(Qt::ApplicationModal);
    dialogSelectLack->setWindowModality(Qt::ApplicationModal);

    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogLackManage::~DialogLackManage()
{
    delete ui;
}

void DialogLackManage::showAllLack(){
    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();

    QSqlQuery query;
    bool ret = query.exec("select * from STOCKOUT;");
    while(query.next()){
         qDebug() << query.value(0).toString() << "|"
                  << query.value(1).toString() << "|"
                  << query.value(2).toString() << "|"
                  << query.value(3).toString() << "|"
                  << query.value(4).toString() << "|"
                  << query.value(5).toString() << "|" ;
        }
    if(ret){
        qDebug()<<"create tb_lack success";
    } else {
            qDebug()<<query.lastError().text();
      }

    model->setQuery("select SOID as '缺货单号',"
                    "DID as '出货单号',"
                    "CID as '货品号',"
                    "STID as '仓库编号', "
                    "SOTIME  as '登记时间',"
                    "SONUM  as '缺货量' from STOCKOUT;");
    ui->tableView->setModel(model);
}

/*槽函数*/

void DialogLackManage::on_btndel_clicked()
{
    dialogDeleteLack->show();
}


void DialogLackManage::on_btnflush_clicked()
{
    showAllLack();
}

void DialogLackManage::on_btnupdate_clicked()
{
    dialogUpdateLack->show();
}

void DialogLackManage::on_btnsel_clicked()
{
    dialogSelectLack->show();
}



void DialogLackManage::on_btnadd_clicked()
{
    if(ui->line_lackid->text().isEmpty()||
            ui->line_outid->text().isEmpty()||
            ui->line_goodsid->text().isEmpty()||
            ui->line_stid->text().isEmpty()||
            ui->line_time->text().isEmpty()||
            ui->line_num->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    query.exec(QString("select * from STOCKOUT where SOID = '%1';").arg(ui->line_lackid->text()));//查询当前货品码是否已存在
    if(query.value(0).toString() == ui->line_lackid->text()){
        qDebug()<<"SOID : " + ui->line_lackid->text() + " is existed." ;
        QMessageBox::information(this,"警告","缺货单号 : "+ui->line_lackid->text()+"已存在");
        return;
    }

    helper->closeDatabase();

    QString lackid = ui->line_lackid->text();
    QString outid = ui->line_outid->text();
    QString goodsid = ui->line_goodsid->text();
    QString stid = ui->line_stid->text();
    QString time = ui->line_time->text();
    QString num = ui->line_num->text();

    Lack lack(lackid,outid,goodsid,stid,time,num);


    LackDao *fd = new LackDaoImp();
    if(fd->insertLack(lack))
    {
        qDebug()<<"insert success";
        QMessageBox::information(this,"插入","插入成功");
    }
    else
    {
        qDebug()<<"insert failed";
        QMessageBox::critical(this,"插入","插入失败，请重新插入");
    }
}
