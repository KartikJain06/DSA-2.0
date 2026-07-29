#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
int findMissing(vector<int>& arr, int n)
{   
    int ans;
    for(int i = 0; i <= n; i++)
    {
        int flag = 0;
        for(int j = 0; j < n; j++)
        {
            if(i == arr[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        return i;
    }
}

//Better Approach, we use hashing in this
//TC -> O(2n)
//SC -> O(n)
int betterApproach(vector<int>& arr, int n)
{
    vector<int> hash(n+1, 0);

    for(int i = 0; i < n; i++)
    {
        hash[arr[i]] = 1;
    }

    for(int i = 0; i < n+1; i++)
    {
        if(hash[i] == 0)
        return i;
    }
}

//Optimal Approach 1
//TC -> O(n)
//SC -> O(1)
int optimalSol(vector<int>& arr, int n)
{
    int sum;
    sum = n*(n+1)/2;

    int s2 = 0;
    for(int i = 0; i < n; i++)
    {
        s2 += arr[i];
    }
    //OR instead of using loop to calc s2 use func like
    // s2 = accumulate(nums.begin(), nums.end(), 0);

    return sum - s2;
}

//Approach using XOR
//TC -> O(n)
//SC -> O(1)
int xorApproach(vector<int>& arr, int n)
{
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ (i);
        xor2 = xor2 ^ arr[i];
    }
    xor1 = xor1^n;
    return xor1^xor2;
}


int main()
{
    vector<int> arr = {3, 2, 4, 0, 1, 5, 6};
    int n = arr.size();

    int ans;
    ans = xorApproach(arr, n);

    cout << ans;
    return 0;
}