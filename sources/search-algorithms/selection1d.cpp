#include <iostream>
using namespace std;

int findMinimumIndex(int *arr, int size, int startingFrom)
{
    int index = startingFrom;
    for (int i = startingFrom + 1; i < size; i++)
    {
        if (arr[i] < arr[index])
        {
            index = i;
        }
    }
    return index;
}

int main(void)
{
    cout << "Please enter size of array: ";
    int size;
    cin >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Please enter " << i + 1 << ". value: ";
        cin >> arr[i];
    }

    for (int i = 0; i < size - 1; i++)
    {
        int minimum = findMinimumIndex(arr, size, i);
        if (minimum != i)
        {
            int temp = arr[i];
            arr[i] = arr[minimum];
            arr[minimum] = temp;
        }
    }

    cout << endl
         << "Result:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}