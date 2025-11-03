#include <iostream>
#include "hora.h"

using namespace std;

Hora::Hora(int hora, int minuto, int segundo){
    if(segundo >= 60){
        minuto += segundo / 60;
        segundo = segundo % 60;
    }

    if(minuto >= 60){
        hora += minuto / 60;
        minuto = minuto % 60;
    }

    _segundo = segundo;
    _minuto = minuto;
    _hora = hora;
}  

Hora Hora::operator+(const Hora& soma) const {
    int seg = 0, min = 0, hor = 0;
    
    seg = this->_segundo + soma._segundo;
    if (seg >= 60){
        seg -= 60;
        min++;
    }
    
    min += this->_minuto + soma._minuto;
    if (min >= 60){
        min -= 60;
        hor++;
    }

    hor += this->_hora + soma._hora;

    return Hora(hor, min, seg);
}

Hora Hora::operator+(int segundos) const{
    int seg = _segundo + segundos;
    int minuto = this->_minuto;
    int hora = this->_hora;
    if (seg >= 60){
        seg -= 60;
        minuto++;
        if (minuto >= 60){
            minuto -= 60;
            hora++;
        }
    }

    return Hora(hora, minuto, seg);
}

Hora Hora::ler(){
    int hora, minuto, segundo;
    cin >> hora >> minuto >> segundo;

    return Hora(hora, minuto, segundo);
}

void Hora::print() const {
    cout << this->_hora << " " << this->_minuto << " " << this->_segundo << endl;
}