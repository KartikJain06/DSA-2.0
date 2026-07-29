#include<bits/stdc++.h>
#include <vector>
using namespace std;

// Brute Approach
//TC -> O(n log n)
//SC -> O(n)
int brutefindMAX(vector<int>& arr)
{
    sort(arr.begin(), arr.end());

    return arr[arr.size() - 1];
}

//Optimal Solution-1
//TC -> O(n)
//SC -> O(1)
int findMAXSol1(vector<int>& arr)
{
    int max = arr[0];
    int n = arr.size();

    for(int i = 0; i < n; i++)
        if(arr[i] > max) max = arr[i];

    return max;
}

// Optimal Solution-2
//TC -> O(n)
//SC -> O(log n), for using recursive stack
int findMAXSol2(vector<int>& arr, int start, int end)
{
    //For single element array
    if(start == end) return arr[start];

    //For 2 element array
    if(start + 1 == end) return (arr[start] > arr[end]) ? arr[start] : arr[end];

    //Recursive Approach for long lists
    int mid = start + (end-start)/2;
    int left = findMAXSol2(arr, start, mid);
    int right = findMAXSol2(arr, mid+1, end);

    return (left > right) ? left : right;
}

int main()
{
    vector<int> arr = {80, 12, 30, 22, 89};
    int n = arr.size();

    int result = findMAXSol2(arr, 0, n-1);

    cout << result;


    return 0;
}