#include <iostream>
#include "conta.h"
#include "pessoa.h"

int main(){
    std::string nome, cpf, numero;
    std:: cin >> nome >> cpf >> numero;

    Pessoa pipou(nome, cpf);
    Conta count(numero, pipou);

    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++){
        char c;
        float valor;
        std::cin >> c >> valor;

        if (c == 'D'){
            count.deposito(valor);
        } else if (c == 'S'){
            count.saque(valor);
        }
    }

    count.print();
    
    return 0;
}