#include <iostream>
#include <cstring>

class Pessoa{
public:
    std::string nome;
    int ano;
    int idade(int ano_atual){
        return ano_atual - this->ano;
    }
};

int main(){
    std::string nome;
    int nascimento;
    std::cin >> nome >> nascimento;

    int anoAtual;
    std::cin >> anoAtual;

    Pessoa pes;

    std::cout << "A idade de " << pes.nome << "e: " << pes.idade(anoAtual);
    return 0;
}


