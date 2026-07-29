#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC -> O(n^2)
//SC -> O(1)
int bruteForce(vector<int>& arr)
{
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        int num = arr[i];
        int cnt = 0;

        for(int j = 0; j < n; j++)
        {
            if(arr[j] == num)
            cnt++;
        }
        if(cnt == 1)
        return num;
    }
}

//Optimal Sol
//TC -> O(n)
//SC -> O(1)
int optimalSol(vector<int>& arr)
{
    int ans = 0;
    for(auto it : arr)
    {
        ans = ans ^ it;
    }

    return ans;
}


int main()
{
    vector<int> arr = {3, 1, 2, 1, 2, 3, 4};

    int ans;

    ans = optimalSol(arr);

    cout << ans;
    return 0;
}