#include <stdio.h>

class Retangulo{
public:
    float altura, largura;
    
    float calculaArea(){
        return this->largura * this->altura;
    }
    
    float calculaPerimetro(){
        return 2*this->altura + 2*this->largura;
    }
};


int main(){
    Retangulo felipeRet;
    scanf("%f %f", &felipeRet.altura, &felipeRet.largura);
    printf("%.0f %.0f\n", felipeRet.calculaArea(), felipeRet.calculaPerimetro());
    return 0;
}