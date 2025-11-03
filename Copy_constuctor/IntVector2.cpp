#include <iostream>
#include <cstdlib>
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

    _arr = (int *)calloc(_alloc, sizeof(int));
  }

  // Construtor de cópia (copia profunda)
  IntVector(const IntVector &other)
  {
    cout << "Copy constructor" << endl;

    _alloc = other._alloc;
    _size = other._size;

    // copia rasa
    _arr = other._arr;

    // copia profunda
    _arr = (int *)calloc(_alloc, sizeof(int));
    memcpy(_arr, other._arr, _size * sizeof(int));
    // alternativa:
    // for (int i = 0; i < _size; i++)
    //   _arr[i] = other._arr[i];

  }

  // Operador de atribuição (usa cópia profunda)
  IntVector &operator=(const IntVector &other)
  {
    cout << "Copy assignment" << endl;

    if (this == &other) // auto-atribuição: v = v;
      return *this;

    // Libera memória antiga
    free(_arr);

    // Copia dados
    _alloc = other._alloc;
    _size = other._size;

    _arr = (int *)calloc(_alloc, sizeof(int));
    memcpy(_arr, other._arr, _size * sizeof(int));

    return *this;
  }

  int size() const { return _size; }

  void add(int val)
  {
    if (_size >= _alloc)
    {
      _alloc += 2;
      int *tmp = (int *)realloc(_arr, _alloc * sizeof(int));
      if (!tmp)
        throw bad_alloc();
      _arr = tmp;
    }

    _arr[_size++] = val;
  }

  int get(int idx) const
  {
    if (idx < 0 || idx >= _size)
      exit(printf("IntVector: Invalid index '%d'.\n", idx));

    return _arr[idx];
  }

  void set(int idx, int val)
  {
    if (idx < 0 || idx >= _size)
      exit(printf("IntVector: Invalid index '%d'.\n", idx));

    _arr[idx] = val;
  }

  ~IntVector()
  {
    cout << "Destructor" << endl;
    free(_arr);
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