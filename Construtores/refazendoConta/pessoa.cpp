#include "pessoa.h"


Pessoa::Pessoa(std::string nome, std::string cpf){
    this->cpf = cpf;
    this->nome = nome;
}

void Pessoa::print(){
    std::cout << "Pessoa(" << this->nome << ", " << this->cpf << ")";
}