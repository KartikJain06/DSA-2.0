#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^3)
//SC -> O(1)
int bruteForce(vector<int>& arr)
{
    int n = arr.size();

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int sum = 0;
            for(int k = i; k < j; k++)
            {
                sum += arr[k];
            }

            ans = max(ans, sum);
        }
    }

    return ans;
}

//Better Soln
//TC -> O(n^2)
//SC -> O(1)
int betterSol(vector<int>& arr)
{
    int n = arr.size();

    int ans = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            ans = max(ans, sum);
        }
    }

    return ans;
}

//Optimal Approach
//TC -> O(n)
//SC -> O(1)
//in this approach -> learn Kadane's Algo
int optimalSol(vector<int>& arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);
        if(sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;

}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};

    cout << betterSol(arr);

    return 0;
}