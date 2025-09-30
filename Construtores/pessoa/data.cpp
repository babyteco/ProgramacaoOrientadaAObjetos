#include  <iostream>
#include "data.h"

Data::Data(int d, int m, int y){
    this->dia = d;
    this->mes = m;
    this->ano = y;
}

void Data::print(){
    std::cout << "Data(" << this->dia << ", " << this->mes << ", " << this->ano << ")";
}

//Data(dia, mes, ano)