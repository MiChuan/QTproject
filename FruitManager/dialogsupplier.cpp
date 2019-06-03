#include "dialogsupplier.h"
#include "ui_dialogsupplier.h"

#include <QModelIndex>
#include <QDebug>
#include <QString>
#include "supplierdaoimp.h"


DialogSupplier::DialogSupplier(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogSupplier)
{
    ui->setupUi(this);


    helper->connectDatabase();
    /**将数据模型与QTableView绑定**/
//    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
//    /**tableView列宽等宽自适应**/
//

    model = new QSqlTableModel(this);
    model->setTable("om_supplier");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    helper->disconnectDatabase();

//    showAllSuppliers();

}

DialogSupplier::~DialogSupplier()
{
    delete ui;
}

void DialogSupplier::showAllSuppliers()
{
//    DBHelper *helper =  DBHelper::getInstance();
//    helper->connectDatabase();

//    model->setQuery("select name as '供应商',"
//                    "fruitName as '水果名',"
//                    "price as '单价￥/500g',"
//                    "number as '数量/kg', "
//                    "address as '地址',"
//                    "telephone as '电话' from om_supplier;");
//    ui->tableView->setModel(model);

//    helper->disconnectDatabase();
}


void DialogSupplier::on_pushButton_5_clicked()
{
       helper->connectDatabase();
    int rowNum = model->rowCount(); //获得表的行数
//    int id = 10;
    model->insertRow(rowNum); //添加一行
//    model->setData(model->index(rowNum,0),id);

//    QString fruitName;
//    QString supplierName;
//    QString address;
//    double price;
//    double number;
//    QString telephone;


//    if(ui->le_supplier->text().isEmpty()||
//            ui->le_fruit_name->text().isEmpty() ||
//            ui->le_price->text().isEmpty() ||
//            ui->le_address->text().isEmpty() ||
//            ui->le_number->text().isEmpty() ||
//            ui->le_telephone->text().isEmpty())
//    {
//        QMessageBox::critical(this,"警告","请完善信息");
//        return;
//    }

//    DBHelper *helper = DBHelper::getInstance();
//    helper->connectDatabase();
//    QSqlQuery query;

//    supplierName = ui->le_supplier->text();
//    fruitName = ui->le_fruit_name->text();
//    address = ui->le_address->text();
//    price = ui->le_price->text().toDouble();
//    number = ui->le_number->text().toDouble();
//    telephone = ui->le_telephone->text();


//    //执行插入
//    query.prepare("insert into om_supplier(name,fruitName, price,number,address,telephone)"
//                  "values(:name, :fruitName, :price, :number, :address, :telephone);");
//    query.bindValue(":name", supplierName);
//    query.bindValue(":fruitName", fruitName);
//    query.bindValue(":price", price);
//    query.bindValue(":number", number);
//    query.bindValue(":address", address);
//    query.bindValue(":telephone", telephone);

//    bool ret = query.exec();

//    if(ret){
//        qDebug()<<"添加供应商成功";
//    }
//    else{
//        qDebug()<<"添加供应商失败"<<query.lastError().text();
//    }

//    helper->disconnectDatabase();
//    showAllSuppliers();
    helper->disconnectDatabase();
}

void DialogSupplier::on_btn_flush_clicked()
{
    showAllSuppliers();
}

void DialogSupplier::on_pushButton_2_clicked()
{
    //获取选中的行
    helper->connectDatabase();
    int curRow = ui->tableView->currentIndex().row();

    //删除该行
        model->removeRow(curRow);

        int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定"
                                                     "删除当前行吗？"),
                                      QMessageBox::Yes,QMessageBox::No);
        if(ok == QMessageBox::No)
        {
           model->revertAll(); //如果不删除，则撤销
        }
        else model->submitAll(); //否则提交，在数据库中删除该行
       helper->disconnectDatabase();
}

void DialogSupplier::on_pushButton_6_clicked()
{
    helper->connectDatabase();
    model->database().transaction(); //开始事务操作
    if (model->submitAll()) {
        model->database().commit(); //提交
    } else {
        model->database().rollback(); //回滚
        QMessageBox::warning(this, tr("tableModel"),tr("数据库错误: %1").arg(model->lastError().text()));
    }
    helper->disconnectDatabase();
}

void DialogSupplier::on_btn_select_clicked()
{
    helper->connectDatabase();
    QString name = ui->lineEdit->text();
    //根据供应商名进行筛选
    model->setFilter(QString("name = '%1'").arg(name));
    //显示结果
    model->select();
    helper->disconnectDatabase();
}

void DialogSupplier::on_pushButton_3_clicked()
{
    helper->connectDatabase();
    model->setTable("om_supplier");   //重新关联表
    model->select();   //这样才能再次显示整个表的内容
}
