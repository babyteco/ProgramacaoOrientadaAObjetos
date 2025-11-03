#include <iostream>
#include <cstdio>
#include <cstring>   // para memcpy
#include <stdexcept> // para std::bad_alloc

using namespace std;

class IntVector
{
public:
  // Construtor padrão
  IntVector()
  {
    cout << "Constructor" << endl;

    _alloc = 2;
    _size = 0;

    // aloca com new (inicializa com zero)
    _arr = new int[_alloc]();
  }

  // Construtor de cópia (cópia profunda)
  IntVector(const IntVector &other)
  {
    cout << "Copy constructor" << endl;

    _alloc = other._alloc;
    _size = other._size;

    _arr = new int[_alloc];
    memcpy(_arr, other._arr, _size * sizeof(int));
  }

  // Operador de atribuição (usa cópia profunda)
  IntVector &operator=(const IntVector &other)
  {
    cout << "Copy assignment" << endl;

    if (this == &other) // auto-atribuição
      return *this;

    // Libera memória antiga
    delete[] _arr;

    // Copia dados
    _alloc = other._alloc;
    _size = other._size;

    _arr = new int[_alloc];
    // memcpy(_arr, other._arr, _size * sizeof(int));
    for (int i = 0; i < _size; i++)
      _arr[i] = other._arr[i];

    return *this;
  }

  int size() const { return _size; }

  void add(int val)
  {
    if (_size >= _alloc)
    {
      // realoca manualmente
      int new_alloc = _alloc + 2;
      int *tmp = new int[new_alloc];

      // copia dados existentes
      memcpy(tmp, _arr, _size * sizeof(int));

      // libera a memória antiga
      delete[] _arr;

      _arr = tmp;
      _alloc = new_alloc;
    }

    _arr[_size++] = val;
  }

  int get(int idx) const
  {
    if (idx < 0 || idx >= _size)
    {
      printf("IntVector: Invalid index '%d'.\n", idx);
      exit(EXIT_FAILURE);
    }

    return _arr[idx];
  }

  void set(int idx, int val)
  {
    if (idx < 0 || idx >= _size)
    {
      printf("IntVector: Invalid index '%d'.\n", idx);
      exit(EXIT_FAILURE);
    }

    _arr[idx] = val;
  }

  ~IntVector()
  {
    cout << "Destructor" << endl;
    delete[] _arr;
  }

private:
  int *_arr;
  int _size;
  int _alloc;
};

void fn(IntVector w)
{
  cout << "Inside fn()" << endl;
}

int main()
{
  IntVector v;

  v.add(1);
  v.add(3);
  v.add(5);
  v.add(7);
  v.add(10);

  for (int i = 0; i < v.size(); i++)
    v.set(i, v.get(i) * 2);

  for (int i = 0; i < v.size(); i++)
    printf("%d\n", v.get(i));

  IntVector w = v; // chama construtor de cópia
  fn(v);           // também chama construtor de cópia

  w.set(0, 999);
  cout << "v[0] = " << v.get(0) << ", w[0] = " << w.get(0) << endl;

  return 0;
}