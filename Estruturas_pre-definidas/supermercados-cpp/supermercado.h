#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include <string>
#include <vector>
#include "produto.h"
#include "compra.h"
using namespace std;

class Supermercado {
private: 
    vector<Compra*> compras;
    vector<Produto*> produtos;
    vector<Usuario*> clientes;

public:
    Supermercado();
    void registraProduto(string nome, float preco);
    void registrarCliente(string nome, string cpf);
    void incrementaProduto(string nome, int qtd);
    void registraCompra(string cpf);
    void revenue();
    void maisVendido();
    void melhorCliente();
    void emFalta();
    void liberaSupermercado();
};

#endif
