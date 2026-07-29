#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
int bruteForce(vector<int>& arr)
{
    int maxLen = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for(int j = i; j < arr.size(); j++)
        {
            sum += arr[j];

            if(sum == 0)
            {
                maxLen = max(maxLen, j-i+1);
            }
        }
    }

    return maxLen;
}

//Better Sol
//TC -> O(n)
//SC -> O(n)
int betterSol(vector<int>& arr)
{
    unordered_map<long long, int> hash;
    int maxi = 0;
    int sum = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if(sum == 0)
        {
            maxi = i+1;
        }
        else
        {
            if(hash.find(sum) != hash.end()){
                maxi = max(maxi, i-hash[sum]);
            }
            else{
                hash[sum] = i;
            }
        }

    }

    return maxi;
}

//Optimal Sol
//TC -> O(2n)
//SC -> O(1)
int optimalSol(vector<int>& arr)
{
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxleng = 0;
    int n = arr.size();

    while(right < n)
    {
        while(left <= right && sum > 0)
        {
            sum -= arr[left];
            left++;
        }
        if(sum == 0)
        {
            maxleng = max(maxleng, right-left+1);
        }
        right++;
        if(right < n)sum += arr[right];
    }

    return maxleng;
}


int main()
{
    vector<int> arr = {9, -3, 3, -1, 6, -5};

    int ans = betterSol(arr);

    cout << ans;

    return 0;
}