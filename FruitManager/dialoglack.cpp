#include "dialoglack.h"
#include "ui_dialoglack.h"

DialogLack::DialogLack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLack)
{
    ui->setupUi(this);

    dialogPurchase = new DialogPurchase();
    dialogPurchase->setWindowModality(Qt::ApplicationModal);

    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    flush();
}

DialogLack::~DialogLack()
{
    delete ui;
}

void DialogLack::on_btn_flush_clicked()
{
    flush();
}

void DialogLack::flush()
{
    DBHelper *helper =  DBHelper::getInstance();
    helper->connectDatabase();

    model->setQuery("select fruitName as '水果名',"
                    "fruitNum as '现存数量/kg',"
                    "fruitPrice as '单价￥/500g', "
                    "limited_number as '最低数量/kg', "
                    "(limited_number - fruitNum) as '缺少数量/kg' from om_entrepot where (limited_number - fruitNum) > 0;");
    ui->tableView->setModel(model);

    helper->disconnectDatabase();
}

void DialogLack::on_btn_buy_clicked()
{
    dialogPurchase->show();
}
