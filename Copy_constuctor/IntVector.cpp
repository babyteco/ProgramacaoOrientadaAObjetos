#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

//erro grave na main
class IntVector
{
public:
    IntVector()
    {
        cout << "Constructor" << endl;

        _alloc = 2;
        _size = 0;
        _arr = (int *) calloc(_alloc, sizeof(int));
    }

    int size() { return _size; }

    void add(int val)
    {
        if (_size >= _alloc)
        {
            _alloc += 2;
            _arr = (int *) realloc(_arr, _alloc * sizeof(int));
        }

        _arr[_size] = val;
        _size++;
    }

    int get(int idx)
    {
        if (idx < _size)
            return _arr[idx];

        exit(printf("IntVector: Invalid index '%d'.\n", idx));
    }

    void set(int idx, int val)
    {
        if (idx < _size)
            _arr[idx] = val;
        else
            exit(printf("IntVector: Invalid index '%d'.\n", idx));
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

int main() {
    // construtor default invocado
    IntVector v;

    v.add(1);
    v.add(3);
    v.add(5);
    v.add(7);
    v.add(10);

    for (int i = 0; i < v.size(); i++)
        v.set(i, v.get(i) * 2);

    // Construtor de copia (shallow) chamado ao usar o
    // objeto como entrada para a funcao. Ao final da funcao,
    // o destrutor é chamado. Como a cópia local (detro de fn)
    // e v compartilham o mesmo ponteiro, o array de v também é liberaado.
    fn(v);

    // Ao usar o método get, vai acontecer uma tentativa de acesso
    // a uma posicao que ja foi liberada com free resultando em erro
    for (int i = 0; i < v.size(); i++)
        printf("%d\n", v.get(i));

    // Construtor de copia invocado
    IntVector w = v;

    // construtor default invocado
    IntVector u;

    // Operator= invocado. Valor de u._arr é substituido por v._arr
    // tornando impossivel liberar u._arr (memory leak).
    u = v;

    // destrutor de v invocado (double free porque já foi liberado em fn)
    // destrutor de w invocado (double free porque o destrutor de v já foi invocado)
    // destrutor de u invocado (double free porque o destrutor de v já foi invocado)

    return 0;
}