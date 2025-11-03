#ifndef HORA_H
#define HORA_H
#include <string>

class Hora {
public:
    Hora(int hora = 0, int minuto = 0, int segundo = 0);
    Hora operator+(const Hora& soma) const;
    Hora operator+(int segundos) const;
    void print() const;
    static Hora ler();

private:
    int _hora, _minuto, _segundo;
};

#endif