//dado pelo professor

#include <cstdio>
#include "hora.h"

int main()
{
  Hora h1;
  Hora h2(2);
  Hora h3(1, 25);
  Hora h4(2, 30, 40);

  Hora h5 = Hora::ler();

  Hora h6 = h1 + h5;
  Hora h7 = h2 + h5;
  Hora h8 = h3 + h5;
  Hora h9 = h4 + h5;

  h6.print();
  h7.print();
  h8.print();
  h9.print();

  return 0;
}