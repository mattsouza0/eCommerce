#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_incluir_clicked()
{
    try {
        if(ui->radioButton_PRODUTO->isChecked()){
            Produto p(ui->lineEdit_CODIGO->text().toInt(),ui->lineEdit_descricao->text(),ui->lineEdit_estoque->text().toInt(),ui->lineEdit_preco->text().toFloat());
            QString saida;
            saida =p.desmontar();
            ArqProd->incluir(saida);
            ui->lineEdit_preco->clear();
            ui->lineEdit_CODIGO->clear();
            ui->lineEdit_estoque->clear();
            ui->lineEdit_descricao->clear();
            ui->textEdit->setText(ArqProd->listar());
        }
        else if(ui->radioButton_CLIENTE->isChecked()){
            Cliente p(ui->lineEdit_CODIGOCLIE->text().toInt(),ui->lineEdit_NOME->text(),ui->lineEdit_ENDERECO->text(),ui->lineEdit_TELEFONE->text(),ui->lineEdit_CPF->text());
            QString saida;
            saida =p.desmontar();
            ArqCLIE->incluir(saida);
            ui->lineEdit_CPF->clear();
            ui->lineEdit_NOME->clear();
            ui->lineEdit_TELEFONE->clear();
            ui->lineEdit_CODIGOCLIE->clear();
            ui->lineEdit_ENDERECO->clear();
            ui->textEdit_cliente->setText(ArqCLIE->listar());
        }
        else
            throw QString("NENHUMA OPCAO ESCOLHIDA");
    } catch (QString &erro) {
        QMessageBox::information(this,"OPA",erro);
    }

}

void MainWindow::on_pushButton_alterar_clicked()
{
    try {
        if(ui->radioButton_PRODUTO->isChecked()){
            int aux =QInputDialog::getText(this,"OPA","INSIRA O ID DO PRODUTO: ").toInt();
            int cont=0;
            form = new Janela2(this);
            form->exec();
            QString saida=form->on_pushButton_confirmar_clicked();
            if(saida!=""){
                saida=QString::number(aux)+";"+form->on_pushButton_confirmar_clicked();
                cont =ArqProd->alterar(aux,saida);
            }
            if(cont!=0){
                QMessageBox::information(this,"OPA","ALTERACÃO FEITA");
                ui->textEdit->setText(ArqProd->listar());
            }
            else
                throw QString("ID NAO ENCONTRADO");
        }else if(ui->radioButton_CLIENTE->isChecked()){
            int aux =QInputDialog::getText(this,"OPA","INSIRA O ID DO CLIENTE: ").toInt();
            int cont=0;
            form2 = new JanelaCliente(this);
            form2->exec();
            QString saida=form2->on_pushButton_CONFIRMAR_clicked();
            if(saida!=""){
                saida=QString::number(aux)+";"+form2->on_pushButton_CONFIRMAR_clicked();
                cont =ArqCLIE->alterar(aux,saida);
            }
            if(cont!=0){
                QMessageBox::information(this,"OPA","ALTERACÃO FEITA");
                ui->textEdit_cliente->setText(ArqCLIE->listar());
            }
            else
                throw QString("ID NAO ENCONTRADO");
        }
        else
            throw QString("NENHUMA OPCAO ESCOLHIDA");

    } catch (QString &erro) {
        QMessageBox::information(this,"OPA",erro);
    }

}

