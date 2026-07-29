#include<bits/stdc++.h>
#include<optional>
using namespace std;

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
optional<int> bruteForce(vector<int>& arr)
{
    int ans;
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[j] == arr[i])
            {
                cnt++;
            }
        }
        if(cnt > n/2)
        return arr[i];
    }

    return std::nullopt;
}

//Better Soln
//TC -> O(n)
//SC -> O(n)
optional<int> betterSol(vector<int> & arr)
{
    unordered_map<int, int> mpp;

    int n = arr.size();

    for(auto it : arr)
    {
        mpp[it]++;
    }

    for(auto it : mpp)
    {
        if(it.second > n/2)
        return it.first;
    }

    return nullopt;
}

//optimal Soln
//TC -> O(n)
//SC -> O(1)
optional<int> optimalSol(vector<int>& arr)
{
    int n = arr.size();
    int ele;
    int cnt = 0;

    //In this for loop we used Moore's Voting Algo  
    for(int i = 0; i < n; i++)   
    {            
        if(cnt == 0)                     
        {
            cnt = 1;
            ele = arr[i];
        }
        else if(arr[i] == ele)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    int check = 0;
    for(auto it : arr)
    {
        if(it == ele)
        check++;
    }

    return (check > n/2) ? make_optional(ele) :nullopt;
}

int main()
{
    vector<int> arr = {2, 2, 3, 3, 1, 2, 1, 1, 1, 1};
    auto ans = optimalSol(arr);

    if(ans.has_value())
    cout << "Majority Element : " << ans.value();
    else
    cout << "No Majority Elements";
    return 0;
}