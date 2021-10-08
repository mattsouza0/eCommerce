#ifndef JANELACLIENTE_H
#define JANELACLIENTE_H
#include<QMessageBox>
#include <QDialog>

namespace Ui {
class JanelaCliente;
}

class JanelaCliente : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaCliente(QWidget *parent = nullptr);
    ~JanelaCliente();

public slots:
    QString on_pushButton_CONFIRMAR_clicked();

private:
    Ui::JanelaCliente *ui;
};

#endif // JANELACLIENTE_H