void MainWindow::on_pushButton_excluir_clicked()
{
    try {
        if(ui->radioButton_PRODUTO->isChecked()){
            int aux =QInputDialog::getText(this,"OPA","INSIRA O ID DO PRODUTO: ").toInt();
            int cont=0;
            cont =ArqProd->excluir(aux);
            if(cont!=0){
                QMessageBox::information(this,"OPA","EXCLUSÃO FEITA");
                ui->textEdit->setText(ArqProd->listar());
            }
            else
                throw QString("ID NAO ENCONTRADO");
            }
        else if(ui->radioButton_CLIENTE->isChecked()){
            int aux =QInputDialog::getText(this,"OPA","INSIRA O ID DO CLIENTE: ").toInt();
            int cont=0;
            cont =ArqCLIE->excluir(aux);
            if(cont!=0){
                QMessageBox::information(this,"OPA","EXCLUSÃO FEITA");
                ui->textEdit_cliente->setText(ArqCLIE->listar());
            }
            else
                throw QString("ID NAO ENCONTRADO");
            }
            else if(ui->radioButton_PEDIDO->isChecked()){
                int aux =QInputDialog::getText(this,"OPA","INSIRA O ID DO PEDIDO: ").toInt();
                int cont=0;
                cont =ArqPED->excluir(aux);
                if(cont!=0){
                    QMessageBox::information(this,"OPA","EXCLUSÃO FEITA");
                    ui->textEdit_pedido->setText(ArqPED->listar());
                }
                else
                    throw QString("ID NAO ENCONTRADO");
                }
        else
            throw QString("NENHUMA OPCAO ESCOLHIDA");

    } catch (QString &erro) {
        QMessageBox::information(this,"OPA",erro);
    }
}

void MainWindow::on_pushButton_listar_clicked()
{
    try {
        if(ui->radioButton_PRODUTO->isChecked()){
            QString saida;
            saida = ArqProd->listar();
            ui->textEdit->setText(saida);
        }
        else if(ui->radioButton_CLIENTE->isChecked()){
            QString saida;
            saida = ArqCLIE->listar();
            ui->textEdit_cliente->setText(saida);
        }else if(ui->radioButton_PEDIDO->isChecked()){
            QString saida;
            saida = ArqPED->listar();
            ui->textEdit_pedido->setText(saida);
        }
        else
            throw QString("NENHUMA OPCAO ESCOLHIDA");
    } catch (QString &erro) {
        QMessageBox::information(this,"OPA",erro);
    }

}

void MainWindow::on_radioButton_PRODUTO_clicked()
{
    ui->lineEdit_CPF->setEnabled(false);
    ui->lineEdit_CPF->clear();
    ui->lineEdit_NOME->setEnabled(false);
    ui->lineEdit_NOME->clear();
    ui->lineEdit_TELEFONE->setEnabled(false);
    ui->lineEdit_TELEFONE->clear();
    ui->lineEdit_CODIGOCLIE->setEnabled(false);
    ui->lineEdit_CODIGOCLIE->clear();
    ui->lineEdit_ENDERECO->setEnabled(false);
    ui->lineEdit_ENDERECO->clear();
    ui->lineEdit_preco->setEnabled(true);
    ui->lineEdit_CODIGO->setEnabled(true);
    ui->lineEdit_estoque->setEnabled(true);
    ui->lineEdit_descricao->setEnabled(true);
    ui->pushButton_Pedido->setEnabled(false);
    ui->pushButton_listar->setEnabled(true);
    ui->pushButton_alterar->setEnabled(true);
    ui->pushButton_excluir->setEnabled(true);
    ui->pushButton_incluir->setEnabled(true);
    ui->pushButton_consultarPedido->setEnabled(false);
    ui->pushButton_consultarCliente->setEnabled(false);
}

void MainWindow::on_radioButton_CLIENTE_clicked()
{
    ui->lineEdit_preco->setEnabled(false);
    ui->lineEdit_CODIGO->setEnabled(false);
    ui->lineEdit_estoque->setEnabled(false);
    ui->lineEdit_descricao->setEnabled(false);
    ui->lineEdit_preco->clear();
    ui->lineEdit_CODIGO->clear();
    ui->lineEdit_estoque->clear();
    ui->lineEdit_descricao->clear();
    ui->lineEdit_CPF->setEnabled(true);
    ui->lineEdit_NOME->setEnabled(true);
    ui->lineEdit_TELEFONE->setEnabled(true);
    ui->lineEdit_CODIGOCLIE->setEnabled(true);
    ui->lineEdit_ENDERECO->setEnabled(true);
    ui->pushButton_Pedido->setEnabled(false);
    ui->pushButton_listar->setEnabled(true);
    ui->pushButton_alterar->setEnabled(true);
    ui->pushButton_excluir->setEnabled(true);
    ui->pushButton_incluir->setEnabled(true);
    ui->pushButton_consultarPedido->setEnabled(false);
    ui->pushButton_consultarCliente->setEnabled(false);
}

