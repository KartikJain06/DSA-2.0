#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
//In any array the maximum majority elements can only be 2
vector<int> bruteForce(vector<int>& arr)
{
    vector<int> ans;

    for(int i = 0; i < arr.size(); i++)
    {
        if(ans.size() == 0 or ans[0] != arr[i])
        {
            int cnt = 0;
            for(int j = 0; j < arr.size(); j++)
            {
                if(arr[i] == arr[j])
                cnt++;
            }
            if(cnt > (arr.size()/3))
            ans.emplace_back(arr[i]);
        }

        if(ans.size() == 2) break;
    }
    return ans;
}

//Better Sol
//TC -> O(n) for unordered_map best and average case O(n) for worst O(n^2) -> if used map TC -> O(n log n)
//SC -> O(n)
vector<int> betterSol(vector<int>& arr)
{
    unordered_map<int, int> mpp;
    vector<int> ans;

    for(auto it : arr)
    {   
        mpp[it]++;

        if(mpp[it] > (arr.size()/3)) ans.emplace_back(it);

        if(ans.size() == 2) break;
    }

    return ans;
}

//Optimal Sol
//TC -> O(n)
//SC -> O(1)
vector<int> optimalSol(vector<int>& arr)
{
    int cnt1 = 0;
    int cnt2  = 0;
    int ele1 = NULL;
    int ele2 = NULL;

    for(int i = 0; i < arr.size(); i++)
    {
        if(cnt1 == 0 and arr[i] != ele2){
            ele1 = arr[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 and arr[i] != ele1){
            ele2 = arr[i];
            cnt2 = 1;
        }
        else if(arr[i] == ele1) cnt1++;
        else if(arr[i] == ele2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ans;
    cnt1 = 0;
    cnt2 = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(ele1 == arr[i]) cnt1++;
        else if(ele2 == arr[i]) cnt2++;
    }

    int mini = (int) arr.size()/3 + 1;

    if(cnt1 >= mini) ans.push_back(ele1);
    if(cnt2 >= mini) ans.push_back(ele2);

    return ans;
}


int main()
{
    vector<int> arr = {3,2,3};

    vector<int> ans;
    ans = optimalSol(arr);

    for(auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}