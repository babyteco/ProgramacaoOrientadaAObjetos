#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>
#include "usuario.h"
#include "produto.h"
#include "compra.h"
#include "supermercado.h"
using namespace std;

Supermercado::Supermercado(){
}

void Supermercado::registraProduto(string nome, float preco){
    Produto* p = new Produto(nome, preco);
    this->produtos.push_back(p); 
}

void Supermercado::registrarCliente(string nome, string cpf){
    Usuario* u = new Usuario(nome, cpf);
    this->clientes.push_back(u);
}

void Supermercado::incrementaProduto(string nome, int qtd){
    for (Produto *p : this->produtos){
        if (p->getNomeProduto() == nome){
            p->incrementaQtd(qtd);
            return;
        }
    }
}

void Supermercado::registraCompra(string cpf){
    string sndComand;
    cin >> sndComand;
    vector<int> qtds;
    vector<Produto*> prods;

    float valor = 0;
    while (sndComand != "FINALIZAR_COMPRA"){
        if (sndComand == "ADD_ITEM"){
            string nome;
            int qtd;
            cin >> nome >> qtd;
    
            for (Produto* p : this->produtos){
                if (p->getNomeProduto() == nome){
                    prods.push_back(p);
                    qtds.push_back(qtd);
                    this->incrementaProduto(nome, (-1) * qtd);
                    valor += p->getPreco() * qtd;
                    break;
                }
            }
        }
        
        
        cin >> sndComand;
    }

    cout << fixed << setprecision(2) << valor << endl;


    Usuario* user = nullptr;
    for (Usuario* u : this->clientes){
        if (u->getCpf() == cpf){
            user = u;
            break;
        }
    }
    
    Compra* c = new Compra(user, prods, qtds);
    this->compras.push_back(c);
}

void Supermercado::revenue(){
    float valor = 0;
    for(Compra* c : this->compras){
        int index = 0;
        for(Produto* p : c->getProdutos()){
            vector<int> qtds = c->getQuantidades();

            valor += p->getPreco() * qtds[index]; 
            index++;
        }
    }

    //precisao de duas casas decimais;
    cout << fixed << setprecision(2) << valor << endl;
}

void Supermercado::maisVendido(){
    unordered_map<string, int> hash;

    for(Produto* prod : this->produtos){
        hash[prod->getNomeProduto()] = 0;
    }
        
    for(Compra* compra : this->compras){
        vector<Produto*> listProdutos = compra->getProdutos();
        vector<int> listQuantidades = compra->getQuantidades();

        int i = 0;
        for(Produto* prod : listProdutos){
            string nomeProduto = prod->getNomeProduto();
            hash[nomeProduto] += listQuantidades[i];
            i++;
        }
    }

    Produto* most = this->produtos[0];
    for(Produto* product : this->produtos){
        if (hash[product->getNomeProduto()] > hash[most->getNomeProduto()]) {
            most = product;
        }
    }

    cout << fixed << setprecision(2) << most->getNomeProduto() << endl;
}

void Supermercado::melhorCliente(){
    unordered_map<string, int> hash;

    for(Usuario* cliente : this->clientes){
        hash[cliente->getCpf()] = 0;
    }
        
    for(Compra* compra : this->compras){
        Usuario* usuario = compra->getUsuario();
        string cpf = usuario->getCpf();

        hash[cpf] += 1;
    }

    Usuario* most = this->clientes[0];
    for(Usuario* user : this->clientes){
        if (hash[user->getCpf()] > hash[most->getCpf()]) {
            most = user;
        }
    }

    cout << fixed << setprecision(2) << most->getNomeCliente() << endl; 
}

void Supermercado::emFalta(){
    for (Produto* prod : this->produtos){
        if (prod->getQtdEstoque() < 5){
            cout << fixed << setprecision(2) << prod->getNomeProduto() << endl;
        }
    }
}

void Supermercado::liberaSupermercado(){
    for (Usuario *u : this->clientes){
        delete u;
    }
    
    for (Produto *p : this->produtos){
        delete p;
    }

    for (Compra *c : this->compras){
        delete c;
    }
}