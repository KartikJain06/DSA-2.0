#include<bits/stdc++.h>
using namespace std;

/* The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

// The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array. */

int findLowerBound(vector<int>& arr, int target)
{
    int n = arr.size();
    int ans = n;

    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 13};

    // int target;
    // target = 2;

    // int ans;

    // ans = findLowerBound(arr, target);

    // cout << "Index is : " << ans;

    auto lb = lower_bound(arr.begin(), arr.end(), 10);

    cout << distance(arr.begin(), lb);


    return 0;
}