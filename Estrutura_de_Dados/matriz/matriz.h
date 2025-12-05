#ifndef MATRIZ_H
#define MATRIZ_H

#include <cstdio>
#include <stdexcept>

class Matriz {
private:
    int _n;        // nÃºmero de linhas
    int _m;        // nÃºmero de colunas
    double** _data; // matriz de valores

    void _alocar(int n, int m) {
        _n = n;
        _m = m;
        _data = new double*[n];
        for (int i = 0; i < n; ++i)
            _data[i] = new double[m];
    }

    // FunÃ§Ã£o auxiliar para liberar memÃ³ria
    void _liberar() {
        if (_data) {
            for (int i = 0; i < _n; ++i)
                delete[] _data[i];
            delete[] _data;
            _data = nullptr;
        }
    }


public:
    // --- Construtor parametrizado: inicializa com zeros ---
    Matriz(int n, int m);

    // --- Construtor parametrizado: inicializa com vetor de valores ---
    Matriz(int n, int m, const double* valores);

    // --- Construtor de cÃ³pia ---
    Matriz(const Matriz& other);

    // --- Operador de atribuiÃ§Ã£o ---
    Matriz& operator=(const Matriz& other);

    // --- Destrutor ---
    ~Matriz();

    // --- MÃ©todos estÃ¡ticos ---
    static Matriz zeros(int n, int m);
    static Matriz ones(int n, int m);
    static Matriz eye(int n, int m);

    // --- Operador + (matriz + matriz) ---
    Matriz operator+(const Matriz& other) const;

    // --- Operador + (matriz + escalar) ---
    Matriz operator+(double escalar) const;

    // --- Operador * (matriz * escalar) ---
    Matriz operator*(double escalar) const;

    // --- Operador * (matriz * matriz) ---
    Matriz operator*(const Matriz& other) const;

    // --- MÃ©todo estÃ¡tico para ler uma matriz ---
    static Matriz ler();

    // --- MÃ©todo print ---
    void print() const;

    // --- MÃ©todos auxiliares ---
    int linhas() const;
    int colunas() const;
};

#endif