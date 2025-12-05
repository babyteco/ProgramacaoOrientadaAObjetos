#include "matriz.h"
#include <iostream>
#include <iomanip>


Matriz::Matriz(int n, int m){
    this->_alocar(n, m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            this->_data[i][j] = 0;
        }
    }
}

Matriz::Matriz(int n, int m, const double* valores){
    this->_alocar(n, m);
    int c = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            this->_data[i][j] = valores[c];
            c++;
        }
    }
}

Matriz::Matriz(const Matriz& other){
    this->_alocar(other._n, other._m);
    for (int i = 0; i < this->_n; i++){
        for (int j = 0; j < this->_m; j++){
            this->_data[i][j] = other._data[i][j];
        }
    }
}

Matriz& Matriz::operator=(const Matriz& other){
    if (this == &other) {
        return *this;
    }
    
    this->_liberar();
    this->_alocar(other._n, other._m);
    for (int i = 0; i < this->_n; i++){
        for (int j = 0; j < this->_m; j++){
            this->_data[i][j] = other._data[i][j];
        }
    }

    return *this;
}

Matriz::~Matriz(){
    this->_liberar();
}

    // --- MÃ©todos estÃ¡ticos ---
Matriz Matriz::zeros(int n, int m){
    return Matriz(n, m);
}

Matriz Matriz::ones(int n, int m){
    Matriz mat = Matriz(n, m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            mat._data[i][j] = 1;
        }
    }
    return mat;
}
Matriz Matriz::eye(int n, int m){
    Matriz mat = Matriz(n, m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == j){
                mat._data[i][j] = 1;
            } else {
                mat._data[i][j] = 0;
            }            
        }
    }
    return mat;
}

    // --- Operador + (matriz + matriz) ---
Matriz Matriz::operator+(const Matriz& other) const {
    Matriz ma(this->_n, this->_m);
    for (int i = 0; i < other._n; i++) {
        for (int j = 0; j < other._m; j++) {
            ma._data[i][j] = this->_data[i][j] + other._data[i][j];
        }
    }

    return ma;
}

Matriz Matriz::operator+ (double escalar) const{
    Matriz ma(this->_n, this->_m);
    for (int i = 0; i < this->_n; i++) {
        for (int j = 0; j < this->_m; j++) {
            ma._data[i][j] = this->_data[i][j] + escalar;
        }
    }

    return ma;
}

Matriz Matriz::operator* (double escalar) const{
    Matriz res(_n, _m);
    for (int i = 0; i < _n; ++i)
        for (int j = 0; j < _m; ++j)
            res._data[i][j] = _data[i][j] * escalar;
    return res;
}

Matriz Matriz::operator* (const Matriz& other) const {
    Matriz res(_n, other._m);
    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < other._m; ++j) {
            res._data[i][j] = 0.0;
            for (int k = 0; k < _m; ++k)
                res._data[i][j] += _data[i][k] * other._data[k][j];
        }
    }
    return res;
}

    // --- MÃ©todo estÃ¡tico para ler uma matriz ---
Matriz Matriz::ler() {
    int n, m;
    std::cin >> n >> m;
    double* valores = new double[n * m];
    for (int i = 0; i < n * m; ++i)
        std::cin >> valores[i];
    Matriz res(n, m, valores);
    delete[] valores;
    return res;
}

    // --- MÃ©todo print ---
void Matriz::print() const {
    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < _m; ++j) {
            std::cout << std::fixed << std::setprecision(2) << _data[i][j];
            if (i != _n - 1 || j != _m - 1) std::cout << " ";
        }
    }
    std::cout << "\n";
}


int Matriz::linhas() const {
    return _n;
}
int Matriz::colunas() const {
    return _m;
}