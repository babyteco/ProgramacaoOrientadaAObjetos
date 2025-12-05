#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> numeros;

    int n;
    cin >> n;

    string jerry;
    int qtd;
    for (int i = 0; i < n; i++){
        cin >> jerry;

        if (jerry == "INSERIR"){
            cin >> qtd;
            numeros.push_back(qtd);
        } else if(jerry == "REMOVER"){
            cout << numeros[numeros.size() - 1] << endl;
            numeros.pop_back();
        } else if(jerry == "VER"){
            cin >> qtd;
            cout << numeros[qtd] << "\n";
        } else if(jerry == "MOSTRAR"){
            for (unsigned int i = 0; i < numeros.size(); i++){
                cout << numeros[i]  << endl;
            } 
        } else if(jerry == "TAMANHO"){
                cout << numeros.size() << endl;
        } else if(jerry == "ORDENAR"){
            sort(numeros.begin(), numeros.end());
        } else if(jerry == "BUSCAR"){
            cin >> qtd;
            auto p = find(numeros.begin(), numeros.end(), qtd);

            if(p == numeros.end()){
                cout << "-1" << endl;
            } else{
                cout << (p -numeros.begin()) << endl;
            }
        }
    }
    

    return 0;
}