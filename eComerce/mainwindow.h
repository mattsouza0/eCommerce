#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<produto.h>
#include<cliente.h>
#include<persistenciaclie.h>
#include<persistenciaprod.h>
#include<persistenciaped.h>
#include<janela2.h>
#include<janelacliente.h>
#include<janelapedido.h>
#include <QMainWindow>
#include<QInputDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_incluir_clicked();

    void on_pushButton_alterar_clicked();

    void on_pushButton_excluir_clicked();

    void on_pushButton_listar_clicked();

    void on_radioButton_PRODUTO_clicked();

    void on_radioButton_CLIENTE_clicked();

    void on_radioButton_PEDIDO_clicked();

    void on_pushButton_Pedido_clicked();

    void on_pushButton_consultarCliente_clicked();

    void on_pushButton_consultarPedido_clicked();

private:
    Ui::MainWindow *ui;
    PersistenciaPROD *ArqProd = new PersistenciaPROD("PRODUTO.txt");
    PersistenciaCLIE *ArqCLIE = new PersistenciaCLIE("CLIENTE.txt");
    PersistenciaPED  *ArqPED = new PersistenciaPED("PEDIDO.txt");
    Janela2 *form;
    JanelaCliente *form2;
    JanelaPedido *form3;

};
#endif // MAINWINDOW_H
