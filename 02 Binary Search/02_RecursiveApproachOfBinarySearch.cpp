#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> & arr, int low, int high, int target)
{
    if(low > high) return -1;
    int mid = (low+high)/2;

    if(arr[mid] == target) return mid;
    else if(target > arr[mid]) return binarySearch(arr, mid+1, high, target);
    else return binarySearch(arr, low, mid-1, target);
}   



int findElem(vector<int>& arr, int target)
{
    int ans;
    int n = arr.size();

    int low = 0;
    int high = n-1;

    ans = binarySearch(arr, low, high, target);

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 7, 9, 11, 13, 15, 16, 17};

    int ans;
    int target = 15;

    ans = findElem(arr, target);

    cout << "Your index to find the target element is " << ans << " and let's check it out with arr[ans] : " << arr[ans];

    return 0;
}