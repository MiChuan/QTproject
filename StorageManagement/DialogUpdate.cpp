#include "DialogUpdate.h"
#include "ui_DialogUpdate.h"
#include <QMessageBox>
#include "goodsdaoimp.h"
DialogUpdate::DialogUpdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUpdate)
{
    ui->setupUi(this);
    this->setWindowTitle("修改货品信息");
}

DialogUpdate::~DialogUpdate()
{
    delete ui;
}

void DialogUpdate::on_buttonBox_accepted()
{
    if(ui->le_id_old->text().isEmpty()||
            ui->le_new_id->text().isEmpty()||
            ui->le_name_new->text().isEmpty()||
            ui->le_num_new->text().isEmpty()||
            ui->le_ma_new->text().isEmpty()||
            ui->le_stid_new->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    QString id_new;
    if(!ui->le_new_id->text().isEmpty())
        id_new = ui->le_new_id->text();
    else
        id_new = ui->le_id_old->text();
    QString name_new = ui->le_name_new->text();
    QString stid_new = ui->le_stid_new->text();
    QString num_new = ui->le_num_new->text();
    QString ma_new = ui->le_ma_new->text();

    Goods goods(id_new,name_new,stid_new,num_new,ma_new);
    GoodsDao *fd = new GoodsDaoImp();
    qDebug() << goods.getGoodsId() << "|"
           << goods.getGoodsName() << "|"
           << goods.getGoodsStid() << "|"
           << goods.getGoodsNum() << "|"
           << goods.getGoodsMa();
    int ret = fd->updateGoods(goods, ui->le_id_old->text());
    if(ret)
    {
        QMessageBox::information(this,"修改","修改成功");
    }
    else
    {
        QMessageBox::critical(this,"修改","修改失败");
    }
    delete(fd);
    fd=NULL;

}

void DialogUpdate::on_buttonBox_rejected()
{
    this->close();
}
