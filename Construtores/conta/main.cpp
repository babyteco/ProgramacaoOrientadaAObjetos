#include <iostream>
#include <string>
#include "pessoa.h"
#include "conta.h"

int main(){
    std::string nome, cpf, numero;
    std::cin >> nome >> cpf >> numero;

    Pessoa pip(nome, cpf);
    Conta conta(numero, pip);

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        char operacao;
        float valor;
        std::cin >> operacao >> valor;

        if (operacao == 'D'){
            conta.deposito(valor);
        } else if (operacao == 'S'){
            conta.saque(valor);
        }
    }

    conta.print();

    return 0;
}