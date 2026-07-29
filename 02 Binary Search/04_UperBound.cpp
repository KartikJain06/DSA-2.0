#include<bits/stdc++.h>
using namespace std;

/* The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.

// But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array. The main difference between the lower and upper bound is in the condition. For the lower bound the condition was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x. */

int findUB(vector<int>& arr, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n-1;

    int ans = n;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){

    vector<int> arr = {1, 3, 6, 7, 8, 8, 10, 10, 10, 13};

    int ans = findUB(arr, 10);

    cout << arr[ans];

    return 0;
}