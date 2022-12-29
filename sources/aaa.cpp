#include <iostream>
using namespace std;
int lin_search(int[], int, int);
int bin_search(int[], int, int);

int main(void)
{
    int a[16] = {3, 6, 23, 35, 42, 88, 155, 434, 570, 678, 732, 755, 812, 834, 900, 945};
    int key, perflin, perfbin;
    cout << "Please enter the search key:";
    cin >> key;
    perflin = lin_search(a, 16, key);
    perfbin = bin_search(a, 16, key);

    if (perflin == -1)
        cout << "\nNot found...";
    else if (perflin < perfbin)
        cout << "\nLinear search algorithm performed better with " << perflin << " iteration(s).." << endl;
    else if (perflin > perfbin)
        cout << "\nBinary search algorithm perfromed better with " << perfbin << " iteration(s).." << endl;
    else
        cout << "\nBoth algorithms performed well.." << endl;
    return 0;
}

int lin_search(int a[], int size, int key)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (a[i] == key)
            return i + 1;
    }
    return -1;
}

int bin_search(int a[], int size, int key)
{
    int low, high, middle, cnt = 0;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        cnt++;
        if (a[middle] == key)
            return cnt;
        else if (a[middle] < key)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}