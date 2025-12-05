#include <string>
#include <vector>
#include "usuario.h"
#include "produto.h"
#include "compra.h"
using namespace std;


Compra::Compra(Usuario* user, vector<Produto*>& prod, vector<int>& qtd){
    this->user = user;
    this->produtos = prod;
    this->quantidades = qtd;
}

vector<Produto*>& Compra::getProdutos(){
    return this->produtos;
}

vector<int>& Compra::getQuantidades(){
    return this->quantidades;
}

Usuario* Compra::getUsuario(){
    return this->user;
}