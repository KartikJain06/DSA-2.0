#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int n = nums.size();
    int ans = n;

    int low = 0;
    int high = n-1;

    while(low <= high)
    {   
        int mid = (low + high) / 2;

        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    
    return ans;
}   

int main()
{
    vector<int> nums = {1,3,5,7};

    int ans = searchInsert(nums, 6);

    cout << ans;

    return 0;
}