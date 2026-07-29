#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(n)
vector<int> bruteForce(vector<int>& arr)
{
    vector<int> ans;

    for(int i = 0; i < arr.size(); i++)
    {
        bool leader = true;
        for(int j = i; j < arr.size(); j++)
        {
            if(arr[i] < arr[j])
            {
                leader = false;
                break;
            }
        }
        if(leader)
        ans.emplace_back(arr[i]);
    }

    return ans;
}

//Optimal Sol
//TC -> O(n) -> O(2n), if we want to maintain the original order, using reverse 
//SC -> O(n)
//Tell the interviewer, we're not using extra space to solve the problem, but to return the answer
vector<int> optimalSol(vector<int>& arr)
{
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = arr.size()-1; i >=0; i--)
    {
        if(arr[i] > maxi){
            ans.emplace_back(arr[i]);
            maxi = arr[i];
        }

    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 5, 3, 1, 2};
    vector<int> ans;

    ans = optimalSol(arr);

    for(auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}