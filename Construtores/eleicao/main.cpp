#include <iostream>
#include "eleicao.h"

int main(){
    int n;
    std::cin >> n;

    Eleicao eleicao(n);
    
    int numVotos;
    std::cin >> numVotos;
    for (int i = 0; i < numVotos; i++){
        int candidato, qtd;
        std::cin >> candidato >> qtd;
        eleicao.votar(candidato, qtd);
    }
    
    int vencedor = eleicao.vencedor();
    int totalVotos = eleicao.numero_votos();

    std::cout << vencedor << std::endl << totalVotos << std::endl;

    return 0;
}