#include "dialogsaleitem.h"
#include "ui_dialogsaleitem.h"
#include <QComboBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>

DialogSaleItem::DialogSaleItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSaleItem)
{
    ui->setupUi(this);

    QComboBox *cb_fruit = ui->comboBox;

    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    bool ret;
    query.prepare("select fruitName from om_entrepot;");
    ret = query.exec();
    if(ret){qDebug()<<"获取水果名单成功";}
    else{qDebug()<<query.lastError().text();}
    helper->disconnectDatabase();

    while(query.next()){
         cb_fruit->addItem(query.value(0).toString());
         qDebug() << query.value(0).toString();
    }


}

DialogSaleItem::~DialogSaleItem()
{
    delete ui;
}

void DialogSaleItem::on_btn_comfirm_clicked()
{
    QString fruitName;
    double fruitNum;
    double fruitExistedNum;
    double fruitLimitedNum;
    double fruitAfterNum;
    double fruitPrice;
    int fruit_id;
    QString date;

    fruitName = ui->comboBox->currentText();
    fruitNum = ui->le_num->text().toDouble();
    fruitPrice = ui->le_price->text().toDouble();

    QDateTime current_date_time = QDateTime::currentDateTime();
    date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");

    qDebug() << fruitNum << "|"
             << ui->le_num->text() << "|"
             << fruitNum << "|"
             << ui->le_price->text() << "|"
             << date;

    if(ui->le_num->text().isEmpty() ||
            ui->le_price->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select id, fruitNum from om_entrepot where fruitName = :fruitName;");
    query.bindValue(":fruitName", fruitName);
    bool ret = query.exec();
    if(ret){qDebug()<<"获取水果库存成功";}
    else{qDebug()<<query.lastError().text();}

    while(query.next()) {
        qDebug() << " --------- \n"
                 << query.value(0).toString() << " " << fruitName << "\n"
                 << "库存 " << query.value(1).toString() << "kg";
        fruit_id = query.value(0).toString().toInt();
        fruitExistedNum = query.value(1).toString().toDouble();
    }
    // qDebug() << fruit_id << " " << fruitName << "库存 " << fruitExistedNum << "kg";
    // fruitExistedNum = query.value(0).toString().toDouble();

    if(fruitExistedNum < fruitNum) {
        QString info = "库存水果：" + fruitName + " 数量不足，库存"
                + QString::number(fruitExistedNum, 10, 2) + "kg, 将要售出"
                + QString::number(fruitNum, 10, 2) + "kg.";
        qDebug() << info;
        QMessageBox::information(this,"警告",info);
        return;
    }
    fruitAfterNum = fruitExistedNum - fruitNum;

    query.prepare("insert into om_sale_order(fruit_id,fruit_name,number, price, date, is_update)"
                  "values(:fruit_id, :fruit_name, :number, :price, :date, 1);");
    query.bindValue(":fruit_id",fruit_id);
    query.bindValue(":fruit_name",fruitName);
    query.bindValue(":number",fruitNum);
    query.bindValue(":price",fruitPrice);
    query.bindValue(":date",date);
    ret = query.exec();
    if(ret){
        qDebug()<<"添加销售记录成功";
    } else {
        qDebug()<<"添加销售记录失败: "<<query.lastError().text();
    }

    // 同步到库存信息
    query.clear();
    query.prepare("update om_entrepot "
                  "set fruitNum = :fruitNum, "
                  "fruitPrice = :fruitPrice "
                  "where fruitName = :fruit_name");
    query.bindValue(":fruitNum",fruitAfterNum);
    query.bindValue(":fruitPrice",fruitPrice);
    query.bindValue(":fruit_name",fruitName);
    ret = query.exec();
    if(ret){
        qDebug()<<"同步销售记录成功";
    } else {
        qDebug()<<"同步销售记录失败: "<<query.lastError().text();
    }


    helper->disconnectDatabase();
    this->close();
}
