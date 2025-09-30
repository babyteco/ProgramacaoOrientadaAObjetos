#include <iostream>
#include "eleicao.h"

Eleicao::Eleicao(int n){
    this->candidatos = (int*) calloc(n, sizeof(int));
    this->numCandidatos = n;
}

Eleicao::~Eleicao(){
    free(this->candidatos);
}

void Eleicao::votar(int candidato, int quantidade){
    this->candidatos[candidato] += quantidade;
}

int Eleicao::vencedor(){
    int champ = -1, maior = 0;
    for (int i = 0; i < this->numCandidatos; i++){
        if (this->candidatos[i] > maior){
            champ = i;
            maior = this->candidatos[i];
        }
    }
    return champ;
}

int Eleicao::numero_votos(){
    int total = 0;
    for (int i = 0; i < this->numCandidatos; i++){
        total += this->candidatos[i];
    }
    return total;
}