#ifndef CONTA_H
#define CONTA_H
#include "pessoa.h"
#include <string>

class Conta{
private:
    std::string numero;
    float saldoAtual;
    Pessoa pipou;

public:
    Conta(std::string numero, Pessoa titular);
    void deposito(float valor);
    void saque(float valor);
    float saldo();
    void print();
};

#endif