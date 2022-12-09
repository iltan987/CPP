#include<iostream>
using namespace std;

int main(void)
{
    int arr[] = {9,1,8,2,7,3,6,4,5};

    bool islemYaptimMi = true;
    int minus = 1;
    while (islemYaptimMi)
    {
        islemYaptimMi = false;
        for (int i = 0; i < 9 - minus; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                islemYaptimMi = true;
            }
            
        }
        minus++;
    }

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}