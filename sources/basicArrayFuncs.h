#include <iostream>
using namespace std;

void print1D(int a[], int size, char delimiter = ' ')
{
    for (int i = 0; i < size - 1; i++)
    {
        cout << a[i] << delimiter;
    }
    cout << a[size - 1];
}

void print2D(int **a, int row, int col, char delimiter = ' ')
{
    for (int i = 0; i < row - 1; i++)
    {
        print1D(a[i], col, delimiter);
        cout << endl;
    }
    print1D(a[row - 1], col, delimiter);
}

void copy1D(int a[], int b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        b[i] = a[i];
    }
}

int **init2D(int row, int col)
{
    int **res = new int *[row];
    for (int i = 0; i < row; i++)
    {
        res[i] = new int[col];
    }
    return res;
}

template <typename T, size_t N, size_t M>
T **convertTo2DPointer(T (&array)[N][M])
{
    T **ptr = new T *[N];
    for (size_t i = 0; i < N; i++)
    {
        ptr[i] = array[i];
    }
    return ptr;
}

int *convert2DTo1D(int **a, int row, int col)
{
    int *res = new int[row * col];
    for (int i = 0; i < row * col; i++)
    {
        res[i] = a[i / row][i % col];
    }
    return res;
}