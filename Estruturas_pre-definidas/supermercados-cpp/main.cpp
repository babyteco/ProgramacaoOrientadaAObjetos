#include <iostream>
#include "supermercado.h"
#include "compra.h"
#include "usuario.h"
#include "produto.h"
using namespace std;

int main() {
    Supermercado jonson;

    string operacao;
    cin >> operacao;

    while (operacao != "ENCERRAR") {

        if (operacao == "REGISTRAR_PRODUTO") {
            string nome;
            float preco;
            cin >> nome >> preco;
            jonson.registraProduto(nome, preco);
        }

        else if (operacao == "REGISTRAR_CLIENTE") {
            string nome, cpf;
            cin >> nome >> cpf;
            jonson.registrarCliente(nome, cpf);
        }

        else if (operacao == "ADQUIRIR_PRODUTO") {
            string nome;
            int qtd;
            cin >> nome >> qtd;
            jonson.incrementaProduto(nome, qtd);
        }

        else if (operacao == "INICIAR_COMPRA") {
            string cpf;
            cin >> cpf;
            jonson.registraCompra(cpf);  
        }

        else if (operacao == "REVENUE") {
            jonson.revenue();
        }

        else if (operacao == "MAIS_VENDIDO") {
            jonson.maisVendido();
        }

        else if (operacao == "MELHOR_CLIENTE") {
            jonson.melhorCliente();
        }

        else if (operacao == "EM_FALTA") {
            jonson.emFalta();
        }

        cin >> operacao;
    }

    jonson.liberaSupermercado();

    return 0;
}