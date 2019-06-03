#include "dialogstockmanage.h"
#include "ui_dialogstockmanage.h"
#include <QSqlQuery>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "goodsdaoimp.h"

DialogStockmanage::DialogStockmanage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStockmanage)
{
    ui->setupUi(this);
    this->setWindowTitle("库存管理");

    /**二级界面**/
    dialogDelete = new DialogDelete(this);
    dialogUpdate = new DialogUpdate(this);
    dialogSelect = new DialogSelect(this);
    /**设置二级界面为模态**/
    dialogDelete->setWindowModality(Qt::ApplicationModal);
    dialogUpdate->setWindowModality(Qt::ApplicationModal);
    dialogSelect->setWindowModality(Qt::ApplicationModal);





    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void DialogStockmanage::showAllGoods()
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



DialogStockmanage::~DialogStockmanage()
{
    delete ui;
}


/*槽函数*/
void DialogStockmanage::on_btn_del_clicked()
{
    dialogDelete->show();
}

void DialogStockmanage::on_btn_flush_clicked()
{
    showAllGoods();
}

void DialogStockmanage::on_btn_update_clicked()
{
    dialogUpdate->show();
}

void DialogStockmanage::on_btn_select_clicked()
{
    dialogSelect->show();
}

void DialogStockmanage::on_bit_add_clicked()
{
    if(ui->le_name->text().isEmpty() ||
            ui->le_id->text().isEmpty() ||
            ui->le_num->text().isEmpty() ||
            ui->le_stid->text().isEmpty() ||
            ui->le_ma->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    query.exec(QString("select * from COMMODITY where CID = '%1';").arg(ui->le_id->text()));//查询当前货品码是否已存在
    if(query.value(0).toString() == ui->le_id->text()){
        qDebug()<<"CID : " + ui->le_id->text() + " is existed." ;
        QMessageBox::information(this,"警告","货品号 : "+ui->le_id->text()+"已存在");
        return;
    }

    helper->closeDatabase();

    QString id = ui->le_id->text();
    QString name = ui->le_name->text();
    QString stid = ui->le_stid->text();
    QString num = ui->le_num->text();
    QString ma = ui->le_ma->text();

    Goods goods(id,name,stid,num,ma);


    GoodsDao *fd = new GoodsDaoImp();
    if(fd->insertGoods(goods))
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
