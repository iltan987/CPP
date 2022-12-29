#include <iostream>
#include "../basicArrayFuncs.h"
using namespace std;

void copy(int[], int[], int, int);

int *insert(int[], int, int);

int *deletion(int[], int, int);

int main()
{
    int *a = new int[4];
    int *b = new int[2];
    int size = 4;
    a[0] = 10;
    a[1] = 20;
    b[0] = 30;
    b[1] = 40;
    cout << "a before copy: ";
    print1D(a, size);
    cout << endl
         << "b before copy: ";
    print1D(b, 2);
    cout << endl;
    copy(b, a, 2, 2);
    delete b;
    cout << "Original: ";
    print1D(a, size);
    int *insertedA = insert(a, size, 25);
    cout << endl
         << "Result after insertion 25: ";
    print1D(insertedA, size + 1);

    int *deletedA = deletion(insertedA, size + 1, 30);
    cout << endl
         << "Result after deletion 30: ";
    print1D(deletedA, size);
    return 0;
}

void copy(int from[], int to[], int begin, int size)
{
    for (int i = begin; i < begin + size; i++)
    {
        to[i] = from[i - begin];
    }
}

int *insert(int a[], int size, int newn)
{
    int *res = new int[size + 1];
    bool inserted = false;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < newn)
        {
            res[i] = a[i];
        }
        else if (a[i] > newn)
        {
            if (!inserted)
            {
                res[i] = newn;
            }
            res[i + 1] = a[i];
            inserted = true;
        }
    }
    return res;
}

int *deletion(int a[], int size, int oldN)
{
    int *res = new int[size - 1];
    for (int i = 0; i < size; i++)
    {
        if (a[i] < oldN)
        {
            res[i] = a[i];
        }
        else if (a[i] > oldN)
        {
            res[i - 1] = a[i];
        }
    }
    return res;
}