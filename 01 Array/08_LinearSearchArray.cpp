#include<bits/stdc++.h>
using namespace std;

int linrSrch(vector<int>& arr, int target)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == target) return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {3, 5, 1, 9, 100, 10};
    int target = 3;

    int trgti;
    trgti = linrSrch(arr, target);

    cout << "Index is " << trgti;

    return 0;
}