#include<bits/stdc++.h>
using namespace std;

//Brute Force 
//TC -> O(n)
//SC -> O(1)
//Will apply Linear Search
int bruteForce(vector<int>& arr, int target)
{
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target) return i;
    }

    return -1;
}


//Optimal Sol
//TC -> O()
//SC -> O(1)
int optimalSol(vector<int>& arr, int target)
{
    int n = arr.size();
    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target) return mid;
        //Identify the Sorted Half, and check for the sorted portion first, if our target element lies in that half, if not, then switch back to unsorted half

        //Left Portion is Sorted
        else if(arr[low] <= arr[mid]){
            //If TRUE, check if "target" lies in this half
            if(arr[low] <= target && target <= arr[mid]) high = mid -1;
            else low = mid + 1; 
        }
        //Right Portion is Sorted
        else{
            if(arr[mid] <= target && target <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;

    cout << bruteForce(arr, target);

    return 0;
}