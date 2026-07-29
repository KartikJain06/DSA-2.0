#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n logn) + O(2n)
//SC -> O(n)
vector<vector<int>> bruteForce(vector<vector<int>>& arr)
{
    vector<vector<int>> ans;


    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        if(!ans.empty() && end <= ans.back()[1]) continue; 

        for(int j = i+1; j < arr.size(); j++)
        {
            if(arr[j][0] <= end)
            end = max(end, arr[j][1]);
            else
            break;
        }

        ans.push_back({start, end});

    }

    return ans;
}

//Optimised
//TC -> O(n logn) + O(n)
//SC -> O(n)
vector<vector<int>> optimised(vector<vector<int>>& arr)
{
    vector<vector<int>> ans;


    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++)
    {
        if(ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }

    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {15, 18}, {16, 17}};

    vector<vector<int>> ans;

    ans = optimised(arr);

    for(auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }

    return 0;
}