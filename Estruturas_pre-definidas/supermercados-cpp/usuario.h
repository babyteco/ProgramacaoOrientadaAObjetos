#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
using namespace std;

class Usuario {
private: 
    string nome;
    string cpf;
public:
    Usuario();
    Usuario(string nome, string cpf);
    string getCpf();
    string getNomeCliente();
};

#endif
