#include <iostream>
#include <string>
#include <iomanip>
#include "conta.h"
#include "pessoa.h"

Conta::Conta(std::string numero, Pessoa titular) : numero(numero), pipou(titular){
    this->saldoAtual = 0;
}

void Conta::deposito(float valor){
    if (valor < 0){
        std::cout << "VALOR INVALIDO" << std::endl;
    } else{
        this->saldoAtual += valor;
    }
}

void Conta::saque(float valor){
    if (valor < 0){
        std::cout << "VALOR INVALIDO" << std::endl;
    } else{
        if (this->saldoAtual - valor >= 0) {
            this->saldoAtual -= valor;
        } else{
            std::cout << "SALDO INSUFICIENTE" << std::endl;
        }
    }
}
    

float Conta::saldo(){
    return this->saldoAtual;
}

void Conta::print(){
    std::cout << std::fixed << std::setprecision(2) << "Conta(" << this->numero << ", " << this->saldoAtual << ", Pessoa(";
    this->pipou.print();
    std::cout << "))" << std::endl;
}