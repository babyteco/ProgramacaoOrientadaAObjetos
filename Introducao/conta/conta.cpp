#include <stdio.h>
#include <string.h>

class Conta{
public:
    float saldo;
    char numero[12];


    void deposito(float valor){
        if(valor <= 0){
            printf("VALOR INVALIDO\n");
            return;
        }

        this->saldo += valor;
    }
    void saque(float valor){
        if(valor <= 0){
            printf("VALOR INVALIDO\n");
            return;
        }

        if(valor > this->saldo){
            printf("SALDO INSUFICIENTE");
            return;
        }

        this->saldo -= valor;
    }
};

int main(){
    Conta c;
    strcpy(c.numero, "123456789");
    c.saldo = 0;

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        char operacao;
        int valor;
        scanf("%c %d\n", &operacao, &valor);

        if (!strcmp(&operacao, "D")){
            printf("depositou\n");
            c.deposito(valor);
        } else if (!strcmp(&operacao, "S")){
            printf("sacou\n");
            c.saque(valor);
        }
    }
    

    return 0;
}