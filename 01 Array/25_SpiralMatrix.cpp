#include<bits/stdc++.h>
using namespace std;

//Optimal Sol
//TC -> O(n*m)
//TC -> O(n*m)
vector<int> spiralMatrix(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = m-1;

    vector<int> ans;

    while(top <= bottom and left <= right)
    {
        //left to right
        for(int i = left; i <= right; i++)
        {
            ans.emplace_back(matrix[top][i]);
        }
        top++;
        //top to bottom
        for(int i = top; i <= bottom; i++)
        {
            ans.emplace_back(matrix[i][right]);
        }
        right--;
        //right to left
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                ans.emplace_back(matrix[bottom][i]);
            }
            bottom--;
        }
        //bottom to top
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
            {
                ans.emplace_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
        
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> ans;

    ans = spiralMatrix(matrix);

    for(auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}   