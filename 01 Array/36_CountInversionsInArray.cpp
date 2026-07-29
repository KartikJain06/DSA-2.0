#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = mid+1;

    int cnt = 0;

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.emplace_back(arr[left]);
            left++;
        }
        else
        {
            temp.emplace_back(arr[right]);
            cnt += (mid-left+1);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.emplace_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.emplace_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int>& arr, int low, int high)
{
    int cnt = 0;
    if(low == high) return cnt;

    int mid = (low + high) / 2;


    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += merge(arr, low, mid, high);

    return cnt;
}

//Brute Force Approach
//TC -> O(n^2)
//SC -> O(1)
long long int bruteForce(vector<int>& nums)
{
    long long ans = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i+1; j < nums.size(); j++)
        {
            if(nums[i] > nums[j])
            ans++;
        }
    }

    return ans;
}

//Optimal Sol
//TC -> O(nlogn)
//SC -> O(n)
//We'll use Merge Sort here
long long int optimalSol(vector<int>& arr)
{
    int n = arr.size();
    int cnt;

    cnt = mergeSort(arr, 0, n-1);

    return cnt;
}


int main()
{
    vector<int> nums = {2, 3, 7, 1, 3, 5};

    long long int ans;

    ans = optimalSol(nums);

    cout << ans;

    return 0;
}