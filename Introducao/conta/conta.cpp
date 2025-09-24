#include <stdio.h>
#include <string.h>

class Conta{
public:
    float saldo;
    char numero[12];


    void deposito(float valor){
        if(valor <= 0){
            printf("VALOR INVALIDO\n%f\n", this->saldo);
            return;
        }

        this->saldo += valor;
        printf("%f\n", this->saldo);
    }

    void saque(float valor){
        if(valor <= 0){
            printf("VALOR INVALIDO\n%f\n", this->saldo);
            return;
        }

        if(valor > this->saldo){
            printf("SALDO INSUFICIENTE\n%f\n", this->saldo);
            return;
        }

        this->saldo -= valor;
        printf("%f\n", this->saldo);
    }
};

int main(){
    Conta c;
    strcpy(c.numero, "123456789");
    c.saldo = 0;

    int N;
    scanf("%d\n", &N);

    for (int i = 0; i < N; i++){
        char operacao;
        int valor;
        scanf("%c %d\n", &operacao, &valor);

        if (operacao == 'D'){
            c.deposito(valor);
        } else if (operacao == 'S'){
            c.saque(valor);
        }
    }
    

    return 0;
}