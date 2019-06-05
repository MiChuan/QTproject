#include "dialogviewlack.h"
#include "ui_dialogviewlack.h"
#include <QSqlQuery>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "lackdaoimp.h"

DialogViewLack::DialogViewLack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogViewLack)
{
    ui->setupUi(this);
    this->setWindowTitle("查看缺货单");

    /**二级界面**/
    dialogSelectLack = new DialogSelectLack(this);
    /**设置二级界面为模态**/
    dialogSelectLack->setWindowModality(Qt::ApplicationModal);


    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogViewLack::~DialogViewLack()
{
    delete ui;
}


void DialogViewLack:: showAllLack(){
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

void DialogViewLack::on_btnflush_clicked()
{
    showAllLack();
}

void DialogViewLack::on_btnsel_clicked()
{
    dialogSelectLack->show();
}
