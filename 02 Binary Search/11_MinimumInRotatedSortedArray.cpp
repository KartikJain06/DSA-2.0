#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC -> O(n)
//SC -> O(1)
int bruteForce(vector<int>& arr)
{
    int n = arr.size();
    int minNum = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        minNum = min(minNum, arr[i]);
    }

    return minNum;
}

//Optima Sol
//TC -> O()
//SC -> O()
int findMin(vector<int>& arr)
{
    int n = arr.size();
    int minNum = arr[0];

    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        //Search space is already sorted
        //then arr[low] will always be lower in that search space
        if(arr[low] <= arr[high])
        {   
            minNum = min(minNum, arr[low]);
            break;
        }

        //Left/Right is Sorted
        if(arr[low] <= arr[mid]){
            minNum = min(minNum, arr[low]);
            low = mid + 1;
        }else{
            minNum = min(minNum, arr[mid]);
            high = mid - 1;
        }
    }

    return minNum;

}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 4, 5, 6};
    
    cout << findMin(arr);

    return 0;
}