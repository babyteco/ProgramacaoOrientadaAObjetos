#include <iostream>

using namespace std;


class Vector2d
{
  public:
    double _x, _y;

    Vector2d()
    {
      cout << "Default constructor" << endl;
      _x = _y = 0.0;
    }

    Vector2d(double x, double y)
    {
      cout << "Constructor Param" << endl;
      _x = x;
      _y = y;
    }

    Vector2d(Vector2d &v)
    {
      cout << "Copy construtor" << endl;
      _x = v._x;
      _y = v._y;
    }

    Vector2d& operator=(const Vector2d &v)
    {
      cout << "Operator=" << endl;
      _x = v._x;
      _y = v._y;
      return *this;
    }

    ~Vector2d()
    {
      cout << "Destructor" << endl;
    }
};

// Recebe argumento por copia resulta na invocacao do construtor de copia
void fn_1(Vector2d v) { }

// Recebe argumento por referencia
void fn_2(Vector2d &v) { }

// Entrada por referencia e saida por copia. A saida causa chamada do construtor de copia.
Vector2d fn_3(Vector2d &v) { return v; }

// Entrada e saida por copia. Ambos causam chamada do construtor de copia.
Vector2d fn_4(Vector2d v) { return v; }

// Entrada e saida por referencia. Nenhuma chamada ao construtor de copia é feita.
Vector2d& fn_5(Vector2d &v) { return v; }

int main()
{
  // construtor parametrizado invocado
  Vector2d a(3, 5);

  // construtor parametrizado invocado
  Vector2d *z = new Vector2d(3, 5);

  // construtor parametrizado invocado
  Vector2d b = Vector2d(3, 5);

  // construtor de copia invocado
  Vector2d c = b;

  // operator= invocado
  c = b;

  // construtor de copia invocado
  Vector2d d(b);

  // destrutor invocado
  delete z;

  printf("--------\n");

  // construtor de copia invocado
  Vector2d e = Vector2d(b);

  // construtor default invocado
  Vector2d f;

  // construtor de copia, operator= e destrutor invocados (a copia é criada é destruída depois da atribuicao)
  f = Vector2d(b);

  printf("--------\n");

  // construtor default invocado 5 vezes
  Vector2d *v = new Vector2d[5];

  // destrutor invocado 5 vezes
  delete[] v;

  // passagem por copia resulta na invocacao do construtor de copia
  fn_1(a);

  // passagem por ref
  fn_2(a);

  // saida por copia resulta na invocacao do construtor de copia
  Vector2d g = fn_3(a);

  // saida por copia resulta na invocacao do construtor de copia
  Vector2d h = fn_4(a);

  // construtor de copia na saida, operator= para atribuição e destrutor da copia
  a = fn_4(a);

  // sem chamadas a construtores dado que entrada e saida sao por referencia
  Vector2d &j = fn_5(a);

  // saida ppor referencia atribuida a variavel que não é referencia, resulta em chamada do construtor e copia
  Vector2d i = fn_5(a);

  // como j é referencia, mudanças em j causam mudanças em a
  j._x = 10;
  cout << a._x << endl;

  // como i não é referencia, mudanças em i NÃO causam mudanças em a
  i._x = 10;
  cout << a._x << endl;

  return 0;
}
