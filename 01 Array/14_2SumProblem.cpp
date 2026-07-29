#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
vector<int> bruteForce(vector<int>& a, int target)
{
    int n = a.size();

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int sum = a[i] + a[j];
            if(sum == target)
            {
                return {i, j};
            }
        }
    }
}

//Optimal Solution
//TC -> O(n x logn) -> if we take unordered map, it could be reduced to O(n x 1) but in worst case it could go upto O(n^2)
//SC -> O(n)
vector<int> optimalSol(vector<int>& nums, int target) 
{
    unordered_map<int, int> mpp;
    for(int i = 0; i < nums.size(); i++)
    {
        int remNeeded = target - nums[i];

        if(mpp.count(remNeeded))
        {
            return {mpp[remNeeded], i};
        }

        mpp[nums[i]] = i;
    }

    return {-1, -1};
}

int main()
{
    vector<int> a = {11, 1, 7, 9, 4};
    int target = 15;

    vector<int> ans;

    ans = optimalSol(a, target);

    for(auto it : ans)
    {
        cout << a[it] << " ";
    }

    return 0;
}