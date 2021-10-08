#include "janelacliente.h"
#include "ui_janelacliente.h"

JanelaCliente::JanelaCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaCliente)
{
    ui->setupUi(this);
}

JanelaCliente::~JanelaCliente()
{
    delete ui;
}

QString JanelaCliente::on_pushButton_CONFIRMAR_clicked()
{
    QString saida;

    if(ui->lineEdit_NOME->text()==""||ui->lineEdit_CPF->text()==""||ui->lineEdit_ENDERECO->text()==""||ui->lineEdit_TELEFONE->text()=="")
        QMessageBox::information(this,"ALTERACAO","DADOS INCOMPLETOS");
    else{
        QString valor =ui->lineEdit_CPF->text();
        int cpf [11];
        QString aux;
        int digito1,digito2,somador = 0;
        for(int i = 0;i < 11;i++){
              aux = valor[i];
              cpf[i] = aux.toInt();
            }
        for(int i = 0; i < 9; i++){
            somador += (cpf[i] * (10 - i));
        }
        somador %= 11;
        if(somador < 2)
            digito1 = 0;
        else
            digito1 = 11 - somador;
        somador = 0;
        for(int i = 0; i < 10; i++){
            somador+= (cpf[i] * (11 - i));
        }
            somador %= 11;
        if(somador < 2)
           digito2 = 0;
        else
           digito2 = 11 - somador;
        if(digito1 == cpf[9] && digito2 == cpf[10]){
            saida+=ui->lineEdit_NOME->text()+";";
            saida+=ui->lineEdit_ENDERECO->text()+";";
            saida+=ui->lineEdit_TELEFONE->text()+";";
            saida+=ui->lineEdit_CPF->text()+";";
            this->close();
        }
        else
            QMessageBox::information(this,"ALTERACAO","CPF INVALIDO");
    }
    return saida;
}
