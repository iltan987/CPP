#include<iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int medium = (low + high) / 2;
        if (arr[medium] == x)
        {
            return medium;
        }
        
        if (x > arr[medium])
        {
            low = medium + 1;
        }
        else if (x < arr[medium])
        {
            high = medium - 1;
        }
    }

    return -1;
}

int binarySearchRecursive(int arr[], int n, int x, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    
    int medium = (low + high) / 2;
    if (arr[medium] == x)
    {
        return medium;
    }
    
    if (x > arr[medium])
    {
        return binarySearchRecursive(arr, n, x, medium + 1, high);
    }
    else
    {
        return binarySearchRecursive(arr, n, x, low, medium - 1);
    }
}

int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9};

    cout << "---Original Array---" << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }

    int aradigimDeger = 5;

    cout << endl << "Result1 is: ";
    int result1 = binarySearchIterative(arr, sizeof(arr) / sizeof(arr[0]), aradigimDeger);
    cout << result1;


    cout << endl << "Result2 is: ";
    int result2 = binarySearchRecursive(arr, sizeof(arr) / sizeof(arr[0]), aradigimDeger, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
    cout << result2;
    return 0;
}