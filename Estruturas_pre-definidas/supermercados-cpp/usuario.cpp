#include <iostream>
#include <string>
#include <vector>
#include "usuario.h"
using namespace std;


Usuario::Usuario(){}

Usuario::Usuario(string nome, string cpf){
    this->nome = nome;
    this->cpf = cpf;
}

string Usuario::getCpf(){
    return this->cpf;
}

string Usuario::getNomeCliente(){
    return this->nome;
}