#include<bits/stdc++.h>
using namespace std;

void sort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }
}

int main()
{
    int arr[] = {2, 8, 19, 38, 91, 1, 15, 56};

    int n = sizeof(arr)/ sizeof(arr[0]);

    sort(arr, n);
    printArray(arr, n);
}

