#include<bits/stdc++.h>
using namespace std;

//Brute Force Solution
//TC -> O(n)
//SC -> O(1)
vector<int> bruteForce(vector<int>& arr, int target)
{
    int n = arr.size();
    int first = -1, last = -1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            if(first == -1) first = i;
            last  = i;
        }
    }

    return {first, last};
}

//Optimal Solution with BS
//TC -> 2 x O(log n)
//SC -> O(1)
class searcRange{
    int floorValue(vector<int>& nums, int target)
    {
        int n = nums.size();

        int floorInd = -1;

        int low = 0, high = n - 1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(nums[mid] <= target){
                floorInd = mid;
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }

        return floorInd;
    }

    public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();

        int low = 0, high = n -1;

        int startInd = -1;
        int endInd = -1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(nums[mid] >= target){
                startInd = mid;
                high = mid - 1;
            }else{
                low =  mid + 1;
            }

        }
        if(startInd == -1 || startInd >= n || nums[startInd] != target)
        {
            return {-1, -1};
        }

        return {startInd, floorValue(nums, target)};
    }
};

//Optimal Solution 2 if we're not allowed to use lower bound or upper bound or floor or ceil
//TC -> 2 x O(log n)
//SC -> O(1 )
vector<int> optimalSol(vector<int>& arr, int target)
{
    int n = arr.size();

    int low = 0, high = n-1;

    int first = -1;
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target){
            first = mid;
            high = mid-1;
        }else if(arr[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    if(first == -1) return {-1, -1};

    low = 0;
    high = n-1;
    int last = -1;
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target){
            last = mid;
            low = mid + 1;
        }else if(arr[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return {first, last};
}

int main()
{
    vector<int> nums = {5,5,6,6,7,7,9,10};

    int target = 7;
    searcRange obj;
    vector<int> ans = optimalSol(nums, target);

    cout << "From Index " <<  ans[0] << " to Index " << ans[1];

    return 0;
}