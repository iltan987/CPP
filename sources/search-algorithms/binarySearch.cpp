#include<iostream>
using namespace std;

int binarySearchIteration(int sortedArr[], int size, int x)
{
	int low=0, high=size-1;
	while (low<=high)
	{
		int mid=(low+high)/2;
		if (sortedArr[mid]==x)
		{
			return mid;
		}
		
		if (x<sortedArr[mid])
		{
			high=mid-1;
		}
		else if (x>sortedArr[mid])
		{
			low=mid+1;
		}
	}
	return -1;
}

int binarySearchRecursive(int sortedArr[], int n, int x, int low, int high)
{
	if (low > high)
	{
		return -1;
	}
	
	int mid = (low+high)/2;
	if (x==sortedArr[mid])
	{
		return mid;
	}
	if (x<sortedArr[mid])
	{
		return binarySearchRecursive(sortedArr, n, x, low, mid-1);
	}
	else
	{
		return binarySearchRecursive(sortedArr, n, x, mid+1, high);
	}
}

int main(void)
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 8;
	int result1 = binarySearchIteration(arr, n, x);
	int result2 = binarySearchRecursive(arr, n, x, 0, n-1);
    cout << result1 << result2;
	return 0;
}