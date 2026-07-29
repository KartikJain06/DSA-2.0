#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(2n)
//SC -> O(n)
optional<vector<int>> bruteForce(vector<int>& arr)
{
    int n = arr.size();

    vector<int> posArr;
    vector<int> negArr;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < 0)
        negArr.emplace_back(arr[i]);
        else
        posArr.emplace_back(arr[i]);
    }

    for(int i = 0; i < n/2; i++)
    {
        arr[2*i] = posArr[i];
        arr[2*i+1] = negArr[i];
    }

    return nullopt;
}

//Optimal Approach
//TC -> O(n)
//SC -> O(n)
vector<int> optimalSol(vector<int>& arr)
{
    int n = arr.size();
    vector<int> ans(n, 0);
    int posInd = 0;
    int negInd = 1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < 0)
        {
            ans[negInd] = arr[i];
            negInd += 2;
        }
        else
        {
            ans[posInd] = arr[i];
            posInd += 2;
        }
    }

    return ans;
}


int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};

    vector<int> ans;
    ans = optimalSol(arr);

    for(auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}