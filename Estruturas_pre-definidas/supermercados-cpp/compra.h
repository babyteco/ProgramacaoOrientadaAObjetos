#ifndef COMPRA_H
#define COMPRA_H

#include <string>
#include <vector>
#include "usuario.h"
#include "produto.h"
using namespace std;

class Compra {
private: 
    vector<Produto*> produtos;
    Usuario* user;
    vector<int> quantidades;

public:
    Compra(Usuario* user, vector<Produto*>& prod, vector<int>& qtd);
    vector<Produto*>& getProdutos();
    vector<int>& getQuantidades();
    Usuario* getUsuario();
};

#endif
