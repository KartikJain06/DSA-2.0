#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^2)
//TC -> O(1)
int bruteForce(vector<int>& arr)
{
    int maxProd = arr[0];

    for(int i = 0; i < arr.size(); i++)
    {
        int prod = 1;

        for(int j = i; j < arr.size(); j++)
        {
            prod *= arr[j];
            maxProd = max(maxProd, prod);
        }
    }

    return maxProd;
}

//Optimal Solution
//TC -> O(n)
//SC -> O(1)
int optimalSol(vector<int>& arr)
{
    int n = arr.size();

    int maxProd = INT_MIN;
    int pre = 1;
    int suf = 1;

    for(int i = 0; i < n; i++)
    {
        if(pre == 0) pre = 1;
        if(suf == 0) suf = 1;

        pre *= arr[i];
        suf *= arr[n-i-1];

        maxProd = max(maxProd, max(pre, suf));
    }

    return maxProd;
}

int main()
{
    vector<int> arr = {0, -2, 0, -1};

    int ans;

    ans = optimalSol(arr);

    cout << ans;

    return 0;
}