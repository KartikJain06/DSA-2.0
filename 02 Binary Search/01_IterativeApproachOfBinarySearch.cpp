#include<bits/stdc++.h>
using namespace std;

int findElem(vector<int>& arr, int target)
{
    int ans;

    int n = arr.size();

    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = (low + high)/2;

        if(arr[mid] == target) return mid;
        else if(target > arr[mid]) low = mid+1;
        else high = mid-1;
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 7, 9, 11, 13, 15, 16, 17};

    int ans;
    int target = 15;

    ans = findElem(arr, target);

    cout << "You'll find the no. " << target << " at index " << ans << endl;

    cout << "To find out, Let's check it out : " << arr[ans];


    return 0;
}