#ifndef CLIENTE_H
#define CLIENTE_H
#include<transformardados.h>

class Cliente:public TransformarDados
{
private:
    int codigoCliente;
    QString nome;
    QString endereco;
    QString telefone;
    QString cpf;
public:
    Cliente();
    Cliente(int codigo,QString nome,QString endereco,QString telefone,QString cpf);
    void montar(QString valor) override;
    QString desmontar() override;
    QString getNome()const{return nome;}
    void setNome(QString valor){nome = valor;}
    QString getEndereco()const{return endereco;}
    void setEndereco(QString valor){endereco = valor;}
    QString getTelefone()const{return telefone;}
    void setTelefone(QString valor){telefone = valor;}
    QString getCPF()const{return cpf;}
    void setCpf(QString valor);
    int getCodigoCliente()const{return codigoCliente;}
    void setCodigoCliente(int codigo);
    QString print();
};

#endif // CLIENTE_H
