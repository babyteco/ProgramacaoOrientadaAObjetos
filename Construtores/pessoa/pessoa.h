#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <string>
#include "endereco.h"
#include "data.h"

class Pessoa{
private:
    std::string nome;
    std::string cpf;
    std::string email;
    Endereco endereco;
    Data nascimento;
    int validar_cpf(std::string cepeefe);
    int validar_email(std::string email);

public:
    Pessoa(std::string nome, std::string cpf, std::string email, Endereco endereco, Data nascimento);
    void set_cpf(std::string cpf);
    void set_email(std::string emaill);
    void print();
};

#endif
/*
os seguintes métodos privados:
- int validar_cpf(std::string cpf): Deve verificar se o cpf é composto apenas de digitos numéricos usando a tabela ASCII e, em caso afirmativo, retornar 1. Caso contrário, retornar 0.
- int validar_email(std::string email): Deve verificar se o email contém "@" e ".com". Em caso afirmativo, retornar 1. Caso contrário, retornar 0.

e os seguintes métodos públicos:
- construtor: Recebe os valores de todos os atributos. O construtor deve verificar se o CPF e o e-mail são válidos. Campos inválidos devem ser inicializados com string vazia ("N/A").
- set_cpf(std::string cpf): Deve verificar se o cpf é válido e, em caso afirmativo, atualizar o cpf. Caso contrário, deve ser exibida a mensagem "CPF INVALIDO" e o cpf não deve ser atualizado.
- set_email(std::string email): Deve verificar se o email é válido e, em caso afirmativo, atualizar o email. Caso contrário, deve ser exibida a mensagem "EMAIL INVALIDO" e o email não deve ser atualizado.
- print: mostra os dados da pessoa na tela no formato Pessoa(nome, cpf, email, Endereco(rua, numero, bairro, cidade, pais), Data(dia, mes, ano)).
*/