#include<iostream>
#include <string>
#include "produto.h"
using namespace std;

Produto::Produto(string nome, float preco){
    this->nome = nome;
    this->preco = preco;
    this->qtd_estoque = 0;
}

Produto::Produto(){}

void Produto::incrementaQtd(int qtd){
    this->qtd_estoque += qtd;
}

string Produto::getNomeProduto(){
    return this->nome;
}

float Produto::getPreco(){
    return this->preco;
}

int Produto::getQtdEstoque(){
    return this->qtd_estoque;
}