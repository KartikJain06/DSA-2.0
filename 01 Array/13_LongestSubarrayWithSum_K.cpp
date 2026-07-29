#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
int bruteForce(vector<int>& arr, int d)
{
    int n = arr.size();
    int len = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];

            if(sum == d)
            len = max(len, j-i+1);
        }
    }
    return len;
}

//Better Sol
//TC -> O(n log n) -> if we use unordered map then it could be O(N) but in worst case, cuz of collisions, it could go upto O(n^2)
//SC -> O(n)
//This approach is the optimal ne if the array has negatives, zeros and positives
int betterSol(vector<int>& arr, int d)
{
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxlen  = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if(sum == d)
        {
            maxlen = max(maxlen, i+1);
        }
        int rem = sum - d;
        if(preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxlen = max(maxlen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxlen;
}

//this is the optimal one, if array containes only +ves and 0s, and not -ves
//Optimal Sol
//TC -> O(2n)
//SC -> O(1)
int optimalSol(vector<int>& arr, int d)
{
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxleng = 0;
    int n = arr.size();

    while(right < n)
    {
        while(left <= right && sum > d)
        {
            sum -= arr[left];
            left++;
        }
        if(sum == d)
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
    vector<int> arr = {2, 1, 3, 2, 1, 1, 1, 1, 2, 3};
    int ans;

    ans = optimalSol(arr, 3);

    cout << ans;

    return 0;
}