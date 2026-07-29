#include<bits/stdc++.h>
using namespace std;

int mergeAndCount(vector<int>& arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;

    for(int i = low; i <= mid; i++)
    {
        while(right <= high && (long long)arr[i] > (2LL * arr[right]))
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }

    // Merging Step of Normal Merger Sort
    vector<int> temp;

    int left = low;
    right = mid+1;

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.emplace_back(arr[left]);
            left++;
        }
        else
        {
            temp.emplace_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.emplace_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.emplace_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int>& arr, int low, int high)
{
    int n = arr.size();
    int cnt = 0;

    if(low >= high) return 0;

    int mid = (low + high) / 2;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += mergeAndCount(arr, low, mid, high);

    return cnt;
}

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
int bruteForce(vector<int>& arr)
{
    int n = arr.size();
    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] > (2 * arr[j])) cnt++;
        }
    }

    return cnt;
}

//Optimal Sol
//TC -> O(n logn)
//SC -> O(n)

//The mergeSort() function has a time complexity of O(n log n) because it divides the array into halves recursively and then merges them back together. The countPairs() function has a time complexity of O(n) because it iterates through the array once. Therefore, the overall time complexity of the optimalSol function is O(n log n)
int optimalSol(vector<int>& arr)
{
    int n = arr.size();

    return mergeSort(arr, 0, n-1);
}

int main()
{
    vector<int> arr = {1,3,2,3,1};

    int ans;

    ans = optimalSol(arr);

    cout << ans;
}