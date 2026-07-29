#include<bits/stdc++.h>
using namespace std;

//Make Rows Zeroes
void makeRowsZero(vector<vector<int>>& arr, int rowI)
{
    for(int i = 0; i < arr[0].size(); i++)
    {   
            if(arr[rowI][i] != 0)
            {
                arr[rowI][i] = -1;
            }
    }
}
//Make Column Zeroes
void makeColmZero(vector<vector<int>>& arr, int colmI)
{
    for(int i = 0; i < arr.size(); i++)
    {   
            if(arr[i][colmI] != 0)
            {
                arr[i][colmI] = -1;
            }
    }
}

//Brute Force Approach
//TC -> O((N*M)*(N+M) + (N*M)) -> ~O(n^3)
//SC -> O(1)
void bruteForce(vector<vector<int>>& arr)
{
    for(int i = 0; i < arr.size(); i++) //O(N) -> O(N*M)
    {
        for(int j = 0; j < arr[0].size(); j++) //O(M)
        {
            if(arr[i][j] == 0)
            {
                makeRowsZero(arr, i);
                makeColmZero(arr, j);
            }
        }
    }

    for(int i = 0; i < arr.size(); i++) //O(N*M)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            if(arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

//Better Soln
//TC -> O(2 * (n * m))
//SC -> O(n) + O(m)
void betterSol(vector<vector<int>>& arr)
{
    vector<int> row(arr.size(), 0);
    vector<int> column(arr[0].size(), 0);

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            if(arr[i][j] == 0)
            {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            if(row[i] or column[j])
            {
                arr[i][j] = 0;
            }
        }
    }
}

//Optimal Sol
//TC -> O(2 * (n * m))
//SC -> O(1)
void optimalSol(vector<vector<int>>& arr)
{
    int col0 = 1;

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            if(arr[i][j] == 0)
            {
                arr[i][0] = 0;

                if(j != 0)
                arr[0][j] = 0;
                else
                col0 = 0;
                
            }
        }
    }

    for(int i = 1; i < arr.size(); i++)
    {   
        for(int j = 1; j < arr[0].size(); j++)
        {
            if(arr[i][j] != 0)
            {
                if(arr[0][j] == 0 or arr[i][0] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }

    if(arr[0][0] == 0)
    {
        for(int j = 1; j < arr[0].size(); j++)
        {
            arr[0][j] = 0;   
        }
    }

    if(col0 == 0)
    {
        for(int i = 0; i < arr.size(); i++)
        {
            arr[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    optimalSol(arr);

    for(auto it : arr)
    {
        for(auto num: it)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

/* Optimal Approach (O(1) Space):


1. Use the First Row & Column as Markers:

    The first row (arr[0][j]) marks which columns need to be zeroed.

    The first column (arr[i][0]) marks which rows need to be zeroed.

    col0 is a special variable to track if the first column itself needs to be zeroed.

2. First Pass: Mark Rows & Columns:

    Loop through the matrix.

    If arr[i][j] == 0:

        Mark arr[i][0] = 0 (row i must be zeroed).

        If j != 0, mark arr[0][j] = 0 (column j must be zeroed).

        If j == 0, set col0 = 0 (first column must be zeroed).

3. Second Pass: Zero Out Based on Marks (Skip First Row/Column):

    Loop from (1,1) to (m-1, n-1).

    If arr[0][j] == 0 or arr[i][0] == 0, set arr[i][j] = 0.

4. Zero the First Row & Column (If Needed):

    If arr[0][0] == 0, zero the entire first row.

    If col0 == 0, zero the entire first column. */