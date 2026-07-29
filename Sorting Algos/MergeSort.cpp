#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> sorted;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high)
    {
        if(arr[left] < arr[right])
        {
            sorted.emplace_back(arr[left]);
            left++;
        }

        else
        {
            sorted.emplace_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        sorted.emplace_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        sorted.emplace_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++)
    {
        arr[i] = sorted[i-low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if(low == high)
    return;

    int mid = (low + high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);

    
}

int main()
{
    vector<int> arr = {3, 78, 1, 65, 91, 2, 3, 18, 1};

    int n = arr.size();

    mergeSort(arr, 0, n-1);

    for(auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}