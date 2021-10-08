#ifndef CRUD_H
#define CRUD_H
#include<QString>

class CRUD
{
public:
    CRUD();
    virtual void incluir(QString valor)=0;
    virtual int alterar(int id,QString valor)=0;
    virtual QString listar()=0;
    virtual int excluir(int id)=0;
    virtual QString procurar(QString id)=0;
};

#endif // CRUD_H
