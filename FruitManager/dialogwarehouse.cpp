#include "dialogwarehouse.h"
#include "ui_dialogwarehouse.h"
#include <fruitdaoimp.h>
#include <QSqlQuery>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QMessageBox>

DialogWarehouse::DialogWarehouse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWarehouse)
{
    ui->setupUi(this);

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


    showAllFruits();

}


void DialogWarehouse::showAllFruits()
{
    DBHelper *helper =  DBHelper::getInstance();
    helper->connectDatabase();

    QSqlQuery query;
    bool ret = query.exec("select (fruitName, fruitNum, fruitPrice, limited_number) from om_entrepot;");
    while(query.next()){
         qDebug() << query.value(0).toString() << "|"
                  << query.value(1).toString() << "|"
                  << query.value(2).toString() << "|"
                  << query.value(3).toString();
    }
    if(ret){
        qDebug()<<"create tb_fruit success";
    } else {
        qDebug()<<query.lastError().text();
    }

    model->setQuery("select fruitName as '水果名',"
                    "fruitNum as '数量/kg',"
                    "fruitPrice as '最新单价￥/500g', "
                    "limited_number as '最低数量/kg' from om_entrepot;");
    ui->tableView->setModel(model);

    helper->disconnectDatabase();

}



DialogWarehouse::~DialogWarehouse()
{
    delete ui;
}

void DialogWarehouse::on_btn_del_clicked()
{
    dialogDelete->show();
}

void DialogWarehouse::on_btn_add_clicked()
{
    QMessageBox::critical(this,"警告","密码错误");
}


void DialogWarehouse::on_btn_flush_clicked()
{
    showAllFruits();
}

void DialogWarehouse::on_btn_update_clicked()
{
    dialogUpdate->show();
}


void DialogWarehouse::on_btn_select_clicked()
{
    dialogSelect->show();
}

void DialogWarehouse::on_bit_add_clicked()
{
    if(ui->le_name->text().isEmpty() ||
            ui->le_price->text().isEmpty() ||
            ui->le_num->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    DBHelper *helper =  DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select * from om_entrepot where fruitName = :fruitName;");
    query.bindValue(":fruitName", ui->le_name->text());
    bool ret = query.exec();
    if(ret){
        qDebug()<<"create tb_fruit success";
    } else {
        qDebug()<<query.lastError().text();
    }
    if(query.size()!=0) {
        qDebug()<<"fruitName : " + ui->le_name->text() + " is existed." ;
        QMessageBox::information(this,"警告","水果名 : "+ui->le_name->text()+"已存在");
        return;
    }

    helper->disconnectDatabase();


    QString name = ui->le_name->text();
    double price = ui->le_price->text().toDouble();
    double num = ui->le_num->text().toDouble();
    double limited_num = 0.0;
    if(!ui->le_num->text().isEmpty())
        limited_num = ui->le_limited->text().toDouble();
    Fruit fruit(name,price,num,limited_num);


    FruitDao *fd = new FruitDaoImp();
    if(fd->insertFruit(fruit))
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
