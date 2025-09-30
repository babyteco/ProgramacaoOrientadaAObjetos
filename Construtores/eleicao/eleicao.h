#ifndef ELEICAO_H
#define ELEICAO_H

class Eleicao{
private:
    int numCandidatos;
    int *candidatos;

public:
    Eleicao(int n);
    ~Eleicao();
    void votar(int candidato, int quantidade);
    int vencedor();
    int numero_votos();
};

#endif