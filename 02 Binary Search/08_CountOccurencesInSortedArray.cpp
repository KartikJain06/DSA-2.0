#include<bits/stdc++.h>
using namespace std;

//Brute Force 
//TC -> O(n)
//SC -> O(1)
//We'll apply linear search and count every occurence on i'th iteration

//Optimal Sol
//TC -> 2 x O(log n)
//SC -> O(1)

//Code same as previous qeustion for first and last occurence

//Find fist and last occurence of 'target', and return (last - first + 1);

int main()
{
    vector<int> nums = {5,5,6,6,7,7,9,10};

    int target = 7;
    // searcRange obj;
    // vector<int> ans = optimalSol(nums, target);

    // cout << "From Index " <<  ans[0] << " to Index " << ans[1];

    return 0;
}