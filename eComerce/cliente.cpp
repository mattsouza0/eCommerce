#include "cliente.h"

Cliente::Cliente():codigoCliente(0),nome(""),endereco(""),telefone(""),cpf("")
{

}
Cliente::Cliente(int codigo,QString nome,QString endereco,QString telefone,QString cpf){
    setCpf(cpf);
    setNome(nome);
    setTelefone(telefone);
    setEndereco(endereco);
    setCodigoCliente(codigo);
}
void Cliente::setCpf(QString valor){
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
    if(digito1 == cpf[9] && digito2 == cpf[10])
        this->cpf = valor;
    else
        throw QString("CPF INVALIDO");
    if(valor=="")
        throw QString("CPF INVALIDO");
}
void Cliente::montar(QString valor){
    QString codigo,nome,endereco,telefone,cpf;
    int aux=0,i=0;
    for (; aux==0;i++){
        if(valor[i]!=';')
            codigo+= valor[i];
        else
            aux++;
    }
    for(;aux==1;i++){
        if(valor[i]!=';')
            nome+= valor[i];
        else
            aux++;
    }
    for(;aux==2;i++){
        if(valor[i]!=';')
            endereco+= valor[i];
        else
            aux++;
    }
    for(;aux==3;i++){
        if(valor[i]!=';')
            telefone+=valor[i];
        else
            aux++;
    }

    for(;i<valor.size();i++){
        if(valor[i]!=';')
            cpf+= valor[i];
    }
    this->setCpf(cpf);
    this->setNome(nome);
    this->setEndereco(endereco);
    this->setTelefone(telefone);
    this->setCodigoCliente(codigo.toInt());


}
QString Cliente::desmontar(){;
    QString saida="";
    saida+=QString::number(this->getCodigoCliente())+";";
    saida+=this->getNome()+";";
    saida+=this->getEndereco()+";";
    saida+=this->getTelefone()+";";
    saida+=this->getCPF()+";";
    return saida;

}
void Cliente::setCodigoCliente(int codigo){
    if(codigo<0)
        throw QString("CODIGO INVALIDO");
    codigoCliente = codigo;

}
QString Cliente::print(){
    QString saida="";
    saida+="CODIGO: "+QString::number(getCodigoCliente())+"\n";
    saida+="NOME: "+getNome()+"\n";
    saida+="ENDERECO: "+getEndereco()+"\n";
    saida+="TELEFONE: "+getTelefone()+"\n";
    saida+="CPF: "+getCPF();
    return saida;
}
