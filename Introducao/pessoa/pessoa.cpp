#include <stdio.h>
#include <string.h>

class Pessoa{
public:
    char nome[32];
    int nascimento;

    int idade(int anoAtual){
        int idade = anoAtual - this->nascimento;
        if(idade < 0){
            printf("VALOR INVALIDO\n");
            return -1;
        } else return idade;
    }
};


int main(){

    Pessoa jonson;
    int anoAtual;

    scanf("%s %d %d", jonson.nome, &jonson.nascimento, &anoAtual);
    int idade = jonson.idade(anoAtual);

    printf("%d\n", idade);

    return 0;
}