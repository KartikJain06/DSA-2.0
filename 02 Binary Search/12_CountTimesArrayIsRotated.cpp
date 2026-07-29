#include<bits/stdc++.h>
using namespace std;

// int bruteForce(vector<int>& arr)
// {

// }

//Optimal Sol
//TC -> O(log n)
//SC -> O(1)
int rotationCount(vector<int>& arr)
{
    int n = arr.size();
    int index = -1;
    int minNum = INT_MAX;

    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[low] <= arr[high]){
            if(arr[low] < minNum){
                index = low;
                minNum = arr[low];
            }
            break;
        }

        if(arr[low] <= arr[mid]){
            low = mid + 1;
            if(arr[low] < minNum){
                index = low;
                minNum = arr[low];
            }
        }else{
            high = mid - 1;
            if(arr[mid] < minNum){
                index = mid;
                minNum = arr[mid];
            }
        }
    }

    return index;
}

int main()
{
    vector<int> arr = {3,4,5,1,2};

    cout << rotationCount(arr);

    return 0;
}