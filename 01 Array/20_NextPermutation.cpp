#include<bits/stdc++.h>
using namespace std;

//Optimal Sol
//TC -> O(3n)
//SC -> O(1)
void nextPermutation(vector<int>& arr)
{
    int n = arr.size();
    int i = n - 2;

    while(i >= 0 and arr[i] >= arr[i+1]){
        i--;
    }

    if(i >= 0)
    {
        int j = arr.size() - 1;
        while(arr[j] <= arr[i]){
            j--;
        }

        swap(arr[i], arr[j]);
    }

    reverse(arr.begin() + i + 1, arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3};

    nextPermutation(arr);

    for(auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}