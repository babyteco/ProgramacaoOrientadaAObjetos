#include  <iostream>
#include "endereco.h"

Endereco::Endereco(std::string street, std::string number, std::string block, std::string city, std::string country){
    this->bairro = block;
    this->cidade = city;
    this->numero = number;
    this->pais = country;
    this->rua = street;
}

void Endereco::print(){
    std::string espacamento = ", ";
    std::cout << "Endereco(" << this->rua << espacamento << this->numero << espacamento << this->bairro << espacamento << this->cidade << espacamento << this->pais << ")";
}

/*
e métodos públicos:
- Construtor: Recebe os valores de todos os atributos como argumento.
- print: mostra o endereço no formato Endereco(rua, numero, bairro, cidade, pais).
*/