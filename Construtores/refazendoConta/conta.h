#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include "pessoa.h"

class Conta{
private:
    std::string numero;
    float saldoAtual;
    Pessoa pessoa;

public:
    Conta(std::string numero, Pessoa titular);
    void deposito(float valor);
    void saque(float valor);
    float saldo();
    void print();
};

#endif


