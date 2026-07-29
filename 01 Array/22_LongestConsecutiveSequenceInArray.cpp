#include<bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& arr, int n)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == n) return true;
    }

    return false;
}

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
int bruteForce(vector<int>& arr)
{
    int longest = 1;

    for(int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        int cnt = 1;

        while(linearSearch(arr, num+1) == true)
        {
            num++;
            cnt++;
        }

        longest = max(longest, cnt);
    }

    return longest;
}

//Better Sol
//TC -> O(n log n)
//SC -> O(1)
int betterSol(vector<int>& arr)
{
    if(arr.size() == 0) return 0;

    int lastSmaller = INT_MIN;
    int longest = 1;
    int crntCnt = 0;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] - 1 == lastSmaller)
        {
            lastSmaller = arr[i];
            crntCnt++;
        }
        else if(arr[i] != lastSmaller)
        {
            crntCnt = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, crntCnt);
    }    

    return longest;
}

//Optimal Sol
//TC -> O(n)
//SC -> O(n)
int optimalSol(vector<int>& arr)
{
    if(arr.size() == 0) return 0;
    int longest = 1;
    unordered_set<int> st;

    for(int i =0; i < arr.size(); i++)
    {
        st.insert(arr[i]);
    }

    int cnt = 1;

    for(auto it : st)
    {
        if(st.find(it -1) == st.end())
        {
            int curLength = 1;
            int num = it;
            while(st.find(num + 1) != st.end())
            {
                num++;
                curLength++;
            }
            longest = max(longest, curLength);
        }
    }

    return longest;
}

int main()
{
    vector<int> arr = {1,0,1,2};

    cout << betterSol(arr);
    return 0;
}