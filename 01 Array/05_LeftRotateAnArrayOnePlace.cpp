#include<bits/stdc++.h>
using namespace std;

//Optimal Solution
//TC -> O(n)
//SC -> O(1)
void rotateArray(vector<int>& arr)
{
    int n = arr.size();
    int temp = arr[0];

    for(int i = 1; i < n; i++)
    {
        arr[i-1] = arr[i];
    }

    arr[n-1] = temp;
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};

    rotateArray(arr);

    for(auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}