#include  <iostream>
#include "endereco.h"
#include "pessoa.h"
#include "data.h"
#include <string>

int main(){

    int dia, mes, ano;
    std::cin >> dia >> mes >> ano;
    Data nasci(dia, mes, ano);

    std::string rua, numero, bairro, cidade, pais;
    std::cin >> rua >> numero >> bairro >> cidade >> pais;
    Endereco address(rua, numero, bairro, cidade, pais);

    std::string nome, cpf, email;
    std::cin >> nome >> cpf >> email; 

    Pessoa pipou(nome, cpf, email, address, nasci);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++){
        std::string opcao, dado;
        std::cin >> opcao >> dado;
        if (opcao == "EMAIL"){
            pipou.set_email(dado);
        } else if (opcao == "CPF"){
            pipou.set_cpf(dado);
        }
    }

    pipou.print();


    return 0;
}


    
    /*std::string oi = "@.com";

    for (long unsigned int i = 0; i < oi.size(); i++){
        int numb = oi[i];
        std::cout << "valor do caractere: " << "oi[" << i << "] = " << numb << std::endl;
    }*/
    