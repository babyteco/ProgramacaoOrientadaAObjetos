#include  <iostream>
#include "endereco.h"
#include "pessoa.h"
#include "data.h"

Pessoa::Pessoa(std::string nome, std::string cpf, std::string email, Endereco address, Data nascimento) : endereco(std::move(address)), nascimento(std::move(nascimento)){
    if (!validar_cpf(cpf)) {
        this->cpf = "N/A";
    } else {
        this->cpf = cpf;
    }
    if (!validar_email(email)) {
        this->email = "N/A";
    } else {
        this->email = email;
    }
    this->nome = nome;
}

void Pessoa::set_cpf(std::string cpf){
    if (!validar_cpf(cpf)) {
        this->cpf = "N/A";
        std::cout << "CPF INVALIDO" << std::endl;
    } else {
        this->cpf = cpf;
    }
}

void Pessoa::set_email(std::string email){
    if (!validar_email(email)) {
        this->email = "N/A";
        std::cout << "EMAIL INVALIDO" << std::endl;
    } else {
        this->email = email;
    }
}

void Pessoa::print(){
    std::string space = ", ";
    std::cout << "Pessoa(" << this->nome << space << this->cpf << space << this->email << space;
    this->endereco.print();
    std::cout << space;
    this->nascimento.print();
    std::cout << ")" << std::endl;
}

int Pessoa::validar_cpf(std::string cepeefe){
    for (long unsigned int i = 0; i < cepeefe.size(); i++){
        int numb = cepeefe[i];
        if (numb < 48 || numb > 57){
            return 0;
        }
    }
    return 1;
}

int Pessoa::validar_email(std::string emaill){
    int flag_arroba = 0;
    int flag_ponto = 0;
    int flag_c = 0;
    int flag_o = 0;
    int flag_m = 0;
    for (long unsigned int i = 0; i < emaill.size(); i++){
        int numb = emaill[i];
        if (numb == 64){
            flag_arroba = 1;
        }
        if (numb == 46){
            flag_ponto = 1;
        }
        if (numb == 99){
            flag_c = 1;
        }
        if (numb == 111){
            flag_o = 1;
        }
        if (numb == 109){
            flag_m = 1;
        }
    }
    if(flag_arroba && flag_c && flag_o && flag_m && flag_ponto){
        return 1;
    } else return 0;
}


/*

os seguintes métodos privados:
- int validar_cpf(std::string cpf): Deve verificar se o cpf é composto apenas de digitos numéricos usando a tabela ASCII e, em caso afirmativo, retornar 1. Caso contrário, retornar 0.
- int validar_email(std::string email): Deve verificar se o email contém "@" e ".com". Em caso afirmativo, retornar 1. Caso contrário, retornar 0.

*/
