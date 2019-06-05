#include "dialogpurchasemanage.h"
#include "ui_dialogpurchasemanage.h"
#include <QSqlQuery>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "purchasedaoimp.h"

DialogPurchaseManage::DialogPurchaseManage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPurchaseManage)
{
    ui->setupUi(this);
    this->setWindowTitle("进货单管理");

    /**二级界面**/
    dialogDeletePurchase = new DialogDeletePurchase(this);
    dialogUpdatePurchase = new DialogUpdatePurchase(this);
    dialogSelectPurchase = new DialogSelectPurchase(this);
    /**设置二级界面为模态**/
    dialogDeletePurchase->setWindowModality(Qt::ApplicationModal);
    dialogUpdatePurchase->setWindowModality(Qt::ApplicationModal);
    dialogSelectPurchase->setWindowModality(Qt::ApplicationModal);

    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogPurchaseManage::~DialogPurchaseManage()
{
    delete ui;
}

void DialogPurchaseManage:: showAllPurchase(){
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


void DialogPurchaseManage::on_btndel_clicked()
{
    dialogDeletePurchase->show();
}

void DialogPurchaseManage::on_btnflush_clicked()
{
    showAllPurchase();
}

void DialogPurchaseManage::on_btnupdate_clicked()
{
    dialogUpdatePurchase->show();
}

void DialogPurchaseManage::on_btnsel_clicked()
{
    dialogSelectPurchase->show();
}

void DialogPurchaseManage::on_btnadd_clicked()
{
    if(ui->line_purchaseid->text().isEmpty()||
       ui->line_goodsid->text().isEmpty()||
       ui->line_stid->text().isEmpty()||
       ui->line_goodsname->text().isEmpty()||
       ui->line_num->text().isEmpty()||
       ui->line_time->text().isEmpty()||
       ui->line_ma->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();

    QSqlQuery query;
    query.exec(QString("select * from STOCK where IID = '%1';").arg(ui->line_purchaseid->text()));//查询当前货品码是否已存在
    query.first();
    qDebug()<<query.value(0).toString();
    if(query.value(0).toString() == ui->line_purchaseid->text()){
        qDebug()<<"IID : " + ui->line_purchaseid->text() + " is existed." ;
        QMessageBox::information(this,"警告","进货单号 : "+ui->line_purchaseid->text()+"已存在");
        return;
    }

    helper->closeDatabase();

    QString pid = ui->line_purchaseid->text();
    QString goodsid = ui->line_goodsid->text();
    QString stid = ui->line_stid->text();
    QString goodsname = ui->line_goodsname->text();
    QString num = ui->line_num->text();
    QString time = ui->line_time->text();
    QString ma = ui->line_ma->text();
    QString check = "?";

    Purchase purch(pid,goodsid,stid,goodsname,num,time,ma,check);

    PurchaseDao *fd = new PurchaseDaoImp();
    if(fd->insertPurchase(purch))
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
