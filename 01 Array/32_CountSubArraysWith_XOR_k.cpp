#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
int bruteForce(vector<int>& arr, int k)
{
    int cnt = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        int xoro = 0;
        for(int j = i; j < arr.size(); j++)
        {
            xoro ^= arr[j];

            if(xoro == k)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

//Optimal Sol
//TC -> O(n) or O(n log n) based on hashmap
//SC -> O(n)
int optimalSol(vector<int>& arr, int k)
{
    int cnt = 0;
    int xr = 0;
    unordered_map<int, int> hashset;
    hashset[xr]++;

    for(int i = 0; i < arr.size(); i++)
    {
        xr ^= arr[i];

        int y = xr ^ k;

        cnt += hashset[y];

        hashset[xr]++;

    }

    return cnt;
}


//Sol if the set of arrays itself are asked
//TC -> O(n^3)
//SC -> O(n^2)
vector<vector<int>> optimal(vector<int>& arr, int k)
{
    vector<vector<int>> ans;

    unordered_map<int, vector<int>> mpp;
    int xr = 0;
    int cnt = 0;
    mpp[0].emplace_back(-1);

    for(int i = 0; i < arr.size(); i++)
    {
        xr ^= arr[i];

        int x = xr^k;

        if(mpp.count(x))
        {
            for(int prev_ind : mpp[x])
            {
                vector<int> temp(arr.begin() + prev_ind + 1, arr.begin() + i + 1);
                ans.emplace_back(temp);
            }
        }

        mpp[xr].push_back(i);
    }

    return ans;

}


int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    vector<vector<int>> ans;

    ans = optimal(arr, k);

    for(auto i : ans)
    {
        for(auto it : i)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}