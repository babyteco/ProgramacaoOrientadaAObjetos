#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
using namespace std;

class Produto {
private: 
    string nome;
    float preco;
    int qtd_estoque;

public:
    Produto(string nome, float preco);
    Produto();
    void incrementaQtd(int qtd);
    string getNomeProduto();
    float getPreco();
    int getQtdEstoque();
};

#endif
