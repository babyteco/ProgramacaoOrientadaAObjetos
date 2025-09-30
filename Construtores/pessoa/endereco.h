#ifndef ENDERECO_H
#define ENDERECO_H
#include <iostream>
#include <string>

class Endereco{
private:
    std::string rua;
    std::string numero;
    std::string bairro;
    std::string cidade;
    std::string pais;


public:
    Endereco(std::string street, std::string number, std::string block, std::string city, std::string country);
    void print();
};

#endif


/*
A classe Endereço deve possuir como atributos privados:
- rua: std::string
- numero: std::string
- bairro: std::string
- cidade: std::string
- país: std::string

e métodos públicos:
- Construtor: Recebe os valores de todos os atributos como argumento.
- print: mostra o endereço no formato Endereco(rua, numero, bairro, cidade, pais).

*/