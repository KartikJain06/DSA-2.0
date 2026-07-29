#include<bits/stdc++.h>
using namespace std;

//Brtute Force Approach
//TC -> O(2 * n^2)
//SC -> O(n*n)
void bruteForce(vector<vector<int>>& arr)
{
    int n = arr.size();
    int m = n-1;
    vector<vector<int>> ans(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans[j][m-i] = arr[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = ans[i][j];
        }
    }
}

//Optimal Sol
//TC -> O(n/2 * n/2) + O(n * n/2) -> O(n^2) + O(n^2)
//SC -> O(1)
void optimalSol(vector<vector<int>> & arr)
{
    //Transpose the Matrix
    for(int i = 0; i < arr.size()-1; i++)
    {
        for(int j = i+1; j < arr.size(); j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    //Rotate the Rows
    for(int i = 0; i < arr.size(); i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
}

int main()
{
    vector<vector<int>> arr = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    optimalSol(arr);
    for(auto it : arr)
    {
        for(auto num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}