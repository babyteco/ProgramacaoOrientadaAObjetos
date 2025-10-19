/*

Nesta atividade, vamos implementar a classe Conta novamente, mas com algumas modificações. As classes devem ser organizadas em arquivos .h e .cpp.

A classe Conta deve ter como atributos privados o número da conta (std::string), o saldo (float) e o titular (Pessoa). A classe deve conter os seguintes métodos:

- construtor(std::string numero, Pessoa titular): Recebe como argumentos o titular e o número da conta. Inicializa o saldo com zero.
- void deposito(float valor): Soma um valor ao saldo.
- void saque(float valor): Remove um valor do saldo.
- float saldo(void): Retorna o valor do saldo.
- void print(void): Mostra os dados da conta na tela no formato Conta(numero, saldo, Pessoa(nome, cpf)). Chame a função print de pessoa para mostrar os dados do titular. O saldo deve ser exibido com 2 casas depois da vírgula.

*/
#include "conta.h"
#include "pessoa.h"
#include <iomanip>

Conta::Conta(std::string numero, Pessoa titular) : numero(numero), pessoa(titular){
    this->saldoAtual = 0;
}

float Conta::saldo(){
    return this->saldoAtual;
}

void Conta::deposito(float valor){
    if(valor < 0){
        std::cout << "VALOR INVALIDO\n";
        return;
    }

    this->saldoAtual += valor;
}

void Conta::saque(float valor){
    if(valor < 0){
        std::cout << "VALOR INVALIDO\n";
        return;
    }

    if((this->saldoAtual - valor) < 0){
        std::cout << "SALDO INSUFICIENTE\n";
    } else this->saldoAtual -= valor;
}

//Conta(numero, saldo, Pessoa(nome, cpf))
void Conta::print(){
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Conta(" << this->numero << ", " << this->saldoAtual << ", ";
    this->pessoa.print();
    std::cout << ")\n";
}