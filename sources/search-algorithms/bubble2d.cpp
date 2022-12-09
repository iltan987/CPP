#include <iostream>
using namespace std;

void display1d(int *arr, int *size);
void display2d(int **arr, int *rowSize, int *colSize);
int *convert2dTo1d(int **arr, int *rowSize, int *colSize);
int **convert1dTo2d(int *arr, int *rowSize, int *colSize);
void swap(int *a, int *b);
void bubbleSort(int arr[], int *size);

int main(void)
{
    cout << "Please enter row size: ";
    int rowSize;
    cin >> rowSize;
    cout << "Please enter column size: ";
    int colSize;
    cin >> colSize;

    int **arr = new int *[rowSize];

    for (int r = 0; r < rowSize; r++)
    {
        arr[r] = new int[colSize];
        for (int c = 0; c < colSize; c++)
        {
            cout << "Please enter row " << r + 1 << ", column " << c + 1 << ": ";
            cin >> arr[r][c];
        }
    }

    cout << endl
         << endl; // For better look...

    cout << "---Original 2D Array---" << endl;
    display2d(arr, &rowSize, &colSize);

    cout << endl
         << endl; // For better look...

    int *arr1D = convert2dTo1d(arr, &rowSize, &colSize);

    cout << "--- 2D Array Converted To 1D Array---" << endl;
    int size = rowSize * colSize;
    display1d(arr1D, &size);

    cout << endl
         << endl; // For better look...

    bubbleSort(arr1D, &size);

    cout << "Sorted 1D Array---" << endl;
    display1d(arr1D, &size);

    cout << endl
         << endl; // For better look...

    int **arrLast = convert1dTo2d(arr1D, &rowSize, &colSize);

    cout << "Sorted 1D Array Converted Back To 2D Array---" << endl;
    display2d(arrLast, &rowSize, &colSize);

    cout << endl
         << "Finished";
    return 0;
}

void display1d(int *arr, int *size)
{
    for (int i = 0; i < *size; i++)
    {
        cout << arr[i] << " ";
    }
}
void display2d(int **arr, int *rowSize, int *colSize)
{
    for (int r = 0; r < *rowSize; r++)
    {
        if (r != 0)
        {
            cout << endl;
        }
        for (int c = 0; c < *colSize; c++)
        {
            cout << arr[r][c] << " ";
        }
    }
}
int *convert2dTo1d(int **arr, int *rowSize, int *colSize)
{
    int *arr2 = new int[*rowSize * *colSize], counter = 0;

    for (int r = 0; r < *rowSize; r++)
    {
        for (int c = 0; c < *colSize; c++)
        {
            arr2[counter++] = arr[r][c];
        }
    }

    return arr2;
}
int **convert1dTo2d(int *arr, int *rowSize, int *colSize)
{
    int **arr2 = new int *[*rowSize];
    int counter = 0;
    for (int r = 0; r < *rowSize; r++)
    {
        arr2[r] = new int[*colSize];
        for (int c = 0; c < *colSize; c++)
        {
            arr2[r][c] = arr[counter++];
        }
    }
    return arr2;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int *size)
{
    bool flag = 1;
    int minus = 1;

    while (flag == 1)
    {
        flag = 0;
        for (int i = 0; i < *size - minus; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                flag = 1;
                swap(arr[i], arr[i + 1]);
            }
        }
        minus++;
    }
}