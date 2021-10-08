#include "janela2.h"
#include "ui_janela2.h"

Janela2::Janela2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Janela2)
{
    ui->setupUi(this);
}

Janela2::~Janela2()
{
    delete ui;
}

QString Janela2::on_pushButton_confirmar_clicked()
{
    QString saida;
    if(ui->lineEdit_DesJane->text()==""||ui->lineEdit_EstoqJane->text().toInt()<0||ui->lineEdit_ProdutoJane->text().toFloat()<=0.0)
        QMessageBox::information(this,"ALTERACAO","DADOS INCOMPLETOS");
    else{
        saida+=ui->lineEdit_DesJane->text()+";";
        saida+=ui->lineEdit_EstoqJane->text()+";";
        saida+=ui->lineEdit_ProdutoJane->text()+";";
        this->close();
    }
    return saida;

}


