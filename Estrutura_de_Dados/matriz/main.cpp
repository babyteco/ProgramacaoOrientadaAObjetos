#include "matriz.h"

int main()
{
  Matriz m1 = Matriz::ler();
  Matriz m2 = Matriz::ler();

  Matriz m3 = m1 * 5 + m1 * 9;
  m3 = m3 + m3;

  Matriz m4(m3);
  m4 = m3 = m3;

  Matriz m5 = (m1 * 3) * (m2 * 2);

  Matriz m6 = Matriz::ones(m5.colunas(), m5.colunas()) * Matriz::eye(m5.colunas(), m5.linhas()) * m5;

  m4.print();
  m5.print();
  m6.print();

  return 0;
}