#include "pessoa.h"
#include <iostream>


Pessoa::Pessoa(std::string name, std::string ccpf){
    this->nome = name;
    this->cpf = ccpf;
}

void Pessoa::print(){
    std::cout << this->nome << ", " << this->cpf;  
}