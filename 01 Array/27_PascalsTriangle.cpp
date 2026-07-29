#include<bits/stdc++.h>
using namespace std;

//Q.1 -> Given Row & Column find the element at that place
//TC -> O(r)
//SC -> O(1)
int nCr(int n, int r)
{
    long long res = 1;
    //these two variable for ignoring 0-indexing
    //if okay with 0 based indexing remove these two vars
    n = n-1;
    r = r-1;

    for(int i = 0; i < r; i++)
    {
        res = res * (n-i);
        res = res / (i+1);
    }

    return res;
}

//Q.2 -> Print Nth row of pascal triangle
//TC -> O(n)
//SC -> O(n)
vector<int> nCr(int n)
{   
    vector<int> result;

    int ans = 1;
    result.emplace_back(1);

    for(int i = 1; i < n; i++)
    {
        ans = ans * (n-i);
        ans = ans / i;

        result.emplace_back(ans);
    }

    return result;
}

//Q.3 -> Given N Generate the Pascal's Triangle till Nth row
//TC -> O()
//SC -> O()
class pascalTriangle
{
    private:
        vector<int> generateRow(int n)
        {
            vector<int> result;
            int ans = 1;

            result.push_back(1);

            for(int i = 1; i < n; i++)
            {
                ans = ans * (n-i);
                ans = ans / i;

                result.push_back(ans);
            }

            return result;
        }

    public:
        vector<vector<int>> nCr(int n)
        {
            vector<vector<int>> ans;

            for(int i = 1; i <= n; i++)
            {
                ans.emplace_back(generateRow(i));
            }

            return ans;
        }

        //Same Approach another code style
        vector<vector<int>> nCr2(int n)
        {
            vector<vector<int>> ans;

            for(int i = 0; i < n; i++)
            {
                vector<int> temp(i+1, 1);
                ans.emplace_back(temp);
            }

            for(int i = 2; i < n; i++)
            {
                for(int j = 1; j < i; j++)
                {
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
            return ans;
        }
};

int main()
{
    int q1;
    // vector<int> q2;
    // vector<vector<int>> q3;
    // pascalTriangle obj;

    // q3 = obj.nCr2(5);

    // for(auto it : q3)
    // {
    //     for(auto num : it)
    //     {
    //         cout << num << " ";
    //     }

    //     cout << endl;
    // }

    q1 = nCr(4, 3);

    cout << q1;
    
    
    return 0;
}