void MainWindow::on_radioButton_PEDIDO_clicked()
{
    ui->lineEdit_preco->setEnabled(false);
    ui->lineEdit_CODIGO->setEnabled(false);
    ui->lineEdit_estoque->setEnabled(false);
    ui->lineEdit_descricao->setEnabled(false);
    ui->lineEdit_CPF->setEnabled(false);
    ui->lineEdit_NOME->setEnabled(false);
    ui->lineEdit_TELEFONE->setEnabled(false);
    ui->lineEdit_CODIGOCLIE->setEnabled(false);
    ui->lineEdit_ENDERECO->setEnabled(false);
    ui->pushButton_Pedido->setEnabled(true);
    ui->pushButton_listar->setEnabled(true);
    ui->pushButton_alterar->setEnabled(false);
    ui->pushButton_excluir->setEnabled(true);
    ui->pushButton_incluir->setEnabled(false);
    ui->pushButton_consultarPedido->setEnabled(true);
    ui->pushButton_consultarCliente->setEnabled(true);
}

void MainWindow::on_pushButton_Pedido_clicked()
{
    try {
        if(ui->radioButton_PEDIDO->isChecked()){
            QString saida;
            Pedido *p;
            Produto *aux;
            form3 = new JanelaPedido(this);
            form3->exec();
            saida=form3->on_pushButton_clicked();
            if(saida!=""){
                p = new Pedido();
                aux= new Produto();
                p->montar(saida+"0.0;"+"0.0;");
                saida = ArqCLIE->procurar(p->getIDCLiente());//ver se existe cliente
                saida = ArqProd->procurar(p->getIDProduto());
                aux->montar(saida);
                if(aux->getQtdEstoque()>=p->getQtd()){
                    int resultado = aux->getQtdEstoque() - p->getQtd();
                    aux->setQtdEstoque(resultado);
                    p->setTotal(aux->getPrecoUnitario() * p->getQtd());
                    p->setUnitario(aux->getPrecoUnitario());
                }
                else{
                    throw QString("QUANTIDADE DE ESTOQUE INVALIDA");
                }
                saida = aux->desmontar();
                ArqProd->alterar(aux->getCodigo(),saida);
                ui->textEdit->setText(ArqProd->listar());
                saida= p->desmontar();
                ArqPED->incluir(saida);
                ui->textEdit_pedido->setText(ArqPED->listar());

            }
            else
                throw QString("ERRO NO PEDIDO TENTE NOVAMENTE");
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"OPA",erro);
    }


}

void MainWindow::on_pushButton_consultarCliente_clicked()
{
    try {
        if(ui->radioButton_PEDIDO->isChecked()){
           int aux =QInputDialog::getText(this,"OPA","INSIRA O ID DO CLIENTE: ").toInt();
           QString saida =ArqPED->procurar(QString::number(aux));
           ui->textEdit_pedido->setText(saida);
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"OPA",erro);
    }
}

void MainWindow::on_pushButton_consultarPedido_clicked()
{
    try {
        if(ui->radioButton_PEDIDO->isChecked()){
           int aux =QInputDialog::getText(this,"OPA","INSIRA O ID DO PEDIDO: ").toInt();
           QString saida =ArqPED->procurar(QString::number(aux));
           ui->textEdit_pedido->setText(saida);
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"OPA",erro);
    }
}
