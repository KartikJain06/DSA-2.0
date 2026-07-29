#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(nlogn)
//SC -> O(n)
void bruteForce(vector<int>& arr)
{
    //Use mergeS Sort here or any other sorting algo which sorts the array in O(nlogn) in worst case
}


//Better Soln
//TC -> O(2n)
//SC -> O(1)
void betterSol(vector<int>& arr)
{

    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for(auto it : arr)
    {
        if(it == 0)
        {
            cnt0++;
        }
        if(it == 1)
        {
            cnt1++;
        }
        if(it == 2)
        {
            cnt2++;
        }
    }

    int i = 0;
    while(cnt0 > 0)
    {
        arr[i] = 0;
        cnt0--;
        i++;
    }
    while(cnt1 > 0)
    {
        arr[i] = 1;
        cnt1--;
        i++;
    }
    while(cnt2 > 0)
    {
        arr[i] = 2;
        cnt2--;
        i++;
    }
}

//here using Dutch National Flag Algo
//Optimal Sol
//TC -> O(n)
//SC -> O(1)
void optimalSol(vector<int>& arr)
{
    int n  = arr.size();
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {0, 0, 1, 2, 1, 0, 2, 2, 1, 1, 0, 2};

    optimalSol(arr);

    for(auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}