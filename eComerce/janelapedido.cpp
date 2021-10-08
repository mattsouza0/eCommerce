#include "janelapedido.h"
#include "ui_janelapedido.h"

JanelaPedido::JanelaPedido(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaPedido)
{
    ui->setupUi(this);
    ui->lineEdit_PEDIDO->setEnabled(false);
    ui->lineEdit_PEDIDO->setText(QString::number(aleatorio));
}

JanelaPedido::~JanelaPedido()
{
    delete ui;
}

QString JanelaPedido::on_pushButton_clicked()
{
    QString saida;
    try {
        if(ui->lineEdit_PEDIDO->text().toInt()<0||ui->lineEdit_CLIENTE->text().toInt()<0||ui->lineEdit_PRODUTO->text().toInt()<0||ui->lineEdit_QUANTIDADE->text().toInt()<=0)
            throw QString("DADOS INCOMPLETOS");
        else{
            saida+=ui->lineEdit_PEDIDO->text()+";";
            saida+=ui->lineEdit_CLIENTE->text()+";";
            saida+=ui->lineEdit_PRODUTO->text()+";";
            saida+=ui->lineEdit_QUANTIDADE->text()+";";
            int dia=ui->lineEdit_DIA->text().toInt();
            int mes=ui->lineEdit_MES->text().toInt();
            int ano=ui->lineEdit_ANO->text().toInt();
            if(dia<=0||dia>31)
                throw QString("DIA INVALIDO");
            else if(mes<=0||mes>12)
                throw QString("MES INVALIDO");
            else if(ano<=1900||ano>2020)
                throw QString("ANO INVALIDO");
            saida+=QString::number(dia)+"/"+QString::number(mes)+"/"+QString::number(ano)+";";
            this->close();
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
        return saida;

}
