#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
int bruteForce(vector<int>& nums, int k)
{
    int cnt = 0;

    for(int i = 0 ; i < nums.size(); i++)
    {   
        int sum = 0;
        for(int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if(sum == k)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

//Optimal Sol
//TC -> O(n) -> if unorderder_map or O(b log n) if map
//SC -> O(n)
int optimalSOl(vector<int>& nums, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int cnt = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        preSum += nums[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;

    }

    return cnt;
}

int main()
{
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    
    int ans;

    ans = optimalSOl(nums, 3);

    cout << ans;

    return 0;   
}