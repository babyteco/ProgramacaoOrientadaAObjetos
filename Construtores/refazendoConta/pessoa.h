#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>


class Pessoa{
public:
    std::string nome;
    std::string cpf;
    Pessoa(std::string nome, std::string cpf);
    void print();
};

#endif