#include<bits/stdc++.h>
using namespace std;

//TC -> O(log n) for best and average case O(n/2) for worst case
//SC -> O(1)
bool sol1(vector<int>& arr, int target)
{
    int n = arr.size();

    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target) return true;

        //For the edge case
        // arr = [3, 1, 2, 3, 3, 3, 3];
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }

        //Left Half is Sorted
        else if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]) high = mid - 1;
            else low = mid + 1;
        }
        //Right Half is Sorted
        else{
            if(arr[mid] <= target && target <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }

    return false;
}

int main()
{
    vector<int> arr = {2,5,6,0,0,1,2};
    int target = 0;
    
    std::cout.setf(std::ios::boolalpha);
    cout << sol1(arr, target) << endl;
    

    return 0;
}