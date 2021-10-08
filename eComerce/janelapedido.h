#ifndef JANELAPEDIDO_H
#define JANELAPEDIDO_H
#include<pedido.h>
#include<QDialog>
#include<QMessageBox>

namespace Ui {
class JanelaPedido;
}

class JanelaPedido : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaPedido(QWidget *parent = nullptr);
    ~JanelaPedido();

public slots:
    QString on_pushButton_clicked();

private:
    Ui::JanelaPedido *ui;
    int aleatorio = rand()%(100-0+1) + 0;
};

#endif // JANELAPEDIDO_H
