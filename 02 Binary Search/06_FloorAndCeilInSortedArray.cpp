#include<bits/stdc++.h>
using namespace std;

//Floor value of any number x is the : Largest no. in array <= x
int floorValue(vector<int>& arr, int x)
{
    int n = arr.size();

    int floor = -1;

    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] <= x){
            floor = mid;
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }

    return floor;
}


//Ceil value of any number x is the : Smallest no. in array >= x
int ceilValue(vector<int>& arr, int x)
{
    int n = arr.size();
    int ceil = n;

    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] >= x)
        {
            ceil = arr[mid];
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return ceil;
}

// int main()
// {
//     vector<int> arr = {3, 4, 4, 5, 8, 10};

//     int x = 5;

//     // int floor = floorValue(arr, x);
//     int ceil = ceilValue(arr, x);

//     // cout << " Floor of " << x << " is " << floor << endl;
//     cout << "Ceil of " << x << " is " << ceil;

//     return 0;
// }