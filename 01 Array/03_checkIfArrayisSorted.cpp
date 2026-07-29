#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(N^2)
//SC -> O(1)
bool bruteForce(vector<int>& a)
{
    int n = a.size();

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[j] < a[i])
            return false;
        }
    }

    return true;
}

//Optimal Approach
//TC -> O(n)
//SC -> O(1)
bool OptimalSol(vector<int>& a)
{
    int n = a.size();
    
    for(int i = 1; i < n; i++)
    {
        // this case is when elem either increase or staying same
        //if elem always increasing then condition (a[i] <= a[i-1])
        if(a[i] < a[i-1])
        return false;
    }

    return true;
}

int main()
{
    vector<int> a = {3, 3, 3, 3, 3, 3, 3, 1};

    bool result;
    result = bruteForce(a);

    cout << ((result) ? "True" : "False");
    return 0;
}