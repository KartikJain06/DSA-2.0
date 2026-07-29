#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
vector<int> bruteForce(vector<int>& nums)
{
    int repeating = -1;
    int missing = -1;

    for(int i = 1; i <= nums.size(); i++)
    {
        int cnt = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] == i) cnt++;
        }

        if(cnt == 2) repeating = i;
        else if(cnt == 0) missing = i;

        if(repeating != -1 && missing != -1) break;
    }

    return {repeating, missing};
}

//Better Approach
//TC -> O(2n)
//SC -> O(n)
vector<int> betterSol(vector<int>& nums)
{
    int n = nums.size();
    vector<int> hash(n+1, 0);
    int repeating = -1;
    int missing = -1;

    for(auto it : nums)
    {
        hash[it]++;
    }

    for(int i = 1; i <= nums.size(); i++)
    {
        if(hash[i] == 2) repeating = i;
        else if(hash[i] == 0) missing = i;

        if(repeating != -1 && missing != -1) break;
    }

    return {repeating, missing};
}

//Optimal Solution
//TC -> O(n)
//SC -> O(1)
vector<int> optimalSol(vector<int>& nums)
{
    long long n = nums.size();

    long long SN = (n * (n+1)) / 2; //Sum of n numbers
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6; //Sum of square of n numbers

    long long S = 0; //Sum of elements of given array
    long long S2 = 0; //Sum of square of elements of given array

    for(int i = 0; i < n; i++)
    {
        S += nums[i];
        S2 += (long long)nums[i] * (long long)nums[i];
    }

    //x-y = S - Sn............eqn[1]
    long long val1 = S - SN; 
    //(x-y)(x+y) = S2 - S2n => x + y = (S2 - S2n)/(x-y)............eqn[2]
    long long val2 = S2 - S2N;       // from eqn[1]
    val2 = val2 / val1;

    long long x = (val1 + val2) / 2; //(x - y) + (x + y) = Some Number => 2x = Some Number => x = Some Number/2; repeating number
    long long y = val2 - x; //Substituting value of x in eqn[2] getting value of y; which is missing number

    return {(int)x, (int)y};

}

int main()
{
    vector<int> nums = {1, 2, 3, 6, 7, 5, 7};

    vector<int> ans;

    ans = optimalSol(nums);

    cout << "[" << ans[0] << ", " << ans[1] << "]";

    return 0;
}